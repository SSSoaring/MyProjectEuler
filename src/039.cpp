#include <iostream>
#include <cmath>

using namespace std;

int count(int n)
{
    int delta,k,cnt=0;
    for(int a=n/3;a<n/2;++a)
    {
        delta=a*(2*n+a)-n*n;
        k=sqrt(delta);
        if(k*k!=delta) continue;
        k+=n-a;
        if(k%2!=0) continue;
        ++cnt;
    }
    return cnt;
}

int main()
{
    int m=0,m_p=0,tmp;
    for(int i=12;i<=1000;i+=2)
    {
        tmp=count(i);
        if(tmp>m)
        {
            m=tmp;
            m_p=i;
        }
    }
    cout << m_p << endl;
    return 0;
}
