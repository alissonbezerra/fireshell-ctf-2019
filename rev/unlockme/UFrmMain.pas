unit UFrmMain;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.Imaging.pngimage,
  Vcl.ExtCtrls, Vcl.Imaging.jpeg;

type
  TFrmMain = class(TForm)
    Image1: TImage;
    K1: TEdit;
    K2: TEdit;
    K3: TEdit;
    K4: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Button1: TButton;
    K5: TEdit;
    Label4: TLabel;
    Image2: TImage;
    procedure K1Change(Sender: TObject);
    procedure K2Change(Sender: TObject);
    procedure K3Change(Sender: TObject);
    procedure K4Change(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
    procedure ShowImg1;
    procedure ShowImg2;
  public
    { Public declarations }
  end;

var
  FrmMain: TFrmMain;

implementation

{$R *.dfm}

procedure TFrmMain.Button1Click(Sender: TObject);
var
  Key: string;
  I: Integer;
  M: TMemoryStream;
  Res: TResourceStream;
  B: Byte;
  Img: TPngImage;
begin
  if Length(K1.Text) <> 5 then
  begin
    K1.SetFocus;
    Beep;
    Exit;
  end;

  if Length(K2.Text) <> 5 then
  begin
    K2.SetFocus;
    Beep;
    Exit;
  end;

  if Length(K3.Text) <> 5 then
  begin
    K3.SetFocus;
    Beep;
    Exit;
  end;

  if Length(K4.Text) <> 5 then
  begin
    K4.SetFocus;
    Beep;
    Exit;
  end;

  if Length(K5.Text) <> 5 then
  begin
    K5.SetFocus;
    Beep;
    Exit;
  end;

  Key := K1.Text + K2.Text + K3.Text + K4.Text + K5.Text;
  M   := TMemoryStream.Create;
  Res := TResourceStream.Create(HInstance, 'Out', RT_RCDATA);
  Img := TPngImage.Create;
  try
    Res.Position := 0;
    M.Position   := 0;
    for I := 0 to Res.Size-1 do
    begin
      Res.Read(B, SizeOf(B));
      B := B xor Ord(Key[I mod Length(Key)+1]);
      M.Write(B, SizeOf(B));
    end;
    M.Position := 0;
    try
      Img.LoadFromStream(M);
      Image2.Picture.Assign(Img);
      ShowImg2;
    except
      ShowImg1;
    end;
  finally
    M.Free;
    Res.Free;
  end;
end;

procedure TFrmMain.K1Change(Sender: TObject);
begin
  if Length(K1.Text) = 5 then
    K2.SetFocus;
end;

procedure TFrmMain.K2Change(Sender: TObject);
begin
  if Length(K2.Text) = 5 then
    K3.SetFocus;
end;

procedure TFrmMain.K3Change(Sender: TObject);
begin
  if Length(K3.Text) = 5 then
    K4.SetFocus;
end;

procedure TFrmMain.K4Change(Sender: TObject);
begin
  if Length(K4.Text) = 5 then
    K5.SetFocus;
end;

procedure TFrmMain.ShowImg1;
begin
  Image1.Visible := True;
  Image2.Visible := False;
end;

procedure TFrmMain.ShowImg2;
begin
  Image2.Visible := True;
  Image1.Visible := False;
end;

end.
