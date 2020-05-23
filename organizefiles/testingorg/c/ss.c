#include<stdio.h>

typedef struct Node
{
    int arr;
    int bur;
}node;

int tat[20];
int wt[20];

void calcutat(node a[],int n)
{
    int t=0,flag=-0,index=-1,i=0;
    int ite=0;
    int complete =0;
    int rt[n];
    for(i=0;i<n;i++)
    {
        rt[i] = a[i].bur;
    }
    while(complete != n)
    {
        index = -1;
        for(i=0;i<n;i++)
        {
            if(a[i].arr <= t)
            {
                if(index == -1)
                {
                    flag = 1;
                    index = i;
                }
                else if(rt[i] < rt[index])
                {
                    index= i;
                }
            }

        }
        if(flag == 0)
        {
            t++;
            continue;
        }
        rt[index]--;
        t++;
        flag = 0;

        if(rt[index] == 0)
        {

            tat[ite] = t-a[index].arr;
            a[index].arr = 10000;
            wt[ite] = tat[ite]-a[index].bur;
            ite++;
            //printf("%d", tat[ite-1]);
            complete++;
        }
    }

}

int main()
{
    int n;
    printf("\nenter no of processes : ");
    scanf("%d", &n);
    node no[n];
    int i=0;
    int wait=0;
    int ta=0;
    for(i=0;i<n;i++)
        scanf("%d  %d", &no[i].arr,&no[i].bur);
    calcutat(no,n);
    for(i=0;i<n;i++)
        printf("\n%d", tat[i]);
    for(i=0;i<n;i++)
    {
        wait = wait+wt[i];
        ta = ta + tat[i];
    }
    printf("\n%f %f",(float)wait/n,(float)ta/n);
}
