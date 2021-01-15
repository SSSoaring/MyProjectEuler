#include <iostream>

using namespace std;
int basis[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int And=3;
int Hundred=7;
int ty[10]={4,3,6,6,5,5,5,7,6,6};

int Count(int num)
{
    int three,two,one;
    if(num<20) return basis[num];
    if(num==1000) return 3+8;
    if(num<100)
    {
        two=num/10;
        one=num%10;
        return ty[two]+basis[one];
    }
    if(num%100==0)
    {
        three=num/100;
        return basis[three]+Hundred;
    }
    three=num/100;
    num%=100;
    if(num<20) return basis[three]+Hundred+And+basis[num];
    two=num/10;
    one=num%10;
    return basis[three]+Hundred+And+ty[two]+basis[one];
}


int main()
{
    int sum=0;
    for(int i=1;i<=1000;++i)
    {
        sum+=Count(i);
    }
    cout << sum << endl;
    return 0;
}
