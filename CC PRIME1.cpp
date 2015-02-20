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
#define lsBit(n) ((n)&(-n))

#define s(n) scanf("%d",&n)
#define fora(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(__typeof((a).begin())i=(a).begin();i!=(a).end();i++)
#define ms(a,b) memset(a,b,sizeof(a))
#define all(a) (a).begin(),(a).end()

#define INF 1e9

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long int ll;

#define MAXN 1000100
vi primes,curPrimes;
bitset<MAXN> isPrime;
bitset<100010> curIsPrime;
void sieveOfErastosthenes()
{
   primes.clear();
   isPrime.set();
   isPrime[0]=0;
   isPrime[1]=0;
   primes.pb(2);
   int m=sqrt(MAXN);
   for(int i=3;i<=m;i+=2)
   {
      if(isPrime[i])
      {
         for(int j=i*i;j<MAXN;j+=i+i)
            isPrime[j]=0;
         primes.pb(i);
      }
   }
   if(m%2==0)  m++;
   for(int i=m;i<MAXN;i+=2)
      if(isPrime[i]) primes.pb(i);
}
void segmentedSieve(int l,int r)
{
   curIsPrime.set();
   curPrimes.clear();
   if(r<MAXN)
   {
      fora(i,0,primes.size())
         if(primes[i]>r)   break;
         else if(primes[i]>=l&&primes[i]<=r) curPrimes.pb(primes[i]);
      return;
   }
   fora(i,1,primes.size())
   {
      if(primes[i]>=l)   break;
      int temp;
      if(l%primes[i]==0)   temp=0;
      else temp=((l/primes[i])*primes[i]+primes[i])-l;
      for(int j=temp;j<=r-l;j+=primes[i])
         curIsPrime[j]=0;
   }
   fora(i,0,r-l+1)
      if((i+l)%2==0) continue;
      else if(curIsPrime[i]) curPrimes.pb(i+l);
}
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("temp.txt","r",stdin);
   #endif
   int t,a,b;
   bool flag=false;
   sieveOfErastosthenes();
   scanf("%d\n",&t);
   while(t--)
   {
      if(flag) puts("");
      flag=true;
      scanf("%d %d\n",&a,&b);
      segmentedSieve(a,b);
      fora(i,0,curPrimes.size())
         printf("%d\n",curPrimes[i]);
   }
   return 0;
}
