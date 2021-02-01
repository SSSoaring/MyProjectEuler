#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int MAX=1001;
    long long int tmp,D[MAX],result,root;
    int cnt=0,total=MAX-1-sqrt(MAX);
    for(int i=0;i<MAX;++i) D[i]=0;
    long long int x=2;

    while(true)
    {
        tmp=x*x-1;
        for(int d=2;d<MAX;++d)
        {
            if(D[d]!=0) continue;
            if(tmp%d!=0) continue;
            result=tmp/d;
            root=sqrt(result);
            if(root*root==result)
            {
                D[d]=x;
                ++cnt;
                cout<<x<<" "<<cnt<<endl;
            }
        }
        if(cnt==total) break;
        ++x;
    }
    cout<<x;
    return 0;
}
