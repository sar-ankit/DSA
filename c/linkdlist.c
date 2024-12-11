#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}
*first=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Dispaly(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data );
        p=p->next;
    }
}

void RDispaly(struct Node *p)
{
if (p!=NULL)
{
    
 RDispaly(p->next);
    printf("%d ",p->data);
   
}


}

int Count (struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;

    }
return 1;
}
int Rcount(struct Node *p)
{
    if(p!=NULL)
    return Rcount(p->next)+1;
    else 
    return 0;
}
int sum(struct Node *p)
{
       int sum=0;
    while(p!=NULL)
    {
      sum=sum+p->data;

        p=p->next;
    }
    return(sum);
}
int Rsum(struct Node *p)
{
    if(p==NULL)
    return 0;
    else
    return  Rsum(p->next)+p->data;
}

int max(struct Node *p)
{
    int max=-32768;
    while(p)
    {
if(p->data>max)

    max=p->data;
    p-p->next;


    }
    return max;
}
int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
    return -32768;
    x=Rmax(p->next);
    if(x>p->data)
    return x;
    else return p->data;
}
struct Node * Lsearch(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
        q->next=p->next;
        p->next=first;
        first=p;

        return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
struct Node *Rsearch(struct Node *p,int key)
{
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;
    return Rsearch(p->next,key);

}
void Insert(struct Node *p,int index,int x)
{
struct Node *t;
int i;
if(index < 0 || index > Count(p))
return;
t=(struct Node *)malloc(sizeof(struct Node));
t->data=x;

if(index==0)
{
    t->next=first;
    first=t;

}
else{
    for(i=0;i<index-1;i++)
    p=p->next;
    t->next=p->next;
    p->next=t;    
}
}
void sortedinsert(struct node *p,int x)
{
struct Node *t,*q=NULL;
t=(struct Node*)malloc(sizeof(struct Node));
t->data=x;
t->next=NULL;
if(first==NULL)

first=t;
else
{
    while(p && p->data<x)
    {
        q=p;
        p=p->next;
       

    }
    if(p==first)
    {
        t->next=first;
        first=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }
}

}
int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > count(p))
    return -1;
    if(index==1)
    {
        q=first;
        x-first->data;
        first=first->next;
        free (q);
        return x;
    }
    else{
for(i=0;i<index-1;i++)
{
    q=p;
    p=p->next;

}
q->next=p->next;
x=p->data;
free (p);
return x;


    }
}




int main()
{
    // struct Node *temp;
int A[]={10,20,30,40,50};
 create(A,5);
printf("fgfbfgbf %d", Delete(first,4));

//  sortedinsert(first,35);

//  Insert(first,0,10);
//   Insert(first,2,6);
// RDispaly(first);
// printf("length is %d", Rcount(first));
// printf("sim is %d\n ",Rsum(first));
// printf("max is %d\n",Rmax(first));
// temp=Lsearch(first,15);
// temp=Lsearch(first,8);
// if(temp)
// printf("key is found %d\n",temp->data);
// else
// printf ("key is not found");
Dispaly(first);
printf("\n\n");
    return 0;
}