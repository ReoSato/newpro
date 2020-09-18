#include <stdio.h>

int strcmp(char *,char *);
void dictsort (char **, int);
/*-----------------------------------------------------------*/
int main (void) {
  int n = 13, i;
  char *colors[] = {"white", "black", "red", "pink",
  "orange", "blue", "yellow", "green", "purple",
  "gray", "brown", "gold", "silver"};
  
  printf("BEFORE: ");
  for(i = 0; i < n; i++) {
    printf("%s ", colors[i]);
  }
  printf("\n");
  
 //--------------------------// 
  dictsort(colors, n);

  printf("AFTER: ");
  for(i = 0; i < n; i++) {
    printf("%s ", colors[i]);
  }
  printf("\n");
  return 0;
}
/* ----------------------------------------------------------*/

void dictsort (char **x, int n) {
 int i,j,z; 
 char *s;  
        
   for(i = 0; i < n - 1; i++) {
      for(j = 0; j < n - i - 1; j++){
    
       z = strcmp(x[j], x[j + 1]);
    
          if (z == 1) {
          s = x[j];
          x[j] = x[j + 1];
          x[j + 1] = s;
          }
       }    
   }
   return ;
}

/*-----------------------------------------------------------*/
int strcmp(char *str1,char *str2) {
   int r = 0;  	

 while (1) {

  if (*str1 != *str2) {
    if (*str1 < *str2) {	
      r = -1;
      break;
    } else if (*str1 > *str2) {
      r = 1;
      break;
    } 
    }
 //---------------------------------//
   else if (*str1 == '\0' == *str2) {
      r = 0;
      break;
    } else if (*str2 == '\0') {
      r = 1;
      break;
    } else if (*str1 == '\0') {
      r = -1;
      break;
    }
    str1++;
    str2++;      
 }
  return r;
}
/*------------------------------------------------------------*/
