#include<stdio.h>
#include<string.h>
#include<ctype.h>

char production[20][100];
char first[200][20];
int ite[2000]={0};
int flag[200]={0};
int n;

void print()
{
    int flagg[200]={0};
    int i,j;
    for(j=0;j<n;j++)
    {
        if(flagg[production[j][0]] != 1)
        {
            printf("%c",production[j][0]);
            for( i=0;i<ite[production[j][0]];i++)
            {
                    printf(" %c  ", first[production[j][0]][i]);
                    flagg[production[j][0]] = 1;
            }

            printf("\n");
        }
    }
}

int main()
{
    int j=0;
	printf("no of productions : ");
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i++)
	{

		scanf("%s", production[i]);
		//printf("%s", production[i]);
	}

	for(i=0;i<n;i++)
        calculate(production[i][0]);

    print();
}

void calculate(char c)
{
    if(flag[c] == 1)
        return;
	printf("%c", c);
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		if(production[i][0] == c)
		{
			//puts("gsgds");
			if(production[i][1] == '#')
			{
				//puts("gsgds1");
				first[c][ite[c]++] = '#';
			}
			else if(isupper(production[i][1]) )
			{
			    int tempflag = 0;
			    int proite =1;
				//puts("gsgds2");
				do
                {
                    if(flag[production[i][proite]] == 1)
                    {
                        for( j=0;j<ite[production[i][proite]];j++)
                        {
                            if(first[production[i][proite]][j] == '#')
                            {
                                tempflag = 1;
                                proite++;
                            }
                            first[c][ite[c]++] = first[production[i][proite]][j];
                        }
                    }
                    else
                    {
                        //puts("gsgds3");
                        calculate(production[i][proite]);
                        for( j=0;j<ite[production[i][proite]];j++)
                        {
                            if(first[production[i][proite]][j] == '#')
                            {
                                tempflag = 1;
                                proite++;
                            }
                            first[c][ite[c]++] = first[production[i][proite]][j];
                        }

                    }
				}while(tempflag == 1 && production[i][proite] != '\0');

			}
			else
			{
			    //puts("non terminal");
				first[c][ite[c]++] = production[i][1];
			}
		}
	}
	flag[c] = 1;
	//puts("sjkdfasjkdf");
}
