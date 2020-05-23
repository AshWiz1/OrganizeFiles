#include<stdio.h>
#include<string.h>
#include<stdbool.h>


typedef struct sDir
{
    char name[10];
    char file[10][10];
    bool flag[10];
    int nof;
}sdir;

sdir dir;

int main()
{
    int ite = 1,cho=0;
    dir.nof = 0;
    int i=0,j=0;
    char fname[20];
    for(i=0;i<10;i++)
    {
        dir.flag[i] = 0;
    }
    while(ite)
    {
        printf("\n1.insert 2.delete 3.search 4.print : ");
        scanf("%d", &cho);
        switch(cho)
        {
        case 1:
            printf("\nenter the name of the file : ");
            scanf("%s", dir.file[dir.nof]);
            dir.nof++;
            break;
        case 2:

            printf("\nenter the name of file to delete : ");
            scanf("%s", fname);
            for(i=0;i<dir.nof;i++)
            {
                if(strcmp(fname,dir.file[i]) == 0)
                {
                    if(dir.nof == 1)
                    {
                        dir.flag[0] == 0;
                        dir.nof--;
                        break;
                    }
                    else
                    {
                        for(j=i;j<dir.nof-1;j++)
                        {
                            strcpy(dir.file[j],dir.file[j+1]);
                        }
                        dir.flag[dir.nof] = 0;
                        dir.nof--;
                        break;
                    }
                }
            }
            if(i == dir.nof)
                printf("\nfile not found!!");
                break;
        case 3:

            printf("\nenter the file name to search : ");
            scanf("%s", fname);
            for(i=0;i<dir.nof;i++)
            {
                if(strcmp(fname,dir.file[i]) == 0)
                {
                    printf("\nfile found");
                    break;
                }
            }
            if(i == dir.nof)
                printf("\nfile not found");
            break;
        case 4:
            for(i=0;i<dir.nof;i++)
            {
                printf("\n%s", dir.file[i]);
            }
            break;
        default:
            ite = 0;
        }
    }
}

