//---------------------------------------------------------------------------

#ifndef DBFParserH
#define DBFParserH
#include "DBFFields.h"
//---------------------------------------------------------------------------

class TDBFParser
{
	private:
		UnicodeString theFile;
		void interpret();
		int RecordLength;
		int RecordsInFile;
		int FirstRecordPosition;
		DBFFields *Fields;
		int RecordCounter;
		TStringList *records;
		TStringList *fieldlist;



	public:
		TDBFParser(UnicodeString FileName );
		~TDBFParser();
		int getFieldCount();
		DBFFields * getFields();
		void rewind();
		void getRecord();
		void getField(int f);
		TStringList * getData();
		TStringList *getFieldList();


};

#endif
