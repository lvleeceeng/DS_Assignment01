#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<cstdio>
void Insert(int*,int);
void view(int*,int);
void del(int*,int);
void sortA(int*,int);
void sortD(int*,int);
void search(int*,int);
void loc(int*,int);
void menu(void);
void clr(void);
int main()
{
    int n,i,item,k,*arr,opt,D;
    printf("Enter the size of array:");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    if(arr==0)
    {
        printf("ERROR:Unable to allocate memory\n");
        exit(0);
    }
    printf("Enter the elements of array:");
    for(i=0; i<n; i++)
    {
        scanf("%d",(arr+i));
    }
    menu();
    while(scanf("%d",&opt))
    {
    switch(opt)
    {
    case 0:
        return 0;
        break;
    case 1:
        view(arr,n);
        break;

    case 2:
        Insert(arr,n);
        break;
    case 3:
          search(arr,n);
          break;
    case 4:
          del(arr,n);
          break;
    case 5:
          sortA(arr,n);
          break;
    case 6:
          sortD(arr,n);
          break;
    case 7:
          loc(arr,n);
          break;
    default:
        printf("INVALID:TRY AGAIN\n");
        break;
    }
    }
    return 0;
//getch();
}

void view(int *arr,int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ",*(arr+i));
    }
    clr();
}

void Insert(int *arr,int n)
{
    int item,k,j;
    printf("Enter the item to be added\n");
    scanf("%d",&item);
    printf("Enter the location you want to add the item\n");
    scanf("%d",&k);
    j=n;
    while(j>=k)
    {
       *(arr+j+1)= *(arr + j);
        j--;
    }
    *(arr+k)=item;
    n=n+1;
    printf("Array after inserting element:\n");
    for(j=0; j<n; j++)
    {
        printf("%d\n",*(arr+j));
    }
    clr();
}
void del(int *arr,int n)
{
    int j,k;
    //printf("Enter the item to be deleted\n");
    //scanf("%d",&item);
    printf("Enter the location of item to be deleted\n");
    scanf("%d",&k);
    //item =  *(arr+k);
    if(k >= n+1)
        printf("Deletion not possible\n");
    else
    {
        for(j=k-1;j<n-1;j++)
        *(arr+j) = *(arr+j+1);
        printf("Resulting array:\n");
        for(j=0;j<n-1;j++)
        printf("%d\n",*(arr+j));
    }
    clr();
}


void sortA(int *arr,int n)
{
    int i,j=0,t;
    for(i=n;i>1;i--)
    for(j=0;j<i-1;j++)
    if(*(arr+j) > *(arr+j+1))
    {
        //swapping adjacent elements

        t= *(arr+j+1);
        *(arr+j+1) = *(arr+j);
        *(arr+j) = t;
    }
    printf("Sorted array in ascending order:\n");
    for(j=0;j<n;j++)
    {
        printf("%d\n",*(arr+j));
    }
    clr();
}


void sortD(int *arr,int n)

{
    int i,j=0,t;
    for(i=n;i>1;i--)
    for(j=0;j<i-1;j++)
    if(*(arr+j) < *(arr+j+1))
    {
        //swapping adjacent elements

        t= *(arr+j+1);
        *(arr+j+1) = *(arr+j);
        *(arr+j) = t;
    }
    printf("Sorted array in descending order:\n");
    for(j=0;j<n;j++)
    {
        printf("%d\n",*(arr+j));
    }
    clr();
}


void search(int *arr,int n)
{
  int k,item,beg,end,mid;
  sortA(arr,n);
  printf("Enter the element to find:\n");
  scanf("%d",&item);
  beg=0;end=n-1;
  mid=((beg+end)/2);
  while(beg<=end)
  {
      if(*(arr+mid) < item)
      {
        beg=mid+1;
      }
      if(*(arr+mid) == item)
      {
          break;
      }
      if(*(arr+mid)>item)
      {
          end=mid-1;
      }
      mid=((beg+end)/2);
  }
  if(*(arr+mid) == item)
  {
      k=mid;
     printf("%d is found at location %d.\n",item,k);
     }
 else
     printf("%d is not found in the list.\n",item);
clr();
}

void loc(int *arr,int n)
{
    int k,index,lc,w,LB=1;
    printf("Enter the desired index number:\n");
    scanf("%d",&k);
    if(k>n)
    {
        printf("The index doesnot exist!!\n");
    }
    else
    {w=sizeof(int);
    lc=(int)*arr+w *(k-LB);
    printf("the adress of desired index is %d\n",lc);
}
clr();
}

void menu()
{
    printf("*****Choose an option*****\n");
    printf("0....Exit\n1....View all elements\n2....Insert new elements\n3....Search an element\n4....Delete an element\n5....Sort elements in ascending order\n6....Sort elements in descendingb order\n7....Find memory location of an element\n\n");
}

void clr()
{
    printf("Press any key to clear screen and get back to menu:\n");
    getch();
    system("cls");
    menu();
}
