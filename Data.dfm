object DM: TDM
  OldCreateOrder = False
  Height = 628
  Width = 682
  object DB: TADOConnection
    ConnectionString = 
      'Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security In' +
      'fo=False;Initial Catalog=Sheego;Data Source=fgh-sql01;Use Proced' +
      'ure for Prepare=1;Auto Translate=True;Packet Size=4096;Applicati' +
      'on Name=SheegoCSV;Workstation ID=VDIW81PERS-7;Use Encryption for' +
      ' Data=False;Tag with column collation when possible=False'
    LoginPrompt = False
    Provider = 'SQLOLEDB.1'
    Left = 24
    Top = 24
  end
  object spGetCustomers: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    LockType = ltReadOnly
    AfterScroll = spGetCustomersAfterScroll
    ProcedureName = 'getCustomers;1'
    Parameters = <>
    Left = 56
    Top = 88
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
    object spGetCustomersActive: TBooleanField
      FieldName = 'Active'
      DisplayValues = 'Yes;No'
    end
  end
  object dsspGetCustomers: TDataSource
    DataSet = spGetCustomers
    Left = 168
    Top = 88
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
    Left = 496
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
        Name = '@Active'
        Attributes = [paNullable]
        DataType = ftBoolean
        Value = Null
      end>
    Left = 388
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
        Name = '@Active'
        Attributes = [paNullable]
        DataType = ftBoolean
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
    Left = 288
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
    Left = 288
    Top = 112
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
    Left = 392
    Top = 112
  end
  object spGetOrderHeaders: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    BeforeClose = spGetOrderHeadersBeforeClose
    AfterScroll = spGetOrderHeadersAfterScroll
    ProcedureName = 'getOrderHeaders;1'
    Parameters = <>
    Left = 56
    Top = 144
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
    Left = 56
    Top = 200
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
    object spGetOrderDetailAmountConfirmed: TIntegerField
      FieldName = 'AmountConfirmed'
    end
    object spGetOrderDetailDateConfirmed: TDateTimeField
      FieldName = 'DateConfirmed'
    end
  end
  object dsspGetOrderHeaders: TDataSource
    DataSet = spGetOrderHeaders
    Left = 168
    Top = 144
  end
  object dsspGetOrderDetail: TDataSource
    DataSet = spGetOrderDetail
    Left = 168
    Top = 200
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
    Left = 496
    Top = 112
  end
  object spGetOrderOutput: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    ProcedureName = 'getOutstandingOrderOutput;1'
    Parameters = <>
    Left = 280
    Top = 232
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
    Left = 584
    Top = 112
  end
  object spGetConfig: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    ProcedureName = 'getConfig;1'
    Parameters = <>
    Left = 56
    Top = 256
    object spGetConfigConfigID: TLargeintField
      FieldName = 'ConfigID'
      ReadOnly = True
    end
    object spGetConfigservername: TStringField
      FieldName = 'servername'
      Size = 50
    end
    object spGetConfigusername: TStringField
      FieldName = 'username'
      Size = 50
    end
    object spGetConfigserverpathout: TStringField
      FieldName = 'serverpathout'
      Size = 150
    end
    object spGetConfigserverpathin: TStringField
      FieldName = 'serverpathin'
      Size = 150
    end
    object spGetConfigaxcustaccount: TStringField
      FieldName = 'axcustaccount'
      Size = 50
    end
  end
  object dsspGetConfig: TDataSource
    DataSet = spGetConfigAdmin
    Left = 168
    Top = 256
  end
  object spUpdateConfig: TADOStoredProc
    Connection = DB
    ProcedureName = 'updateConfig;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@servername'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@username'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@serverpathout'
        Attributes = [paNullable]
        DataType = ftString
        Size = 150
        Value = Null
      end
      item
        Name = '@serverpathin'
        Attributes = [paNullable]
        DataType = ftString
        Size = 150
        Value = Null
      end
      item
        Name = '@AXAccount'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@ConfigID'
        Attributes = [paNullable]
        DataType = ftInteger
        Direction = pdInputOutput
        Precision = 10
        Value = Null
      end>
    Left = 480
    Top = 200
  end
  object spGetServerPassword: TADOStoredProc
    Connection = DB
    ProcedureName = 'getServerPwd;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = Null
      end
      item
        Name = '@username'
        Attributes = [paNullable]
        DataType = ftString
        Size = 50
        Value = Null
      end
      item
        Name = '@pwd'
        Attributes = [paNullable]
        DataType = ftString
        Direction = pdInputOutput
        Size = 50
        Value = Null
      end>
    Left = 376
    Top = 200
  end
  object spGetConfigAdmin: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    AfterScroll = spGetConfigAdminAfterScroll
    ProcedureName = 'getConfigAdmin;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end>
    Left = 576
    Top = 200
    object spGetConfigAdminConfigID: TLargeintField
      FieldName = 'ConfigID'
      ReadOnly = True
    end
    object spGetConfigAdminservername: TStringField
      FieldName = 'servername'
      Size = 50
    end
    object spGetConfigAdminusername: TStringField
      FieldName = 'username'
      Size = 50
    end
    object spGetConfigAdminserverpathout: TStringField
      FieldName = 'serverpathout'
      Size = 150
    end
    object spGetConfigAdminserverpathin: TStringField
      FieldName = 'serverpathin'
      Size = 150
    end
    object spGetConfigAdminaxcustaccount: TStringField
      FieldName = 'axcustaccount'
      Size = 50
    end
  end
  object spGetResponseHeaders: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    AfterScroll = spGetResponseHeadersAfterScroll
    ProcedureName = 'getResponseHeaders;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end>
    Left = 56
    Top = 376
    object spGetResponseHeadersResponseDate: TDateTimeField
      FieldName = 'ResponseDate'
    end
    object spGetResponseHeadersFileName: TStringField
      FieldName = 'FileName'
      Size = 250
    end
    object spGetResponseHeadersResponsesID: TLargeintField
      FieldName = 'ResponsesID'
      ReadOnly = True
    end
  end
  object spGetResponseDetail: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    ProcedureName = 'getResponseDetail;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@ResponseID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = 1
      end>
    Left = 56
    Top = 440
  end
  object dsspGetResponseHeaders: TDataSource
    AutoEdit = False
    DataSet = spGetResponseHeaders
    Left = 200
    Top = 376
  end
  object dsspGetResponseDetail: TDataSource
    AutoEdit = False
    DataSet = spGetResponseDetail
    Left = 168
    Top = 440
  end
  object spGetResponseExport: TADOStoredProc
    Connection = DB
    CursorType = ctStatic
    ProcedureName = 'getResponseExport;1'
    Parameters = <
      item
        Name = '@RETURN_VALUE'
        DataType = ftInteger
        Direction = pdReturnValue
        Precision = 10
        Value = 0
      end
      item
        Name = '@ResponseID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = 11
      end>
    Left = 56
    Top = 504
  end
  object DataSource1: TDataSource
    DataSet = spGetResponseExport
    Left = 168
    Top = 504
  end
  object cmdDeleteResponse: TADOCommand
    CommandText = 'deleteResponse;1'
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
        Name = '@ResponseID'
        Attributes = [paNullable]
        DataType = ftInteger
        Precision = 10
        Value = Null
      end>
    Left = 336
    Top = 504
  end
  object dsspGetSKUStock: TDataSource
    DataSet = spGetSKUStock
    Left = 168
    Top = 312
  end
  object spGetSKUStock: TADODataSet
    Connection = DB
    CursorType = ctStatic
    CommandText = 'getSKUStock2;1'
    CommandType = cmdStoredProc
    Parameters = <>
    Left = 56
    Top = 312
    object spGetSKUStockItemNo: TStringField
      FieldName = 'ItemNo'
      ReadOnly = True
      Size = 6
    end
    object spGetSKUStockSizeCode: TStringField
      FieldName = 'SizeCode'
      ReadOnly = True
      Size = 6
    end
    object spGetSKUStockUKSize: TStringField
      FieldName = 'UKSize'
      ReadOnly = True
    end
    object spGetSKUStockColour: TStringField
      FieldName = 'Colour'
      ReadOnly = True
      Size = 9
    end
    object spGetSKUStockColourName: TStringField
      FieldName = 'ColourName'
      ReadOnly = True
      Size = 80
    end
    object spGetSKUStockAvailabilitySKU: TIntegerField
      FieldName = 'AvailabilitySKU'
    end
    object spGetSKUStockInventQtyAvailPhysical: TIntegerField
      FieldName = 'InventQtyAvailPhysical'
    end
    object spGetSKUStockSKUId: TStringField
      FieldName = 'SKUId'
      Size = 50
    end
    object spGetSKUStockUKItem: TStringField
      FieldName = 'UKItem'
      ReadOnly = True
      Size = 10
    end
  end
end
