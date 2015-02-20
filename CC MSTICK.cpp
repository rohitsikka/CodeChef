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
   vi st,A;
   inline int left(int p)  {   return p<<1;   }
   inline int right(int p)  {   return (p<<1)+1;   }
   void build(int p,int L,int R)
   {
      if(L==R)
         st[p]=L;
      else
      {
         build(left(p),L,(L+R)/2);
         build(right(p),(L+R)/2+1,R);
         int p1=st[left(p)];
         int p2=st[right(p)];
         st[p]=(A[p1]<=A[p2]) ?  p1 :  p2;
      }
   }
   int rmq(int p,int L,int R,int i,int j)
   {
      if(i>R||j<L)   return -1;
      if(L>=i&&R<=j) return st[p];
      int p1=rmq(left(p),L,(L+R)/2,i,j);
      int p2=rmq(right(p),(L+R)/2+1,R,i,j);
      if(p1==-1)  return p2;
      if(p2==-1)  return p1;
      return (A[p1]<=A[p2]) ? p1 :  p2;
   }
public:
   segmentTree()  {}
   segmentTree(vi &_A)
   {
      A=_A;
      st.resize(4*(int)A.size());
      build(1,0,(int)A.size()-1);
   }
   void build(const vi &_A)
   {
      A=_A;
      st.resize(4*(int)A.size());
      build(1,0,(int)A.size()-1);
   }
   int rmq(int i,int j)
   {
      return rmq(1,0,(int)A.size()-1,i,j);
   }
};
int main()
{
   freopen("temp.txt","r",stdin);
   int n,q,l,r;
   double t1,t2,t3,t4;
   vi b,negb;
   scanf("%d\n",&n);
   b.resize(n);
   negb.resize(n);
   fora(i,0,n)
   {
      scanf("%d",&b[i]);
      negb[i]=-b[i];
   }
   segmentTree stMin(b);
   segmentTree stMax(negb);
   scanf("%d\n",&q);
   double ans;
   while(q--)
   {
      scanf("%d %d\n",&l,&r);
      t1=t2=t3=t4=0;
      t1=b[stMin.rmq(l,r)];
      t2=b[stMax.rmq(l,r)];
      if(l>0)  t3=b[stMax.rmq(0,l-1)];
      if(r<n-1)  t4=b[stMax.rmq(r+1,n-1)];
      ans=t1+max((t2-t1)/2.0,max(t3,t4));
      printf("%.1lf\n",ans+0.01);
   }

   return 0;
}
