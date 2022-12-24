#include<stdio.h>
#include<stdlib.h>

int main()
{
    int test_case;
    int prize;
    int players;
    int cost_p,cost_g;

    scanf("%d",&test_case);

    for(int i =0; i<test_case;i++)
    {
        scanf("%d %d",&cost_p,&cost_g);
        scanf("%d",&players);
        int sum_1=0,sum_2=0;
        for(int j =0;j<players;j++)
        {
            int p,g;
            scanf("%d %d",&p,&g);
            sum_1 += p*cost_p + g*cost_g;
            sum_2 += p*cost_g + g*cost_p;
        }
        if(sum_1<sum_2)
        {
            printf("%d\n",sum_1);
        }
        else
        {
            printf("%d\n",sum_2);
        }
    }
 return 0;   
}