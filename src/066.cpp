#include <iostream>
#include <cmath>

using namespace std;

int gcd(int m,int n)
{
    if(n==0) return m;
    return gcd(n,m%n);
}

class fraction
{
private:
    int k;
    int N;
    int b;
    int den;
public:
    void set(int n,int a0)
    {
        N=n;
        k=1;
        b=a0;
        den=n-a0*a0;
    }
    int iter()
    {
        int a=(k*sqrt(N)+b)/den;
        int k_new=den*k;
        int b_new=den*(a*den-b);
        int den_new=k*k*N-(a*den-b)*(a*den-b);
        int factor=gcd(gcd(k_new,den_new),b_new);
        k=k_new/factor;
        b=b_new/factor;
        den=den_new/factor;
        return a;
    }
};

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
    void print()
    {
        for(int i=len-1;i>=0;--i) cout<<num[i];
        cout<<endl;
    }
};


const int MAX=1000;
int a[MAX];
longlongint den(1);
longlongint num(1);

int get_ai(int i,int period)
{
    if(i<=period+1) return a[i-1];
    return a[i-1-period*((i-2)/period)];
}

void expand(int n,int period)
{
    if(n==0) return;
    longlongint den_tmp=den;
    den=num;
    num.mul(get_ai(n,period));
    num.add(den_tmp);
    expand(n-1,period);
}


int main()
{
    int period;
    int n,max_D;
    fraction f;
    longlongint max_x(0),max_y(0);

    for(int i=1;i<1001;++i)
    {
        a[0]=sqrt(i);
        if(a[0]*a[0]==i) continue;

        f.set(i,a[0]);
        period=1;
        while(true)
        {
            a[period]=f.iter();
            if(a[period]==2*a[0]) break;
            ++period;
        }

        if(period%2==1) n=period*2;
        else n=period;

        den=longlongint(1);
        num=longlongint(get_ai(n,period));
        expand(n-1,period);
        if(num>max_x)
        {
            max_x=num;
            max_y=den;
            max_D=i;
        }
    }
    cout<<"x=";
    max_x.print();
    cout<<"y=";
    max_y.print();
    cout<<"D="<<max_D;
    return 0;
}
