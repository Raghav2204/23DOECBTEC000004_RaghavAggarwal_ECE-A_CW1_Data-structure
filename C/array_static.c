#include<stdio.h>
void search(int arr[],int n)
{
    int num;
    printf("enter the element to be searched:\n");
    scanf("%d",&num);
    for(int i=0; i<n;i++)
    {
        if(num==arr[i])
        {
            printf("element found at position %d\n",i+1);
        }
        else
        {
          continue;
          printf("element not found");
        }
    }
}
void insert(int arr[],int n)
{
    int pos,i,insert;
    int new_arr[n+1];
    printf("enter the element to be inserted: ");
    scanf("%d",&insert);
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos>n)
    {
        printf("element can't be inserted");
    }
    for(i=0;i<pos;i++)
    {
        new_arr[i]=arr[i];
    }
    new_arr[pos]=insert;
    for (i = pos; i<n;i++)
    {
        new_arr[i+1] =arr[i];  
    }
    printf("Array elements after insertion\n");  
    for (i = 0; i <= n; i++) 
    {
        printf("%d\t", new_arr[i]);  
    }
    printf("\n");
}
void delete(int arr[],int n)
{
    int del,i,pos;
    printf("enter the element to be deleted:");
    scanf("%d",&del);
    for(i=0;i<n;i++)
    {
        if(del==arr[i])
        {
            pos=i+1;
            if(pos>=n+1)
            {
                printf("deletion not possible");
            }
            else
            {
                for(i=pos-1;i<n-1;i++)
                {
                    arr[i]=arr[i+1];
                    printf("resultant array is:\n");
                    for(i=0;i<n-1;i++)
                    {
                        printf("%d\n",arr[i]);
                    }
                }
            }
          }
    }
}
void reverse(int arr[],int n)
{
    printf("reversed array is:\n");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d\t",arr[i]);
    }
}
void update(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i%2==0)
        {
            arr[i]*=2;
        }
        else
        {
            arr[i]+=5;
        }    
    }
    printf("array after updation is:\n");
    for (i=0;i<n;i++)
    {
        printf("arr[%d]=%d\n",i,arr[i]);
    }
}
int main()
{
    int n;
    printf("enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n;i++){
      printf("enter the element at %d position:",i+1);
      scanf("%d",&arr[i]);
    }
    n=sizeof(arr)/sizeof(arr[0]);
    printf("array is:");
     for(int i=0; i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    int operations;
    do
    {
        printf("\n1: Array traversal");
        printf("\n2: Array Reversal");
        printf("\n3: Array Updation");
        printf("\n4: Element Insertion");
        printf("\n5: Element deletion");
        printf("\n6: EXIT\n");
        printf("enter the operation to be performed:");
        scanf("%d",&operations);
        switch(operations)
        {
            case 1: 
                search(arr,n);
                break;
            case 2:
                reverse(arr,n);
                break;
            case 3:
                update(arr,n);
                break;
            case 4:
                insert(arr,n); 
                break;
            case 5:
                delete(arr,n);
                break;
            case 6:
                default:
                printf("thank you!!"); 
        }
    }
    while(operations<6);
    return 0;
}