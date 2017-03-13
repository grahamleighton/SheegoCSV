//---------------------------------------------------------------------------

#pragma hdrstop


#include "DBFFields.h"
//---------------------------------------------------------------------------
DBFFields::DBFFields()
{
	FieldCount = 0;
	FieldCounter = 0;



}


DBFFields::~DBFFields()
{

#if 0
	int i = 0;

	while ( i < FieldCount )
		{   if (F[i] ) {
				delete F[i];

			}
			i++;
		}
#endif
}

void
DBFFields::addField ( UnicodeString FieldName , char FieldType , int Displacement , int Length , int DecimalPlaces )
{
	if ( FieldCount < 100 ) {
		F[FieldCount] = new DBFField();

		F[FieldCount]->setField(FieldName,FieldType,Displacement,Length,DecimalPlaces);
		FieldCount++;
	}
}

int
DBFFields::getFieldCount()
{
	return FieldCount;
}

void
DBFFields::resetCounter()
{
	FieldCounter = 0;
}

DBFField *
DBFFields::getNextField()
{
	if ( FieldCounter < FieldCount  ) {
		FieldCounter++;
		return F[FieldCounter-1];
	}
	else
		return NULL;
}





#pragma package(smart_init)
