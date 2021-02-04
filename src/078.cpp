#include <iostream>

using namespace std;

int main()
{
    const int N=60000;
    const int factor=1000000;

    int dp[N+1];

    for(int i=0;i<=N;++i) dp[i]=0;
    dp[0]=1;

    int i=1;
    bool flag=true;
    while(flag)
    {
        for(int j=i;j<=N;++j)
        {
            dp[j]+=dp[j-i];
            dp[j]%=factor;
        }
        if(dp[i]==0)
        {
            cout<<i;
            break;
        }
        if(i==N) break;
        ++i;
    }
    return 0;
}
