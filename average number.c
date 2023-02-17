#include<stdio.h>
int main()
{
    int i,n,sum=0,numbers;
    float average;
    printf("enter the numbers of term\n");
    scanf("%d",&n);
    printf("\n enter the number\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&numbers);
        sum=sum+numbers;
    }
    average=sum/n;
    printf("\n Average number of the %d Numbers=%2f\n",n,average);
    return 0;
}
