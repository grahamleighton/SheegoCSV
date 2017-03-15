object DM: TDM
  OldCreateOrder = False
  Height = 314
  Width = 682
  object DB: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=Sheego;Data Source=fgh-sql02'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 64
    Top = 40
  end
  object spGetCustomers: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    LockType = ltReadOnly
    AfterScroll = spGetCustomersAfterScroll
    ProcedureName = 'getCustomers;1'
    Parameters = <>
    Left = 168
    Top = 40
    object spGetCustomersCustomerID: TLargeintField
      FieldName = 'CustomerID'
      ReadOnly = True
    end
    object spGetCustomersFirstName: TStringField
      FieldName = 'FirstName'
      Size = 50
    end
    object spGetCustomersLastName: TStringField
      FieldName = 'LastName'
      Size = 50
    end
    object spGetCustomersAccountNo: TStringField
      FieldName = 'AccountNo'
      Size = 50
    end
  end
  object dsspGetCustomers: TDataSource
    DataSet = spGetCustomers
    Left = 168
    Top = 104
  end
  object spDeleteCustomer: TADOCommand
    CommandText = 'deleteCustomer;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@CustomerID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = 0
      end>
    Left = 352
    Top = 40
  end
  object spUpdateCustomer: TADOCommand
    CommandText = 'updateCustomer;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@CustomerID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@FirstName'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@LastName'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@AccountNo'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end>
    Left = 460
    Top = 40
  end
  object spAddCustomer: TADOCommand
    CommandText = 'addCustomer;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@FirstName'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@LastName'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@AccountNo'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@CustomerID'
        Attributes = [paNullable]
        DataType = ftInteger
        Direction = pdInputOutput
        Precision = 10
        Value = Null
      end>
    ParamCheck = False
    Left = 256
    Top = 40
  end
  object spAddOrderHeader: TADOCommand
    CommandText = 'addOrderHeader;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@CustomerID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@ReceiptDate'
        Attributes = [paNullable]
        DataType = ftWideString
        Size = 10
        Value = Null
      end
      item
        Name = '@CreateID'
        Attributes = [paNullable]
        DataType = ftInteger
        Direction = pdInputOutput
        Precision = 10
        Value = Null
      end>
    ParamCheck = False
    Left = 352
    Top = 104
  end
  object spAddOrderLine: TADOCommand
    CommandText = 'addOrderLine;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@OrderFileHeaderID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end
      item
        Name = '@MG'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@BG'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PUBL'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@WG'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@ITEMNO'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@OPT_DESC'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@ITEM_NO'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PO_NO'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@OPT_DESC2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PO_BAL_WO_'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PO_BAL_WO_2'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PO_BAL_WO_3'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@PO_BAL_WO_4'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@ORG_PO_U_I'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@ITEM_E_TOT'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@ITEM_E_SUP'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@WHOLESALE_NALI'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end>
    ParamCheck = False
    Left = 456
    Top = 104
  end
  object spGetOrderHeaders: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    BeforeClose = spGetOrderHeadersBeforeClose
    AfterScroll = spGetOrderHeadersAfterScroll
    ProcedureName = 'getOrderHeaders;1'
    Parameters = <>
    Left = 72
    Top = 176
    object spGetOrderHeadersOrderFileHeaderID: TLargeintField
      FieldName = 'OrderFileHeaderID'
      ReadOnly = True
    end
    object spGetOrderHeadersImportDateTime: TDateTimeField
      FieldName = 'ImportDateTime'
    end
    object spGetOrderHeadersSentDate: TDateTimeField
      FieldName = 'SentDate'
    end
    object spGetOrderHeadersResponseDate: TDateTimeField
      FieldName = 'ResponseDate'
    end
    object spGetOrderHeadersCustomerID: TLargeintField
      FieldName = 'CustomerID'
    end
    object spGetOrderHeadersReceiptDateRequested: TWideStringField
      FieldName = 'ReceiptDateRequested'
      Size = 10
    end
    object spGetOrderHeadersCustomerID_1: TLargeintField
      FieldName = 'CustomerID_1'
      ReadOnly = True
    end
    object spGetOrderHeadersFirstName: TStringField
      FieldName = 'FirstName'
      Size = 50
    end
    object spGetOrderHeadersLastName: TStringField
      FieldName = 'LastName'
      Size = 50
    end
    object spGetOrderHeadersAccountNo: TStringField
      FieldName = 'AccountNo'
      Size = 50
    end
  end
  object spGetOrderDetail: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    DataSource = dsspGetOrderHeaders
    ProcedureName = 'getOrderDetail;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@OrderHeaderID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end>
    Left = 72
    Top = 240
    object spGetOrderDetailOrderRecordID: TLargeintField
      FieldName = 'OrderRecordID'
      ReadOnly = True
    end
    object spGetOrderDetailOrderFileHeaderID: TLargeintField
      FieldName = 'OrderFileHeaderID'
    end
    object spGetOrderDetailMG: TStringField
      FieldName = 'MG'
      Size = 50
    end
    object spGetOrderDetailBG: TStringField
      FieldName = 'BG'
      Size = 50
    end
    object spGetOrderDetailPUBL: TStringField
      FieldName = 'PUBL'
      Size = 50
    end
    object spGetOrderDetailWG: TStringField
      FieldName = 'WG'
      Size = 50
    end
    object spGetOrderDetailITEMNO: TStringField
      FieldName = 'ITEMNO'
      Size = 50
    end
    object spGetOrderDetailOPT_DESC: TStringField
      FieldName = 'OPT_DESC'
      Size = 50
    end
    object spGetOrderDetailITEM_NO: TStringField
      FieldName = 'ITEM_NO'
      Size = 50
    end
    object spGetOrderDetailPO_NO: TStringField
      FieldName = 'PO_NO'
      Size = 50
    end
    object spGetOrderDetailOPT_DESC2: TStringField
      FieldName = 'OPT_DESC2'
      Size = 50
    end
    object spGetOrderDetailPO_BAL_WO_: TStringField
      FieldName = 'PO_BAL_WO_'
      Size = 50
    end
    object spGetOrderDetailPO_BAL_WO_2: TStringField
      FieldName = 'PO_BAL_WO_2'
      Size = 50
    end
    object spGetOrderDetailPO_BAL_WO_3: TStringField
      FieldName = 'PO_BAL_WO_3'
      Size = 50
    end
    object spGetOrderDetailPO_BAL_WO_4: TStringField
      FieldName = 'PO_BAL_WO_4'
      Size = 50
    end
    object spGetOrderDetailORG_PO_U_I: TStringField
      FieldName = 'ORG_PO_U_I'
      Size = 50
    end
    object spGetOrderDetailITEM_E_TOT: TStringField
      FieldName = 'ITEM_E_TOT'
      Size = 50
    end
    object spGetOrderDetailITEM_E_SUP: TStringField
      FieldName = 'ITEM_E_SUP'
      Size = 50
    end
    object spGetOrderDetailWholeSaleNali: TBooleanField
      FieldName = 'WholeSaleNali'
      DisplayValues = '1;0'
    end
  end
  object dsspGetOrderHeaders: TDataSource
    DataSet = spGetOrderHeaders
    Left = 184
    Top = 176
  end
  object dsspGetOrderDetail: TDataSource
    DataSet = spGetOrderDetail
    Left = 184
    Top = 240
  end
  object spDeleteOrder: TADOCommand
    CommandText = 'deleteOrder;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@OrderID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end>
    Left = 344
    Top = 176
  end
  object spGetOrderOutput: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    ProcedureName = 'getOutstandingOrderOutput;1'
    Parameters = <>
    Left = 448
    Top = 176
    object spGetOrderOutputCustAccount: TStringField
      FieldName = 'CustAccount'
      ReadOnly = True
      Size = 8
    end
    object spGetOrderOutputSalesIdExternal: TStringField
      FieldName = 'SalesIdExternal'
      Size = 50
    end
    object spGetOrderOutputCurrencyCode: TStringField
      FieldName = 'CurrencyCode'
      ReadOnly = True
      Size = 3
    end
    object spGetOrderOutputCustomerRef: TStringField
      FieldName = 'CustomerRef'
      Size = 50
    end
    object spGetOrderOutputReceiptDateRequested: TStringField
      FieldName = 'ReceiptDateRequested'
      ReadOnly = True
      FixedChar = True
      Size = 10
    end
    object spGetOrderOutputfirstName: TStringField
      FieldName = 'firstName'
      Size = 50
    end
    object spGetOrderOutputlastName: TStringField
      FieldName = 'lastName'
      Size = 50
    end
    object spGetOrderOutputsku: TStringField
      FieldName = 'sku'
      Size = 50
    end
    object spGetOrderOutputMenge: TStringField
      FieldName = 'Menge'
      Size = 50
    end
    object spGetOrderOutputWholeSaleNali: TIntegerField
      FieldName = 'WholeSaleNali'
      ReadOnly = True
    end
    object spGetOrderOutputID: TLargeintField
      FieldName = 'ID'
    end
  end
  object spUpdateOrderAsSent: TADOCommand
    CommandText = 'updateOrderAsSent;1'
    CommandType = cmdStoredProc
    Connection = DB
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@OrderID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end>
    ParamCheck = False
    Left = 344
    Top = 240
  end
  object ADOTable1: TADOTable
    Connection = DB
    TableName = 'viewOrderOutstanding'
    Left = 440
    Top = 240
  end
  object DBAMAINT: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=dbamaint;Data Source=fgh-sql02;Use Proc' +
      'edure for Prepare=1;Auto Translate=True;Packet Size=4096;Worksta' +
      'tion ID=VDIW81PERS-7;Use Encryption for Data=False;Tag with colu' +
      'mn collation when possible=False'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 568
    Top = 40
  end
  object qryFTPPassword: TADOQuery
    Connection = DBAMAINT
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'server'
        DataType = ftWideString
        Size = 10
        Value = 'ottoukfp'
      end
      item
        Name = 'user'
        DataType = ftWideString
        Size = 14
        Value = 'ottouk\ftnwcon'
      end>
    SQL.Strings = (
      'select  dbo.fx_decrypt_pw(:server,:user) pwd')
    Left = 568
    Top = 104
    object qryFTPPasswordpwd: TStringField
      FieldName = 'pwd'
      ReadOnly = True
      Size = 50
    end
  end
  object tblConfig: TADOTable
    Connection = DB
    CursorType = ctStatic
    TableName = 'Config'
    Left = 568
    Top = 176
    object tblConfigConfigID: TLargeintField
      FieldName = 'ConfigID'
      ReadOnly = True
    end
    object tblConfigservername: TStringField
      FieldName = 'servername'
      Size = 50
    end
    object tblConfigusername: TStringField
      FieldName = 'username'
      Size = 50
    end
    object tblConfigserverpathout: TStringField
      FieldName = 'serverpathout'
      Size = 150
    end
    object tblConfigserverpathin: TStringField
      FieldName = 'serverpathin'
      Size = 150
    end
  end
end
