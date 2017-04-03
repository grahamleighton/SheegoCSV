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

	orderids = new TStringList();
	orderids->Clear();

	orderids->Sorted = true;
	orderids->Duplicates = System::Types::dupIgnore ;


	spGetConfig->Active = true;

	if ( !spGetConfig->Eof ) {
		Config->setUserAndServer( spGetConfigusername->AsString.Trim() , spGetConfigservername->AsString.Trim() , spGetConfigserverpathin->AsString.Trim() , spGetConfigserverpathout->AsString.Trim()  );
		Config->setAXAccount(spGetConfigaxcustaccount->AsString.Trim() );
	}

	spGetConfig->Active = false;


	try
	{
		spGetConfigAdmin->Open() ;
		spGetConfigAdmin->Close();
	}
	catch(...)
	{
		if ( fmSheego) {
			fmSheego->tabConfig->TabVisible = false;
			fmSheego->cmdDeleteResponse->Visible = false;
			fmSheego->GetPwd1->Visible = false;
		}
	}






}
//---------------------------------------------------------------------------
void __fastcall TDM::spGetCustomersAfterScroll(TDataSet *DataSet)
{
	fmSheego->txtFirstName->Text = DataSet->FieldByName("FirstName")->AsString;
	fmSheego->txtFirstName->Tag = DataSet->FieldByName("CustomerID")->AsInteger;
	fmSheego->txtFirstName->Hint = "CustomerID : " + IntToStr(DataSet->FieldByName("CustomerID")->AsInteger);


	fmSheego->txtLastName->Text = DataSet->FieldByName("LastName")->AsString;
	fmSheego->txtAccountNo->Text = DataSet->FieldByName("AccountNo")->AsString;

	if ( DataSet->FieldByName("Active")->IsNull || ! DataSet->FieldByName("Active")->AsBoolean )   {
		// false
		fmSheego->cmbActive->ItemIndex = fmSheego->cmbActive->Items->IndexOf("No");
	}
	else
	{
		// true
		fmSheego->cmbActive->ItemIndex = fmSheego->cmbActive->Items->IndexOf("Yes");
	}




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

	spGetServerPassword->Parameters->ParamByName("@username")->Value = Config->getUser() ;
	spGetServerPassword->ExecProc();

	Config->setPassword(spGetServerPassword->Parameters->ParamByName("@pwd")->Value );




}


void
TDM::CreateCSVFiles()
{
	TStringList *PO = new TStringList();
	PO->Sorted = true;

	if ( !p ) {
		p = new TfmProgress(Application);
	}
	p->Animate1->Active = true;

	p->Label1->Text = "Getting POs to send..";
	Application->ProcessMessages();


	PO->Duplicates = System::Types::dupIgnore ;

	PO->Clear();
	try
	{
		spGetOrderOutput->Active = true;
		while ( ! spGetOrderOutput->Eof )
			{
				p->Label1->Text = "Getting POs to send..";
				Application->ProcessMessages();
				PO->Add(spGetOrderOutputSalesIdExternal->Value  );
				spGetOrderOutput->Next() ;
			}
	}
	catch(...)
	{

	}

	int i = 0;

	while ( i < PO->Count )
		{
			p->Label1->Text = "Creating CSV for PO " + PO->Strings[i] ;
			Application->ProcessMessages();
			spGetOrderOutput->Active = false;
			p->Label1->Text = "Creating CSV for PO " + PO->Strings[i] ;
			Application->ProcessMessages();
			spGetOrderOutput->Filter = "[SalesIdExternal]='" + PO->Strings[i].Trim() + "'";
			spGetOrderOutput->Filtered = true;
			p->Label1->Text = "Creating CSV for PO " + PO->Strings[i] ;
			Application->ProcessMessages();
			spGetOrderOutput->Active = true;
			p->Label1->Text = "Creating CSV for PO " + PO->Strings[i] ;
			Application->ProcessMessages();
			CreateCSV();
			i++;
		}
	spGetOrderOutput->Active = false;

	UpdateOrders() ;

	delete p;
	fmSheego->SetFocus();

	MessageDlg ( "Success! All files sent to Sheego" , mtInformation , TMsgDlgButtons() << mbOK , 0 );



	delete PO;

}


