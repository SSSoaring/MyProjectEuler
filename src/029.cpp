#include <iostream>

using namespace std;

int main()
{
    const int n=100;
    int a[n+1][6*n+1], power, result;
    int cnt=0;
    for(int i=2;i<=n;++i)
        for(int j=2;j<=6*n;++j)
            a[i][j]=0;

    for(int i=2;i<=n;++i)
    {
        if(a[i][0]==1) continue;
        result=i;
        power=1;
        while(result<=n)
        {
            a[result][0]=1;
            for(int j=2;j<=n;++j)
            {
                if(a[i][power*j]==0)
                {
                    cnt++;
                    a[i][power*j]=1;
                }

            }
            ++power;
            result*=i;
        }
    }


    cout << cnt << endl;
    return 0;
}
