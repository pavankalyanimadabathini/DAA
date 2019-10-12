#include<stdio.h>
#include<stdlib.h>
void minMax(int *a,int l,int h,int *min,int *max)
{
    int m,min1,max1;
    if(l == h){
        *min = a[l];
        *max = a[h];
    }
    else if(l+1 == h){
        if(a[l]<a[h]){
            *min = a[l];
            *max = a[h];
        }
        else{
            *min = a[h];
            *max = a[l];
        }
    }
    else{
        m=(l+h)/2;
        minMax(a,l,m,min,max);
        minMax(a,m+1,h,&min1,&max1);
        if(min1 < *min)
            *min = min1;
        if(max1 > *max)
            *max = max1;
    }
}
int main()
{
    int *a,n,i,min,max;
    printf("enter size of array:");
    scanf("%d",&n);
    a = (int *)calloc(n+1,sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", a+i);
    minMax(a,0,n-1,&min,&max);
    printf("Minimum = %d \n", min);
    printf("Maximum = %d \n", max);
    return 0;
}
