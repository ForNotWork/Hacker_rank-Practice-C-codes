#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      for(int i = 0;i<2*n-1;i++)
      {
          for(int j=0;j<2*n-1;j++)
          {
              int x=0;
              if(i<j)
              {
                  x=i;
              }
              else{
                  x=j;
              }
              if(2*n-2-i<x)
              {
                  x=2*n-2-i;
              }
              else {
                  x=x;
              }
              if(2*n-2-j<x)
              {
                  x=2*n-2-j;
              }
              else {
              x=x;
              }
              printf("%d\t",n-x);
          }
          printf("\n");
      }
    return 0;
}
/*int n;
scanf("%d", &n);

  for(int i = 0; i<2*n-1; i++){
      for(int j = 0; j<2*n-1; j++){
            int min;
            min =i<j? i:j;
            min = 2*n-2-i < min? 2*n-2-i:min;
            min = 2*n-2-j<min ? 2*n-2-j:min;
            printf("%d ",n-min);
      }printf("\n");
  }
return 0;*/