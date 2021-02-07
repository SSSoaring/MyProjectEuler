#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a=1,b,c,l1,l2,l3,min_path,cnt=0;
    while(true)
    {
        for(b=1;b<a;++b)
        {
            for(c=1;c<b;++c)
            {
                l1=sqrt(a*a+(b+c)*(b+c));
                min_path=l1;
                l2=sqrt(b*b+(a+c)*(a+c));
                if(min_path>l2) min_path=l2;
                l3=sqrt(c*c+(a+b)*(a+b));
                if(min_path>l3) min_path=l3;

                if(min_path*min_path==a*a+(b+c)*(b+c)) ++cnt;
                if(min_path*min_path==b*b+(a+c)*(a+c)) ++cnt;
                if(min_path*min_path==c*c+(a+b)*(a+b)) ++cnt;
            }

            c=b;
            l1=sqrt(a*a+(b+c)*(b+c));
            min_path=l1;
            l2=sqrt(b*b+(a+c)*(a+c));
            if(min_path>l2) min_path=l2;

            if(min_path*min_path==a*a+(b+c)*(b+c)) ++cnt;
            if(min_path*min_path==b*b+(a+c)*(a+c)) ++cnt;
        }

        b=a;
        for(c=1;c<b;++c)
        {
            l1=sqrt(a*a+(b+c)*(b+c));
            min_path=l1;
            l3=sqrt(c*c+(a+b)*(a+b));
            if(min_path>l3) min_path=l3;

            if(min_path*min_path==a*a+(b+c)*(b+c)) ++cnt;
            if(min_path*min_path==c*c+(a+b)*(a+b)) ++cnt;
        }

        if(cnt>1000000) break;
        ++a;
    }
    cout<<a;
    return 0;
}
