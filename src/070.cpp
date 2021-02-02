#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX=10000000;
int p[MAX];


int main()
{
    for(int i=1; i<MAX; ++i)
    {
        if(i%2==0) p[i]=2;
        if(i%4==0) p[i]=0;
        else p[i]=1;
    }
    for(int i=3;i<MAX;i+=2)
    {
        if(p[i]!=1) continue;
        p[i]=0;
        for(int j=2*i;j<MAX;j+=i)
        {
            if(p[j]==1) p[j]=i;
            else
            {
                if(p[j]*i!=j) p[j]=0;
                else p[j]=(p[j]-1)*(i-1);
            }
        }
    }

    string n,phi_n;
    int min_i=0,limit=sqrt(MAX);
    double min_ratio=2,ratio;

    for(int i=MAX-1;i>=limit;i-=2)
    {
        if(p[i]==0) continue;
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
