#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int t,n,maximum,maxNum,num,arr[10010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(arr,0,sizeof(arr));
        maximum=0;
        maxNum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            arr[num]++;
            if(arr[num]>maximum)
            {
                maximum=arr[num];
                maxNum=num;
            }
            else if(arr[num]==maximum&&num<maxNum)
                maxNum=num;
        }
        printf("%d %d\n",maxNum,maximum);
    }
    return 0;
}
