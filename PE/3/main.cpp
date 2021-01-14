#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main()
{
    long long int n=600851475143;
    int prime=1;
    for(int i=2;i<n;++i)
    {
        if(n%i==0)
        {
            prime=i;
            printf("prime=%d\n", prime);
        }
        while(n%i==0)
        {
            n=n/i;
            printf("n=%lld\n",n);
        }
    }
    cout << n << " largest primer factor " <<  prime << endl;
    return 0;
}
