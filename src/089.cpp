#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int int2roman(int n)
{
    string str="";
    while(n/1000!=0)
    {
        str+='M';
        n-=1000;
    }
    if(n>=900)
    {
        str+="CM";
        n-=900;
    }
    if(n>=500)
    {
        str+='D';
        n-=500;
    }
    if(n>=400)
    {
        str+="CD";
        n-=400;
    }
    while(n/100!=0)
    {
        str+='C';
        n-=100;
    }
    if(n>=90)
    {
        str+="XC";
        n-=90;
    }
    if(n>=50)
    {
        str+='L';
        n-=50;
    }
    if(n>=40)
    {
        str+="XL";
        n-=40;
    }
    while(n/10!=0)
    {
        str+='X';
        n-=10;
    }
    if(n==9)
    {
        str+="IX";
        n-=9;
    }
    if(n>=5)
    {
        str+='V';
        n-=5;
    }
    if(n==4)
    {
        str+="IV";
        n-=4;
    }
    while(n!=0)
    {
        str+='I';
        --n;
    }
    return str.length();
}

int num_of_char(string str)
{
    int num=0;
    int current,tmp=1000;
    for(size_t i=0;i<str.length();++i)
    {
        switch(str[i])
        {
            case 'M':current=1000;break;
            case 'D':current=500;break;
            case 'C':current=100;break;
            case 'L':current=50;break;
            case 'X':current=10;break;
            case 'V':current=5;break;
            case 'I':current=1;break;
        }
        num+=current;
        if(tmp<current)
        {
            switch(tmp)
            {
            case 1:num-=2;break;
            case 10:num-=20;break;
            case 100:num-=200;break;
            }
        }
        tmp=current;
    }

    return str.length()-int2roman(num);
}

int main()
{
    ifstream file("../data/p089_roman.txt");
    int cnt=0;
    string one_line;
    if(file.is_open())
    {
        for(int i=0;i<1000;++i)
        {
            getline(file,one_line);
            cnt+=num_of_char(one_line);
        }
    }

    file.close();
    cout<<cnt<<endl;
    return 0;
}
