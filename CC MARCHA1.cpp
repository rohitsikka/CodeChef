#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int demand;

void printPowerSet(int *s, int set_size)
{

    unsigned long long int pow_set_size = 1<<set_size;
    unsigned long long int counter, j;


    for(counter = 1; counter <pow_set_size; counter++)
    {
        int sum = 0;
        for(j = 0; j < set_size; j++)
        {
            if(counter & (1<<j))
                sum+=s[j];

        }
        if(sum==demand)
        {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");

}

int main()
{
    freopen("temp.txt","r",stdin);
    int test(0),n(0);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&demand);
        int arr[30];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printPowerSet(arr, n);
    }

    return 0;
}
