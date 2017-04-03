//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Progress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfmProgress *fmProgress;
//---------------------------------------------------------------------------
__fastcall TfmProgress::TfmProgress(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfmProgress::Timer1Timer(TObject *Sender)
{
	Application->ProcessMessages();

}

void
TfmProgress::setFrame()
{
	Animate1->Tag += 3;

	if ( Animate1->Tag > Animate1->FrameCount - 1 ) {
		Animate1->Tag = 1;
	}
	Animate1->Play(Animate1->Tag , Animate1->Tag + 1 , 1 );

}

//---------------------------------------------------------------------------
