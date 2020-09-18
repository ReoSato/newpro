#include<stdio.h>
#include <drawlib.h>
#include <math.h>
//----------------------160//
int main() {
  int ballx = 320, bally =10, hitback, hit = 1,keep = 1;
  int batfx = 280, batfy = 495, r = 80, i = 0;
  int total =0, out = 0, t,k,x,y; 
  double start = -1.57, turn, wait_time = 0.01;  
  char OUT[] = {"OUT "}, SCORE[] = {"SCORE "}, TOTAL[] = {"00000000000000000000000000"};
   dl_initialize(1.0); 
while(1) {   
 while(out != 3) { 
 //------------イベント処理------------//
  if(dl_get_event(&t,&k,&x,&y)) {
      if (t == DL_EVENT_L_DOWN) {
        while(start < 3.14){
       dl_line(280,415,280 + r*cos(start),415 - r*sin(start),DL_RGB(145,150,155), 5);
      i += 1.0;
      start = (-90 + i) * 3.14 / 360;
      hit = 415 + ((- r*sin(start) / cos(start))/2);
      if (hit == bally + 15) {
         hitback = hit;
         keep = hit;
         turn = start;
         }             }   }  }                            
 //-------アウト判定-------//
  if (160<= ballx && ballx<=240 && bally < 2 && bally > -14)
   out = out + 1;
  if (380<= ballx && ballx<=490 && bally < 2 && bally > -14) 
   out = out + 1;
 //-------ヒット判定------//
  if (30<=ballx && ballx<=150 && bally < 2 && bally > -7)
  total += 60;  
  
  if (530<= ballx && ballx<=640 && bally < 2 && bally > -5)
  total += 40;
   
  if (290< ballx && ballx<350 && bally < 2)
  total += 100;
   
  if (0<= bally && bally<=135 && ballx < 2 && ballx > -3)
  total += 5;
   
  if (0<= bally && bally<=135 && ballx > 638 && ballx < 641)
  total += 10;     
 //-----ファウルゾーン-----// 
  if (135< bally && ballx < 2 && ballx > -1)
  total -= 30;
 
  if (135< bally && ballx > 638 && ballx < 641)
  total -= 20;

/*----------------------------- 描画 ---------------------------------*/ 
   dl_stop(); 
   dl_clear(DL_RGB(105,75,40));//背景色設定//
//ライン//
   dl_line(280,430,0,135,DL_C("white"), 4);
   dl_line(360,430,640,135,DL_C("white"), 4);

//スコア&アウト 文字表示//
   dl_text(SCORE,400,440,1.0,DL_C("white"),4); 
   dl_text(OUT,40,440,1.0,DL_C("white"),4);

//アウトカウント//
  if (out == 1) 
   dl_circle(130, 430,12, DL_C("red"),1,1);
  if (out == 2) {
   dl_circle(130, 430,12, DL_C("red"),1,1);
   dl_circle(160, 430,12, DL_C("red"),1,1);
   }
//バット//
   dl_line(280,415,280 + r*cos(start),415 - r*sin(start),DL_RGB(145,150,155), 5);

//初期化//
  if (bally > 510 || bally < -17 || ballx > 700 || ballx < -15) {
   ballx = 320; bally = 10;
   start = -1.57; turn = 0; i = 0;
   hit = 1; hitback = 0; keep = 1;
 } 
//的のライン//
   dl_line(0,30,0,135,DL_C("yellow"), 7);  
   dl_line(30,2,160,2,DL_C("blue"), 7);
   dl_line(160,2,240,2,DL_C("red"), 7);  
   dl_line(300,2,340,2,DL_C("white"), 7);
   dl_line(400,2,490,2,DL_C("red"), 7);
   dl_line(530,2,640,2,DL_C("blue"), 7);
   dl_line(640,30,640,135,DL_C("yellow"), 7);

//スコア処理//
   sprintf(TOTAL,"%d",total);
   dl_text(TOTAL,520,440,1.0,DL_C("white"),4);

//ボール//
   dl_circle(ballx, bally,15, DL_RGB(0,255,150),1,1);
 
  if (hitback == keep) {
    if (sin(turn) / cos(turn) > 0) {
    ballx = ballx - 5;
    bally = bally - (cos(turn) / sin(turn)* 5);
    }
    if (sin(turn) / cos(turn) < 0) {
    ballx = ballx + 5;
    bally = bally + (cos(turn) / sin(turn)* 5);
    }
    if (sin(turn) / cos(turn) ==  0) {
    bally -= 5;
    }   
  }
  else {
  bally = bally + 2; 
  } 
 dl_resume();
 dl_wait(wait_time); 
 }
 //最終スコア表示// //スリーアウト//　//四秒後に終了//
 sprintf(TOTAL,"%d",total);
 dl_text(TOTAL,230,320,3.0,DL_C("white"),5);
 dl_circle(130, 430,12, DL_C("red"),1,1);
 dl_circle(160, 430,12, DL_C("red"),1,1);
 dl_circle(190, 430,12, DL_C("red"),1,1);
 dl_wait(4.0);
 break;
 }
return 0;
}
