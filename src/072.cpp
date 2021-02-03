#include <iostream>

using namespace std;

const int MAX=1000000;
int p[MAX+1];

int main()
{
    long long int cnt=0;
    for(int i=1; i<=MAX; ++i)
    {
        if(i%2==0) p[i]=i/2;
        else p[i]=i;
    }
    for(int i=3;i<MAX;i+=2)
    {
        if(p[i]!=i) continue;
        for(int j=i;j<=MAX;j+=i)
        {
            p[j]=p[j]/i*(i-1);
        }
    }
    for(int i=2;i<=MAX;++i) cnt+=p[i];
    cout<<cnt<<endl;
    return 0;
}
