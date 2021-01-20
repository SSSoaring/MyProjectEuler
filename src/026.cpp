#include <iostream>

using namespace std;

int recurring(int n)
{
    int a[1000];
    for(int i=0;i<n;++i) a[i]=0;

    int i=1;
    int d=10;
    while(d<n)
    {
        d*=10;
    }

    d=d%n;
    a[d]=0;
    d*=10;

    while(d!=0)
    {
        d=d%n;
        if(a[d]!=0) return i-a[d];
        a[d]=i;
        d*=10;
        ++i;
    }
    return 0;
}

int main()
{
    int l,max_=0,max_d=0;
    for(int i=2;i<1000;++i)
    {
        l=recurring(i);
        if(l>max_d)
        {
            max_=l;
            max_d=i;
        }
    }
    cout << max_ <<" "<<max_d << endl;
    return 0;
}
