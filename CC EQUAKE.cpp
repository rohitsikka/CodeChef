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
int q[6];
class segmentTree
{
private:
   int st[4000100][12];
   int flag[4000100];
   vector<int> A;
   int lazy[4000100];
   int n;
   inline int left(int p)   {  return p<<1;   }
   inline int right(int p)   {  return (p<<1)+1;   }
   int rotate(int x, int rt)
   {
      int xx=x, l=0;
      while (xx>0) xx/=10, l++;
      xx=x;
      for (int i=l-1; i>=0; i--) q[i]=xx%10, xx/=10;
      int res=0;
      for (int i=rt; i<rt+l; i++)
         res=res*10 + q[i%l];
      return res;
   }
   void build(int p,int l,int r)
   {
      if(l==r)
      {
         fora(i,0,12)
            st[p][i]=rotate(A[l],i);
      }
      else
      {
         int lp=left(p);
         int rp=right(p);
         build(lp,l,(l+r)/2);
         build(rp,(l+r)/2+1,r);
         fora(i,0,12)
            st[p][i]=max(st[lp][i],st[rp][i]);
      }
   }
   int rmq(int p,int l,int r,int &i,int &j)
   {
      if(i>r||j<l)   return -1;
      if(lazy[p]!=0)
      {
         flag[p]+=lazy[p];
         flag[p]%=12;
         if(l!=r)
         {
            lazy[left(p)]+=lazy[p];
            lazy[left(p)]%=12;
            lazy[right(p)]+=lazy[p];
            lazy[right(p)]%=12;
         }
         lazy[p]=0;
      }
      if(l>=i&&r<=j) return st[p][flag[p]];
      int lp=rmq(left(p),l,(l+r)/2,i,j);
      int rp=rmq(right(p),(l+r)/2+1,r,i,j);
      return max(lp,rp);
   }
   void update(int p,int l,int r,int &i,int &j,int &v)
   {
      if(lazy[p]!=0)
      {
         flag[p]+=lazy[p];
         flag[p]%=12;
         if(l!=r)
         {
            lazy[left(p)]+=lazy[p];
            lazy[left(p)]%=12;
            lazy[right(p)]+=lazy[p];
            lazy[right(p)]%=12;
         }
         lazy[p]=0;
      }
      if(l>r||l>j||r<i)   return ;
      if(l>=i&&r<=j)
      {
         flag[p]+=v;
         flag[p]%=12;
         if(l!=r)
         {
            lazy[left(p)]+=v;
            lazy[left(p)]%=12;
            lazy[right(p)]+=v;
            lazy[right(p)]%=12;
         }
         return ;
      }
      update(left(p),l,(l+r)/2,i,j,v);
      update(right(p),(l+r)/2+1,r,i,j,v);
      fora(k,0,12)
         st[p][(k+flag[p])%12]=max(st[left(p)][(k+flag[left(p)])%12] , st[right(p)][(k+flag[right(p)])%12]);
   }
public:
   segmentTree(){}
   segmentTree(vector<int> &_A)
   {
      A=_A;
      n=A.size();
      ms(lazy,0);
      ms(flag,0);
      build(1,0,n-1);
   }
   void build(vector<int> &_A)
   {
      A=_A;
      n=A.size();
      ms(lazy,0);
      ms(flag,0);
      build(1,0,n-1);
   }
   int rmq(int i,int j)
   {
      return rmq(1,0,n-1,i,j);
   }
   void update(int i,int j,int v)
   {
      v%=12;
      update(1,0,n-1,i,j,v);
   }
}st;

int main()
{
   freopen("temp.txt","r",stdin);
   int n,t,l,r,v,m;
   vi arr;
   scanf("%d",&n);
   arr.resize(n);
   fora(i,0,n)
      scanf("%d",&arr[i]);
   st.build(arr);
   scanf("%d",&m);
   fora(i,0,m)
   {
      scanf("%d",&t);
      if(t)
      {
         scanf("%d %d",&l,&r);
         printf("%d\n",st.rmq(l,r));
      }
      else
      {
         scanf("%d %d %d",&l,&r,&v);
         st.update(l,r,v);
      }
   }
   return 0;
}
