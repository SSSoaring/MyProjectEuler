#include <iostream>

using namespace std;

int main()
{
    const int MAX=100;
    int dp[MAX+1];

    for(int i=1;i<=MAX;++i) dp[i]=0;
    dp[0]=1;

    for(int i=1;i<MAX;++i)
    {
        for(int j=i;j<=MAX;++j)
        {
            dp[j]+=dp[j-i];
        }
    }

    cout<<dp[MAX];

    return 0;
}
