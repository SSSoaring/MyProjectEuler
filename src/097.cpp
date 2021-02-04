#include <iostream>

using namespace std;

int main()
{
    long long int result=1,mod=10000000000;
    const int N=7830457;
    for(int i=0;i<N;++i)
    {
        result*=2;
        result%=mod;
    }
    result*=28433;
    result%=mod;
    cout<<result+1;
    return 0;
}
