//---------------------------------------------------------------------------

#include <vcl.h>


#ifndef DBFFieldH

#define DBFFieldH
//---------------------------------------------------------------------------

class DBFField
{

private:
	char fFieldType;
	UnicodeString fFieldName;
	int fDisplacement;
	int fLength;
	int fDecimalPlaces;


public:

	void setField ( UnicodeString FieldName , char FieldType , int Displacement , int Length , int DecimalPlaces );

	UnicodeString getFieldName();
	char getFieldType();
	int getDisplacement();
	int getLength();
	int getDecimalPlaces();




	DBFField();


};

#endif
