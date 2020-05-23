#include<stdio.h>
#include<string.h>
#include<ctype.h>

char production[20][100];
char first[200][20];
int ite[2000]={0};
int flag[200]={0};
int n;

char follow[200][20];
int fite[2000]={0};
int fflag[200]={0};



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

void fprint()
{
    int flagg[200]={0};
    int i,j;
    printf("\n\n");
    for(j=0;j<n;j++)
    {
        if(flagg[production[j][0]] != 1)
        {
            printf("%c",production[j][0]);
            for( i=0;i<fite[production[j][0]];i++)
            {
                    printf(" %c  ", follow[production[j][0]][i]);
                    flagg[production[j][0]] = 1;
            }

            printf("\n");
        }
    }
}

void cal(char c){
//	printf("%c ",c);
	int i,j,k;
	for(i=0;i<n;i++){
		//if(c != production[i][0]){
		int n = strlen(production[i]);
		int temp = 1;
		for(j=1;j<n;j++){
			if(production[i][j] == c)
				break;
		}
		if(j == n)
			continue;
		if(j == n-1){
			//printf("yes ");
			if(c != production[i][0])
			{
				//printf("oh yead ");
				if(fflag[production[i][0]] != 1)
					cal(production[i][0]);
				for( k=0;k<fite[production[i][0]];k++){
					//printf(" %c",follow[production[i][0]][k]);
					fadd(c,follow[production[i][0]][k]);
				}
			}
		}
		for(j=j+1;j<n && temp==1;j++){
			if(!isupper(production[i][j])){
				fadd(c,production[i][j]);
				//printf(" %c",production[i][j]);
				temp = 0;
				break;
			}
			temp=0;
			for(k=0;k<ite[production[i][j]];k++)
			{
				if(first[production[i][j]][k] == '#')
				{
					temp = 1;
					continue;
				}
				//printf(" %c",first[production[i][j]][k]);
				fadd(c,first[production[i][j]][k]);			
			}
		}
		if(temp == 1){
			if(c != production[i][0])
			{
				//printf("oh yead ");
				if(fflag[production[i][0]] != 1)
					cal(production[i][0]);
				for( k=0;k<fite[production[i][0]];k++){
					//printf(" %c",follow[production[i][0]][k]);
					fadd(c,follow[production[i][0]][k]);
				}
			}
		}
//	}
	}
	
	fflag[c] = 1;
}

void fadd(char c1,char c2){
	int i;
	for( i=0;i<fite[c1];i++){
		if(follow[c1][i] == c2)
			return;
	}
	follow[c1][fite[c1]++] = c2;
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

	for(i=0;i<n;i++){
		if(flag[production[i][0]] != 1)
        	calculate(production[i][0]);
    }
    
    print();
    fadd(production[0][0],'$');
    
    for(i=0;i<n;i++){
    	if(fflag[production[i][0]] != 1)  
    		cal(production[i][0]);
	}
	
	fprint();
//	cal(production[0][0]);
//	cal(production[1][0]);
    //print();
}

void add(char c1,char c2){
	int i;
	for( i=0;i<ite[c1];i++){
		if(first[c1][i] == c2)
			return;
	}
	first[c1][ite[c1]++] = c2;
}

void calculate(char c)
{
    if(flag[c] == 1)
        return;
//	printf("%c", c);
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		if(production[i][0] == c)
		{
			//puts("gsgds");
			if(production[i][1] == '#')
			{
				//puts("gsgds1");
				add(c,'#') ;
				//first[c][ite[c]++] = '#';
			}
			else if(isupper(production[i][1]))
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
                            //first[c][ite[c]++]  
							add(c,first[production[i][proite]][j]);
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
                            //first[c][ite[c]++] =
							 add(c,first[production[i][proite]][j]);
                        }

                    }
				}while(tempflag == 1 && production[i][proite] != '\0');

			}
			else
			{
			    //puts("non terminal");
				//first[c][ite[c]++]  
				add(c,production[i][1]);
			}
		}
	}
	flag[c] = 1;
	//puts("sjkdfasjkdf");
}
