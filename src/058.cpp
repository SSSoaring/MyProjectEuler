#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
	int limit=sqrt(n);
	if(n%3==0) return false;
	for(int i=5; i <= limit; i+=6)
    {
        if(n%i==0) return false;
        if(n%(i+2)==0) return false;
    }
	return true;
}

int main()
{
    int i=3;
    int n=3;
    int cnt=3;
    while(true)
    {
        i+=2;
        n=n+7*i-13;
        if(is_prime(n)) ++cnt;
        n=n-i+1;
        if(is_prime(n)) ++cnt;
        n=n-i+1;
        if(is_prime(n)) ++cnt;
        n=n-i+1;
        if(is_prime(n)) ++cnt;
        if(cnt/(double)(2*i-1)<0.1) break;
    }
    cout<<i;
    return 0;
}
