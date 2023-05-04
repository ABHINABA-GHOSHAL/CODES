#include<stdio.h>
#include<stdlib.h>
int find_remove_duplicate(int *p,int n,int *result)
{
    int *flag=(int *)calloc(n,sizeof(int));

    printf("the duplicate elements are:\n");
    int Count=0;
    int k=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        if(flag[i]!=1)
        {
            for(int j=0;j<n;j++)
            {
                if(p[i]==p[j])
                {
                    c=c+1;
                    flag[j]=1;
                }
            }
        }
        if(c>1)
        {
            Count=Count+1;
            printf("%d\t",p[i]);
        }
        else if(c==1)
        {
            result[k]=p[i];
            k++;
        }
    }
    if(Count==0){
        printf("NIL");
    }
    return k;


}

int main()
{
    int n;
    printf("enter number of elements of array:");
    scanf("%d",&n);
    int *arr=(int *)calloc(n,sizeof(int));
    printf("enter elements of the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);

    }
    int *res=(int *)calloc(n,sizeof(int));
    int Size=find_remove_duplicate(arr,n,res);
    arr=res;
    printf("\nelements of the array after removing duplicate elements are:\n");
    for(int i=0;i<Size;i++)
    {
        printf("%d\t",arr[i]);

    }

}