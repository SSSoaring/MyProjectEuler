#include <iostream>

using namespace std;

//(0,n)=c(0,n+1)
//(1,n)=c(1,n+1)
//(2,n)=c(1,n+1)+...+c(1,2)+c(2,2)=c(2,n+2)
//(3,n)=c(2,n+2)+...+c(2,3)+c(3,3)=c(3,n+3)
//...
//(m,n)=(n,m)=c(m,n+m)
//(m,m)=c(m,2m)
//"C" is for "combination"
//(m,m) is the result

const int k=20;
long long int a[k+1][k+1];

long long int compute(int m,int n)
{
    if(m==0||n==0) return 1;
    if(m==1) return n+1;
    if(n==1) return m+1;
    if(a[m][n]!=0) return a[m][n];
    a[m][n]=compute(m-1,n)+compute(m,n-1);
    a[n][m]=a[m][n];
    return a[m][n];
}

long long int computeC(int m,int n)
{
    long long int a[n+1][m+1];
    for(int i=0;i<=n;++i)
    {
        a[i][0]=1;
        a[i][1]=i;
    }
    for(int j=2;j<=m;++j)
    {
        a[j][j]=1;
        for(int i=j+1;i<=n;++i)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
    return a[n][m];
}

int main()
{
    for(int i=1;i<k+1;++i)
    {
        for(int j=1;j<k+1;++j) a[i][j]=0;
    }
    long long int c=compute(k,k);

    long long int p=computeC(k,2*k);
    cout<<"(k,k)="<<c<< endl;
    cout<<"C(k,k)="<<p<<endl;
    cout<<"They should be the same number.\n";
    return 0;
}
