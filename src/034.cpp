#include <iostream>

using namespace std;

int main()
{
    int factorial[10];
    factorial[0]=1;
    for(int i=1;i<10;++i)
    {
        factorial[i]=factorial[i-1]*i;
    }
    int sum=0;
    int num;
    //no 2-digit number
    //3-digit:100-555
    for(int a=1;a<=5;++a)
    {
        for(int b=0;b<=5;++b)
        {
            for(int c=0;c<=5;++c)
            {
                num=a*100+b*10+c;
                if(num==factorial[a]+factorial[b]+factorial[c])
                {
                    sum+=num;
                }
            }
        }
    }
    //4-digit:1000-7777
    for(int a=1;a<=7;++a)
    {
        for(int b=0;b<=7;++b)
        {
            for(int c=0;c<=7;++c)
            {
                for(int d=0;d<=7;++d)
                {
                    num=a*1000+b*100+c*10+d;
                    if(num==factorial[a]+factorial[b]+factorial[c]+factorial[d])
                    {
                        sum+=num;
                    }
                }
            }
        }
    }
    //5-digit:10000-88888
    for(int a=1;a<=8;++a)
    {
        for(int b=0;b<=8;++b)
        {
            for(int c=0;c<=8;++c)
            {
                for(int d=0;d<=8;++d)
                {
                    for(int e=0;e<=8;++e)
                    {
                        num=a*10000+b*1000+c*100+d*10+e;
                        if(num==factorial[a]+factorial[b]+factorial[c]+factorial[d]+factorial[e])
                        {
                            sum+=num;
                        }
                    }
                }
            }
        }
    }
    //6-digit:100000-99999
    for(int a=1;a<=9;++a)
    {
        for(int b=0;b<=9;++b)
        {
            for(int c=0;c<=9;++c)
            {
                for(int d=0;d<=9;++d)
                {
                    for(int e=0;e<=9;++e)
                    {
                        for(int f=0;f<=9;++f)
                        {
                            num=a*100000+b*10000+c*1000+d*100+e*10+f;
                            if(num==factorial[a]+factorial[b]+factorial[c]+factorial[d]+factorial[e]+factorial[f])
                            {
                                sum+=num;
                            }
                        }
                    }
                }
            }
        }
    }
    //7-digit:1000000-299999
    for(int a=1;a<=2;++a)
    {
        for(int b=0;b<=9;++b)
        {
            for(int c=0;c<=9;++c)
            {
                for(int d=0;d<=9;++d)
                {
                    for(int e=0;e<=9;++e)
                    {
                        for(int f=0;f<=9;++f)
                        {
                            for(int g=0;g<=9;++g)
                            {
                                num=a*1000000+b*100000+c*10000+d*1000+e*10+f*10+g;
                                if(num==factorial[a]+factorial[b]+factorial[c]+factorial[d]+factorial[e]+factorial[f]+factorial[g])
                                {
                                    sum+=num;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
