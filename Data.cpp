//---------------------------------------------------------------------------


#pragma hdrstop



#include "Data.h"
#include "Config.h"


extern GConfig *Config;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
	: TDataModule(Owner)
{
	tblConfig->Open();

	if ( !tblConfig->Eof ) {
		Config->setUserAndServer(tblConfigusername->AsString.Trim() , tblConfigservername->AsString.Trim() , tblConfigserverpathin->AsString.Trim() , tblConfigserverpathout->AsString.Trim()  );
	}
	tblConfig->Close();





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
TDM::setFTPDetails()
{
	qryFTPPassword->Parameters->ParamByName("user")->Value = Config->getUser() ;
	qryFTPPassword->Parameters->ParamByName("server")->Value = Config->getServer()  ;

	qryFTPPassword->Open();
	if ( ! qryFTPPassword->Eof ) {
		Config->setPassword(qryFTPPasswordpwd->Value );
	}
	qryFTPPassword->Close();




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

//	if ( ! fmSheego->SaveDialog1->Execute() ) {
//		spGetOrderOutput->Close();
//		return;
//	}


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

	int IDix = flds->IndexOf("ID");

	if ( IDix > -1 ) {
		flds->Delete(IDix);
	}


	flds->Delimiter = ';';
	rec->Delimiter = ';';
	csv->Add ( flds->DelimitedText );
	int col = 0;

	TStringList *f2 = new TStringList();

	f2->Clear();
	f2->Add("sku");
	f2->Add("Menge");
	f2->Add("WholeSaleNali");


	if( ! spGetOrderOutput->Eof )
	{
		rec->Clear();
		orderids->Add(IntToStr(spGetOrderOutputID->AsInteger) ) ;


		col = 0;
		while ( col < flds->Count  )
		{
			if ( f2->IndexOf(flds->Strings[col]) != -1 ) {
				rec->Add ( "" );
			}
			else
			{
			if ( flds->Strings[col] == "ReceiptDateRequested") {
				rec->Add ( spGetOrderOutput->FieldByName(flds->Strings[col])->AsDateTime.FormatString("dd.mm.yyyy") );
			}
			else
			{
				if ( flds->Strings[col] != "ID") {
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
			}
			}

			col++;
		}
		csv->Add(rec->DelimitedText );
	}

	while ( ! spGetOrderOutput->Eof )
		{
			rec->Clear();
			orderids->Add(IntToStr(spGetOrderOutputID->AsInteger) ) ;

			col = 0;

			while ( col < flds->Count  )
			{
				if ( f2->IndexOf(flds->Strings[col]) == -1 ) {
					rec->Add ( "" );
				}
				else
				{
				if ( flds->Strings[col] == "ReceiptDateRequested") {
					rec->Add ( spGetOrderOutput->FieldByName(flds->Strings[col])->AsDateTime.FormatString("dd.mm.yyyy") );
				}
				else
				{
					if ( flds->Strings[col] != "ID") {
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
				}
				}

				col++;
			}
			csv->Add(rec->DelimitedText );

			spGetOrderOutput->Next() ;
		}

	spGetOrderOutput->Close();
	delete f2;


	UnicodeString fileName = "order_fgh_sheego_" + Now().FormatString("yyyymmdd") + "_" + Now().FormatString("hhnnss") + ".csv";

	try
	{
		ForceDirectories("h:\\shgo\\temp");
		csv->SaveToFile("h:\\shgo\\temp\\" + fileName);
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

	// now send the file to the ftp folder


	Config->setCurrentFile("h:\\shgo\\temp\\" + fileName);
	Config->SentOK = false;


	fmSheego->actSendFile->Execute() ;




	if (Config->SentOK ) {
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
			MessageDlg ( "Success! Saved to " + fileName , mtInformation , TMsgDlgButtons() << mbOK , 0 );
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
	}



	delete orderids;

}

//---------------------------------------------------------------------------




