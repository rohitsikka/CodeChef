#include<iostream>
#include<cstdio>
using namespace std;
static int p1[100001],p2[100001];
int main()
{
    freopen("temp.txt","r",stdin);
    int t,n,a;
    bool flag;
    while(scanf("%d",&t)&&t)
    {
        flag=false;
        for(int i=1;i<=t;i++)
        {
            scanf("%d",&p1[i]);
            p2[p1[i]]=i;
        }
        for(int i=1;i<=t;i++)
            if(p1[i]!=p2[i])
                flag=true;
        if(flag)
            printf("not ambiguous\n");
        else
            printf("ambiguous\n");
    }
    return 0;
}
