//---------------------------------------------------------------------------

#ifndef DBFFieldsH
#define DBFFieldsH
#include "DBFField.h"
//---------------------------------------------------------------------------


class DBFFields
{
	private:

		int FieldCount;
		int FieldCounter;
		DBFField *F[100];

	public:
		DBFFields();
		~DBFFields();
		void addField ( UnicodeString FieldName , char FieldType , int Displacement , int Length , int DecimalPlaces );
		int getFieldCount();

		void resetCounter();

		DBFField * getNextField();




};






#endif
