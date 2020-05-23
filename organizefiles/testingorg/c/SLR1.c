#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct prod
{
    char lhs;
    char rhs[10];
};
typedef struct prod prod;
prod prods[7];
struct slr
{
    char ch;
    int x;
    bool goto_check;
};
typedef struct slr slr;
slr arr[15][10];
int hasher(char ch)
{
    switch(ch)
    {
    case 'i':
        return 0;
    case '+':
        return 1;
    case '*':
        return 2;
    case '(':
        return 3;
    case ')':
        return 4;
    case '$':
        return 5;
    case 'E':
        return 6;
    case 'T':
        return 7;
    case 'F':
        return 8;
    default:
        return -1;
    }
}
void makeprod()
{
    prods[0].lhs='S';
    strcpy(prods[0].rhs,"E");

    prods[1].lhs='E';
    strcpy(prods[1].rhs,"E+T");


    prods[2].lhs='E';
    strcpy(prods[2].rhs,"T");


    prods[3].lhs='T';
    strcpy(prods[3].rhs,"T*F");

    prods[4].lhs='T';
    strcpy(prods[4].rhs,"F");

    prods[5].lhs='F';
    strcpy(prods[5].rhs,"(E)");

    prods[6].lhs='F';
    strcpy(prods[6].rhs,"i");


}
void maketable()
{
    /*for(int i=0;i<6;i++)arr[0][i].goto_check=false;
    arr[0][0].ch='i';
    arr[0][1].ch='+';
    arr[0][2].ch='*';
    arr[0][3].ch='(';
    arr[0][4].ch=')';
    arr[0][5].ch='$';
    for(int i=6;i<9;i++)arr[0][i].goto_check=true;
    arr[0][6].ch='E';
    arr[0][7].ch='T';
    arr[0][8].ch='F';
*/

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<9;j++)
        {
            arr[i][j].ch='-';
            arr[i][j].x=-1;
        }
    }

    for(int i=0;i<15;i++)
    {

        for(int j=0;j<6;j++)
            arr[i][j].goto_check=false;
        for(int j=6;j<9;j++)
            arr[i][j].goto_check=true;

    }
    arr[0][0].ch='s';
    arr[0][0].x=5;

    arr[0][hasher('(')].ch='s';
    arr[0][hasher('(')].x=4;

    arr[0][hasher('E')].x=1;
    arr[0][hasher('T')].x=2;
    arr[0][hasher('F')].x=3;

    arr[1][hasher('+')].ch='s';
    arr[1][hasher('+')].x=6;

    arr[1][hasher('$')].ch='r';
    arr[1][hasher('$')].x=0;

    arr[2][hasher('+')].ch='r';
    arr[2][hasher('+')].x=2;

    arr[2][hasher('*')].ch='s';
    arr[2][hasher('*')].x=7;

    arr[2][hasher(')')].ch='r';
    arr[2][hasher(')')].x=2;

    arr[2][hasher('$')].ch='r';
    arr[2][hasher('$')].x=2;

    arr[3][hasher('+')].ch='r';
    arr[3][hasher('+')].x=4;

    arr[3][hasher('*')].ch='r';
    arr[3][hasher('*')].x=4;

    arr[3][hasher(')')].ch='r';
    arr[3][hasher(')')].x=4;

    arr[3][hasher('$')].ch='r';
    arr[3][hasher('$')].x=4;

    arr[4][hasher('i')].ch='s';
    arr[4][hasher('i')].x=5;

    arr[4][hasher('(')].ch='s';
    arr[4][hasher('(')].x=4;

    arr[4][hasher('E')].x=8;
    arr[4][hasher('T')].x=2;
    arr[4][hasher('F')].x=3;

    arr[5][hasher('+')].ch='r';
    arr[5][hasher('+')].x=6;

    arr[5][hasher('*')].ch='r';
    arr[5][hasher('*')].x=6;

    arr[5][hasher(')')].ch='r';
    arr[5][hasher(')')].x=6;

    arr[5][hasher('$')].ch='r';
    arr[5][hasher('$')].x=6;

    arr[6][hasher('i')].ch='s';
    arr[6][hasher('i')].x=5;

    arr[6][hasher('(')].ch='s';
    arr[6][hasher('(')].x=4;

    //arr[6][hasher('E')].x=4;
    arr[6][hasher('T')].x=9;
    arr[6][hasher('F')].x=3;

    arr[7][hasher('i')].ch='s';
    arr[7][hasher('i')].x=5;

    arr[7][hasher('(')].ch='s';
    arr[7][hasher('(')].x=4;
    arr[7][hasher('F')].x=10;

    arr[8][hasher('+')].ch='s';
    arr[8][hasher('+')].x=6;

    arr[8][hasher(')')].ch='s';
    arr[8][hasher(')')].x=11;

    arr[9][hasher('+')].ch='r';
    arr[9][hasher('+')].x=1;

    arr[9][hasher('*')].ch='s';
    arr[9][hasher('*')].x=7;

    arr[9][hasher(')')].ch='r';
    arr[9][hasher(')')].x=1;

    arr[9][hasher('$')].ch='r';
    arr[9][hasher('$')].x=1;

    arr[10][hasher('+')].ch='r';
    arr[10][hasher('+')].x=3;


    arr[10][hasher('*')].ch='r';
    arr[10][hasher('*')].x=3;


    arr[10][hasher(')')].ch='r';
    arr[10][hasher(')')].x=3;


    arr[10][hasher('$')].ch='r';
    arr[10][hasher('$')].x=3;

    arr[11][hasher('+')].ch='r';
    arr[11][hasher('+')].x=5;


    arr[11][hasher('*')].ch='r';
    arr[11][hasher('*')].x=5;

    arr[11][hasher(')')].ch='r';
    arr[11][hasher(')')].x=5;

    arr[11][hasher('$')].ch='r';
    arr[11][hasher('$')].x=5;

    for(int i=0;i<12;i++)
    {

        for(int j=0;j<9;j++)
            printf("    %c%d   ",arr[i][j].ch,arr[i][j].x);
        printf("\n");
    }
}
void print(slr stack[],int top)
{
    for(int i=top;i>=0;i--)
    {
        printf("-----\n");
        if(stack[i].x==-1)
            printf("%c\n",stack[i].ch);
        else if(stack[i].ch=='-')
            printf("%d\n",stack[i].x);
            else
                printf("I fucked up\n");
    }
}
void parseslr(char str[])
{

    slr stack[100];
    for(int i=0;i<100;i++)
    {
        stack[i].ch='-';
        stack[i].x=-1;
    }
    stack[0].ch='$';
    stack[1].x=0;
    int iter=0;
    int top=1;
    while(iter<strlen(str))
    {
        printf("\n\ntop=%d , iter=%d\n",top,iter);
        print(stack,top);
        if(stack[top].x!=-1)
        {
            int row=stack[top].x;
            //we check 3 cases if shift or reduce or goto
            int col=hasher(str[iter]);
            printf("Stack top =%d and %c  \n",stack[top].x,stack[top].ch );
            printf("element considered is %c %d\n ",arr[row][col].ch,arr[row][col].x);
            if(arr[row][col].ch=='-' && arr[row][col].x==-1)
            {
                printf("Invalid ");
                return;
            }
            if(arr[row][col].goto_check==false)
            {
                if(arr[row][col].ch=='s')
                {
                    stack[++top].ch=str[iter++];
                    stack[++top].x=arr[row][col].x;
                }
                else if(arr[row][col].ch=='r')
                {
                    if(arr[row][col].x==0)
                    {

                        printf("accepted ");
                        return ;
                    }
                        int poplen=strlen(prods[arr[row][col].x].rhs)*2;
                        for(int i=top;i>top-poplen;i--)
                        {
                            stack[i].ch='-';
                            stack[i].x=-1;
                        }
                        top=top-poplen;
                        int lower=top;
                        stack[++top].ch=prods[arr[row][col].x].lhs;
                       // printf("Special check for stakc\n");
                        //print(stack,top);
                        printf("row =%d column=%d and val=%d\n",stack[lower].x,hasher(stack[top].ch),arr[stack[lower].x][hasher(stack[top].ch)].x);
                        int val=arr[stack[lower].x][hasher(stack[top].ch)].x;;
                        stack[++top].x=val;
                        print(stack,top);
                }

                }
            }
            else
            {
                //i dont think it will even come here bruh ena poda bruh moment da
                printf("Invalid state \n");
                return;

            }
        }

}
int main()
{
    char str[10];
    makeprod();
    maketable();
    printf("String to be processed along with endmarker:");
    gets(str);
    parseslr(str);
    return 0;
}
