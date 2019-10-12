#include<stdio.h>
#include<stdlib.h>
int merge_link(float *t,int q, int r, int *link)
{
    int i,j,k;
    i=q;
    j=r;
    k=0;
    while(i!=0 && j!=0)
    {
        if(t[i] > t[j]){
            link[k] = i;
            k = i;
            i = link[i];
        }
        else{
            link[k] = j;
            k = j;
            j = link[j];
        }
        if(i == 0)
            link[k] = j;
        else
            link[k] = i;
    }
    return link[0];
}
int sort(float *t,int l,int h,int *link)
{
    int m,q,r;
    if ( l == h)
        return l;
    if (l < h)
    {
        m=(l+h)/2;
        q=sort(t,l,m,link);
        r=sort(t,m+1,h,link);
        return merge_link(t,q,r,link);
    }
}
float *knapsack(int *w, int n, int m, int *link)
{
    float *x;
    int i,u = m;
    x = (float *)calloc(n+1,sizeof(n+1));
    for(i = link[0];i!=0;i = link[i])
    {
        if(w[i] > u)
            break;
        x[i] = 1;
        u -= w[i];
    }
    if(i != 0)
        x[i] = (float) u/w[i];
    return x;
}
int main()
{
    int n, *w, *p, i, j, m, *link;
    float *t, *x, profit = 0.0;
    printf("Enter number of objects:");
    scanf("%d", &n);
    printf("Enter the capacity of Knapsack:");
    scanf("%d", &m);
    w = (int *)calloc(n+1, sizeof(int));
    p = (int *)calloc(n+1, sizeof(int));
    printf("Enter %d weights: ",n);
    for(i = 0; i < n; i++)
		scanf("%d",&w[i+1]);
    printf("Enter %d Profits:",n);
    for(i = 0; i < n; i++)
    	scanf("%d",&p[i+1]);
    t = (float *)calloc(n+1, sizeof(float));
    for(i = 0; i < n; i++)
    	t[i+1]= (float) p[i+1] / w[i+1];
    link = (int *)calloc(n+1,sizeof(int));
    sort(t,1,n,link);
    x = knapsack(w,n,m,link);
    for(i = link[0];i!=0;i= link[i])
        profit += p[i]*x[i];
    printf("Solution is:");
    for(i=0; i<n; i++)
        printf("%f",x[i+1]);
    printf("\n");
    printf("Profit : %f \n",profit);
    return 0;
}
