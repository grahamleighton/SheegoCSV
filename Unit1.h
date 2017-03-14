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
//---------------------------------------------------------------------------
class TfmSheego : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TActionList *ActionList1;
	TFileOpen *FileOpen1;
	TFileExit *FileExit1;
	TMenuItem *Open1;
	TMenuItem *Open2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
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
	TTabSheet *TabSheet3;
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
	TMenuItem *Orders1;
	TMenuItem *RefreshOrders1;
	TMenuItem *CreateCSV1;
	TImageList *ImageList1;
	TSaveDialog *SaveDialog1;
	TLabeledEdit *txtAccountNo;
	TDateTimePicker *DateTimePicker1;
	TLabel *Label1;
	TMenuItem *Theme1;
	TBitBtn *BitBtn4;
	TAction *actCommit;
	TPanel *Panel6;
	void __fastcall FileOpen1Accept(TObject *Sender);
	void __fastcall TabSheet1Show(TObject *Sender);
	void __fastcall btnNewCustomerClick(TObject *Sender);
	void __fastcall txtFirstNameKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btnUpdateClick(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall TabSheet3Show(TObject *Sender);
	void __fastcall TabSheet3Hide(TObject *Sender);
	void __fastcall actCreateCSVExecute(TObject *Sender);
	void __fastcall actRefreshOrdersExecute(TObject *Sender);
	void __fastcall Auric1Click(TObject *Sender);
	void __fastcall actCommitExecute(TObject *Sender);

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
