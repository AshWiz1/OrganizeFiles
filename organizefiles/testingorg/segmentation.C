#include<stdio.h>
void menu(){
    printf("[1]:Load segments\n");
    printf("[2]:Display main memory\n");
    printf("[3]:segments Display\n");
    printf("[4]:Remove segments\n");
    printf("[5]:Quit\n");
}
typedef struct Segment{
    int n;
    int arr[10];
}Segment;
int totpg=64;
int mem[64]={0};
Segment segment[10];

int nextAvailable(int id){
    int i;
    for(i=0;i<totpg;i++){
        if(mem[i]==0){
            mem[i]=id;
            return i;
        }
    }
    return -1;
}
void loadDisplay(){
    int temp;
    printf("Enter the id of segment(0-9)\n");
    scanf("%d",&temp);
    int temp1;
    printf("Enter the size of segment\n");
    scanf("%d",&temp1);
    segment[temp].n=temp1;
    int i;
    int temp2;
    for(i=0;i<temp1;i++){
        temp2=nextAvailable(temp);
        if(temp2!=-1)
            segment[temp].arr[i]=temp2;
        else
            printf("The segment cant be allocated no sufficient memory\n");
    }
}
void displayMainMemory(){
    int i;
    for(i=0;i<totpg;i++){
        if(i%4==0)
            printf("\n");
        printf("%d ",mem[i]);
    }
    printf("\n");
}
void segmentDisplay(){
    int n;
    printf("Enter the segment id\n");
    scanf("%d",&n);
    printf("The segment id is %d\n",n);
    printf("The size of segment is %d\n",segment[n].n);
    int i;
    printf("The memory allocation is\n");
    for(i=0;i<segment[n].n;i++){
        printf("%d ",segment[n].arr[i]);
    }
    printf("\n");
}
void removesegment(){
    int n;
    printf("Enter the id of the segment\n");
    scanf("%d",&n);
    int i;
    for(i=0;i<segment[n].n;i++){
        mem[segment[n].arr[i]]=0;
    }
}
int main(){
    menu();
    int n;
    while(1){
        printf("Enter the option\n");
        scanf("%d",&n);
        switch(n){
        case 1:
            loadDisplay();
            break;
        case 2:
            displayMainMemory();
            break;
        case 3:
            segmentDisplay();
            break;
        case 4:
            removesegment();
            break;
        case 5:
            break;
        }
    }
}
