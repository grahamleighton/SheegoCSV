//---------------------------------------------------------------------------

#pragma hdrstop

#include <vcl.h>


#include "DBFField.h"
//---------------------------------------------------------------------------

DBFField::DBFField()
{

}




void
DBFField::setField ( UnicodeString FieldName , char FieldType , int Displacement , int Length , int DecimalPlaces )
{
	fFieldName = FieldName;
	fFieldType = FieldType;
	fDisplacement = Displacement;
	fLength = Length;
	fDecimalPlaces = DecimalPlaces;

}


UnicodeString
DBFField::getFieldName()
{
	return fFieldName;
}
char
DBFField::getFieldType()
{
	return fFieldType;
}

int
DBFField::getDisplacement()
{
	return fDisplacement;
}

int
DBFField::getLength()
{
	return fLength;
}

int
DBFField::getDecimalPlaces()
{
	return fDecimalPlaces;
}








#pragma package(smart_init)

