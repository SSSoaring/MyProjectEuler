#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int n)
{
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    int num=1;
    int prime=3;
    while(true)
    {
        if(IsPrime(prime))
        {
            ++num;
            if(num>10000) break;
        }
        prime+=2;
    }
    cout<<num<<" "<<prime<<endl;
    return 0;
}
