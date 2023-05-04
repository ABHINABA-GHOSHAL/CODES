#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int **matrix(int m,int n)
{
    int **p=(int**)calloc(m,sizeof(int*));
    for(int i=0; i<m; i++)
    {
        p[i]=(int*)calloc(n,sizeof(int));
    }
    return p;
}
void subject_marks(int *p)
{
    int lowest = 0, highest = 100;
    for (int i = 0; i < 4; i++)
    {
        p[i] = (rand() % (highest - lowest + 1)) + lowest;
    }

}

void display(int **p,int m,int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
int maths(int **p,int m,int n)
{
    int c=0;
    for(int i=0; i<m; i++)
    {
        if(p[i][0]>=90)
        {
            c=c+1;
        }
    }
    return c;

}
int highest(int **p,int m,char subject[10])
{
    int mx;
    if(strcmp(subject,"english")==0)
    {
        mx=p[0][3];
        for(int i=1; i<m; i++)
        {
            if(p[i][2]>mx)
            {
                mx=p[i][2];
            }
        }
        return mx;


    }
    if(strcmp(subject,"hindi")==0)
    {
        int mx=p[0][3];
        for(int i=1; i<m; i++)
        {
            if(p[i][3]>mx)
            {
                mx=p[i][3];

            }
        }
        return mx;


    }

}
int lowest(int **p,int m,char subject[20])
{
    int mn;
    if(strcmp(subject,"english")==0)
    {
        mn=p[0][2];
        for(int i=1; i<m; i++)
        {
            if(p[i][2]<mn)
            {
                mn=p[i][2];
            }
        }
        return mn;


    }
    if(strcmp(subject,"hindi")==0)
    {
        int mn=p[0][3];
        for(int i=0; i<m; i++)
        {
            if(p[i][3]<mn)
            {
                mn=p[i][3];

            }
        }
        return mn;


    }

}
int fail(int **p,int stud_no)
{
    int s=0;
    for(int i=0; i<stud_no; i++)
    {
        int c=0;
        for(int j=0; j<4; j++)
        {
            if(p[i][j]<=32)
            {

                c=c+1;
            }

        }
        if(c==4)
        {
            s=s+1;
        }
    }
    return s;
}
float avg(int **p,int stud_no)
{
    float s=0;
    for(int i=0; i<stud_no; i++)
    {
        for(int j=0; j<4; j++)
        {
            s=s+p[i][j];

        }

    }
    s=s/200;
    return s;

}
float sub_avg(int **p,int m,char subject[20])
{
    float s=0;
    if(strcmp(subject,"maths")==0)
    {
        for(int i=0; i<m; i++)
        {
            s=s+p[i][0];
        }
        return s/50;


    }
    if(strcmp(subject,"science")==0)
    {

        for(int i=0; i<m; i++)
        {
            s=s+p[i][1];
        }
        return s/50;


    }
    if(strcmp(subject,"english")==0)
    {

        for(int i=0; i<m; i++)
        {
            s=s+p[i][2];
        }
        return s/50;


    }
    if(strcmp(subject,"hindi")==0)
    {

        for(int i=0; i<m; i++)
        {
            s=s+p[i][3];
        }
        return s/50;


    }


}
float percent(int *p)
{
    float s=0.0;
    for(int i=0; i<4; i++)
    {
        s=s+p[i];
    }
    float per=(s*100.0)/400.0;
    return per;
}
int main()
{
    int stud_no=50,subject=4;
    int **marks=matrix(50,4);
    for(int i=0; i<stud_no; i++)
    {
        subject_marks(marks[i]);

    }
    display(marks,50,4);
    printf("%d students have got grade A in Maths\n",maths(marks,50,4));
    printf("highest marks in english is %d and lowest marks in english is %d\n",highest(marks,50,"english"),lowest(marks,50,"english"));
    printf("highest marks in hindi is %d and lowest marks in hindi is %d\n",highest(marks,50,"hindi"),lowest(marks,50,"hindi"));
    printf("No of students failed:%d\n",fail(marks,stud_no));
    printf("overall average:%f\n",avg(marks,stud_no));
    printf("average marks of maths: %f\n",sub_avg(marks,stud_no,"maths"));
    printf("average marks of science: %f\n",sub_avg(marks,stud_no,"science"));
    printf("average marks of english: %f\n",sub_avg(marks,stud_no,"english"));
    printf("average marks of hindi: %f\n",sub_avg(marks,stud_no,"hindi"));
    for(int i=0; i<stud_no; i++)
    {
        printf("percentage of student %d is: %f\n",i+1,percent(marks[i]));
    }

}