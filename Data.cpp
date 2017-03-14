//---------------------------------------------------------------------------


#pragma hdrstop

#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::spGetCustomersAfterScroll(TDataSet *DataSet)
{
	fmSheego->txtFirstName->Text = DataSet->FieldByName("FirstName")->AsString;
	fmSheego->txtFirstName->Tag = DataSet->FieldByName("CustomerID")->AsInteger;
	fmSheego->txtFirstName->Hint = "CustomerID : " + IntToStr(DataSet->FieldByName("CustomerID")->AsInteger);


	fmSheego->txtLastName->Text = DataSet->FieldByName("LastName")->AsString;
	fmSheego->txtAccountNo->Text = DataSet->FieldByName("AccountNo")->AsString;

	fmSheego->lblCustomer->Caption = "Using customer " + fmSheego->txtFirstName->Text + " " + fmSheego->txtLastName->Text + " (" + fmSheego->txtAccountNo->Text + ")";

	fmSheego->btnCancel->Enabled = false;
	fmSheego->btnUpdate->Enabled = false;



}
//---------------------------------------------------------------------------
void __fastcall TDM::spGetOrderHeadersAfterScroll(TDataSet *DataSet)
{
	spGetOrderDetail->DisableControls() ;

	spGetOrderDetail->Active = false;

	spGetOrderDetail->Parameters->Items[0]->Value = 0 ;
	spGetOrderDetail->Parameters->Items[1]->Value = spGetOrderHeadersOrderFileHeaderID->Value ;

	spGetOrderDetail->ExecProc ();

	spGetOrderDetail->Active = true;

	spGetOrderDetail->EnableControls() ;


}
//---------------------------------------------------------------------------

void __fastcall TDM::spGetOrderHeadersBeforeClose(TDataSet *DataSet)
{
	spGetOrderDetail->Active = false;
}


void
TDM::CreateCSV()
{
	// creates csv

	try
	{
		spGetOrderOutput->Active = true;
	}
	catch(Exception &E)
	{
		MessageDlg ("Error during CSV creation\n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
		return;
	}

	if ( spGetOrderOutput->Eof ) {
		MessageDlg ( "No outstanding orders" , mtInformation , TMsgDlgButtons() << mbOK , 0 , mbOK );
		spGetOrderOutput->Active = false;
		return;
	}

	if ( ! fmSheego->SaveDialog1->Execute() ) {
		spGetOrderOutput->Close();
		return;
	}


	TStringList *csv = new TStringList();
	TStringList *rec = new TStringList();
	TStringList *flds = new TStringList();
	TStringList *orderids = new TStringList();

	orderids->Sorted = true;
	orderids->Duplicates = System::Types::dupIgnore ;

	csv->Clear();
	rec->Clear();
	flds->Clear();

	spGetOrderOutput->GetFieldNames(flds);


	flds->Delimiter = ';';
	rec->Delimiter = ';';
	csv->Add ( flds->DelimitedText );
	int col = 0;
	while ( ! spGetOrderOutput->Eof )
		{
			rec->Clear();
			orderids->Add(IntToStr(spGetOrderOutputSalesIdExternal->AsInteger) ) ;

			col = 0;
			while ( col < flds->Count  )
			{
				if ( flds->Strings[col] == "ReceiptDateRequested") {
					rec->Add ( spGetOrderOutput->FieldByName(flds->Strings[col])->AsDateTime.FormatString("dd.mm.yyyy") );
				}
				else
				{
					switch (spGetOrderOutput->FieldByName(flds->Strings[col])->DataType) {
						case ftInteger : {
							rec->Add ( IntToStr(spGetOrderOutput->FieldByName(flds->Strings[col])->AsInteger) ) ;
							break;
						}
						case ftDate :
						case ftDateTime :
						{
							rec->Add ( spGetOrderOutput->FieldByName(flds->Strings[col])->AsDateTime.FormatString("dd.mm.yyyy") );
							break;
						}
						case ftBoolean :
						{
							if (spGetOrderOutput->FieldByName(flds->Strings[col])->AsBoolean == true) {
								rec->Add ( "1");
							}
							else
							{
								rec->Add ("0");
							}
							break;
                        }
					default:
						rec->Add ( spGetOrderOutput->FieldByName(flds->Strings[col])->Value ) ;
					}
				}

				col++;
			}
			csv->Add(rec->DelimitedText );

			spGetOrderOutput->Next() ;
		}

	spGetOrderOutput->Close();


	try
	{
		csv->SaveToFile(fmSheego->SaveDialog1->FileName);
	}
	catch(Exception &E)
	{
		MessageDlg ( "Error saving CSV file to " + fmSheego->SaveDialog1->FileName + "\n\n" + E.Message
			,mtError
			,TMsgDlgButtons() << mbOK
			, 0 );
	}


	delete csv;
	delete rec;
	delete flds;

	// now update the orderids

	int oi = 0;

	try
	{
		DB->BeginTrans() ;

		while ( oi < orderids->Count)
			{
				spUpdateOrderAsSent->Parameters->ParamByName("@OrderID")->Value =
					orderids->Strings[oi];
				spUpdateOrderAsSent->Execute();

				oi++;
			}

		DB->CommitTrans() ;
		MessageDlg ( "Success! Saved to " + fmSheego->SaveDialog1->FileName , mtInformation , TMsgDlgButtons() << mbOK , 0 );
	}
	catch(Exception &E)
	{
		try
		{
			DB->RollbackTrans() ;
		}
		catch(...)
		{

		}
		MessageDlg ( "Error while creating CSV , backing out all changes\n\n" + E.Message ,
			mtError ,
			TMsgDlgButtons() << mbOK , 0 );
	}

	delete orderids;

}

//---------------------------------------------------------------------------




