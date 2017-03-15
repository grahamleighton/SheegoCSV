object fmSheego: TfmSheego
  Left = 0
  Top = 0
  Caption = 'Sheego CSV Creator Version : 1 .0'
  ClientHeight = 600
  ClientWidth = 721
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefault
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 14
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 721
    Height = 600
    ActivePage = TabSheet3
    Align = alClient
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Import New'
      OnShow = TabSheet1Show
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 713
        Height = 571
        Align = alClient
        Caption = 'Click on "Open..." to start a new order'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object Panel3: TPanel
          Left = 1
          Top = 471
          Width = 711
          Height = 99
          Align = alBottom
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
          object lblCustomer: TLabel
            Left = 0
            Top = 56
            Width = 5
            Height = 18
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -15
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
          object Label1: TLabel
            Left = 224
            Top = 6
            Width = 155
            Height = 18
            Caption = 'Receipt date Requested'
          end
          object BitBtn3: TBitBtn
            Left = 121
            Top = 6
            Width = 89
            Height = 36
            Action = actCommit
            Caption = 'Commit'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -15
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
          object DateTimePicker1: TDateTimePicker
            Left = 385
            Top = 6
            Width = 128
            Height = 26
            Date = 42801.630592002320000000
            Time = 42801.630592002320000000
            TabOrder = 1
          end
          object BitBtn4: TBitBtn
            Left = 0
            Top = 6
            Width = 97
            Height = 36
            Action = FileOpen1
            Caption = '&Open...'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -15
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
            TabOrder = 2
          end
        end
        object StringGrid1: TStringGrid
          Left = 1
          Top = 1
          Width = 711
          Height = 470
          Align = alClient
          DrawingStyle = gdsGradient
          FixedColor = clSkyBlue
          FixedCols = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Verdana'
          Font.Style = []
          GradientEndColor = clSkyBlue
          Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing, goThumbTracking]
          ParentFont = False
          TabOrder = 1
          Visible = False
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Orders'
      ImageIndex = 2
      OnHide = TabSheet3Hide
      OnShow = TabSheet3Show
      object Splitter1: TSplitter
        Left = 0
        Top = 225
        Width = 713
        Height = 3
        Cursor = crVSplit
        Align = alTop
        ExplicitWidth = 347
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 713
        Height = 225
        Align = alTop
        Caption = 'Panel4'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        object GroupBox1: TGroupBox
          Left = 1
          Top = 1
          Width = 711
          Height = 223
          Align = alClient
          Caption = 'Order Headers'
          TabOrder = 0
          object DBGrid2: TDBGrid
            Left = 2
            Top = 16
            Width = 707
            Height = 144
            Align = alClient
            DataSource = DM.dsspGetOrderHeaders
            FixedColor = clMoneyGreen
            Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
            ReadOnly = True
            TabOrder = 0
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clWindowText
            TitleFont.Height = -12
            TitleFont.Name = 'Verdana'
            TitleFont.Style = []
            Columns = <
              item
                Expanded = False
                FieldName = 'OrderFileHeaderID'
                Visible = False
              end
              item
                Expanded = False
                FieldName = 'ImportDateTime'
                Title.Caption = 'Import Time'
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'SentDate'
                Title.Caption = 'Sent Date'
                Width = 64
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'ResponseDate'
                Title.Caption = 'Response Date'
                Width = 64
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'CustomerID'
                Visible = False
              end
              item
                Expanded = False
                FieldName = 'ReceiptDateRequested'
                Title.Caption = 'Receipt Date Req'#39'd'
                Width = 64
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'CustomerID_1'
                Visible = False
              end
              item
                Expanded = False
                FieldName = 'FirstName'
                Title.Caption = 'First Name'
                Width = 64
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'LastName'
                Title.Caption = 'Last Name'
                Width = 64
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'AccountNo'
                Title.Caption = 'Account No'
                Width = 64
                Visible = True
              end>
          end
          object GroupBox3: TGroupBox
            Left = 2
            Top = 160
            Width = 707
            Height = 61
            Align = alBottom
            Caption = 'Actions'
            TabOrder = 1
            DesignSize = (
              707
              61)
            object Button1: TButton
              Left = 24
              Top = 24
              Width = 75
              Height = 25
              Caption = 'Delete'
              TabOrder = 0
              OnClick = Button1Click
            end
            object Button2: TButton
              Left = 592
              Top = 24
              Width = 99
              Height = 25
              Action = actCreateCSV
              Anchors = [akTop, akRight]
              TabOrder = 1
            end
          end
        end
      end
      object Panel5: TPanel
        Left = 0
        Top = 228
        Width = 713
        Height = 343
        Align = alClient
        Caption = 'Panel5'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Verdana'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        object GroupBox2: TGroupBox
          Left = 1
          Top = 1
          Width = 711
          Height = 341
          Align = alClient
          Caption = 'Order Detail'
          TabOrder = 0
          object DBGrid3: TDBGrid
            Left = 2
            Top = 16
            Width = 707
            Height = 323
            Align = alClient
            DataSource = DM.dsspGetOrderDetail
            Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
            TabOrder = 0
            TitleFont.Charset = DEFAULT_CHARSET
            TitleFont.Color = clWindowText
            TitleFont.Height = -12
            TitleFont.Name = 'Verdana'
            TitleFont.Style = []
            Columns = <
              item
                Expanded = False
                FieldName = 'OrderRecordID'
                Visible = False
              end
              item
                Expanded = False
                FieldName = 'OrderFileHeaderID'
                Visible = False
              end
              item
                Expanded = False
                FieldName = 'MG'
                Width = 40
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'BG'
                Width = 40
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PUBL'
                Width = 60
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'WG'
                Width = 40
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'ITEMNO'
                Width = 100
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'OPT_DESC'
                Width = 120
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'ITEM_NO'
                Width = 100
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PO_NO'
                Width = 80
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'OPT_DESC2'
                Width = 80
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PO_BAL_WO_'
                Width = 55
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PO_BAL_WO_2'
                Width = 55
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PO_BAL_WO_3'
                Width = 55
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'PO_BAL_WO_4'
                Width = 55
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'ORG_PO_U_I'
                Width = 40
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'ITEM_E_TOT'
                Width = 40
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'ITEM_E_SUP'
                Width = 120
                Visible = True
              end
              item
                Expanded = False
                FieldName = 'WholeSaleNali'
                Visible = True
              end>
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Customers'
      ImageIndex = 1
      object Panel1: TPanel
        Left = 0
        Top = 312
        Width = 713
        Height = 259
        Align = alBottom
        TabOrder = 0
        object txtFirstName: TLabeledEdit
          Left = 88
          Top = 24
          Width = 200
          Height = 22
          EditLabel.Width = 57
          EditLabel.Height = 14
          EditLabel.Caption = 'First Name'
          LabelPosition = lpLeft
          ParentShowHint = False
          ShowHint = True
          TabOrder = 0
          OnKeyDown = txtFirstNameKeyDown
        end
        object txtLastName: TLabeledEdit
          Left = 88
          Top = 51
          Width = 200
          Height = 22
          EditLabel.Width = 57
          EditLabel.Height = 14
          EditLabel.Caption = 'Last Name'
          LabelPosition = lpLeft
          TabOrder = 1
          OnKeyDown = txtFirstNameKeyDown
        end
        object btnNewCustomer: TButton
          Left = 8
          Top = 200
          Width = 89
          Height = 25
          Caption = 'New Customer'
          TabOrder = 5
          TabStop = False
          OnClick = btnNewCustomerClick
        end
        object btnCancel: TButton
          Left = 208
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Cancel'
          TabOrder = 4
          OnClick = btnCancelClick
        end
        object btnUpdate: TButton
          Left = 127
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Update'
          TabOrder = 3
          OnClick = btnUpdateClick
        end
        object BitBtn1: TBitBtn
          Left = 320
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Delete'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clRed
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 6
          OnClick = BitBtn1Click
        end
        object BitBtn2: TBitBtn
          Left = 416
          Top = 200
          Width = 75
          Height = 25
          Caption = 'Copy'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clTeal
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          TabOrder = 7
          OnClick = BitBtn2Click
        end
        object txtAccountNo: TLabeledEdit
          Left = 88
          Top = 78
          Width = 200
          Height = 22
          EditLabel.Width = 65
          EditLabel.Height = 14
          EditLabel.Caption = 'Account No'
          LabelPosition = lpLeft
          TabOrder = 2
          OnKeyDown = txtFirstNameKeyDown
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 713
        Height = 312
        Align = alClient
        Caption = 'Panel2'
        TabOrder = 1
        object DBGrid1: TDBGrid
          Left = 1
          Top = 1
          Width = 711
          Height = 310
          Align = alClient
          DataSource = DM.dsspGetCustomers
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Verdana'
          Font.Style = []
          Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgAlwaysShowSelection, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
          ParentFont = False
          TabOrder = 0
          TitleFont.Charset = DEFAULT_CHARSET
          TitleFont.Color = clWindowText
          TitleFont.Height = -12
          TitleFont.Name = 'Tahoma'
          TitleFont.Style = []
          Columns = <
            item
              Expanded = False
              FieldName = 'CustomerID'
              Visible = False
            end
            item
              Expanded = False
              FieldName = 'FirstName'
              Width = 100
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'LastName'
              Width = 100
              Visible = True
            end
            item
              Expanded = False
              FieldName = 'AccountNo'
              Width = 100
              Visible = True
            end>
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Order Files'
      ImageIndex = 3
      object Panel7: TPanel
        Left = 0
        Top = 0
        Width = 713
        Height = 41
        Align = alTop
        Caption = 'Order Files (In)'
        TabOrder = 0
        ExplicitLeft = 136
        ExplicitTop = 104
        ExplicitWidth = 185
        object BitBtn5: TBitBtn
          Left = 16
          Top = 10
          Width = 153
          Height = 25
          Action = actRefreshOrderFiles
          Caption = 'Refresh'
          TabOrder = 0
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 530
        Width = 713
        Height = 41
        Align = alBottom
        Caption = 'Order Files (Out)'
        TabOrder = 1
        ExplicitLeft = 232
        ExplicitTop = 408
        ExplicitWidth = 185
      end
      object Panel9: TPanel
        Left = 0
        Top = 41
        Width = 713
        Height = 489
        Align = alClient
        Caption = 'Panel9'
        TabOrder = 2
        ExplicitLeft = 168
        ExplicitTop = 184
        ExplicitWidth = 185
        ExplicitHeight = 41
        object Splitter2: TSplitter
          Left = 1
          Top = 217
          Width = 711
          Height = 3
          Cursor = crVSplit
          Align = alTop
          ExplicitTop = 1
          ExplicitWidth = 254
        end
        object lvOut: TListView
          Left = 1
          Top = 220
          Width = 711
          Height = 268
          Align = alClient
          Columns = <
            item
              Caption = 'FileName'
              Width = 300
            end
            item
              Caption = 'Size'
              Width = 80
            end
            item
              Caption = 'Modified'
              Width = 180
            end>
          ReadOnly = True
          RowSelect = True
          TabOrder = 0
          ViewStyle = vsReport
          ExplicitTop = 1
          ExplicitHeight = 216
        end
        object lvIn: TListView
          Left = 1
          Top = 1
          Width = 711
          Height = 216
          Align = alTop
          Columns = <
            item
              Caption = 'FileName'
              Width = 300
            end
            item
              Caption = 'Size'
              Width = 80
            end
            item
              Caption = 'Modified'
              Width = 180
            end>
          ReadOnly = True
          RowSelect = True
          TabOrder = 1
          ViewStyle = vsReport
          ExplicitLeft = 2
          ExplicitTop = 9
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 440
    Top = 64
    object File1: TMenuItem
      Caption = 'File'
      object Open1: TMenuItem
        Action = FileOpen1
        ImageIndex = 4
      end
      object Open2: TMenuItem
        Action = FileExit1
      end
      object GetPwd1: TMenuItem
        Action = actGetPwd
      end
    end
    object Orders1: TMenuItem
      Caption = 'Orders'
      object RefreshOrders1: TMenuItem
        Action = actRefreshOrders
        ImageIndex = 10
        ShortCut = 116
      end
      object CreateCSV1: TMenuItem
        Action = actCreateCSV
        ImageIndex = 8
      end
      object SendFile1: TMenuItem
        Action = actSendFile
      end
    end
    object Theme1: TMenuItem
      AutoHotkeys = maManual
      Caption = 'Theme'
      Visible = False
    end
  end
  object ActionList1: TActionList
    Images = ImageList1
    Left = 224
    Top = 56
    object FileOpen1: TFileOpen
      Category = 'File'
      Caption = '&Open...'
      Dialog.Filter = 'DBF Files|*.dbf|CSV Files|*.csv'
      Hint = 'Open|Opens an existing file'
      ImageIndex = 0
      ShortCut = 16463
      OnAccept = FileOpen1Accept
    end
    object FileExit1: TFileExit
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
    end
    object actCreateCSV: TAction
      Category = 'File'
      Caption = 'Create CSV'
      ImageIndex = 6
      OnExecute = actCreateCSVExecute
    end
    object actRefreshOrders: TAction
      Category = 'File'
      Caption = 'Refresh Orders'
      ImageIndex = 8
      OnExecute = actRefreshOrdersExecute
    end
    object actCommit: TAction
      Category = 'File'
      Caption = 'Commit'
      ImageIndex = 1
      OnExecute = actCommitExecute
    end
    object actSendFile: TAction
      Category = 'File'
      Caption = 'Send File'
      OnExecute = actSendFileExecute
    end
    object actGetPwd: TAction
      Category = 'File'
      Caption = 'GetPwd'
      OnExecute = actGetPwdExecute
    end
    object actRefreshOrderFiles: TAction
      Category = 'File'
      Caption = 'Refresh'
      ImageIndex = 10
      OnExecute = actRefreshOrderFilesExecute
    end
  end
  object ImageList1: TImageList
    Left = 296
    Top = 104
    Bitmap = {
      494C01010C0018003C0010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000004000000001002000000000000040
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000808080008080
      8000000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800000000000FFFFFF000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFFFFF008080800080808000808080008080800080808000FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000000000
      00000000000080808000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000080808000FFFFFF00000000000000
      00000000000080808000FFFFFF0000000000FFFFFF00FFFFFF00000000008080
      8000FFFFFF000000000080808000FFFFFF000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00000000000000000000000000000000000000000000000000000000008080
      8000808080008080800000000000000000000000000080808000808080008080
      8000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      00000000000080808000C0C0C0000000000000000000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000080808000FFFFFF00000000000000
      00000000000080808000FFFFFF008080800080808000FFFFFF00000000008080
      8000FFFFFF000000000080808000FFFFFF0000000000000000000000FF000000
      FF000000FF0000000000808080000000000080808000000000000000FF000000
      FF000000FF000000000000000000000000000000000000000000808080008080
      800000000000000000000000000080808000FFFFFF0000000000808080008080
      800080808000FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000080808000C0C0C0000000000000000000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000080808000FFFFFF00000000000000
      00000000000080808000FFFFFF008080800080808000FFFFFF00FFFFFF008080
      8000FFFFFF000000000080808000FFFFFF00000000000000FF000000FF000000
      FF00000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF0000000000000000000000000080808000808080000000
      00000000000000000000808080008080800080808000FFFFFF00000000000000
      00008080800080808000FFFFFF00000000000000000000000000000000000000
      00000000000080808000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C0000000000000000000000000000000000080808000FFFFFF00000000000000
      0000000000008080800080808000808080008080800080808000808080008080
      8000000000000000000080808000FFFFFF00000000000000FF000000FF000000
      0000000000000000000080808000000000008080800000000000000000000000
      00000000FF000000FF0000000000000000000000000080808000808080000000
      0000000000000000000000000000808080000000000000000000000000000000
      00000000000080808000FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080808000FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0080808000FFFFFF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF00000000008080800080808000FFFFFF000000
      000000000000000000000000000000000000FFFFFF0000000000000000000000
      0000000000008080800080808000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080808000FFFFFF00808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      800080808000FFFFFF0080808000FFFFFF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF00000000008080800080808000FFFFFF000000
      000000000000000000000000000080808000FFFFFF00FFFFFF00000000000000
      000000000000000000008080800000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000080808000FFFFFF0080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080808000FFFFFF000000FF000000FF00000000000000
      0000000000000000000080808000000000008080800000000000000000000000
      0000000000000000000000000000000000008080800080808000FFFFFF000000
      00000000000000000000808080008080800080808000FFFFFF00000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000080808000FFFFFF0080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080808000FFFFFF000000FF000000FF00000000000000
      0000000000000000000000008000000000000000800000000000000000000000
      0000000000000000000000000000000000008080800080808000FFFFFF000000
      00000000000000000000808080008080800080808000FFFFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000080808000FFFFFF0080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080808000FFFFFF000000FF000000FF00000000000000
      00000000000000000000000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF00000000008080800080808000FFFFFF00FFFF
      FF000000000000000000808080008080800080808000FFFFFF00808080008080
      8000808080008080800080808000FFFFFF00000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000080808000FFFFFF0080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080808000FFFFFF00000000000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF0000000000000000008080800000000000FFFF
      FF00FFFFFF0000000000808080008080800080808000FFFFFF00000000008080
      8000808080008080800080808000FFFFFF00000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000080808000FFFFFF0080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0080808000FFFFFF00000000000000FF000000FF000000
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000080808000808080000000
      0000FFFFFF00FFFFFF00808080008080800080808000FFFFFF0000000000FFFF
      FF00808080008080800080808000FFFFFF00000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000080808000000000000000000080808000FFFFFF0080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000808080008080800080808000FFFFFF0000000000000000000000FF000000
      FF000000FF0000000000808080000000000080808000000000000000FF000000
      FF000000FF000000FF000000FF00000000000000000000000000808080008080
      800000000000FFFFFF00000000008080800000000000FFFFFF00808080008080
      8000808080008080800080808000FFFFFF00000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000808080000000000080808000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0080808000FFFFFF0080808000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF0000000000000000000000FF00000000000000000000000000000000008080
      8000808080008080800000000000000000000000000080808000808080008080
      8000000000000000000080808000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00000000000000000000000000000000000000000080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800000000000000000000000000000000000000000000000
      0000000000000000FF000000FF000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080008080800080808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000000000000000000000
      000000000000000000000000000000FFFF000000000000000000FFFFFF000000
      00000000000000000000000000000000000080808000FFFFFF00000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00000000000000
      000000000000000000000000000000FFFF0000FFFF0000000000000000000000
      0000000000000000000000FFFF00000000000000000080808000FFFFFF00FFFF
      FF000000000000000000000000008080800080808000FFFFFF00000000000000
      0000000000000000000080808000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF0000FFFF000000
      000000000000000000000000000000FFFF0000FFFF0000000000000000000000
      00000000000000FFFF0000FFFF0000000000000000008080800080808000FFFF
      FF00FFFFFF0000000000000000008080800080808000FFFFFF00000000000000
      0000000000008080800080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000000000FFFF0000FF
      FF0080808000808080008080800000FFFF0000FFFF0080808000808080008080
      800000FFFF0000FFFF0000000000000000000000000000000000808080008080
      8000FFFFFF00FFFFFF00FFFFFF008080800080808000FFFFFF00FFFFFF00FFFF
      FF00808080008080800000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      80008080800000000000000000000000000000000000FFFFFF00808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      80008080800080808000808080000000000080808000FFFFFF0000000000FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000080808000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      000000000000000000000000000000000000000000000000000080808000FFFF
      FF0000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF008080
      8000FFFFFF0000000000000000000000000000000000FFFFFF000000FF00C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000808080000000000080808000FFFFFF00808080000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00000000000000000080808000000000000000000000000000FFFF
      FF000000000000000000FFFFFF00000000000000000000000000FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF0080808000FFFF
      FF00808080008080800000000000808080008080800080808000000000008080
      8000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000808080000000000080808000FFFFFF00000000000000
      0000808080008080800080808000808080008080800080808000808080008080
      80000000000000000000000000008080800000FFFF0000FFFF0000000000FFFF
      FF00FFFFFF00FFFFFF00C0C0C000FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      000000FFFF0000FFFF0000FFFF0000000000808080008080800080808000FFFF
      FF0000000000FFFFFF000000000000000000FFFFFF00FFFFFF00FFFFFF008080
      8000808080008080800080808000FFFFFF0000000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000808080000000000080808000FFFFFF00000000000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000808080000000000000FFFF0000000000FFFF
      FF0000000000C0C0C00080808000000000000000000000000000000000000000
      000000000000000000000000000000FFFF00000000008080800080808000FFFF
      FF008080800000000000FFFFFF00808080008080800080808000808080008080
      80008080800080808000808080008080800000000000FFFFFF00C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000808080000000000080808000FFFFFF00000000000000
      0000808080008080800080808000808080008080800080808000808080008080
      800000000000000000000000000080808000000000000000000000000000C0C0
      C000C0C0C000C0C0C00000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00000000000000000000000000000000000000000080808000FFFF
      FF00000000008080800080808000000000000000000000000000000000000000
      00000000000080808000000000000000000000000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000808080000000000080808000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000080808000000000000000000000000000C0C0
      C0000000000080808000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C0C0
      C000000000000000000000000000000000000000000000000000808080000000
      000080808000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0080808000FFFFFF00000000000000000000000000FFFFFF00C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000808080000000000080808000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF000000000000000000000000000000000000000000000000008080
      8000808080008080800080808000808080008080800080808000808080008080
      800080808000FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000080808000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0080808000000000000000000000FFFF0000FF
      FF0000000000000000000000000000FFFF0000FFFF0000000000000000000000
      000000FFFF0000FFFF0000000000000000000000000000000000808080008080
      80000000000000000000000000008080800080808000FFFFFF00000000000000
      00008080800080808000FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800080808000808080000000000000FFFF0000FFFF000000
      000000000000000000000000000000FFFF0000FFFF0000000000000000000000
      00000000000000FFFF0000FFFF00000000000000000080808000808080000000
      00000000000000000000000000008080800080808000FFFFFF00000000000000
      0000000000008080800080808000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF00000000000000
      000000000000000000000000000000FFFF0000FFFF0000000000000000000000
      0000000000000000000000FFFF00000000000000000080808000000000000000
      0000000000000000000000000000808080008080800000000000000000000000
      0000000000000000000080808000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      000000000000000000000000000000FFFF008080800000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF000000000000000000000000000000000080808000FFFFFF00000000000000
      00000000000000000000FFFFFF00808080000000000000FFFF0000FFFF000000
      000080808000808080008080800000FFFF0000FFFF0080808000808080008080
      80008080800000FFFF0000FFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFFFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000000000008080800080808000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF008080800080808000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00808080008080800000000000000000000000000000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000000000000000000000000000000000000000000000
      0000000000000000FF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000FFFFFF00FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000808080008080800000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000008080800000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000080808000808080008080800080808000FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000FFFFFF000000000000000000000000000000000000000000000000000000
      000080808000FFFFFF0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000008080800000000000000000000000000000000000000000000000
      00000000FF000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000080808000808080008080800080808000FFFFFF00FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
      FF0080808000FFFFFF0000000000000000000000000000000000000000000000
      0000FFFFFF000000000000000000FFFFFF00000000000000000000000000FFFF
      FF00000000008080800000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      80008080800080808000808080008080800080808000FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      8000FFFFFF008080800080808000000000008080800080808000808080000000
      000080808000FFFFFF0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000080808000000000000000000000000000000000000000FF000000
      FF000000FF000000FF000000FF000000FF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      80008080800080808000808080008080800080808000FFFFFF00FFFFFF000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF008080
      8000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
      FF0080808000FFFFFF00FFFFFF00FFFFFF0000FFFF0000FFFF0000FFFF000000
      0000FFFFFF0000000000000000000000000000000000FFFFFF0000000000FFFF
      FF000000000000FFFF0000FFFF000000000000000000808080000000FF000000
      FF0000000000000000000000FF000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000808080000000000080808000808080008080800080808000FFFFFF000000
      0000000000000000000000000000000000008080800080808000808080008080
      8000FFFFFF008080800080808000808080008080800000000000808080000000
      0000808080008080800080808000FFFFFF000000000000FFFF0000FFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000FFFF0000FFFF0000FFFF00808080000000FF00000000000000
      00000000000000000000000000000000FF000000FF0000000000000000000000
      0000000000000000000000000000000000008080800080808000808080000000
      0000000000000000000000000000808080008080800080808000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000080808000808080008080
      8000FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00808080008080800080808000808080000000000000000000000000000000
      0000FFFFFF000000000000000000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000080808000808080008080800080808000FFFF
      FF00000000000000000000000000000000000000000000000000000000008080
      8000FFFFFF008080800080808000000000008080800080808000808080008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF000000FF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000808080008080800080808000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000000000008080
      8000FFFFFF0000000000FFFFFF00FFFFFF0080808000FFFFFF00000000008080
      8000FFFFFF000000000000000000000000000000000000000000000000000000
      0000FFFFFF0000000000C0C0C000FFFFFF0000000000FFFFFF000000000000FF
      FF00000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000FF000000FF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000808080008080
      8000FFFFFF00FFFFFF0000000000000000000000000000000000000000008080
      8000FFFFFF0080808000808080000000000080808000FFFFFF00808080008080
      8000FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000000000FF
      FF0000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080008080
      800080808000FFFFFF00FFFFFF00000000000000000000000000000000008080
      8000FFFFFF00FFFFFF00FFFFFF00FFFFFF008080800080808000000000008080
      800080808000FFFFFF00FFFFFF0000000000000000000000000000FFFF000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      80000000FF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      80008080800080808000FFFFFF00FFFFFF000000000000000000808080008080
      80008080800080808000808080008080800080808000FFFFFF00000000000000
      00008080800080808000FFFFFF00FFFFFF000000000000FFFF0000FFFF000000
      000000000000000000000000000000FFFF0000FFFF0000000000000000000000
      00000000000000FFFF0000FFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000FF000000FF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008080800080808000808080000000000080808000808080000000
      0000000000000000000000000000808080008080800000000000000000000000
      00000000000080808000808080000000000000FFFF0000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      000000000000000000000000000000FFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      000000000000000000000000000080808000424D3E000000000000003E000000
      2800000040000000400000000100010000000000000200000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFC001FFFFFC1F80038002F83FF007
      00013924E00FE38300013824C447CE41000138048C639C310001380C9C739EF8
      000120003FF91F78000100003EF91E3D00010FF03C7F1C3F00010FF03C7F1C20
      00010FF03C410C0000010FF09C61A42000010FF08C71902000010FF0C441CA80
      00014001E00DE38D80038003F83FF83FFF7EDF3EFFFFFFFFBE7D8E3CFFFFFFFF
      9E798639FFFF8000C003C00300000000C007C00700002FFEC00FC90700001806
      C00F82200000300E00010B0000003806800084000000300EC003C9FB00003FFE
      C007D00300003FFEE007E00100000000CE73CE30000000009E799E38FFFFFFFF
      BE7DBE7DFFFFFFFF7EFE7EFEFFFFFFFFFF7EFFFFFFFFCF3C9001FFFFFCFF8001
      C003F9FFF87FC003E003F0FFF07FE7F3E003F0FFF03FE483E003E07FE03FE113
      E003C07FC01F84200001843F841F005080001E3F1E0F8480E007FE1FFE0FE107
      E00FFF1FFF07E427E00FFF8FFF83E103E027FFC7FFC1E021C073FFE3FFE0C030
      9E79FFF8FFF89E797EFEFFFFFFFF7EFE00000000000000000000000000000000
      000000000000}
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'CSV Files|*.csv|All Files|*.*'
    Left = 544
    Top = 88
  end
  object IdFTP1: TIdFTP
    IPVersion = Id_IPv4
    NATKeepAlive.UseKeepAlive = False
    NATKeepAlive.IdleTimeMS = 0
    NATKeepAlive.IntervalMS = 0
    ProxySettings.ProxyType = fpcmNone
    ProxySettings.Port = 0
    OnAfterClientLogin = IdFTP1AfterClientLogin
    Left = 56
    Top = 344
  end
  object IdFTP2: TIdFTP
    IPVersion = Id_IPv4
    NATKeepAlive.UseKeepAlive = False
    NATKeepAlive.IdleTimeMS = 0
    NATKeepAlive.IntervalMS = 0
    ProxySettings.ProxyType = fpcmNone
    ProxySettings.Port = 0
    OnAfterClientLogin = IdFTP2AfterClientLogin
    OnAfterPut = IdFTP2AfterPut
    Left = 144
    Top = 344
  end
end
