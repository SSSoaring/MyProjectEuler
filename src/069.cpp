#include <iostream>

using namespace std;

int main()
{
    const int MAX=1000000;
    int p[]={2,3,5,7,11,13,17,19,23,29};

    int product=1,i=0;
    while(product*p[i]<MAX)
    {
        product*=p[i];
        ++i;
    }

    cout<<product;
    return 0;
}
