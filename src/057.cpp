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
    int add(const longlongint &num2)
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
        return this->len;
    }
};

longlongint den(1);
longlongint num(1);
int iter=0;

bool expand()
{
    ++iter;
    longlongint num_tmp=den;
    num_tmp.add(den);
    int len1=num_tmp.add(num);
    int len2=den.add(num);
    num=num_tmp;
    if(len1>len2) return true;
    return false;
}

int main()
{
    int cnt=0;
    for(int i=0;i<1000;++i)
    {
        if(!expand()) continue;
        ++cnt;
    }
    cout<<cnt;
    return 0;
}
