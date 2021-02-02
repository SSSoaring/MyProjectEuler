#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX=10000000;
int p[MAX];


int main()
{
    for(int i=3; i<MAX; ++i)
    {
        if(i%2==1) p[i]=i;
        else p[i]=i/2;
    }
    p[1]=1;
    p[2]=1;
    for(int i=3;i<MAX;++i)
    {
        if(p[i]!=i) continue;
        for(int j=i;j<MAX;j+=i)
        {
            p[j]=p[j]/i*(i-1);
        }
    }

    string n,phi_n;
    int min_i=0;
    double min_ratio=2,ratio;
    for(int i=2;i<MAX;++i)
    {
        ratio=i/(double)p[i];
        if(ratio>min_ratio) continue;
        n=to_string(i);
        phi_n=to_string(p[i]);
        sort(n.begin(),n.end());
        sort(phi_n.begin(),phi_n.end());
        if(n!=phi_n) continue;
        min_ratio=ratio;
        min_i=i;
    }
    cout<<min_i;
    return 0;
}
