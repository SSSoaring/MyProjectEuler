#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum=0;
    for(int i=1;i<10;++i) sum+=1/(1-log10(i));
    cout<<sum;
    return 0;
}
