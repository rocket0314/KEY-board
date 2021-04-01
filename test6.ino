#include <Keyboard.h>



int row1 =2;
int row2 =3;
int row3 =4;
int row4 =5;
int row5=6;
int row6=7;
int row7=8;
int row8=9;

int col1=10;
int col2=11;
int col3=12;
int col4=13;
int col5=A0;
int col6=A1;
int col7=A2;
int col8=A3;
char CharCurrent=0x00;
char CharPast=0x00;
char CharPast2=0x00;


const byte COLS=15;
const byte ROWS=5;
char keys[ROWS][COLS] = {
  {0xB1,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x30,0x2D,0x3D,0xB2,0xD4},
  {0xB3,0x71,0x77,0x65,0x72,0x74,0x79,0x75,0x69,0x6F,0x70,0x5B,0x5D,0x5C,0x7E},
  {0xC1,0x61,0x73,0x64,0x66,0x67,0x68,0x6A,0x6B,0x6C,0x3B,0x27,0xB0,0x00,0xD1},
  {0x81,0x7A,0x78,0x63,0x76,0x62,0x6E,0x6D,0x2C,0x2E,0x2F,0x85,0x00,0xDA,0x00},
  {0x80,0x83,0x82,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x86,0x84,0xD8,0xD9,0xD7}
};
/*
byte rowPins[ROWS]={2,3,4,5,6,7,8,9};
byte colPins[COLS]={10,11,12,13,14,15,16,17};
*/

int count;
int nothing=0;
int State=0;
int hex=0;
int CAStatus=0;  //caps lock
int IStatus=0;   //insert
int ShiftStatus=0;

