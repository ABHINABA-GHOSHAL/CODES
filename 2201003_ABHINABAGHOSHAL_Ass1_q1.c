#include<stdio.h>
#include<stdlib.h>
int **matrix(int m,int n)
{
    int **p=(int**)calloc(m,sizeof(int*));
    for(int i=0;i<m;i++)
    {
        p[i]=(int*)calloc(n,sizeof(int));
    }
    return p;
}
void create(int **p,int m,int n)
{
    printf("enter values for matrix:");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
}
void display(int **p,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
int trace(int **p,int m,int n)
{

    int s=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j){
                s=s+p[i][j];
            }
        }
    }
    return s;
}
int **transpose(int ** p,int m,int n)
{
    int **trans=matrix(m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            trans[i][j]=p[j][i];
        }
    }
    return trans;

}
int **multiply(int **p,int **q,int m,int n)
{
    int **result=matrix(m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int s=0;
            for(int k=0;k<n;k++)
            {
                s=s+(p[i][k]*q[k][j]);


            }
            result[i][j]=s;
        }
    }
    return result;
}
void singular(int **p)
{
    int det=(p[0][0]*(p[1][1]*p[2][2]-p[2][1]*p[1][2]))-(p[0][1]*(p[1][0]*p[2][2]-p[2][0]*p[1][2]))+(p[0][2]*(p[1][0]*p[2][1]-p[2][0]*p[1][1]));
    if(det==0)
    {
        printf("it is a singular matrix");

    }
    else{
         printf("it is a singular matrix");
    }

}

int main()
{
    int **A=matrix(3,3);
    int **B=matrix(3,3);
    create(A,3,3);
    printf("The matrix A is:\n");
    display(A,3,3);
    create(B,3,3);
    printf("The matrix B is:\n");
    display(B,3,3);
    printf("the trace of A is: %d\n",trace(A,3,3));
    printf("the trace of B is: %d\n",trace(B,3,3));
    int **transpose_A=transpose(A,3,3);
    int **transpose_B=transpose(B,3,3);
    printf("The Transpose of matrix A is:\n");
    display(transpose_A,3,3);
    printf("The Transpose of matrix b is:\n");
    display(transpose_B,3,3);
    int **mul=multiply(transpose_A,B,3,3);
    printf("the result of multiplication is:\n");
    display(mul,3,3);
    singular(mul);
}