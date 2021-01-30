#include <iostream>

using namespace std;

const long long int MAX=1000000000;
bool p[MAX];

int main()
{
    for(long long int i=3; i<MAX; ++i)
        p[i]=i%2;
    p[1]=false;
    p[2]=true;
    for(long long int i=3;i<MAX;++i)
    {
        if(!p[i])
            continue;
        for(long long int j=i*3;j<MAX;j+=i*2)
        {
            p[j]=false;
        }
    }

    int i=1;
    long long int n;
    int cnt=0;
    double ratio;
    while(true)
    {
        ++i;
        n=4*i*i-4*i+1;
        if(p[n]) ++cnt;
        n=4*i*i-6*i+3;
        if(p[n]) ++cnt;
        n=4*i*i-8*i+5;
        if(p[n]) ++cnt;
        n=4*i*i-10*i+7;
        if(p[n]) ++cnt;
        ratio=cnt/(double)(4*i-3);
        //cout<<ratio<<endl;
        if(ratio<0.1) break;
    }
    cout<<2*i-1;
    return 0;
}
