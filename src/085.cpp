#include <iostream>

using namespace std;

int main()
{
    const int N=1000;
    int result[N+1];
    int minimal=1000,min_area;
    int limit=2000000;

    for(int j=1;j<=N;++j)
    {
        result[j]=j*(j+1)/2;
        if(abs(result[j]-limit)<minimal)
        {
            minimal=abs(result[j]-limit);
            min_area=j;
        }
        if(result[j]>limit) break;
    }

    int i=2;
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int j=i;j<=N;++j)
        {

            result[j]+=i*(j+1)*j/2;
            if(abs(result[j]-limit)<minimal)
            {
                minimal=abs(result[j]-limit);
                min_area=i*j;
            }
            if(result[j]>limit) break;
            flag=true;
        }
        ++i;
    }

    cout<<min_area<<endl;

    return 0;
}
