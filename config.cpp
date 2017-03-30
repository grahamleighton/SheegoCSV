//---------------------------------------------------------------------------

#pragma hdrstop

#include <vcl.h>

#include "config.h"



GConfig::GConfig()
{
	fUser = "";
	fServer = "";
	fPwd = "";
	fServerFolderIn = "";
	fServerFolderOut = "";

}


void
GConfig::displaySettings()
{
	MessageDlg ( "User : [" + fUser + "]\nPassword : [" + fPwd + "]\nServer [" + fServer + "]\nServer Folder In [" + fServerFolderIn + "]\nServer Folder Out [" + fServerFolderOut + "]"  ,
		mtInformation ,
		TMsgDlgButtons() << mbOK ,
		0 );

}

void
GConfig::setAXAccount(UnicodeString AXAccount )
{
	fAXAccount = AXAccount;
}

UnicodeString
GConfig::getAXAccount()
{
    return fAXAccount;
}

void
GConfig::setUserAndServer(UnicodeString User , UnicodeString Server, UnicodeString ServerFolderIn,UnicodeString ServerFolderOut)
{
	fUser = User;
	fServer = Server;
	fServerFolderIn = ServerFolderIn;
	fServerFolderOut = ServerFolderOut;

}

void
GConfig::setPassword(UnicodeString Pwd )
{
	fPwd = Pwd;
}

void
GConfig::setCurrentFile(UnicodeString CurrentFile )
{
	fCurrentFile = CurrentFile;
}


UnicodeString
GConfig::getCurrentFile()
{
	return fCurrentFile ;
}


UnicodeString
GConfig::getServer()
{
	return fServer;
}

UnicodeString
GConfig::getServerFolderIn()
{
	return fServerFolderIn;
}

UnicodeString
GConfig::getServerFolderOut()
{
	return fServerFolderOut;
}

UnicodeString
GConfig::getPassword()
{
	return fPwd;
}

UnicodeString
GConfig::getUser()
{
	return fUser;
}



//---------------------------------------------------------------------------
#pragma package(smart_init)
