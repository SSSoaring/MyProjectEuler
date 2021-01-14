#include <iostream>
#include <cmath>

using namespace std;

int count_factor(int n)
{
    int num=0;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            if(i*i==n) num+=1;
            else num+=2;
        }
    }
    return num;
}

int main()
{
    int k=500;
    int i=1;
    int triangle=0;
    while(true)
    {
        triangle=i*(i+1)/2;
        if(count_factor(triangle)>k)
        {
            cout<<triangle<<endl;
            break;
        }
        ++i;
    }
    return 0;
}
