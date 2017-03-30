//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Data.h"
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdExplicitTLSClientServerBase.hpp>
#include <IdFTP.hpp>
#include <IdGlobal.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Data.DB.hpp>
#include "config.h"
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <Vcl.Bind.DBEngExt.hpp>
#include <Vcl.Bind.Editors.hpp>
//---------------------------------------------------------------------------
class TfmSheego : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList1;
	TFileOpen *FileOpen1;
	TFileExit *FileExit1;
	TPageControl *PageControl1;
	TTabSheet *tabImport;
	TTabSheet *tabCustomers;
	TPanel *Panel1;
	TPanel *Panel2;
	TDBGrid *DBGrid1;
	TLabeledEdit *txtFirstName;
	TLabeledEdit *txtLastName;
	TButton *btnNewCustomer;
	TButton *btnCancel;
	TButton *btnUpdate;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TStringGrid *StringGrid1;
	TPanel *Panel3;
	TBitBtn *BitBtn3;
	TLabel *lblCustomer;
	TTabSheet *tabOrders;
	TPanel *Panel4;
	TPanel *Panel5;
	TGroupBox *GroupBox1;
	TGroupBox *GroupBox2;
	TDBGrid *DBGrid2;
	TDBGrid *DBGrid3;
	TGroupBox *GroupBox3;
	TButton *Button1;
	TSplitter *Splitter1;
	TAction *actCreateCSV;
	TButton *Button2;
	TAction *actRefreshOrders;
	TImageList *ImageList1;
	TSaveDialog *SaveDialog1;
	TLabeledEdit *txtAccountNo;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label1;
	TBitBtn *BitBtn4;
	TAction *actCommit;
	TPanel *Panel6;
	TAction *actSendFile;
	TIdFTP *IdFTP1;
	TTabSheet *tabOrderFiles;
	TAction *actGetPwd;
	TPanel *Panel7;
	TPanel *Panel8;
	TPanel *Panel9;
	TSplitter *Splitter2;
	TBitBtn *BitBtn5;
	TAction *actRefreshOrderFiles;
	TListView *lvOut;
	TListView *lvIn;
	TIdFTP *IdFTP2;
	TComboBox *cmbActive;
	TLabel *Label2;
	TTabSheet *tabInstruct;
	TPanel *Panel10;
	TRichEdit *RichEdit1;
	TButton *Button3;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	TLabel *Label3;
	TTabSheet *tabConfig;
	TLabel *txtConfigID;
	TDBGrid *DBGrid4;
	TLabeledEdit *txtConfigServerName;
	TLabeledEdit *txtConfigServerPathIn;
	TLabeledEdit *txtConfigUserName;
	TLabeledEdit *txtConfigServerPathOut;
	TButton *Button4;
	TLabeledEdit *txtConfigAXAccount;
	TMenuItem *GetPwd1;
	TTabSheet *TabSheet1;
	TPanel *Panel11;
	TPanel *Panel12;
	TDBGrid *DBGrid5;
	TPanel *Panel13;
	TPanel *Panel14;
	TDBGrid *DBGrid6;
	TSplitter *Splitter3;
	TAction *actExportResponse;
	TButton *Button5;
	TButton *cmdDeleteResponse;
	TAction *actDeleteResponse;
	TAction *actResponseRefresh;
	TButton *Button7;
	TStatusBar *StatusBar1;
	void __fastcall FileOpen1Accept(TObject *Sender);
	void __fastcall tabImportShow(TObject *Sender);
	void __fastcall btnNewCustomerClick(TObject *Sender);
	void __fastcall txtFirstNameKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btnUpdateClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall tabOrdersShow(TObject *Sender);
	void __fastcall tabOrdersHide(TObject *Sender);
	void __fastcall actCreateCSVExecute(TObject *Sender);
	void __fastcall actRefreshOrdersExecute(TObject *Sender);
	void __fastcall Auric1Click(TObject *Sender);
	void __fastcall actCommitExecute(TObject *Sender);
	void __fastcall actSendFileExecute(TObject *Sender);
	void __fastcall IdFTP1AfterClientLogin(TObject *Sender);
	void __fastcall actGetPwdExecute(TObject *Sender);
	void __fastcall actRefreshOrderFilesExecute(TObject *Sender);
	void __fastcall IdFTP2AfterClientLogin(TObject *Sender);
	void __fastcall IdFTP2AfterPut(TObject *Sender);
	void __fastcall cmbActiveChange(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall tabConfigShow(TObject *Sender);
	void __fastcall TabSheet1Show(TObject *Sender);
	void __fastcall actExportResponseExecute(TObject *Sender);
	void __fastcall actDeleteResponseExecute(TObject *Sender);
	void __fastcall actResponseRefreshExecute(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfmSheego(TComponent* Owner);
	void RefreshCustomers();
	void LoadDBFFile();
	void LoadCSVFile(UnicodeString CSVFile);
	void RefreshOrders();

};
//---------------------------------------------------------------------------
extern PACKAGE TfmSheego *fmSheego;
//---------------------------------------------------------------------------
#endif
