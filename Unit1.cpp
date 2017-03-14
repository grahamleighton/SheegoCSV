//---------------------------------------------------------------------------

#include <vcl.h>
#include <dateutils.hpp>


#pragma hdrstop

#include "Unit1.h"
#include "DBFParser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmSheego *fmSheego;
//---------------------------------------------------------------------------
__fastcall TfmSheego::TfmSheego(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void
TfmSheego::LoadDBFFile()
{
try
{
	TDBFParser *parser = new TDBFParser(FileOpen1->Dialog->FileName);

//	Memo1->Lines->Add ( "Loaded " + FileOpen1->Dialog->FileName );

//	Memo1->Lines->Add ( "Found " + IntToStr(parser->getFieldCount() ) + " fields");

	int i = 0 ;

	if ( parser->getFields()  ) {
		parser->getFields()->resetCounter() ;

		while ( i < parser->getFieldCount() )
		{
			DBFField *D = parser->getFields()->getNextField() ;

//			Memo1->Lines->Add ( D->getFieldName() );
//			Memo1->Lines->Add ( D->getFieldType() );
//			Memo1->Lines->Add ( D->getDisplacement() );

			i++;
		}

//		Memo1->Lines->Add ( "DATA");
//		Memo1->Lines->Add ( parser->getFieldList()->CommaText );
//		Memo1->Lines->AddStrings(parser->getData() );

	}


 //	parser->rewind() ;

	TStringList *csv = new TStringList();

	csv->Clear();
	csv->Add ( parser->getFieldList()->CommaText );
	csv->AddStrings(parser->getData() );

	csv->SaveToFile(ExtractFileDir(FileOpen1->Dialog->FileName) + "\\data.csv" );

	delete csv;


	delete parser;
 }
 catch(...)
 {

 }

}



void
TfmSheego::LoadCSVFile(UnicodeString CSVFile)
{
	TStringList *csv = new TStringList(); // to hold the file contents
	TStringList *hdr = new TStringList(); // to hold the header data
	TStringList *rec = new TStringList(); // to hold each record at a time
	bool Error = false;

	csv->Clear();
	hdr->Clear();
	rec->Clear();

	// Clear the string grid


	int i , j ;

	for ( i = 0; i < StringGrid1->ColCount; i++) {
		for (j = 0; j < StringGrid1->RowCount; j++) {
			StringGrid1->Cells[i][j] = "";
		}
	}

	StringGrid1->RowCount = 0;
	StringGrid1->ColCount = 0;


	// 1. Load the CSV file

	try
	{
		csv->LoadFromFile(CSVFile);
	}
	catch(Exception &E)
	{
		MessageDlg ( "Error loading file \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
		Error = true;
	}

	// 2. Load the header record to StringGrid

	if ( ! Error ) {
		if ( csv->Count > 1) {
			try
			{
				hdr->CommaText = csv->Strings[0];
				StringGrid1->ColCount = hdr->Count + 1 ;

				int h = 0;
				while ( h < hdr->Count )
				{
					AnsiString Orig = hdr->Strings[h];
					int start = -1;
					while ( StringGrid1->Rows[0]->IndexOf(hdr->Strings[h]) != -1 ) {
						start++;
						AnsiString newColumn = Orig + "_" + IntToStr(start);
						hdr->Strings[h] = newColumn;
					}

					StringGrid1->Cells[h][0] = hdr->Strings[h];
					h++;
				}

				// add the wholesalenali

				StringGrid1->Cells[h][0] = "WholeSaleNali";

			}
			catch(Exception &E)
			{
				MessageDlg ( "Error loading header record \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
				Error = true;
			}
		}
	}

	// 2. Load the header record to StringGrid

	if ( ! Error ) {
		if ( csv->Count > 1 ) {
			StringGrid1->RowCount = csv->Count ;
			try
			{
				int row = 1;

				while ( row < csv->Count )
				{
					rec->CommaText = csv->Strings[row];
					int col = 0;

					while ( col < rec->Count )
						{
							StringGrid1->Cells[col][row] = rec->Strings[col];
							col++;
						}
					StringGrid1->Cells[col][row] = "0";

					row++;
				}
			}
			catch(Exception &E)
			{
				MessageDlg ( "Error loading data records \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
				Error = true;
			}
		}
	}


	StringGrid1->FixedRows = 1;
	StringGrid1->FixedCols = 9;

	int hc = 0;

	while ( hc < StringGrid1->ColCount )
		{
			int mx = 0 ;

			mx = 0;
			int r = 0;
			while (r < StringGrid1->RowCount )
			{
				if ( StringGrid1->Cells[hc][r].Length() > mx ) {
					mx = StringGrid1->Cells[hc][r].Length() ;
				}
				r++;
			}

			StringGrid1->ColWidths[hc] = (mx+1) * 10;
			hc++;
		}






	delete hdr;
	delete rec;
	delete csv;

	TabSheet1->TabVisible = true;
	PageControl1->ActivePage = TabSheet1;

}

void __fastcall TfmSheego::FileOpen1Accept(TObject *Sender)
{

	if (ExtractFileExt(FileOpen1->Dialog->FileName ).UpperCase() == ".DBF") {
		LoadDBFFile() ;
		LoadCSVFile(ExtractFileDir(FileOpen1->Dialog->FileName) + "\\data.csv" );


	}

	if (ExtractFileExt(FileOpen1->Dialog->FileName ).UpperCase() == ".CSV") {
		LoadCSVFile(FileOpen1->Dialog->FileName) ;
	}

    StringGrid1->Visible = true;





}
//---------------------------------------------------------------------------



void __fastcall TfmSheego::TabSheet1Show(TObject *Sender)
{
	DM->spGetCustomers->Active = true;

}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::btnNewCustomerClick(TObject *Sender)
{
	txtFirstName->Text = "";
	txtFirstName->Tag = 0;
	txtLastName->Text = "";
	txtAccountNo->Text = "";

	txtFirstName->SetFocus() ;

	btnCancel->Enabled = false;
	btnUpdate->Enabled = false;



}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::txtFirstNameKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	btnUpdate->Enabled = true;
	btnCancel->Enabled = true;

}
//---------------------------------------------------------------------------


void __fastcall TfmSheego::btnUpdateClick(TObject *Sender)
{
	if ( txtFirstName->Tag == 0 ) {
		// new record
		TADOCommand *sp = DM->spAddCustomer ;

		sp->Parameters->ParamByName("@FirstName")->Value =
			txtFirstName->Text.Trim();
		sp->Parameters->ParamByName("@LastName")->Value =
			txtLastName->Text.Trim();
		sp->Parameters->ParamByName("@AccountNo")->Value =
			txtAccountNo->Text.Trim();

		try
		{
			sp->Execute() ;
		}
		catch(Exception &E)
		{
			MessageDlg ( "Error adding new customer \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
			return;
		}

		RefreshCustomers();

	}
	else
	{
		// this is an update

		TADOCommand *sp = DM->spUpdateCustomer ;

		sp->Parameters->ParamByName("@CustomerID")->Value =
			txtFirstName->Tag;

		sp->Parameters->ParamByName("@FirstName")->Value =
			txtFirstName->Text.Trim();

		sp->Parameters->ParamByName("@LastName")->Value =
			txtLastName->Text.Trim();

		sp->Parameters->ParamByName("@AccountNo")->Value =
			txtAccountNo->Text.Trim();
		try
		{
			sp->Execute() ;
		}
		catch(Exception &E)
		{
			MessageDlg ( "Error updating new customer \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
			return;
		}

	RefreshCustomers();


	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::btnCancelClick(TObject *Sender)
{
	RefreshCustomers();
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::BitBtn1Click(TObject *Sender)
{
	if ( MessageDlg("Are you sure you want to delete this record ?" , mtConfirmation ,TMsgDlgButtons() << mbYes << mbNo , 0 ) == mrYes ) {
		DM->spDeleteCustomer->Parameters->ParamByName("@CustomerID")->Value =
			txtFirstName->Tag;
		try
		{
			DM->spDeleteCustomer->Execute() ;
		}
		catch(Exception &E)
		{
			MessageDlg ( "Error deleting customers \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
		}
	}

	RefreshCustomers();

}

void
TfmSheego::RefreshCustomers()
{
	try
		{
			DM->spGetCustomers->DisableControls() ;
			int CID = DM->spGetCustomersCustomerID->AsInteger ;
			DM->spGetCustomers->Active = false;
			DM->spGetCustomers->Active = true;
			try
			{
				DM->spGetCustomers->Locate("CustomerID",CID , TLocateOptions() );
			}
			catch(...)
			{

			}
			DM->spGetCustomers->EnableControls() ;
		}
		catch(Exception &E)
		{
			MessageDlg ( "Error refreshing customers \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );

		}
		btnUpdate->Enabled = false;
		btnCancel->Enabled = false;

}

//---------------------------------------------------------------------------

void __fastcall TfmSheego::BitBtn2Click(TObject *Sender)
{
	txtFirstName->Tag = 0;
	btnUpdate->Enabled = true;
	btnCancel->Enabled = true;
}
//---------------------------------------------------------------------------





void __fastcall TfmSheego::BitBtn3Click(TObject *Sender)
{
	// Commit










}
//---------------------------------------------------------------------------



void __fastcall TfmSheego::FormShow(TObject *Sender)
{
	DateTimePicker1->Date = IncDay(Date(),1);

	DM->spGetCustomers->Active = true;


#if 0
	if ( Theme1->Count > 0 ) {
			return;
	}
	TStyleManager *sm = new TStyleManager();

	TStringDynArray arr = sm->StyleNames;


	int s = 0;
	while (s < arr.High )
		{
			TMenuItem *mi = new TMenuItem(Theme1);
			mi->Caption = arr[s];
			mi->AutoHotkeys = maManual ;


			Theme1->Insert(0,mi);
			mi->OnClick = Auric1Click;


			s++;
		}

	delete sm;
#endif



}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::Button1Click(TObject *Sender)
{

	if ( ! DM->spGetOrderHeadersSentDate->IsNull   ) {
		MessageDlg ( "Order has already been sent , cannot delete" , mtInformation , TMsgDlgButtons() << mbOK , 0 );
		return;
	}

	if ( MessageDlg ( "Are you sure you want to delete this order ?" , mtConfirmation , TMsgDlgButtons() << mbYes << mbNo , 0 ) == mrYes ) {
		try
		{
			DM->spDeleteOrder->Parameters->ParamByName("@OrderID")->Value =
				DM->spGetOrderHeadersOrderFileHeaderID->Value ;
			DM->spDeleteOrder->Execute();

			RefreshOrders() ;


		}
		catch(Exception &E)
		{
			MessageDlg ( "Error deleting order \n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
		}

	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::TabSheet3Show(TObject *Sender)
{
	DM->spGetOrderHeaders->Active = true;

}

void
TfmSheego::RefreshOrders()
{
	DM->spGetOrderHeaders->DisableControls();
	DM->spGetOrderDetail->DisableControls() ;
	DM->spGetOrderHeaders->Active = false;
	DM->spGetOrderHeaders->Active = true;

	DM->spGetOrderDetail->EnableControls() ;
	DM->spGetOrderHeaders->EnableControls();

}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::TabSheet3Hide(TObject *Sender)
{
	DM->spGetOrderHeaders->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actCreateCSVExecute(TObject *Sender)
{
	DM->CreateCSV();
	RefreshOrders();


}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actRefreshOrdersExecute(TObject *Sender)
{
	RefreshOrders() ;

}
//---------------------------------------------------------------------------




void __fastcall TfmSheego::Auric1Click(TObject *Sender)
{
	TStyleManager *sm = new TStyleManager();


	sm->TrySetStyle(((TMenuItem *)(Sender))->Caption );

	delete sm;


}
//---------------------------------------------------------------------------



void __fastcall TfmSheego::actCommitExecute(TObject *Sender)
{

	DM->DB->BeginTrans() ;

	// add a new order....
	try
	{
		DM->spAddOrderHeader->Parameters->ParamByName("@CustomerID")->Value =
			txtFirstName->Tag;
		DM->spAddOrderHeader->Parameters->ParamByName("@ReceiptDate")->Value =
			DateTimePicker1->Date.FormatString("yyyy-mm-dd");

		DM->spAddOrderHeader->Execute();
	}
	catch(Exception &E)
	{
		MessageDlg ( "Error adding a new order\n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
	}


	int ID = DM->spAddOrderHeader->Parameters->ParamByName("@CreateID")->Value;
//	Memo1->Lines->Add ( "Created order id : " + IntToStr(ID));


#if 0
	TStringList *pars = new TStringList();

	pars->Clear();

	int p = 0;

	while ( p < DM->spAddOrderLine->Parameters->Count     )
		{
			pars->Add ( DM->spAddOrderLine->Parameters->Items[p]->Name );
			p++;
		}
#endif

	int row = 1;

	while  ( row < StringGrid1->RowCount )
		{
			// populate order details
			int j = 0;

			int p = 0;

			while ( p < DM->spAddOrderLine->Parameters->Count   )
				{
					DM->spAddOrderLine->Parameters->Items[p]->Value = NULL;
					p++;
				}

			DM->spAddOrderLine->Parameters->ParamByName("@OrderFileHeaderID")->Value =
				ID;

			while ( j < StringGrid1->ColCount  )
			{
				UnicodeString vdata = StringGrid1->Cells[j][row];
				UnicodeString vhead = StringGrid1->Cells[j][0];

				if ( DM->spAddOrderLine->Parameters->FindParam("@"+vhead) ) {
					DM->spAddOrderLine->Parameters->ParamByName("@"+vhead)->Value  = vdata;
				}

				j++;
			}

			try
			{

				DM->spAddOrderLine->Execute();
			}
			catch(Exception &E)
			{
				MessageDlg ( "Error adding a new order detail line\n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
			}

			row++;
		}

	DM->DB->CommitTrans() ;

	MessageDlg ( "Success!" , mtInformation , TMsgDlgButtons() << mbOK , 0 );



	RefreshOrders() ;



//	delete pars;


}
//---------------------------------------------------------------------------





