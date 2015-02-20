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

int main()
{
   freopen("temp.txt","r",stdin);
   int t,n;
   static char g[1010][1010];
   static bool rayX[1010][1010];
   static bool rayY[1010][1010];
   scanf("%d\n",&t);
   while(t--)
   {
      scanf("%d\n",&n);
      fora(i,0,n)
         gets(g[i]);
      memset(rayX,0,sizeof(rayX));
      memset(rayY,0,sizeof(rayY));
      fora(i,0,n)
         if(g[i][n-1]=='.')
            rayX[i][n-1]=true;
      fora(i,0,n)
         if(g[n-1][i]=='.')
            rayY[n-1][i]=true;
      fora(i,0,n)
      {
         for(int j=n-1;j>=1;j--)
         {
            if(g[i][j]=='.'&&rayX[i][j]==1)
               rayX[i][j-1]=1;
            if(g[j][i]=='.'&&rayY[j][i]==1)
               rayY[j-1][i]=1;
         }
      }
      int count=0;
      fora(i,0,n)
         fora(j,0,n)
            if(g[i][j]=='.'&&rayX[i][j]==1&&rayY[i][j]==1) count++;
      printf("%d\n",count);
   }
   return 0;
}
