#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int t = *a;
        *a = *b;
        *b = t;
}
int partition(int *a, int l, int h){
    int pivot,i,j;
    pivot = a[l];
    i = l+1;
    j = h;
    while(i<=j){
        if(a[i] > pivot && a[j] < pivot)
            swap(&a[i],&a[j]);
        if(a[i] < pivot)
            i++;
        if(a[j] > pivot)
            j--;
    }
    swap(&a[l],&a[j]);
    return j;
}
int ksmallest(int *a,int l,int h,int k){
    int pi;
    if(l<h){
        pi = partition(a,l,h);
        if(pi == k-1)
            printf("The %d th smallest element is %d\n",k,a[pi]);
        else if(pi < k-1)
            ksmallest(a, pi+1, h, k);
        else
            ksmallest(a, l, pi-1, k);
    }
}
int main()
{
    int *a,n,i,k;
    printf("Enter size of array:");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d",a+i);
    printf("Enter the value of k:");
    scanf("%d",&k);
    ksmallest(a,0,n-1,k);
    return 0;
}
