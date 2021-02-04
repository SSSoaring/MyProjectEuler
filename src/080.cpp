#include <iostream>
#include <cmath>

using namespace std;

class longlongint
{
private:
    int num[120];
    int len;
public:
    longlongint(int n)
    {
        len=0;
        if(n==0)
        {
            len=1;
            num[0]=0;
        }
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
    bool operator>(const longlongint &num2)
    {
        if(len>num2.len) return true;
        if(len<num2.len) return false;
        for(int i=len-1;i>=0;--i)
        {
            if(num[i]>num2.num[i]) return true;
            if(num[i]<num2.num[i]) return false;
        }
        return false;
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
    void sub(const longlongint &num2)
    {
        int carry=0;
        for(int i=0;i<num2.len;++i)
        {
            this->num[i]-=(num2.num[i]+carry);
            if(this->num[i]<0)
            {
                this->num[i]+=10;
                carry=1;
            }
            else carry=0;
        }
        for(int i=num2.len;i<this->len;++i)
        {
            this->num[i]-=carry;
            if(this->num[i]<0)
            {
                this->num[i]+=10;
                carry=1;
            }
            else carry=0;
        }
        while(this->num[this->len-1]==0)
        {
            --this->len;
        }
    }
    void mul(const int n)
    {
        int carry=0;
        if(n==0)
        {
            len=1;
            num[0]=0;
            return;
        }
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
    void shift(int n)
    {
        len+=n;
        for(int i=len-1;i>=n;--i)
        {
            num[i]=num[i-n];
        }
        for(int i=n-1;i>=0;--i)
        {
            num[i]=0;
        }
    }
    void insert_digit(int n)
    {
        num[0]=n;
    }
};

int digit_sum(int n)
{
    longlongint before(0),tmp(0);
    int digit,sum=0;
    longlongint rest(n);
    for(int i=0;i<100;++i)
    {
        digit=9;
        while(true)
        {
            tmp=before;
            tmp.mul(20);
            tmp.insert_digit(digit);
            tmp.mul(digit);
            if(tmp>rest) --digit;
            else break;
        }
        sum+=digit;
        rest.sub(tmp);
        rest.shift(2);
        before.shift(1);
        before.insert_digit(digit);
    }
    return sum;
}

int main()
{
    int sum=0,tmp;
    for(int i=1;i<100;++i)
    {
        tmp=sqrt(i);
        if(tmp*tmp==i) continue;
        sum+=digit_sum(i);
    }
    cout<<sum;
    return 0;
}
