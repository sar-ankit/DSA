#include<stdio.h>
#define size 10

int hash(int key)
{
return key%size;
}
int probe(int H[],int key){
    int index=hash(key);
    int i=0;
    while(H[(index+1*i)%size]!=0)
    i++;
    return(index+1*i)%size;
}
void Insert(int H[],int key){
    int index=hash(key);
     if(H[index]!=0)
     index = probe(H,key);
     H[index]=key; 
}
int search(int H[],int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+1*i)%size]!=key)
    i++;
    return(index+i)%size;

}

int main(){

int HT[10]={0};
Insert(HT,12);
Insert(HT,25);
Insert(HT,35);
Insert(HT,26);
printf("\n key found at %d\n",search(HT,35));
    return 0;
}