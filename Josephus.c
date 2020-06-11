#include<stdio.h>

void josephus(int n, int m)
{
    int queue[n], index, times, j;
    for(index=0; index<n; index++)
    {
        queue[index] = index + 1;
    }
    index = 0;
    for(times=0; times<n; times++)
    {
        index = (index + m - 1)%(n - times);
        printf("%d\t", queue[index]);
        for(j=index; j<=n-times-2; j++)
        {
            queue[j] = queue[j+1];
        }
    }
}



int main()
{
    josephus(8, 4);
    return 0;
}

