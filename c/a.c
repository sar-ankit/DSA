#include<stdio.h>
#include<stdlib.h>

struct Array
{
  int A[10];
  int size;
  int length;

};

void Display(struct Array arr)
{
int i;
 printf("\nElements are\n");
for(i=0;i<arr.length;i++)
printf("%d ",arr.A[i]);

}



void Append(struct Array *arr,int x)
{
if(arr->length<arr->size)
arr->A[arr->length++]=x;
}
void Insert(struct Array *arr,int index,int x)
{
int i;
if(index>=0 && index <=arr->length)
{
  for(i=arr->length;i>index;i--)
  arr->A[i]=arr->A[i-1];
  arr->length++;
}

}
int Delete(struct Array *arr,int index)
{
int x=0;
int i;
if(index>=0 &&index<arr->length)
{
  x=arr->A[index];
  for(i=index;i<arr->length-1;i++)
  arr->A[i]=arr->A[i+1];
  arr->length--;
}

  return 0;
}
void swap(int *x,int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
int Linearsearch(struct Array *arr,int key)
{
int i;
for(i=0;i<arr->length;i++)
{
  if(key==arr->A[i])
  {
swap(&arr->A[i],&arr->A[0]);


  return i;
  }
}
return -1;

}
//Binary search (iterative version)
int Binarysearch(struct Array arr,int key)
{
  int l,mid,h;
  l=0;
  h=arr.length-1;
while(l<=h){
mid=(l+h)/2;
if(key==arr.A[mid])
return mid;
else if(key<arr.A[mid])
h=mid-1;
else
l=mid+1;

}


  return -1;

  
}
//Binary search (by recursive version version)


int RBinarysearch(int a[],int l,int h,int key)
{
int mid;
if (l<=h)
{
  mid=(l+h)/2;
  if(key==a[mid]) 
  return mid;
  else if(key<a[mid])
  return RBinarysearch(a,l,mid-1,key);
  else
  return RBinarysearch(a,mid+1,h,key);
}



  return -1;
}
int Get(struct Array arr,int index)
{
  if(index>=0 && index<arr.length)
  return arr.A[index];

  return -1;
}
void Set(struct Array *arr,int index,int x)
{
  if(index>=0 && index<arr->length)
  arr->A[index]=x;
}

int max(struct Array arr)
{
  int max=arr.A[0];
  int i;
  for(i=1;i<arr.length;i++)
  {
    if(arr.A[i]>max)
    max=arr.A[i];

  }
  return max;
}

int min(struct Array arr)
{
  int min=arr.A[0];
  int i;
  for(i=1;i<arr.length;i++)
  {
    if(arr.A[i]<min)
    min=arr.A[i];

  }
  return min;
}
int Sum(struct Array arr)
{
  int s=0;
  int i;
  for(i=0;i<arr.length;i++)
  s+=arr.A[i];
  return s;
}
float Avg(struct Array arr)
{
  return (float)Sum(arr)/arr.length;
}
void Reverse (struct Array *arr)
{
  int *B;
  int i,j;

  B=(int *)malloc (arr->length*sizeof(int));
  for(i-arr->length-1,j=0;i>=0;i--,i++)
  B[j]=arr->A[i];
  for(i=0;i>arr->length;i++)
  arr->A[i]=B[i];
}
void Reverse2(struct Array*arr)
{
  int i,j;
  for(i=0,j=arr->length-1;i<j;i++,j--)
  {swap(&arr->A[i],&arr->A[j]);
  }
}
void Insertsort(struct Array *arr,int x){
  int i=arr->length-1;
if(arr->length==arr->size)
return;
while(i>=0 && arr->A[i]>x)
{

  arr->A[i+1]=arr->A[i];
  i--;
}

arr->A[i+1]=x;
arr->length++;
}
int issorted(struct Array arr)
{
  int i;
  for(i=0;i<arr.length-1;i++)
  {
    if(arr.A[i]>arr.A[i+1])
    return 1;
  }
}
void Rearrange(struct Array *arr)
{
int i,j;
i=0;
j=arr->length-1;
while(i<j)
{
  while(arr->A[i]<0)
  i++;
}

while(arr->A[i]>=0)j--;
if(i<j)swap(&arr->A[i],&arr->A[j]);

}
struct array *Merge(struct Array *arr1, struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;
 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
 while(i<arr1->length&& j<arr2->length)
 {
if(arr1->A[i]<arr2->A[j])
arr3->A[k++]=arr1->A[i++];
else
arr3->A[k++]=arr2->A[j++];
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 arr3->length=arr1->length+arr2->length;
 arr3->size=10;
 return arr3;
}
struct Array *Unino(struct Array *arr1, struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;
 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
 while(i<arr1->length && j<arr2->length)
 {
if(arr1->A[i]<arr2->A[j])
arr3->A[k++]=arr1->A[i++];
else if(arr2->A[j]<arr1->A[i])
arr3->A[k++]=arr2->A[j++];
else
{
arr3->A[k++]=arr1->A[i++];
j++;
}
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 
 arr3->A[k++]=arr2->A[j];
 arr3->length=k;
 arr3->size=10;
 return arr3;
}
struct Array*intersection(struct Array *arr1, struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;
 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
 while(i<arr1->length && j<arr2->length)
 {
if(arr1->A[i]<arr2->A[j])
i++;
else if(arr2->A[j]<arr1->A[i])
j++;
else if(arr1->A[i]==arr2->A[j])
{
arr3->A[k++]=arr1->A[i++];
}
 }

 arr3->length=k;
 arr3->size=10;
 return arr3;
}
struct Array *Difference(struct Array *arr1, struct Array *arr2)
{
  int i,j,k;
  i=j=k=0;
 struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
 while(i<arr1->length && j<arr2->length)
 {
if(arr1->A[i]<arr2->A[j])
arr3->A[k++]=arr1->A[i++];
else if(arr2->A[j]<arr1->A[i])
j++;
else
{
i++;
j++;
}
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];

 arr3->length=k;
 arr3->size=10;
 return arr3;
}


int main()
{
   struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};
      struct Array *arr3;
     
// printf("%d\n",Get(arr,3));
// Set(&arr,2,15);
// printf("%d\n",max(arr));
//  printf("%d\n",min(arr));
//  printf("%d\n",Sum(arr));
//  printf("%f\n",Avg(arr));
// Reverse2(&arr);

// Insertsort(&arr,1);
//  printf("%f\n",issorted(arr));
// Rearrange(&arr);
      //  arr3=Unino(&arr1,&arr2);
        //  arr3=intersection(&arr1,&arr2);
        //   arr3=Difference(&arr1,&arr2);
  // Display(*arr3);
  return 0;
}