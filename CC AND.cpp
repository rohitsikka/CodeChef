#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int n,num,bitCount[30];
    scanf("%d",&n);
    memset(bitCount,0,sizeof(bitCount));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        for(int i=0;i<30&&num;i++,num>>=1)
            if(num&1)
                bitCount[i]++;
    }
    long long int ans=0;
    for(int i=0;i<30;i++)
        ans=ans+((long long)(1<<i)*(long long)bitCount[i]*(long long)(bitCount[i]-1));
    printf("%lld\n",ans/2);
    return 0;
}
