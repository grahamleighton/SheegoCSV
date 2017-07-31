//---------------------------------------------------------------------------

#include <vcl.h>
#include <dateutils.hpp>

#include <IdAllFTPListParsers.hpp>

#include <IdException.hpp>

#pragma hdrstop

#include "Unit1.h"
#include "DBFParser.h"

#include "config.h"

GConfig *Config;
UnicodeString fileToSend;


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmSheego *fmSheego;
//---------------------------------------------------------------------------
__fastcall TfmSheego::TfmSheego(TComponent* Owner)
	: TForm(Owner)
{
	Config = new GConfig();
	char user[255];

	unsigned long l = 255;

	memset( user , 0 , 255 );

	GetUserNameA(user,&l);

	UnicodeString usr ;

	usr = user;
	StatusBar1->Panels->Items[1]->Text = usr.UpperCase();





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

	tabImport->TabVisible = true;
	PageControl1->ActivePage  = tabImport;

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



void __fastcall TfmSheego::tabImportShow(TObject *Sender)
{

	if (! DM->spGetCustomers->Active ) {
		DM->spGetCustomers->Active = true;
		if (! DM->spGetCustomers->Eof ) {
			//if not eof then find first with active = 1
			if ( ! DM->spGetCustomers->Locate("Active",1,TLocateOptions() ) )
			{
				// couldn't find an active one so default to first record
				DM->spGetCustomers->First();
			}
		}
	}
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
		sp->Parameters->ParamByName("@Active")->Value =
				( cmbActive->Text == "Yes" ) ? 1 : 0;
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

		sp->Parameters->ParamByName("@Active")->Value =
				( cmbActive->Text == "Yes" ) ? 1 : 0;

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

	RichEdit1->Lines->LoadFromFile("I:\\whseapps\\sheego\\instructions\\instructions.rtf");

	PageControl1->ActivePage = tabImport;



//	DM->spGetCustomers->Active = true;


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

void __fastcall TfmSheego::tabOrdersShow(TObject *Sender)
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

void __fastcall TfmSheego::tabOrdersHide(TObject *Sender)
{
	DM->spGetOrderHeaders->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actCreateCSVExecute(TObject *Sender)
{
	DM->CreateCSVFiles();
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
				if (vhead == "OPT_DESC_0") {
					vhead = "OPT_DESC2";
				}



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





void __fastcall TfmSheego::actSendFileExecute(TObject *Sender)
{

	StatusBar1->Panels->Items[2]->Text = "Setting FTP details...";
	Application->ProcessMessages();

	DM->setFTPDetails() ;

	IdFTP2->Host = Config->getServer() ;
	IdFTP2->Username = Config->getUser() ;
	IdFTP2->Password = Config->getPassword() ;

	try
	{
		if ( ! IdFTP2->Connected() ) {
			StatusBar1->Panels->Items[2]->Text = "Connecting to FTP Server...";
			Application->ProcessMessages();
			IdFTP2->Tag = 0;
			IdFTP2->Connect();
		}
		else
		{
			IdFTP2->Tag = 1;
			IdFTP2AfterClientLogin(Sender);
		}

	}
	catch(Exception &E)
	{
		if (E.Message.UpperCase().Pos("ALREADY CONNECTED") > 0 ) {
			StatusBar1->Panels->Items[2]->Text = "Connecting to FTP Server...";
			Application->ProcessMessages();
			IdFTP2AfterClientLogin(Sender);
		}
		else
			MessageDlg ( E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
	}





}
//---------------------------------------------------------------------------


void __fastcall TfmSheego::IdFTP1AfterClientLogin(TObject *Sender)
{

	static UnicodeString pwd = IdFTP1->RetrieveCurrentDir() ;

	if (!pwd.IsEmpty() ) {
		 IdFTP1->ChangeDir(pwd);
	}

	IdFTP1->ChangeDir(Config->getServerFolderIn() );

	IdFTP1->List();

	int i = 0 ;

	lvIn->Items->Clear();

	while ( i < IdFTP1->DirectoryListing->Count   )
		{
			TListItem *LI = lvIn->Items->Add();

			LI->Caption = IdFTP1->DirectoryListing->Items[i]->FileName;
			LI->SubItems->Add ( IntToStr(IdFTP1->DirectoryListing->Items[i]->Size) ) ;
			LI->SubItems->Add ( IdFTP1->DirectoryListing->Items[i]->ModifiedDate.FormatString("dd/mm/yyyy hh:nn")  );
			i++;
		}

	IdFTP1->ChangeDir(pwd);
	IdFTP1->ChangeDir(Config->getServerFolderOut() );



	IdFTP1->List();

	i = 0 ;
	lvOut->Items->Clear();

	while ( i < IdFTP1->DirectoryListing->Count   )
		{
			TListItem *LI = lvOut->Items->Add();

			LI->Caption = IdFTP1->DirectoryListing->Items[i]->FileName;
			LI->SubItems->Add ( IntToStr(IdFTP1->DirectoryListing->Items[i]->Size) ) ;
			LI->SubItems->Add ( IdFTP1->DirectoryListing->Items[i]->ModifiedDate.FormatString("dd/mm/yyyy hh:nn")  );
			i++;
		}



//	IdFTP1->Disconnect();







}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actGetPwdExecute(TObject *Sender)
{
	DM->setFTPDetails() ;

	IdFTP1->Host = Config->getServer() ;
	IdFTP1->Username = Config->getUser() ;
	IdFTP1->Password = Config->getPassword() ;


	Config->displaySettings() ;


}
//---------------------------------------------------------------------------


void __fastcall TfmSheego::actRefreshOrderFilesExecute(TObject *Sender)
{
	DM->setFTPDetails() ;

	StatusBar1->Panels->Items[2]->Text = "Refreshing...";
	Application->ProcessMessages();


	IdFTP1->Host = Config->getServer() ;
	IdFTP1->Username = Config->getUser() ;
	IdFTP1->Password = Config->getPassword() ;


	lvIn->Items->Clear() ;
	lvOut->Items->Clear() ;

 //	Config->displaySettings() ;

	try
	{
		if ( ! IdFTP1->Connected() ) {
			IdFTP1->Connect();
		}
		else
			IdFTP1AfterClientLogin(Sender);

	}
	catch(Exception &E)
	{
		if (E.Message.UpperCase().Pos("ALREADY CONNECTED") > 0 ) {
			IdFTP1AfterClientLogin(Sender);
		}
		else
			MessageDlg ( E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
	}

	StatusBar1->Panels->Items[2]->Text = "";
	Application->ProcessMessages();



}
//---------------------------------------------------------------------------


void __fastcall TfmSheego::IdFTP2AfterClientLogin(TObject *Sender)
{

	StatusBar1->Panels->Items[2]->Text = "Changing directory...";
	Application->ProcessMessages();

	if (IdFTP2->Tag == 0 ) {
		IdFTP2->ChangeDir(Config->getServerFolderOut() );

	}

	StatusBar1->Panels->Items[2]->Text = "Sending File...";
	Application->ProcessMessages();
	IdFTP2->Put(Config->getCurrentFile() );














}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::IdFTP2AfterPut(TObject *Sender)
{
	Config->SentOK = true;

	StatusBar1->Panels->Items[2]->Text = "Sent File OK";
	Application->ProcessMessages();

	Sleep(1500);

	StatusBar1->Panels->Items[2]->Text = "";
	Application->ProcessMessages();




}
//---------------------------------------------------------------------------



void __fastcall TfmSheego::cmbActiveChange(TObject *Sender)
{
	btnUpdate->Enabled = true;
	btnCancel->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::Button3Click(TObject *Sender)
{
	RichEdit1->Print("Instructions");
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::Button4Click(TObject *Sender)
{
	if ( DM->spGetConfigAdmin->Eof || txtConfigID->Caption.IsEmpty() ) {
		return;
	}

	DM->spUpdateConfig->Parameters->ParamByName("@ConfigID")->Value =
		txtConfigID->Caption.ToInt();
	DM->spUpdateConfig->Parameters->ParamByName("@servername")->Value =
		txtConfigServerName->Text;
	DM->spUpdateConfig->Parameters->ParamByName("@username")->Value =
		txtConfigUserName->Text;
	DM->spUpdateConfig->Parameters->ParamByName("@serverpathin")->Value =
		txtConfigServerPathIn->Text;
	DM->spUpdateConfig->Parameters->ParamByName("@serverpathout")->Value =
		txtConfigServerPathOut->Text;
	DM->spUpdateConfig->Parameters->ParamByName("@AXAccount")->Value =
		txtConfigAXAccount->Text;

	try
	{
		DM->spUpdateConfig->ExecProc();
	}
	catch(Exception &E)
	{
		MessageDlg ( "Error while updating config\n\nError : " + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
	}

	DM->spGetConfigAdmin->Requery();

	Config->setUserAndServer( txtConfigUserName->Text.Trim() , txtConfigServerName->Text.Trim() , txtConfigServerPathIn->Text.Trim() , txtConfigServerPathOut->Text.Trim()  );
	Config->setAXAccount( txtConfigAXAccount->Text.Trim() );



}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::tabConfigShow(TObject *Sender)
{
	DM->spGetConfigAdmin->Open() ;

}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::TabSheet1Show(TObject *Sender)
{
	if ( ! DM->spGetResponseHeaders->Active  ) {
		DM->spGetResponseHeaders->Active = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actExportResponseExecute(TObject *Sender)
{
	if ( SaveDialog1->Execute() ) {
        DM->ExportResponse(SaveDialog1->FileName );
	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actDeleteResponseExecute(TObject *Sender)
{

	if ( ! DM->spGetResponseHeaders->Active || DM->spGetResponseHeadersResponsesID->IsNull  ) {
		return;
	}

	if ( InputBox ( "Confirm delete ?" ,"Are you sure you wish to remove this order  ? Type \"YES\" to confirm","" ) != "YES" ) {
		return;
	}


	DM->cmdDeleteResponse->Parameters->ParamByName("@ResponseID")->Value =
		DM->spGetResponseHeadersResponsesID->Value;

	try
	{
		DM->cmdDeleteResponse->Execute();
		MessageDlg ( "Response deleted OK", mtInformation , TMsgDlgButtons() << mbOK , 0 );
	}
	catch(Exception &E)
	{
		MessageDlg ( "Error deleting Response record\n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
	}

	actResponseRefresh->Execute() ;






}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::actResponseRefreshExecute(TObject *Sender)
{
	try
	{
		StatusBar1->Panels->Items[2]->Text = "Refreshing...";
		Application->ProcessMessages();

		DM->spGetResponseHeaders->Active = false;
		DM->spGetResponseHeaders->Active = true;
	}
	catch(Exception &E)
	{
		MessageDlg ( "Error refreshing Responses\n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );

	}
	StatusBar1->Panels->Items[2]->Text = "";
	Application->ProcessMessages();

}
//---------------------------------------------------------------------------





void __fastcall TfmSheego::Button6Click(TObject *Sender)
{
	if (! txtFindSKU->Text.IsEmpty()) {

		DM->spGetSKUStock->Filter = "[UKItem] like '" + txtFindSKU->Text + "%'";
		DM->spGetSKUStock->Filtered = true;

	}
	else
	{
		DM->spGetSKUStock->Filtered = false;
		DM->spGetSKUStock->Filter = "";

    }
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::TabSheet2Show(TObject *Sender)
{
	DM->spGetSKUStock->Open();
}
//---------------------------------------------------------------------------


void __fastcall TfmSheego::txtFindSKUKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if ( Key ==  13) {
        Button6->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TfmSheego::Button8Click(TObject *Sender)
{
	if ( SaveDialog1->Execute()) {
		TStringList *csv = new TStringList();
		TStringList *rec = new TStringList();
		TStringList *col = new TStringList();

		csv->Clear();
		rec->Clear();
		col->Clear();


		int c = 0;

		while ( c < DBGrid7->Columns->Count  )
		{
			rec->Add(DBGrid7->Columns->Items[c]->FieldName  );
			c++;
		}
		col->Text = rec->Text;
		csv->Add(rec->CommaText);

		rec->Clear();

		try
		{
			TDataSet *D = DBGrid7->DataSource->DataSet;
			TBookmark bmk = D->GetBookmark();

			D->DisableControls();

			try
			{
				// create the CSV from the data

				D->First() ;
				while( ! D->Eof )
				{
					int cl = 0;
					rec->Clear();

					AnsiString ct = "";
					while ( cl < col->Count )
					{
						if ( cl == 2 || cl == 0  )
							rec->Add ( " " + D->FieldByName(col->Strings[cl])->Value + " " ) ;
						else
							rec->Add ( D->FieldByName(col->Strings[cl])->Value ) ;

						if ( cl < 7 )
						{
						if ( ct.IsEmpty() )
							ct = "=\"" + D->FieldByName(col->Strings[cl])->Value + "\"";
						else
							ct += ",=\"" + D->FieldByName(col->Strings[cl])->Value + "\"";

						}
						else
						{
							ct +=  "," + D->FieldByName(col->Strings[cl])->Value;
						}
						cl++;
					}




//					csv->Add ( rec->CommaText );
					csv->Add ( ct  );
					D->Next();
				}

			}
			catch(Exception &E)
			{
			}

			D->GotoBookmark(bmk);

			D->EnableControls();
		}
		catch(...)
		{
		}
		bool retry = true;
		bool saved = false;
		while ( retry )
		{
			try
			{
				csv->SaveToFile ( SaveDialog1->FileName );
				saved = true;
				retry = false;
			}
			catch(Exception &E)
			{
				if ( MessageDlg ( "Error while trying to save to " + SaveDialog1->FileName + "\n\nError : " + E.Message + "\n\nRetry ?",
					mtWarning,
					TMsgDlgButtons() << mbYes << mbNo , 0 ) == mrNo )
				{
					retry = false;
				}
			}
		}
		if ( saved)
		{
			MessageDlg ( "SKU Stock Saved to " + SaveDialog1->FileName ,
				mtInformation , TMsgDlgButtons() << mbOK , 0 );
		}
	}
}
//---------------------------------------------------------------------------

