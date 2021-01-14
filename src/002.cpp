#include <iostream>

using namespace std;

int main()
{
    const int n=100;
    int F[101], k=0;
    F[0]=1;
    F[1]=1;
    int sum=0;
    for(int i=2;i<=n;++i)
    {
        F[i]=F[i-1]+F[i-2];
        if(F[i]>4000000)
        {
            k=i;
            cout<<F[i]<<' '<<k<<endl;
            break;
        }
        if(i%3==2) sum+=F[i];
    }
    cout<<sum<<endl;
}
