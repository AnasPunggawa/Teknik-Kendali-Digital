int D1 = 10;
int D2 = 11;
int D3 = 12;
int D4 = 13;


const byte numeral[11]={
B11111100, //untuk angka 0
B01100000, //untuk angka 1
B11011010, //untuk angka 2
B11110010, //untuk angka 3
B01100110, //untuk angka 4
B10110110, //untuk angka 5
B10111110, //untuk angka 6
B11100000, //untuk angka 7
B11111110, //untuk angka 8
B11110110, //untuk angka 9
B00000000, //tanpa menampilkan apapun
};
 
//inisialisasi pin yang digunakan
const int segmentPins[8]= { 9, 8, 7, 6, 5, 4, 3, 2 }; //dp,g,f,e,d,c,b,a
 
void setup(){
for (int i=0; i < 8; i++){
pinMode(segmentPins[i], OUTPUT);
}
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
}
 
void loop(){
for (int i=0; i <=10; i++){
tunjukanAngka(i);
delay(1000);
}
delay(2000); }
 
void tunjukanAngka (int number){
boolean isBitSet;
for (int segment=1; segment < 8; segment++){
isBitSet= bitRead(numeral[number], segment);
digitalWrite(segmentPins[segment], isBitSet); }
}
