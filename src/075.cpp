#include <iostream>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAX=1500001;

char cnt[MAX];

int gcd(int m,int n)
{
    if(n==0) return m;
    else return gcd(n,m%n);
}

int main()
{
    int uplimit_n=sqrt(MAX)/2,uplimit_m=sqrt(MAX/2);
    int sum;

    memset(cnt,0, sizeof cnt);

    for(int n=1;n<=uplimit_n;++n)
    {
        for(int m=n+1;m<=uplimit_m;m+=2)
        {
            if(gcd(m,n)!=1) continue;
            sum=2*m*m+2*m*n;
            for(int k=sum;k<MAX;k+=sum)
            {
                ++cnt[k];
            }
        }
    }
    cout << count(cnt,cnt+MAX,1);
    return 0;
}
