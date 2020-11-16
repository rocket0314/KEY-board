const byte ROWS=5;
const byte COLS=10;
const char* presets[ROWS][COLS]={
  {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"},
  {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"},
  {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"},
  {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"},
  {"00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000","00000000"},
};
const char* keys[ROWS][COLS]={
  {"0xB1","0xD4","0x00","0xD2","0xD5","0xC2","0xC3","0xC4","0xC5","0xC6"},
  {"0xD3","0x67","0x68","0x69","0x6F","0xC7","0xC8","0xC9","0xCA","0xCB"},
  {"0xD6","0x64","0x65","0x66","0x6A","0xCC","0xCD","0xF0","0xF1","0xF2"},
  {"0x00","0x61","0x62","0x63","0x6D","0xF3","0xF4","0xF5","0xF6","0xF7"},
  {"0x00","0x00","0x60","0xB0","0x6B","0xF8","0xF9","0xFA","0xFB","0x5D"},
};

int row1=4;  //4,5,6,7,8,9
int row2=5;
int row3=6;
int row4=7;
int row5=8;
int row6=9;

int col1=10;  //10,13,A0,A1,A2,A3,A4,A5
int col2=13;
int col3=A0;
int col4=A1;
int col5=A2;
int col6=A3;
int col7=A7;
int col8=A6;


//Ctrl,Shift,GUI,Alt
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(row1,OUTPUT);
  pinMode(row2,OUTPUT);
  pinMode(row3,OUTPUT);
  pinMode(row4,OUTPUT);
  pinMode(row5,OUTPUT);
  pinMode(row6,OUTPUT);
  pinMode(col1,INPUT);
  pinMode(col2,INPUT);
  pinMode(col3,INPUT);
  pinMode(col4,INPUT);
  pinMode(col5,INPUT);
  pinMode(col6,INPUT);
  pinMode(col7,INPUT);
  pinMode(col8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(row1,HIGH);
  if(digitalRead(col1)==HIGH){
//    Serial.println(presets[][]);
//    Serial.println(keys[][]);
  }
  if(digitalRead(col2)==HIGH){
    Serial.println(presets[4][9]);
    Serial.println(keys[4][9]);
  }
  if(digitalRead(col3)==HIGH){
    Serial.println(presets[3][9]);
    Serial.println(keys[3][9]);
  }
  if(digitalRead(col4)==HIGH){
    Serial.println(presets[2][9]);
    Serial.println(keys[2][9]);
  }
  if(digitalRead(col5)==HIGH){
    Serial.println(presets[1][9]);
    Serial.println(keys[1][9]);
  }
  if(digitalRead(col6)==HIGH){
    Serial.println(presets[0][9]);
    Serial.println(keys[0][9]);
  }
  if(digitalRead(col7)==HIGH){
    Serial.println(presets[4][8]);
    Serial.println(keys[4][8]);
  }
  if(digitalRead(col8)==HIGH){
    Serial.println(presets[4][7]);
    Serial.println(keys[4][7]);
  }
  digitalWrite(row1,LOW);
  
  digitalWrite(row2,HIGH);
  if(digitalRead(col1)==HIGH){
    Serial.println(presets[3][8]);
    Serial.println(keys[3][8]);
  }
  if(digitalRead(col2)==HIGH){
    Serial.println(presets[2][8]);
    Serial.println(keys[2][8]);
  }
  if(digitalRead(col3)==HIGH){
    Serial.println(presets[1][8]);
    Serial.println(keys[1][8]);
  }
  if(digitalRead(col4)==HIGH){
    Serial.println(presets[0][8]);
    Serial.println(keys[0][8]);
  }
  if(digitalRead(col5)==HIGH){
    Serial.println(presets[3][7]);
    Serial.println(keys[3][7]);
  }
  if(digitalRead(col6)==HIGH){
    Serial.println(presets[2][7]);
    Serial.println(keys[2][7]);
  }
  if(digitalRead(col7)==HIGH){
    Serial.println(presets[1][7]);
    Serial.println(keys[1][7]);
  }
  if(digitalRead(col8)==HIGH){
    Serial.println(presets[0][7]);
    Serial.println(keys[0][7]);
  }
  digitalWrite(row2,LOW);
  
  digitalWrite(row3,HIGH);
  if(digitalRead(col1)==HIGH){
    Serial.println(presets[4][6]);
    Serial.println(keys[4][6]);
  }
  if(digitalRead(col2)==HIGH){
    Serial.println(presets[3][6]);
    Serial.println(keys[3][6]);
  }
  if(digitalRead(col3)==HIGH){
    Serial.println(presets[2][6]);
    Serial.println(keys[2][6]);
  }
  if(digitalRead(col4)==HIGH){
    Serial.println(presets[1][6]);
    Serial.println(keys[1][6]);
  }
  if(digitalRead(col5)==HIGH){
    Serial.println(presets[4][5]);
    Serial.println(keys[4][5]);
  }
  if(digitalRead(col6)==HIGH){
    Serial.println(presets[3][5]);
    Serial.println(keys[3][5]);
  }
  if(digitalRead(col7)==HIGH){
    Serial.println(presets[2][5]);
    Serial.println(keys[2][5]);
  }
  if(digitalRead(col8)==HIGH){
    Serial.println(presets[1][5]);
    Serial.println(keys[1][5]);
  }
  digitalWrite(row3,LOW);

  digitalWrite(row4,HIGH);
  if(digitalRead(col1)==HIGH){
    Serial.println(presets[0][6]);
    Serial.println(keys[0][6]);
  }
  if(digitalRead(col2)==HIGH){
    Serial.println(presets[0][5]);
    Serial.println(keys[0][5]);
  }
  if(digitalRead(col3)==HIGH){
    Serial.println(presets[0][4]);
    Serial.println(keys[0][4]);
  }
  if(digitalRead(col4)==HIGH){
    Serial.println(presets[0][3]);
    Serial.println(keys[0][3]);
  }
  if(digitalRead(col5)==HIGH){
    Serial.println(presets[0][1]);
    Serial.println(keys[0][1]);
  }
  if(digitalRead(col6)==HIGH){
    Serial.println(presets[0][0]);
    Serial.println(keys[0][0]);
  }
  if(digitalRead(col7)==HIGH){
    Serial.println(presets[0][2]);
    Serial.println(keys[0][2]);
  }
  if(digitalRead(col8)==HIGH){
    Serial.println(presets[0][1]);
    Serial.println(keys[0][1]);
  }
  digitalWrite(row4,LOW);
  
  digitalWrite(row5,HIGH);
  if(digitalRead(col1)==HIGH){
    Serial.println(presets[4][3]);
    Serial.println(keys[4][3]);
  }
  if(digitalRead(col2)==HIGH){
    Serial.println(presets[4][3]);
    Serial.println(keys[4][3]);
  }
  if(digitalRead(col3)==HIGH){
    Serial.println(presets[4][2]);
    Serial.println(keys[4][2]);
  }
  if(digitalRead(col4)==HIGH){
    Serial.println(presets[4][1]);
    Serial.println(keys[4][1]);
  }
  if(digitalRead(col5)==HIGH){
    Serial.println(presets[3][4]);
    Serial.println(keys[3][4]);
  }
  if(digitalRead(col6)==HIGH){
    Serial.println(presets[3][3]);
    Serial.println(keys[3][3]);
  }
  if(digitalRead(col7)==HIGH){
    Serial.println(presets[3][2]);
    Serial.println(keys[3][2]);
  }
  if(digitalRead(col8)==HIGH){
    Serial.println(presets[3][1]);
    Serial.println(keys[3][1]);
  }
  digitalWrite(row5,LOW);
  
  digitalWrite(row6,HIGH);
  if(digitalRead(col1)==HIGH){
    Serial.println(presets[2][4]);
    Serial.println(keys[2][4]);
  }
  if(digitalRead(col2)==HIGH){
    Serial.println(presets[2][3]);
    Serial.println(keys[2][3]);
  }
  if(digitalRead(col3)==HIGH){
    Serial.println(presets[2][2]);
    Serial.println(keys[2][2]);
  }
  if(digitalRead(col4)==HIGH){
    Serial.println(presets[2][1]);
    Serial.println(keys[2][1]);
  }
  if(digitalRead(col5)==HIGH){
    Serial.println(presets[1][4]);
    Serial.println(keys[1][4]);
  }
  if(digitalRead(col6)==HIGH){
    Serial.println(presets[1][3]);
    Serial.println(keys[1][3]);
  }
  if(digitalRead(col7)==HIGH){
    Serial.println(presets[1][2]);
    Serial.println(keys[1][2]);
  }
  if(digitalRead(col8)==HIGH){
    Serial.println(presets[1][1]);
    Serial.println(keys[1][1]);
  }
  digitalWrite(row6,LOW);

  delay(75);
}
