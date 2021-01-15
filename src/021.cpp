#include <iostream>
#include <cmath>

using namespace std;

int compute_d(int n)
{
    int sum=1;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0) sum+=i+n/i;
        if(i*i==n) sum-=i;
    }
    return sum;
}

int main()
{
    int d[30000];
    for(int i=1;i<30000;++i) d[i]=0;
    for(int i=1;i<10000;++i)
    {
        d[i]=compute_d(i);
        if(d[i]>9999) d[d[i]]=compute_d(d[i]);
    }
    int sum=0;
    for(int i=1;i<10000;++i)
    {
        if(d[i]>i&&d[d[i]]==i)
        {
            sum+=i+d[i];
        }
    }
    cout << sum << endl;
    return 0;
}
