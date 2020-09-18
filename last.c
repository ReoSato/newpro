#include<stdio.h>
#include<stdlib.h>
#include <drawlib.h>
#include <math.h>


int main () {
  
  int bx = 320,by = 0,barY = 400, add =  4;
  int theta = -90, r=80, t, k, x, y, i = 0;
  double start;
dl_initialize(1.0);
//-----------お試しmain関数-----------//

int main() {
  int bx,by;
  int OUT;
  dl_initialize(1.0);
  
while (OUT < 3) {
//背景黒化とボール移動//
dl_clear(DL_RGB(0,0,0));
by = by + add; 
//移動する半径15のボール//
dl_circle(bx, by,15, DL_C("blue"),1,1);

if (by == 480) {
 by = 0;
}
//イベントorボタン処理//

if ("イベントorボタンが押されたら") {
    "バットを回転させる"
  if ("接触したら") {
    "角度に応じてボールを跳ね返す"
   if ("的１にあたったら") {"ＯＵＴ"OUT = OUT + 1;}
   else if ("２に") {
   "ＯＵＴ"OUT = OUT + 1;}
   else if ("３に") {
   "６０加点"}
   else if ("４に") {
   "４０加点"}
   else if ("大砲に") {
   "１００加点"}}}

}

//--------------------------------------------------//

while(1) {
while (by != barY) {
dl_clear(DL_RGB(0,0,0));
   by = by + add;
   dl_line(280, barY,
   280 + r * cos(start), barY + r * sin(start),DL_C("red"), 2 );
   dl_line(280,430,0,130,DL_C("white"), 4);
   dl_line(360,430,640,130,DL_C("white"), 4);
   dl_circle(bx, by, 20, DL_C("blue"),1,1);
/* -----------------------------------------------------------------*/  
   if(dl_get_event(&t, &k, &x,&y)) {
    if(t == DL_EVENT_KEY){
      while(start < 1.57){
      i++;
      start = (-90 + i) * 3.14 / 180;
   }
   }
   }
  /*-------------------------------------------------------------*/
   
   dl_wait(0.01);
   }
   
while(by != 0) {
 dl_clear(DL_RGB(0,0,0));
   by = by + (add * -1);
   
    
   dl_line(280,430,0,130,DL_C("white"), 4);
   dl_line(360,430,640,130,DL_C("white"), 4);
   dl_line(280,barY,360,barY,DL_C("red"),2);
   dl_circle(bx, by,20, DL_C("blue"),1,1);
   
   dl_wait(0.01);
   }
   
   
}
   
  
   
  

 
return 0;
} 
