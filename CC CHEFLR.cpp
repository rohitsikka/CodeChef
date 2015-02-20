#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MOD 1000000007ll


int main()
{
   freopen("temp2.txt","r",stdin);
   int t;
   long long int ans;
   static char str[100100];
   scanf("%d\n",&t);
   while(t--)
   {
      scanf("%s\n",str);
      ans=1;
      for(int i=0;str[i]!='\0';i++)
      {
         if(i%2==0)
         {
            if(str[i]=='l')
               ans=(ans*2ll)%MOD;
            else
               ans=((ans*2ll+2ll)%MOD);
         }
         else
         {
            if(str[i]=='l')
               ans=((ans*2ll-1ll)%MOD);
            else
               ans=((ans*2ll+1ll)%MOD);
         }
      }
      printf("%lld\n",ans);
   }
   return 0;
}
