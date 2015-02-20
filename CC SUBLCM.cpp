#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<algorithm>
#include<typeinfo>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define setBit(n,i) (n|=(1<<i))
#define clearBit(n,i) (n&=(~(1<<i)))
#define checkBit(n,i) (n&(1<<i))

#define s(n) scanf("%d",&n)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define all(a) (a).begin(),(a).end()
#define gc getchar

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
   freopen("temp.txt","r",stdin);
   static vi factors[1000010];
   static int DP[1000010];
   static int arr;
   static int prev[1000010];
   int u,v,x,ans;
  fora(i,2,1000001)
      if(factors[i].size()==0)
         for(int j=i;j<1000001;j+=i)
            factors[j].pb(i);
   int t,n;
   scanf("%d\n",&t);
   while(t--)
   {
      memset(prev,-1,sizeof(prev));
      scanf("%d\n",&n);
      ans=-1;
      fora(i,0,n)
      {
         x=-1;
         scanf("%d",&arr);
         u=arr;
         fora(j,0,factors[u].size())
         {
            v=factors[u][j];
            if(prev[v]!=-1)   x=max(x,prev[v]);
            prev[v]=i;
         }
         if(i)
         {
            DP[i]=min(DP[i-1]+1,i-x);
            ans=max(ans,DP[i]);
         }
         else
            DP[i]=1;
      }
      if(ans==1)  ans=-1;
      printf("%d\n",ans);
   }
   return 0;
}
