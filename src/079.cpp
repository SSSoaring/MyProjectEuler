#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    string digit[10];
    int length[10],max_len=0;
    int index;
    for(int i=0;i<10;++i) length[i]=0;
    char result[max_len+2];

    ifstream file;
    file.open("../data/p079_keylog.txt");
    char buf[4];

    if(file.is_open())
    {
        while(file.good()&&!file.eof())
        {
            file.getline(buf,4);
            if(buf[0]=='\0') continue;

            index=buf[0]-'0';
            if(digit[index].find(buf[1])==string::npos)
            {
                digit[index]+=buf[1];
                length[index]+=1;
                if(length[index]>max_len) max_len=length[index];
            }
            if(digit[index].find(buf[2])==string::npos)
            {
                digit[index]+=buf[2];
                length[index]+=1;
                if(length[index]>max_len) max_len=length[index];
            }
            index=buf[1]-'0';
            if(digit[index].find(buf[2])==string::npos)
            {
                digit[index]+=buf[2];
                length[index]+=1;
                if(length[index]>max_len) max_len=length[index];
            }
        }
    }

    for(int i=0;i<10;++i)
    {
        if(digit[i]!="")
        {
            result[max_len-length[i]]=i+'0';
            if(length[i]==1) result[max_len]=digit[i][0];
        }
    }
    result[max_len+1]='\0';

    cout<<result;
    return 0;
}
