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

class segmentTree
{
private:
   vector<int> st;
   vector<int> A;
   vector<int> lazy;
   int n;
   inline int left(int p)   {  return p<<1;   }
   inline int right(int p)   {  return (p<<1)+1;   }
   int build(int p,int l,int r)
   {
      if(l==r)
         return st[p]=A[l];
      else
      {
         int lp=left(p);
         int rp=right(p);
         return st[p]=build(lp,l,(l+r)/2)+build(rp,(l+r)/2+1,r);
      }
   }
   int rmq(int p,int l,int r,int &i,int &j)
   {
      if(i>r||j<l)   return 0;
      if(lazy[p]!=0)
      {
         st[p]=(r-l+1)-st[p];
         if(l!=r)
         {
            lazy[left(p)]+=1;
            lazy[left(p)]%=2;
            lazy[right(p)]+=1;
            lazy[right(p)]%=2;
         }
         lazy[p]=0;
      }
      if(l>=i&&r<=j) return st[p];
      int lp=rmq(left(p),l,(l+r)/2,i,j);
      int rp=rmq(right(p),(l+r)/2+1,r,i,j);
      return lp+rp;
   }
   void update(int p,int l,int r,int &i,int &j)
   {
      if(lazy[p]!=0)
      {
         st[p]=(r-l+1)-st[p];
         if(l!=r)
         {
            lazy[left(p)]+=1;
            lazy[left(p)]%=2;
            lazy[right(p)]+=1;
            lazy[right(p)]%=2;
         }
         lazy[p]=0;
      }
      if(l>r||l>j||r<i)   return ;
      if(l>=i&&r<=j)
      {
         st[p]=(r-l+1)-st[p];
         if(l!=r)
         {
            lazy[left(p)]+=1;
            lazy[left(p)]%=2;
            lazy[right(p)]+=1;
            lazy[right(p)]%=2;
         }
         return ;
      }
      update(left(p),l,(l+r)/2,i,j);
      update(right(p),(l+r)/2+1,r,i,j);
      st[p]=st[left(p)]+st[right(p)];
   }
public:
   segmentTree(){}
   segmentTree(int a)
   {
      n=a;
      A.assign(n,0);
      st.assign(4*n,0);
      lazy.assign(4*n,0);
      //build(1,0,n-1);
   }
   void build(int a)
   {
      n=a;
      A.assign(n,0);
      st.assign(4*n,0);
      lazy.assign(4*n,0);
      //build(1,0,n-1);
   }
   int rmq(int i,int j)
   {
      return rmq(1,0,n-1,i,j);
   }
   void update(int i,int j)
   {
      update(1,0,n-1,i,j);
   }
};

int main()
{
   #ifndef ONLINE_JUDGE
      freopen("temp.txt","r",stdin);
   #endif
   int n,q;
   int t,a,b;
   scanf("%d %d\n",&n,&q);
   segmentTree st(n);
   fora(i,0,q)
   {
      scanf("%d %d %d\n",&t,&a,&b);
      if(t)
         printf("%d\n",st.rmq(a,b));
      else
         st.update(a,b);
   }
   return 0;
}
