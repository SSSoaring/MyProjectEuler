#include <iostream>

using namespace std;

const int MAX=1000000;
bool p[MAX];

int main()
{
    bool flag;

    for(int i=3; i<MAX; ++i)
        p[i]=i%2;
    p[1]=false;
    p[2]=true;
    for(int i=3;i<MAX;++i)
    {
        if(!p[i])
            continue;
        for(int j=i*3;j<MAX;j+=i*2)
        {
            p[j]=false;
        }
    }

    for(int i=3;i<MAX;i+=2)
    {
        if(p[i]) continue;
        flag=false;
        for(int j=1;j*j<i/2;++j)
        {
            if(p[i-j*j*2])
            {
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
