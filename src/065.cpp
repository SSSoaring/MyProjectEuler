#include <iostream>

using namespace std;

class longlongint
{
private:
    int num[400];
    int len;
public:
    longlongint(int n)
    {
        len=0;
        while(n!=0)
        {
            num[len]=n%10;
            n/=10;
            ++len;
        }
    }
    longlongint(const longlongint &num2)
    {
        len=num2.len;
        for(int i=0;i<len;++i)
        {
            num[i]=num2.num[i];
        }
    }
    void add(const longlongint &num2)
    {
        int carry=0;
        if(this->len<num2.len)
        {
            for(int i=this->len;i<num2.len;++i)
            {
                this->num[i]=0;
            }
            this->len=num2.len;
        }
        for(int i=0;i<num2.len;++i)
        {
            this->num[i]+=num2.num[i]+carry;
            carry=this->num[i]/10;
            this->num[i]%=10;
        }
        for(int i=num2.len;i<this->len;++i)
        {
            this->num[i]+=carry;
            carry=this->num[i]/10;
            this->num[i]%=10;
        }
        if(carry!=0)
        {
            this->num[this->len]=carry;
            ++this->len;
        }
    }
    void mul(const int n)
    {
        int carry=0;
        for(int i=0;i<len;++i)
        {
            num[i]=num[i]*n+carry;
            carry=num[i]/10;
            num[i]%=10;
        }
        while(carry)
        {
            num[len]=carry%10;
            carry/=10;
            ++len;
        }
    }
    int sum()
    {
        int s=0;
        for(int i=0;i<len;++i) s+=num[i];
        return s;
    }
};


int get_ai(int i)
{
    if(i==1) return 2;
    if(i%3==0) return i*2/3;
    return 1;
}

const int n=100;
longlongint den(1);
longlongint num(get_ai(n));

void expand(int n)
{
    if(n==0) return;
    longlongint den_tmp=den;
    den=num;
    num.mul(get_ai(n));
    num.add(den_tmp);
    expand(n-1);
}

int main()
{
    expand(n-1);
    cout<<num.sum();
    return 0;
}
