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

#define INF 1e15

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
   freopen("temp.txt","r",stdin);
   long long int a,d,ta,td;
   long long int arr[100100];
   long long int darr[100100];
   map<int,int> m;
   int n,k;
   scanf("%d %d\n",&n,&k);
   fora(i,0,n)
      scanf("%lld ",&arr[i]);
   m.clear();
   a=INF;
   d=INF;
   fora(i,0,n-1)
   {
         darr[i]=arr[i+1]-arr[i];
         if(m.find(darr[i])==m.end())
            m[darr[i]]=1;
         else
            m[darr[i]]++;
   }
   for(int i=n-2;i>=0;i--)
   {
      if(n-m[darr[i]]<=(k+1))
      {
         ta=arr[i]-darr[i]*i;
         if(ta<a)
         {
            a=ta;
            d=darr[i];
         }
         else if(ta==a)
         {
            if(darr[i]<d)
            {
               a=ta;
               d=darr[i];
            }
         }
      }

   }
   fora(i,0,n-1)
   {
      printf("%lld ",a);
      a+=d;
   }
   printf("%lld",a);
   return 0;
}
