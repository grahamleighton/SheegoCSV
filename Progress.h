//---------------------------------------------------------------------------

#ifndef ProgressH
#define ProgressH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfmProgress : public TForm
{
__published:	// IDE-managed Components
	TAnimate *Animate1;
	TPanel *Panel1;
	TTimer *Timer1;
	TEdit *Label1;
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	void setFrame();
public:		// User declarations
	__fastcall TfmProgress(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TfmProgress *fmProgress;
//---------------------------------------------------------------------------
#endif
