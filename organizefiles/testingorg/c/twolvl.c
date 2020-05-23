#include<stdio.h>
#include<stdbool.h>
#include<string.h>

 typedef struct sDir
{
    char name[10];
    char file[10][10];
    bool flag[10];
    int nof;
}sdir;

sdir dir[10];
size = 0;

int main()
{
    int ite = 1,cho=0;
    char dirr[20];
    int i=0,j=0,k;
    char fname[20];
    while(ite)
    {
        printf("\n1.insert 2.delete 3.search 4.create dir: ");
        scanf("%d", &cho);
        switch(cho)
        {
        case 1:
            printf("\nenter the dir name : ");
            scanf("%s", dirr);
            for(i=0;i<size;i++)
            {
                if(strcmp(dir[i].name,dirr) == 0)
                {
                    printf("\nenter the file name : ");
                    scanf("%s", &fname);
                    strcpy(dir[i].file[dir[i].nof],fname);
                    dir[i].nof++;
                    break;
                }
            }
            if(i == size)
                printf("\ndir not found");
            break;
        case 2:
            printf("\nenter the name of dir : ");
            scanf("%s", dirr);

            for(k=0;k<size;k++)
            {
                if(strcmp(dirr,dir[k].name) == 0)
                {
                    printf("\nenter the name of file to delete : ");
                scanf("%s", fname);
                for(i=0;i<dir[k].nof;i++)
                {
                    if(strcmp(fname,dir[k].file[k]) == 0)
                    {
                        if(dir[k].nof == 1)
                        {
                            dir[k].nof--;
                            break;
                        }
                        else
                        {
                            for(j=i;j<dir[k].nof-1;j++)
                            {
                                strcpy(dir[k].file[j],dir[k].file[j+1]);
                            }
                            dir[k].nof--;
                            break;
                        }
                    }
                }
                if(i == dir[k].nof)
                    printf("\nfile not found!!");
                break;
                }
            }
            if(k == size)
                printf("\ndir not found");
            break;
        case 3:
             printf("\nenter the name of dir : ");
            scanf("%s", dirr);

            for(k=0;k<size;k++)
            {
                if(strcmp(dirr,dir[k].name) == 0)
                {
                        printf("\nenter the file name to search : ");
                        scanf("%s", fname);
                        for(i=0;i<dir[k].nof;i++)
                        {
                            if(strcmp(fname,dir[k].file[i]) == 0)
                            {
                                printf("\nfile found");
                                break;
                            }
                        }
                        if(i == dir[k].nof)
                            printf("\nfile not found");
                        break;
                }
            }
            if(k == size)
                printf("\ndir not found ");
            break;

        case 4:
            printf("\nenter the name of dir : ");
            scanf("%s", dirr);
            strcpy(dir[size].name,dirr);
            dir[size].nof = 0;
            size++;
        }
    }
}

