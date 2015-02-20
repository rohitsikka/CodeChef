#include<cstdio>
int main()
{
    freopen("temp.txt","r",stdin);
    int n,index;
    static int arr[1000010];
    int i,j;
    for(i=0;i<1000010;i++)
        arr[i]=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&index);
        arr[index]++;
    }
    for(i=0;i<1000010;i++)
        for(j=0;j<arr[i];j++)
            printf("%d\n",i);
    return 0;
}
