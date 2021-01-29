#include <iostream>

using namespace std;

const int n=100;

long long int c[n+1][n+1];

int compute()
{
    int cnt=0;
    c[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        c[i][0]=1;
        c[i][i]=1;
        for(int j=1;j<i;++j)
        {
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            if(c[i][j]>1000000)
            {
                cnt+=(i+1-j*2);
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    cout<<compute();
    return 0;
}
