#include <hidef.h>      /* common defines and macros */
#include <mc9s12dg256.h>
#pragma LINK_INFO DERIVATIVE "mc9s12dg256b"

#include "main_asm.h" /* interface to the assembly module */



#define C0    45827   //Unaudiable on Board speaker
#define Cs0   43256
#define D0    40829
#define Ds0   38538
#define E0    36376
#define F0    34335
#define Fs0   32409
#define G0    30590
#define Gs0   28874
#define A0    27254
#define As0   25725
#define B0    24282
#define C1    22919
#define Cs1   21633
#define D1    20419
#define Ds1   19274
#define E1    18192
#define F1    17172
#define Fs1   16208
#define G1    15299
#define Gs1   14441
#define A1    13630
#define As1   12866
#define B1    12144
#define C2    11462
#define Cs2   10819
#define D2    10212
#define Ds2   9639
#define E2    9098
#define F2    8588
#define Fs2   8106
#define G2    7651
#define Gs2   7222
#define A2    6817
#define As2   6434
#define B2    6073
#define C3    5733
#define Cs3   5411
#define D3    5107
#define Ds3   4821
#define E3    4550
#define F3    4295
#define Fs3   4054
#define G3    3827
#define Gs3   3612
#define A3    3409
#define As3   3218
#define B3    3037
#define C4    2867
#define Cs4   2706
#define D4    2554
#define Ds4   2411
#define E4    2276
#define F4    2148
#define Fs4   2028
#define G4    1914
#define Gs4   1806
#define A4    1705
#define As4   1609
#define B4    1519
#define C5    1434
#define Cs5   1353
#define D5    1277
#define Ds5   1206
#define E5    1138
#define F5    1074
#define Fs5   1014
#define G5    957
#define Gs5   903
#define A5    853
#define As5   805
#define B5    760
#define C6    717
#define Cs6   677
#define D6    639
#define Ds6   603
#define E6    569
#define F6    537
#define Fs6   507
#define G6    479
#define Gs6   452
#define A6    426
#define As6   402
#define B6    380
#define C7    359
#define Cs7   338
#define D7    319
#define Ds7   302
#define E7    285
#define F7    269
#define Fs7   254
#define G7    239
#define Gs7   226
#define A7    213
#define As7   201
#define B7    190
#define C8    179
#define Cs8   169
#define D8    160
#define Ds8   151
#define E8    142
#define F8    134
#define Fs8   127
#define G8    120
#define Gs8   113
#define A8    107
#define As8   101
#define B8    95
#define r  0

#define sixtenth    62   //0.062 seconds
#define eigth       125  //0.125 seconds
#define quarter     250  //0.25 seconds
#define quarterDot  375  //0.375 seconds
#define half        500  //0.5 seconds
#define halfDot     750  //.750 seconds
#define whole       1000 //1 second

void JoyToTheWorld(void);
void TetrisThemeA(void);

int i;
int pitch;
int rest;
int joytotheworldScore[59] = {
  C6, B5, A5, G5, F5, E5, D5, C5, G5, A5, A5, B5, B5, C6, C6, C6, //16
  C6, B5, A5, G5, G5, F5, E5, C6, C6, B5, A5, G5, G5, F5, E5, E5, //16
  E5, E5, E5, E5, F5, G5, F5, E5, D5, D5, D5, D5, E5, F5, E5, D5, //16
  C5, C6, A5, G5, F5, E5, F5, E5, D5, C5, r                      //11
  
};
int joytotheworldDelay[59] = {
    half, quarterDot, eigth, halfDot, quarter, half, half, halfDot, quarter, halfDot, quarter, halfDot, quarter, whole, halfDot, quarter,
    quarter, quarter, quarter, quarter, quarterDot, eigth, quarter, quarter, quarter, quarter, quarter, quarter, quarterDot, eigth, quarter, quarter,
    quarter, quarter, quarter, eigth, eigth, halfDot, eigth, eigth, quarter, quarter, quarter, eigth, eigth, halfDot, eigth, eigth,
    quarter, half, quarter, quarterDot, eigth, quarter, quarter, half, half, whole, half
};


int tetrisScore[98]={
  E6,B5,C6,D6,E6,D6,C6,B5,A5,A5,C6,E6,B6,C6,B5,C6,D6,E6,C6,A5,A5,r,D6,F6,A6,G6,F6, //27 NOTES
  E6,C6,E6,D6,C6,B5,B5,C6,D6,E6,C6,A5,A5,r,//REPEAT!                                //14 NOTES
  E6,B5,C6,D6,E6,D6,C6,B5,A5,A5,C6,E6,B6,C6,B5,C6,D6,E6,C6,A5,A5,r,D6,F6,A6,G6,F6, //27 NOTES
  E6,C6,E6,D6,C6,B5,B5,C6,D6,E6,C6,A5,A5,rest,E5,C5,D5,B4,                            //18 NOTES
  C5,A4,Gs4,B4,E5,C5,D5,B4,C5,E5,A5,Gs5                                               //12 NOTES
};
int tetrisDelay[98]={
  quarter,eigth,eigth,eigth,sixtenth,sixtenth,eigth,eigth,quarter,eigth,eigth,quarter,eigth,eigth,quarterDot,eigth,quarter,quarter,quarter,quarter,half,eigth,quarter,eigth,quarter,eigth,eigth,
  quarterDot,eigth,quarter,eigth,eigth,quarter,eigth,eigth,quarter,quarter,quarter,quarter,quarter, //REPEAT
  quarter,eigth,eigth,eigth,sixtenth,sixtenth,eigth,eigth,quarter,eigth,eigth,quarter,eigth,eigth,quarterDot,eigth,quarter,quarter,quarter,quarter,half,eigth,quarter,eigth,quarter,eigth,eigth,
  quarterDot,eigth,quarter,eigth,eigth,quarter,eigth,eigth,quarter,quarter,quarter,quarter,quarter,half,half,half,half,
  half,half,half,half,half,half,half,half,quarter,quarter,half,whole
};


//Timer Channel 5 interrupt service routine
void interrupt 13 handler(){
 tone(pitch);
}

void main(void) {
  PLL_init();

  
  while(1){
    TetrisThemeA();

  } 
}


void JoyToTheWorld(){
      
    for(i=0; i<59; i++){
      pitch = joytotheworldScore[i];
      rest = joytotheworldDelay[i] * 2;
      sound_init();
      sound_on();
      ms_delay(rest);
    }
}

void TetrisThemeA(){
      
    for(i=0; i<98; i++){
      pitch = tetrisScore[i];
      rest = tetrisDelay[i] / 4;
      sound_init();
      sound_on();
      ms_delay(rest);
    }
} 
  
