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
typedef long long ll;

#define MOD 1000000007
int ans;
static int DP[9][500500];
int cla(int prev,int n)
{
   if(n<0)
      return 0;
   if(prev==7)
      return 1;
   if(n==0&&prev>=6)
      return 1;
   if(DP[prev][n]!=-1)
      return DP[prev][n];
   DP[prev][n]=((cla(prev,n-1)%MOD)+(cla(prev+1,n-1)%MOD))%MOD;
   return DP[prev][n];
}

int main()
{
   int n,l;
   long long ans;
   fora(i,1,8)
      fora(j,0,500500)
         DP[i][j]=-1;
   scanf("%d",&n);
      n++;
      l=n/2;
      fora(i,1,l-1)
      {
         fora(j,1,8)
         {
               DP[j][i-1]=cla(j,i-1);
               DP[j+1][i-1]=cla(j+1,i-1);
               DP[j][i]=(DP[j][i-1]+DP[j+1][i-1])%MOD;
         }
      }
      if(l-2<0)
         printf("0");
      else
         printf("%d",DP[1][l-2]);
   return 0;
}
