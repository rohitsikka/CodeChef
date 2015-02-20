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

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int gcd(int a,int b)
{
   int t;
   while(b)
   {
      t=a;
      a=b;
      b=t%b;
   }
   return a;
}
int main()
{
   freopen("temp.txt","r",stdin);
   int t,m,n,a,ans;
   scanf("%d\n",&t);
   while(t--)
   {
      scanf("%d\n",&n);
      ans=0;
      fora(i,0,n)
      {
         scanf("%d",&a);
         ans=gcd(a,ans);
      }
      if(ans==1)
         printf("%d\n",n);
      else
         puts("-1");
   }
   return 0;
}
