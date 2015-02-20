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
   int n,m;
   char ch;
   char inp[100];
   char *pch;
   int temp;
   int arr[100010],t[100010];
   int k;
   int start=0;
   int pos;
   scanf("%d %d\n",&n,&m);
   fora(i,0,n)
      scanf("%d ",&arr[i]);
   start=0;
   fora(i,0,m)
   {
      scanf("%c %d\n",&ch,&temp);
      if(ch=='C')
      {
         start=(start+temp)%n;
      }
      else if(ch=='A')
      {
         start=start-temp;
         start=((start)%n+n)%n;
      }
      else
      {
         pos=(start+temp-1)%n;
         printf("%d\n",arr[pos]);

      }
   }
   return 0;
}
