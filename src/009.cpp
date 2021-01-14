#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    for(a=3;a<=292;++a)
    {
        for(b=a;b<500;++b)
        {
            c=1000-a-b;
            if(c*c==a*a+b*b) cout<<a<<" "<<b<<" "<<c<<" "<<a*b*c;
        }
    }
    return 0;
}
