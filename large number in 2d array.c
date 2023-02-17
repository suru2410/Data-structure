#include<stdio.h>
int main()
{
    int a[100],max,size,c;
    printf("enter the number of element in array\n");
    scanf("%d",&size);
    printf("enter the %d integers\n",size);
    for(c=0;c<size;c++)
        scanf("%d",&a[c]);
    max=a[0];
    for(c=1;c<size;c++)
    {
        if(a[c]>max)
        {
            max=a[c];
        }
    }
    printf("maximum element is %d.\n",max);
}
