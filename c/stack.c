#include<stdio.h>
#include <stdlib.h>

struct stack
{
  int size;
  int top;
  int *s;
};
void create(struct stack *st){
printf("enter size");
scanf("%d",&st->size);
st->top=-1;
st->s=(int *)malloc(st->size*sizeof(int));


}

void Dispaly(struct stack st)
{
    int i;
 
    for(i=st.top;i>=0;i--)
    printf("%d ",st.s[i]);
    printf("\n");
}
void push(struct stack *st, int x)
{
if(st->top==st->size-1)
printf("stack is full\n");
else
{
    st->top++;
    st->s[st->top]=x;

}
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
    printf("stack is underflow\n");
    else{
     x=st->s[st->top--];

  
}

  return x;

}
int peek(struct stack st,int index){
    int x=-1;
    if(st.top-index+1<0)
    printf("invalid");
    x=st.s[st.top-index+1];
    return x;
}
int isEmpty(struct stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}
int isFull(struct stack st)
{
    if(!isEmpty(st))
    return st.s[st.top];
    return -1;
}

int main()
{
struct stack st;
create(&st);
push(&st,10);
push(&st,20);
push(&st,30);
push(&st,40);
// printf("%d \n",pop(&st));
// printf("%d \n",pop(&st));
// printf("%d \n",pop(&st));
// printf("%d \n",pop(&st));
printf("%d \n",peek(st,2));
Dispaly(st);

    return 0;
}