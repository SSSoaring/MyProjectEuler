#include <iostream>

using namespace std;


const int MAX=1000000;
int a[MAX];

int compute(long long int n)
{
    if(n<MAX)
    {
        if(a[n]!=0) return a[n];
        if(n%2==0)
            a[n]=compute(n/2)+1;
        else
            a[n]=compute(3*n+1)+1;
        return a[n];
    }
    else
    {
        if(n%2==0)
            return compute(n/2)+1;
        else
            return compute(3*n+1)+1;
    }
}

void compute(long long int n,bool verbose)
{
    if(n==1)
    {
        cout<<'1'<<endl;
        return;
    }
    cout<<n<<"->\n";
    if(n%2==0)
        compute(n/2,1);
    else
        compute(3*n+1,1);
}

int main()
{
    for(int i=0;i<MAX;++i) a[i]=0;
    a[1]=1;
    int term=0;
    int maxt=0,maxi;
    for(int i=500000;i<MAX;++i)
    {
        term=compute(i);
        if(term>maxt)
        {
            maxt=term;
            maxi=i;
        }
    }
    compute(maxi,true);
    cout<<maxi<<" "<<maxt<<endl;
    return 0;
}
