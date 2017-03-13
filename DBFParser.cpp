//---------------------------------------------------------------------------

#pragma hdrstop

#include <vcl.h>
#include <stdio.h>
#include <string.h>

#include "DBFParser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



TDBFParser::TDBFParser(UnicodeString FileName)
{
	theFile = FileName;

	records = new TStringList();
	records->Clear();

	fieldlist = new TStringList();
	fieldlist->Clear();

	Fields = new DBFFields();

	interpret();
}

TDBFParser::~TDBFParser()
{

#if 0
	delete Fields;
	delete fieldlist;

	delete records;
#endif
}


void
TDBFParser::interpret()
{

	typedef struct
	{
		char FieldName[11];
		char FieldType;
		int DisplaceMent;
		char FieldLength;
		char DecimalPlaces;
		char FieldFlags;
		int NextValue;
		char IncrementStep;
		char reserved[7];
	} filesubrecord_t;

	typedef struct
	{
		char FileType;
		char LastUpdate[3];
		int  RecordCount;
		short FirstRecordPosition;
		short RecordLength;
		char reserved[16];
		char tableflag;
		char codepagemark;
		char reserved2[2];
//		filesubrecord_t sf;
	} fileheader_t;



	UnicodeString OpenMode = "rb";


	FILE *fp = _wfopen ( theFile.w_str()  , OpenMode.w_str()  );
	fileheader_t header;
	filesubrecord_t subrecord;

	memset ( &header , 0 , sizeof( header ) );

	if ( fp ) {
		fread(&header, sizeof(header) , ( size_t )(1) , fp );
		memset ( &subrecord , 0 , sizeof(filesubrecord_t)  );
		int fc = (header.FirstRecordPosition - 296)/32;
		fread(&subrecord , sizeof(filesubrecord_t) , 1 , fp );
		int flddisp = 0;
		int fi = 0;
		while ( subrecord.FieldName[0] != '\r' && subrecord.FieldName[0]  )
			{
				Fields->addField(subrecord.FieldName,subrecord.FieldType, flddisp  , subrecord.FieldLength , subrecord.DecimalPlaces   );
				fieldlist->Add ( subrecord.FieldName );
				flddisp += subrecord.FieldLength;
				char c = getc(fp);
				if ( c == '\r') {
					subrecord.FieldName[0] = c;
				}
				else
				{
					ungetc(c,fp);
					fread(&subrecord , sizeof(filesubrecord_t),  1 , fp );
				}
				fi++;
 //				subrecord.FieldName[0] = 0;
			}


		RecordLength = header.RecordLength ;
		RecordsInFile = header.RecordCount ;
		FirstRecordPosition = header.FirstRecordPosition ;

		fseek(fp,FirstRecordPosition,SEEK_SET );

		unsigned char *record;
		int rs = RecordLength ;

		record = ( unsigned char *)(malloc(rs+10));

		int rc = 0;



		TStringList *datarec = new TStringList();
		while ( rc < RecordsInFile )
		{
			Fields->resetCounter() ;

			memset ( record , 0 , rs );
			fread( record , rs , 1 , fp );
			rewind();
			DBFField *D;

			D  = Fields->getNextField();
			datarec->Clear();

			while ( D )
			{
				UnicodeString fldName = D->getFieldName() ;
				char FieldType = D->getFieldType() ;
				int FieldLength = D->getLength() ;
				int disp = D->getDisplacement() ;


				if ( FieldType == 'C') {
					char *val = ( char *)(malloc(FieldLength+1));
					memset ( val , 0 , FieldLength );
					memcpy(val , record + disp + 1 , FieldLength );
					val[FieldLength] = 0;
					UnicodeString fldValue = val;
					datarec->Add ( fldValue.Trim()  );
					free(val);
				}

				if ( FieldType == 'N') {
					char *val = ( char *)(malloc(FieldLength+1));
					memset ( val , 0 , FieldLength );
					memcpy(val , record + disp + 1 , FieldLength );
					val[FieldLength] = 0;
					UnicodeString fldValue = val;
					fldValue = fldValue.Trim();
					double v = fldValue.ToDouble();
					datarec->Add ( FloatToStr(v) );
					free(val);

				}

				D = Fields->getNextField();
			}
			records->Add ( datarec->CommaText  );


			rc++;
		}
		delete datarec;

		free(record);
		fclose(fp);

	}

}

int
TDBFParser::getFieldCount()
{
	return Fields->getFieldCount() ;
}

TStringList *
TDBFParser::getData()
{
	return records;
}

TStringList *
TDBFParser::getFieldList()
{
	return fieldlist;
}


DBFFields *
TDBFParser::getFields()
{
	return Fields;
}

void
TDBFParser::rewind()
{
	RecordCounter = 0;
}

void
TDBFParser::getRecord()
{

}

void
TDBFParser::getField(int FieldNum)
{

}



