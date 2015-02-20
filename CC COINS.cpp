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
#include<cstdint>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define setBit(n,i) (n|=(1<<i))
#define clearBit(n,i) (n&=(~(1<<i)))
#define checkBit(n,i) (n&(1<<i))
#define lsBit(n) ((n)&(-n))

#define s(n) scanf("%d",&n)
#define fore(i,a) for(__typeof((a).begin()) i=(a).begin;i!=(a).end();i++)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define ms(a,b) memset(a,b,sizeof(a))
#define all(a) (a).begin(),(a).end()

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;

map<ll,ll> m;
ll fun(ll n)
{
   if(n<12) return n;
   if(m.count(n)) return m[n];
   return m[n]=max(n,fun(n/2)+fun(n/3)+fun(n/4));
}
int main()
{
   //freopen("temp.txt","r",stdin);
   int t;
   ll n;
   m.clear();
   while(scanf("%lld\n",&n)!=EOF)
   {
      printf("%lld\n",fun(n));
   }
   return 0;
}
