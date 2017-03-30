//---------------------------------------------------------------------------

#ifndef DataH
#define DataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *DB;
	TADOStoredProc *spGetCustomers;
	TDataSource *dsspGetCustomers;
	TADOCommand *spDeleteCustomer;
	TADOCommand *spUpdateCustomer;
	TADOCommand *spAddCustomer;
	TADOCommand *spAddOrderHeader;
	TADOCommand *spAddOrderLine;
	TADOStoredProc *spGetOrderHeaders;
	TADOStoredProc *spGetOrderDetail;
	TDataSource *dsspGetOrderHeaders;
	TDataSource *dsspGetOrderDetail;
	TLargeintField *spGetOrderDetailOrderRecordID;
	TLargeintField *spGetOrderDetailOrderFileHeaderID;
	TStringField *spGetOrderDetailMG;
	TStringField *spGetOrderDetailBG;
	TStringField *spGetOrderDetailPUBL;
	TStringField *spGetOrderDetailWG;
	TStringField *spGetOrderDetailITEMNO;
	TStringField *spGetOrderDetailOPT_DESC;
	TStringField *spGetOrderDetailITEM_NO;
	TStringField *spGetOrderDetailPO_NO;
	TStringField *spGetOrderDetailOPT_DESC2;
	TStringField *spGetOrderDetailPO_BAL_WO_;
	TStringField *spGetOrderDetailPO_BAL_WO_2;
	TStringField *spGetOrderDetailPO_BAL_WO_3;
	TStringField *spGetOrderDetailPO_BAL_WO_4;
	TStringField *spGetOrderDetailORG_PO_U_I;
	TStringField *spGetOrderDetailITEM_E_TOT;
	TStringField *spGetOrderDetailITEM_E_SUP;
	TADOCommand *spDeleteOrder;
	TADOStoredProc *spGetOrderOutput;
	TADOCommand *spUpdateOrderAsSent;
	TLargeintField *spGetCustomersCustomerID;
	TStringField *spGetCustomersFirstName;
	TStringField *spGetCustomersLastName;
	TStringField *spGetCustomersAccountNo;
	TLargeintField *spGetOrderHeadersOrderFileHeaderID;
	TDateTimeField *spGetOrderHeadersImportDateTime;
	TDateTimeField *spGetOrderHeadersSentDate;
	TDateTimeField *spGetOrderHeadersResponseDate;
	TLargeintField *spGetOrderHeadersCustomerID;
	TWideStringField *spGetOrderHeadersReceiptDateRequested;
	TLargeintField *spGetOrderHeadersCustomerID_1;
	TStringField *spGetOrderHeadersFirstName;
	TStringField *spGetOrderHeadersLastName;
	TStringField *spGetOrderHeadersAccountNo;
	TStringField *spGetOrderOutputCustAccount;
	TStringField *spGetOrderOutputCurrencyCode;
	TStringField *spGetOrderOutputCustomerRef;
	TStringField *spGetOrderOutputReceiptDateRequested;
	TStringField *spGetOrderOutputfirstName;
	TStringField *spGetOrderOutputlastName;
	TStringField *spGetOrderOutputsku;
	TStringField *spGetOrderOutputMenge;
	TIntegerField *spGetOrderOutputWholeSaleNali;
	TBooleanField *spGetOrderDetailWholeSaleNali;
	TStringField *spGetOrderOutputSalesIdExternal;
	TLargeintField *spGetOrderOutputID;
	TBooleanField *spGetCustomersActive;
	TADOStoredProc *spGetConfig;
	TLargeintField *spGetConfigConfigID;
	TStringField *spGetConfigservername;
	TStringField *spGetConfigusername;
	TStringField *spGetConfigserverpathout;
	TStringField *spGetConfigserverpathin;
	TDataSource *dsspGetConfig;
	TADOStoredProc *spUpdateConfig;
	TADOStoredProc *spGetServerPassword;
	TADOStoredProc *spGetConfigAdmin;
	TLargeintField *spGetConfigAdminConfigID;
	TStringField *spGetConfigAdminservername;
	TStringField *spGetConfigAdminusername;
	TStringField *spGetConfigAdminserverpathout;
	TStringField *spGetConfigAdminserverpathin;
	TStringField *spGetConfigAdminaxcustaccount;
	TStringField *spGetConfigaxcustaccount;
	TADOStoredProc *spGetResponseHeaders;
	TADOStoredProc *spGetResponseDetail;
	TDataSource *dsspGetResponseHeaders;
	TDataSource *dsspGetResponseDetail;
	TDateTimeField *spGetResponseHeadersResponseDate;
	TStringField *spGetResponseHeadersFileName;
	TLargeintField *spGetResponseHeadersResponsesID;
	TADOStoredProc *spGetResponseExport;
	TDataSource *DataSource1;
	TADOCommand *cmdDeleteResponse;
	void __fastcall spGetCustomersAfterScroll(TDataSet *DataSet);
	void __fastcall spGetOrderHeadersAfterScroll(TDataSet *DataSet);
	void __fastcall spGetOrderHeadersBeforeClose(TDataSet *DataSet);
	void __fastcall spGetConfigAdminAfterScroll(TDataSet *DataSet);
	void __fastcall spGetResponseHeadersAfterScroll(TDataSet *DataSet);

private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);
	void CreateCSV();
	void ExportResponse(UnicodeString savefile );

	void setFTPDetails();
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
