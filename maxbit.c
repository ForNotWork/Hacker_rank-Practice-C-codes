#include <stdio.h>

void calculate_the_maximum(int n,int k)
{
    int a[10];
    int b[10];
    int c[10];
    int* pa;
    pa =a;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            for(int m=j;)
            //if(i==1)a[j] =i;
            //if(i==2)b[j]=i;
            //if(i==3)c[j]=i;
            //int m=0;
            //*(pa+m)=i;
            ///m++;
        }
    }
    printf ("\n");
    for(int i =0;i<k;i++)
    {
        printf("%d\t",a[i]);
        printf("\n%d\t",b[i]);
        printf("\n%d\t",c[i]);
    }
}

void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int max_and =0, max_or=0, max_xor=0, and, or, xor, i, j;
  
  for (i = 1; i < n; i++)
  {
      for (j= i+1 ; j <= n; j++)
      {
          and = i & j;
          or = i | j;
          xor = i ^ j;
          
          if ((and > max_and) && (and < k))
              max_and = and;
          if ((or > max_or) && (or < k))
              max_or = or;
          if ((xor > max_xor) && (xor < k))
              max_xor = xor;
        }
  }
  printf("%d\n%d\n%d",max_and,max_or,max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
/*#include <stdio.h>

struct data
{
    unsigned int a:4;
}Data;

int main()
{
//    struct data Data;

    scanf("%d",Data.a);
    printf("%d",Data.a);
    return 0;
}*/
/*int max_and=0,max_or=0,max_xor=0,and,or,xor,i,j;
  for(i =0;i<n;i++)
  {
    for(j =i+1;j<=n;j++)
    {
        and = i & j;
        or = i | j;
        xor = i ^ j;
          
        if((and > max_and) && (and < k))
            max_and = and;
        if((or > max_or) && (or < k))
            max_or = or;
        if((xor > max_xor) && (xor < k))
            max_xor = xor;
    }
  }
  printf("%d\n%d\n%d",max_and,max_or,max_xor);
}*/
