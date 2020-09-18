#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include <errno.h>
double dist(double x2, double x1, double y2, double y1);

double main(void) {
 double a,b,c, d,e,f;
 double x1, y1, x2, y2,x3, y3;
 double array[4], l;
 int i,u;
 printf("x1:"); scanf("%3lf",&x1);
 printf("y1:"); scanf("%3lf",&y1);
 printf("x2:"); scanf("%3lf",&x2);
 printf("y2:"); scanf("%3lf",&y2);
 printf("x3:"); scanf("%3lf",&x3);
 printf("y3:"); scanf("%3lf",&y3);

 array[0] = dist(x2,x1,y2,y1);
 printf("%4.3lf\n", array[0]);

 array[1] = dist(x3,x1,y3,y1);
 printf("%4.3lf\n", array[1]);

 array[2]= dist(x2,x3,y2,y3);
 printf("%4.3lf\n", array[2]);

 for(u = 0; u < 2; u++) {
  for(i = 0; i < 2; i++) {

    if(array[i] < array[i+1]) {
     l = array[i+1];
     array[i+1] = array[i];
     array[i] = l;
    }
  }
 }
   a = array[0];
   b = array[1];
   c = array[2];
   d = powf(a,2);
   e = powf(b,2);
   f = powf(c,2);
   
   printf("%4.6lf\n",d);
   printf("%4.6lf\n",e);
   printf("%4.6lf\n",f);
   
 if (a == b + c){
 printf("三角形になりません");
 }
 else if(d == e + f || ((e + f -0.1 < d) && (d < e + f + 0.1))) {
 printf("直角三角形です");
 }
 else if(d > e + f ) {
 printf("鈍角三角形です");
 }
 
 else if(d < e + f) {
 printf("鋭角三角形です");
 }
 printf("\n");
 

return 0;
}

double dist(double x2, double x1, double y2, double y1){
 double v,a,b;
 a = powf((x2-x1),2);
 b = powf((y2-y1),2);
 v = sqrtl(a + b);
 
 return v;
}







