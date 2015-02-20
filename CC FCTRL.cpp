#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("temp.txt","r",stdin);
    int t;
    long int n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        while(n)
        {
            ans+=(n/5);
            n/=5;
        }
        printf("%d\n",ans);
    }
    return 0;
}
