#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
  int arr[3]={a,b,c};
  int sum=0;
    if(n>3)
    {
        for(int i=0;i<n;i++)
        {
            arr[i]= find_nth_term(n-i-1,a,b,c);
            sum+=arr[i];
        }
        return sum;
    }
    else
    {
        return arr[n-1];
    }
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}