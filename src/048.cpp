#include <iostream>

using namespace std;
long long int m=10000000000;

long long int last_ten_digit_power(int base)
{
    long long int k=1;
    for(int i=0;i<base;++i)
    {
        k*=base;
        k%=m;
    }
    return k;
}

int main()
{
    long long int sum=0;

    for(int i=1;i<=1000;++i)
    {
        if(i%10==0) continue;
        sum+=last_ten_digit_power(i);
        sum%=m;
    }
    cout<<sum;
    return 0;
}
