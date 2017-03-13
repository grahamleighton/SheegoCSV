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
	TLargeintField *spGetOrderOutputSalesIdExternal;
	TStringField *spGetOrderOutputCurrencyCode;
	TStringField *spGetOrderOutputCustomerRef;
	TStringField *spGetOrderOutputReceiptDateRequested;
	TStringField *spGetOrderOutputfirstName;
	TStringField *spGetOrderOutputlastName;
	TStringField *spGetOrderOutputsku;
	TStringField *spGetOrderOutputMenge;
	TBooleanField *spGetOrderOutputWholeSaleNali;
	void __fastcall spGetCustomersAfterScroll(TDataSet *DataSet);
	void __fastcall spGetOrderHeadersAfterScroll(TDataSet *DataSet);
	void __fastcall spGetOrderHeadersBeforeClose(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
	__fastcall TDM(TComponent* Owner);
	void CreateCSV();
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