void
TDM::CreateCSV()
{
	// creates csv




/*	try
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
*/

//	if ( ! fmSheego->SaveDialog1->Execute() ) {
//		spGetOrderOutput->Close();
//		return;
//	}


	TStringList *csv = new TStringList();
	TStringList *rec = new TStringList();
	TStringList *flds = new TStringList();



	csv->Clear();
	rec->Clear();
	flds->Clear();

	Application->ProcessMessages();
	spGetOrderOutput->GetFieldNames(flds);

	int IDix = flds->IndexOf("ID");

	if ( IDix > -1 ) {
		flds->Delete(IDix);
	}

	Application->ProcessMessages();

	flds->Delimiter = ';';
	rec->Delimiter = ';';
	csv->Add ( flds->DelimitedText );
	int col = 0;

	TStringList *f2 = new TStringList();

	f2->Clear();
	f2->Add("sku");
	f2->Add("Menge");
	f2->Add("WholeSaleNali");

	Application->ProcessMessages();

	if( ! spGetOrderOutput->Eof )
	{
		rec->Clear();
		orderids->Add(IntToStr(spGetOrderOutputID->AsInteger) ) ;

		Application->ProcessMessages();

		col = 0;
		while ( col < flds->Count  )
		{
			if ( f2->IndexOf(flds->Strings[col]) != -1 ) {
				rec->Add ( "" );
			}
			else
			{
			if ( flds->Strings[col] == "ReceiptDateRequested") {
				rec->Add ( spGetOrderOutput->FieldByName(flds->Strings[col])->AsDateTime.FormatString("yyyy-mm-dd") );
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
			Application->ProcessMessages();


			col++;
		}
		csv->Add(rec->DelimitedText );
	}

	while ( ! spGetOrderOutput->Eof )
		{
			rec->Clear();
			orderids->Add(IntToStr(spGetOrderOutputID->AsInteger) ) ;
			Application->ProcessMessages();

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
				Application->ProcessMessages();

			}
			csv->Add(rec->DelimitedText );

			spGetOrderOutput->Next() ;
		}

	spGetOrderOutput->Close();
	delete f2;

	Sleep(2000);  // Note , leave the Sleep in to force filenames to be unique.
	Application->ProcessMessages();

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
	Application->ProcessMessages();

	if ( p  ) {
		p->Label1->Text = "Sending " + fileName + " to FTP Server";
		Application->ProcessMessages();
	}

	Config->setCurrentFile("h:\\shgo\\temp\\" + fileName);
	Config->SentOK = false;

	Application->ProcessMessages();

	fmSheego->actSendFile->Execute() ;


#if 0

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
#endif




}

//---------------------------------------------------------------------------


void
TDM::UpdateOrders()
{
		int oi = 0;
		try
		{
			DB->BeginTrans() ;

			while ( oi < orderids->Count)
				{
					if ( p ) {
						p->Label1->Text = "Updating order " + IntToStr(oi+1) + " as sent ";
						Application->ProcessMessages();
					}

					spUpdateOrderAsSent->Parameters->ParamByName("@OrderID")->Value =
						orderids->Strings[oi];
					spUpdateOrderAsSent->Execute();

					oi++;
				}

			DB->CommitTrans() ;
			orderids->Clear();
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






void __fastcall TDM::spGetConfigAdminAfterScroll(TDataSet *DataSet)
{
	fmSheego->txtConfigID->Caption = IntToStr(spGetConfigAdminConfigID->AsInteger);

	fmSheego->txtConfigServerName->Text = spGetConfigAdminservername->AsString ;
	fmSheego->txtConfigUserName->Text = spGetConfigAdminusername->AsString ;
	fmSheego->txtConfigServerPathIn->Text = spGetConfigAdminserverpathin->AsString ;
	fmSheego->txtConfigServerPathOut->Text = spGetConfigAdminserverpathout->AsString ;

	fmSheego->txtConfigAXAccount->Text = spGetConfigAdminaxcustaccount->AsString ;

}
//---------------------------------------------------------------------------

void __fastcall TDM::spGetResponseHeadersAfterScroll(TDataSet *DataSet)
{
	spGetResponseDetail->DisableControls() ;

	try
	{
		spGetResponseDetail->Active = false;
		spGetResponseDetail->Parameters->ParamByName("@ResponseID")->Value =
			spGetResponseHeadersResponsesID->Value;

		spGetResponseDetail->Active = true;

	}
	catch(Exception &E)
	{

	}

	spGetResponseDetail->EnableControls() ;

}

void
TDM::ExportResponse(UnicodeString savename )
{

	spGetResponseExport->Parameters->ParamByName("@ResponseID")->Value =
		spGetResponseHeadersResponsesID->Value ;

	try
	{
		spGetResponseExport->Active = true;
	}
	catch(Exception &E)
	{
		MessageDlg ("Error during CSV creation\n\n" + E.Message , mtError , TMsgDlgButtons() << mbOK , 0 );
		return;
	}

	if ( spGetResponseExport->Eof ) {
		MessageDlg ( "No outstanding orders" , mtInformation , TMsgDlgButtons() << mbOK , 0 , mbOK );
		spGetResponseExport->Active = false;
		return;
	}

//	if ( ! fmSheego->SaveDialog1->Execute() ) {
//		spGetOrderOutput->Close();
//		return;
//	}


	TStringList *csv = new TStringList();
	TStringList *rec = new TStringList();
	TStringList *flds = new TStringList();

	csv->Clear();
	rec->Clear();
	flds->Clear();

	spGetResponseExport->GetFieldNames(flds);


	flds->Delimiter = ';';
	rec->Delimiter = ';';
	csv->Add ( flds->DelimitedText );
	int col = 0;

	TStringList *f2 = new TStringList();

	f2->Clear();

	while( ! spGetResponseExport->Eof )
	{
		rec->Clear();

		col = 0;
		while ( col < flds->Count  )
		{
			if ( f2->IndexOf(flds->Strings[col]) != -1 ) {
				rec->Add ( "" );
			}
			else
			{
			if ( flds->Strings[col] == "ReceiptDateRequestedxx") {
				rec->Add ( spGetResponseExport->FieldByName(flds->Strings[col])->AsDateTime.FormatString("yyyy-mm-dd") );
			}
			else
			{
				if ( flds->Strings[col] != "ID") {
					switch (spGetResponseExport->FieldByName(flds->Strings[col])->DataType) {
						case ftInteger : {
							rec->Add ( IntToStr(spGetResponseExport->FieldByName(flds->Strings[col])->AsInteger) ) ;
							break;
						}
						case ftDate :
						case ftDateTime :
						{
							rec->Add ( spGetResponseExport->FieldByName(flds->Strings[col])->AsDateTime.FormatString("dd.mm.yyyy") );
							break;
						}
						case ftBoolean :
						{
							if (spGetResponseExport->FieldByName(flds->Strings[col])->AsBoolean == true) {
								rec->Add ( "1");
							}
							else
							{
								rec->Add ("0");
								}
							break;
						}
					default:
						rec->Add ( spGetResponseExport->FieldByName(flds->Strings[col])->Value ) ;
					}

				}
			}
			}

			col++;
		}
		csv->Add(rec->DelimitedText );
		spGetResponseExport->Next();
	}

	spGetResponseExport->Close();
	delete f2;

	try
	{
		if ( FileExists(savename) ) {
			if (MessageDlg ( "File already exists.Overwrite ?" , mtConfirmation , TMsgDlgButtons() << mbYes << mbNo , 0 ) == mrYes ) {
				try
				{
					DeleteFile(savename);
					if ( FileExists(savename) ) {
						MessageDlg ( "Cannot delete file ( it could be in use ) , please choose a different name" ,
							mtWarning , TMsgDlgButtons() << mbOK , 0);
					}
					else
					{
						csv->SaveToFile(savename);
						MessageDlg ( "Saved OK" , mtInformation , TMsgDlgButtons() << mbOK , 0 );
					}
				}
				catch(Exception &E)
				{
					MessageDlg ( "Cannot delete file ( it could be in use ) \n" + E.Message + "\n\nPlease choose a different name" ,
						mtWarning , TMsgDlgButtons() << mbOK , 0);
				}
			}
		}
		else
		{
			csv->SaveToFile(savename);
			MessageDlg ( "Saved OK" , mtInformation , TMsgDlgButtons() << mbOK , 0 );
		}


	}
	catch(Exception &E)
	{
		MessageDlg ( "Error saving CSV file to " + savename + "\n\n" + E.Message
			,mtError
			,TMsgDlgButtons() << mbOK
			, 0 );
	}




	delete csv;
	delete rec;
	delete flds;


}

//---------------------------------------------------------------------------


