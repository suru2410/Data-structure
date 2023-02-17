#include<stdio.h>
int main()
{
    int c,f,l,m,n,s,array[100];
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("enter %d integer\n",n);
    for(c=0;c<n;c++)
        scanf("%d",&array[c]);
    printf("enter value to be find\n");
    scanf("%d",&s);
    f=0;l=n-1;
    m=(f+l)/2;
    while(f<=l){
        if(array[m]<s)
            f=m+1;
        else if(array[m]==s){
            printf("%d found at location%d.\n",s,m+1);
            break;
        }
        else
        l=m-1;
        m=(f+l)/2;
    }
    if(f>l)
        printf("not found!%d isn't present in the list.\n",s);
    return 0;
}
