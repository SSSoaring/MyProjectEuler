#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int tmp,delta;
    for(int i=143;i<50000;++i)
    {
        delta=i*(2*i-1);
        tmp=sqrt(1+24*delta);
        if(tmp*tmp!=1+24*delta) continue;
        if((tmp+1)%6!=0) continue;
        cout<<delta<<endl;
    }
    return 0;
}