void type(int ROW,int COL){
  CharCurrent=keys[ROW][COL];
  if(CharCurrent==CharPast&&CharCurrent==keys[1][14]){
    delay(10);
  }
  else if(CharCurrent==CharPast&&count>=10){
    Keyboard.write(keys[ROW][COL]);
    delay(10);
  }
  else if(CharCurrent==CharPast||CharCurrent==CharPast2&&count==0){
    count++;
    delay(25);
  }
  else if(CharCurrent==CharPast||CharCurrent==CharPast2&&count==1){
    count++;
    delay(25);
  }
  else if(CharCurrent==CharPast||CharCurrent==CharPast2){
    count++;
    Keyboard.write(keys[ROW][COL]);
    delay(75);
  }
  else{
    Keyboard.write(keys[ROW][COL]);
    count=0;
  }
  CharPast2=CharPast;
  CharPast=CharCurrent;
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Keyboard.begin();
  pinMode(row1,OUTPUT);
  pinMode(row2,OUTPUT);
  pinMode(row3,OUTPUT);
  pinMode(row4,OUTPUT);
  pinMode(row5,OUTPUT);
  pinMode(row6,OUTPUT);
  pinMode(row7,OUTPUT);
  pinMode(row8,OUTPUT);
  
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
  nothing++;
  
  digitalWrite(row8,HIGH);
  
  if(digitalRead(col7)==HIGH&&CAStatus==0){
    Keyboard.press(keys[2][0]);
    CAStatus=1;
  }else if(digitalRead(col7)==HIGH&&CAStatus==1){
    Keyboard.release(keys[2][0]);
    CAStatus=0;
  }

  if(digitalRead(col2)==HIGH){    //left shift
    Keyboard.press(keys[3][0]);
    ShiftStatus=1;
  }else{
    Keyboard.release(keys[3][0]);
    ShiftStatus=0;
  }
  if(digitalRead(col4)==HIGH){     //left ctrl
    Keyboard.press(keys[4][0]);
  }else{
    Keyboard.release(keys[4][0]);
  }
  if(digitalRead(col6)==HIGH){     //left gui
    Keyboard.press(keys[4][1]);
  }else{
    Keyboard.release(keys[4][1]);
  }
  if(digitalRead(col5)==HIGH){     //left alt
    Keyboard.press(keys[4][2]);
  }else{
    Keyboard.release(keys[4][2]);
  }
  if(digitalRead(col3)==HIGH){     //right ctrl
    Keyboard.press(keys[4][11]);
  }else{
    Keyboard.release(keys[4][11]);
  }
  if(digitalRead(col1)==HIGH){     //right shift
    Keyboard.press(keys[3][11]);
    ShiftStatus=2;
  }else{
    Keyboard.release(keys[3][11]);
    if(ShiftStatus==1){
      ShiftStatus=1;
    }
    else if(ShiftStatus==0){
      ShiftStatus=0;
    }
  }
  if(digitalRead(col8)==HIGH&&ShiftStatus!=0&&IStatus==0){
    Keyboard.release(keys[3][0]);
    Keyboard.release(keys[3][11]);
    Keyboard.press(keys[2][14]);
    IStatus=1;
    if(ShiftStatus==1){
      Keyboard.press(keys[3][0]);
    }
    else if(ShiftStatus==2){
      Keyboard.press(keys[3][11]);
    }
  }else if(digitalRead(col8)==HIGH&&ShiftStatus!=0&&IStatus==1){   //sets insert key to press insert when shift is pressed
    Keyboard.release(keys[3][0]);
    Keyboard.release(keys[3][11]);
    Keyboard.release(keys[2][14]);
    IStatus=0;
    if(ShiftStatus==1){
      Keyboard.press(keys[3][0]);
    }
    else if(ShiftStatus==2){
      Keyboard.press(keys[3][11]);
    }
  }else if(digitalRead(col8)==HIGH&&ShiftStatus==0){   //sets insert key to press delete when shift is not pressed
    type(0,14);
    nothing=0;
  }

  digitalWrite(row8,LOW);
  digitalWrite(row7,HIGH);
  if(digitalRead(col8)==HIGH){     //right alt
    Keyboard.press(keys[4][10]);
  }else{
    Keyboard.release(keys[4][10]);
  }
  digitalWrite(row7,LOW);
  

  
  digitalWrite(row1,HIGH);
  if(digitalRead(col1)==HIGH){
    type(0,7);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(0,6);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(0,5);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(0,4);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(0,3);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(0,2);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(0,1);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH&&ShiftStatus==0){  //Sets ESC key when ` is pressed
    type(0,0);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH&&ShiftStatus==1){   //Sets ~ key when Shift + ` is pressed
    type(1,14);
    nothing=0;
  }
  digitalWrite(row1,LOW);
  digitalWrite(row2,HIGH);
  
  if(digitalRead(col1)==HIGH){
    type(1,7);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(1,6);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(1,5);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(1,4);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(1,3);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(1,2);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(1,1);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH){
    type(1,0);
    nothing=0;
  }
  digitalWrite(row2,LOW);  
  digitalWrite(row3,HIGH);
  
  if(digitalRead(col1)==HIGH){
    type(2,1);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(2,2);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(2,3);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(2,4);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(2,5);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(2,6);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(2,7);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH){
    type(2,8);
    nothing=0;
  }
  digitalWrite(row3,LOW);
  digitalWrite(row4,HIGH);
  
  if(digitalRead(col1)==HIGH){
    type(3,1);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(3,2);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(3,3);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(3,4);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(3,5);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(3,6);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(3,7);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH){
    type(3,8);
    nothing=0;
  }
  digitalWrite(row4,LOW);
  digitalWrite(row5,HIGH);
  
  if(digitalRead(col1)==HIGH){
    type(0,8);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(0,9);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(0,10);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(0,11);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(0,12);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(0,13);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(1,12);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH){
    type(1,13);
    nothing=0;
  }
  digitalWrite(row5,LOW);
  digitalWrite(row6,HIGH);
  
  if(digitalRead(col1)==HIGH){
    type(1,8);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(1,9);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(1,10);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(1,11);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(2,9);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(2,10);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(2,11);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH){
    type(2,12);
    nothing=0;
  }
  digitalWrite(row6,LOW);
  digitalWrite(row7,HIGH);
  
  if(digitalRead(col1)==HIGH){
    type(3,9);
    nothing=0;
  }
  else if(digitalRead(col2)==HIGH){
    type(3,10);
    nothing=0;
  }
  else if(digitalRead(col3)==HIGH){
    type(4,6);
    nothing=0;
  }
  else if(digitalRead(col4)==HIGH){
    type(3,13);
    nothing=0;
  }
  else if(digitalRead(col5)==HIGH){
    type(4,12);
    nothing=0;
  }
  else if(digitalRead(col6)==HIGH){
    type(4,13);
    nothing=0;
  }
  else if(digitalRead(col7)==HIGH){
    type(4,14);
    nothing=0;
  }
  else if(digitalRead(col8)==HIGH){
    type(4,11);
    nothing=0;
  }
  digitalWrite(row7,LOW);

  if(nothing!=0){
    type(3,14);
  }


}
