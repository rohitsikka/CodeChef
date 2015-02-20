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
long long int m;

long long int power(long long int base,long long int exp)
{
   long long int res=1;
   while(exp)
   {
      if(exp%2==1)
         res=(res*base)%m;
      exp=exp/2;
      base=(base*base)%m;
   }
   return res;
}
unsigned long long int arr2[4];

long long int sumQ(long long int n,long long int m30)
{
   long long int ar;
   ar=n%m30;
   ar=(ar*((n+1)%m30))%m30;
   ar=(ar*(2*n+1)%m30)%m30;
   ar=(ar*(((((3*(n%m30))%m30)*((n+1))%m30)-1+m30)%m30)%m30)%m30;
   return (long long int)((ar%m30))/30;

}
int main()
{
   freopen("temp.txt","r",stdin);
   int t;
   long long int n;
   long long int range;
   long long int ans;
   long long int minLimit,oldLimit,maxLimit,minLimitSum,maxLimitSum;
   cin>>t;
   while(t--)
   {
      cin>>n;
      cin>>m;

      ans=0;
      range=5;
      minLimit=n+1;
      oldLimit=minLimit;
      for(long long int i=1;i<=n;i++)
      {
         oldLimit=minLimit;
         minLimit=(n/(i+1))+1;
         maxLimit=n/i;
         if(maxLimit-minLimit<range)
            break;
         minLimitSum=sumQ(minLimit-1,m*30);
         maxLimitSum=sumQ(maxLimit,m*30);
         ans=(ans+((i%m)*(((maxLimitSum-minLimitSum)%m+m)%m))%m)%m;
      }
      for(long long int i=1;i<oldLimit;i++)
      {
        ans=(ans+( power(i,4)* ( (n/i)%m ) )%m )%m;
      }
      printf("%lld\n",ans);
   }
   return 0;
}
