//---------------------------------------------------------------------------

#ifndef configH
#define configH
//---------------------------------------------------------------------------



class GConfig
{
	private:
		UnicodeString fUser;
		UnicodeString fPwd;
		UnicodeString fServer;
		UnicodeString fServerFolderIn;
		UnicodeString fServerFolderOut;
		UnicodeString fCurrentFile;
		UnicodeString fAXAccount;
	public:
		bool SentOK;
		GConfig();
		void setUserAndServer(UnicodeString User , UnicodeString Server, UnicodeString ServerFolderIn,UnicodeString ServerFolderOut);
		UnicodeString getUser();
		UnicodeString getServer();
		UnicodeString getPassword();
		UnicodeString getServerFolderIn();
		UnicodeString getServerFolderOut();
		void setPassword(UnicodeString pwd);
		void displaySettings();
		void setCurrentFile(UnicodeString CurrentFile);
		UnicodeString getCurrentFile();

		UnicodeString getAXAccount();
		void setAXAccount(UnicodeString AXAccount);

};

#endif
