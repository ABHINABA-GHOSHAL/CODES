#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int **matrix(int m, int n)
{
    int **p = (int **)calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        p[i] = (int *)calloc(n, sizeof(int));
    }
    return p;
}
void display(int **p, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}
void deviation(int **original, int **second, int m, int n)
{
    int **dev = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dev[i][j] = original[i][j] - second[i][j];
        }
    }
    printf("the deviation is:\n");
    display(dev, m, n);
}
int **cond_1(int **p, int m, int n)
{
    int **temp = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = p[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp[i][j] == 0)
            {
                temp[i][j] = rand() % (5) + 1;
            }
        }
    }
    return temp;
}
int **cond_2(int **p, int m, int n)
{
    int **temp = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = p[i][j];
        }
    }
    double s;
    int c;
    for (int i = 0; i < m; i++)
    {
        s = 0.0;
        c = 0;
        for (int j = 0; j < n; j++)
        {

            if (temp[i][j] != 0)
            {
                s = s + temp[i][j];
                c = c + 1;
            }
        }
        int avg = round(s / c);
        for (int k = 0; k < n; k++)
        {
            if (temp[i][k] == 0)
            {
                temp[i][k] = avg;
            }
        }
    }
    return temp;
}
int **cond_3(int **p, int m, int n)
{
    int **temp = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = p[i][j];
        }
    }
    double s;
    int c;
    for (int i = 0; i < n; i++)
    {
        s = 0.0;
        c = 0;
        for (int j = 0; j < m; j++)
        {

            if (temp[j][i] != 0)
            {
                s = s + temp[j][i];
                c = c + 1;
            }
        }
        int avg = round(s / c);
        for (int k = 0; k < m; k++)
        {
            if (temp[k][i] == 0)
            {
                temp[k][i] = avg;
            }
        }
    }
    return temp;
}
int **cond_4(int **p, int m, int n)
{
    int **temp = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = p[i][j];
        }
    }
    double s1;
    int c1, c2;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s1 = 0;
            c1 = 0;
            c2 = 0;
            if (p[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if (p[i][k] != 0)
                    {
                        s1 = s1 + p[i][k];
                        c1 = c1 + 1;
                    }
                }
                for (int l = 0; l < m; l++)
                {
                    if (p[l][j] != 0)
                    {
                        s1 = s1 + p[l][j];
                        c2 = c2 + 1;
                    }
                }
                int avg = round(s1 / (c1 + c2));
                temp[i][j] = avg;
            }
        }
    }
    return temp;
}
int main()
{
    int m, n;
    printf("enter number of users and movies respectively:");
    scanf("%d%d", &m, &n);
    int **original = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            original[i][j] = rand() % (5) + 1;
        }
    }
    printf("original matrix:\n");
    display(original, m, n);
    int **second = matrix(m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            second[i][j] = rand() % (6);
        }
    }
    printf("second matrix:\n");
    display(second, m, n);
    int **fill_1 = cond_1(second, m, n);
    printf("matrix after cond1:\n");
    display(fill_1, m, n);
    deviation(original, fill_1, m, n);
    int **fill_2 = cond_2(second, m, n);
    printf("matrix after cond2:\n");
    display(fill_2, m, n);
    deviation(original, fill_2, m, n);
    int **fill_3 = cond_3(second, m, n);
    printf("matrix after cond3:\n");
    display(fill_3, m, n);
    deviation(original, fill_3, m, n);
    int **fill_4 = cond_4(second, m, n);
    printf("matrix after cond4:\n");
    display(fill_4, m, n);
    deviation(original, fill_4, m, n);
}