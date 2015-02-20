#include<iostream>
#include<cstdio>
#include<bitset>
#include<map>

using namespace std;
int primes[100000],noPrimes;
int t,n,num[13];
map<int,int> m;
void sieveOfErastosthenes()
{
    noPrimes=0;
    primes[noPrimes++]=2;
    bitset <1000100> sieve;
    sieve.set();
    sieve.set(0,false);
    sieve.set(1,false);
    for(int i=3;i*i<1000100;i+=2)
    {
        if(sieve.test((size_t)i))
        {
            for(int j=i*i;j<1000100;j+=i+i)
                sieve.set(j,false);
            primes[noPrimes++]=i;
        }
    }
    for(int i=1001;i<1000100;i+=2)
        if(sieve.test((size_t)i))
            primes[noPrimes++]=i;
}
int main()
{
    sieveOfErastosthenes();
    freopen("temp.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        m.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<noPrimes;j++)
            {
                while(num[i]>1&&num[i]%primes[j]==0)
                {
                    num[i]/=primes[j];
                    if(m.find(primes[j])!=m.end())
                        m[primes[j]]++;
                    else
                       m[primes[j]]=1;
                }
            }
        }
        long long int ans=1;
        for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
            ans=ans*(i->second+1);
		printf("%lld\n",ans);
    }
    return 0;
}
