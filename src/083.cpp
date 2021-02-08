#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("../data/p083_matrix.txt");
    const int N=80;
    int data[N][N];
    int result[N][N];
    string one_line,single_data;
    if(file.is_open())
    {
        for(int i=0;i<N;++i)
        {
            getline(file,one_line);
            istringstream _stream(one_line);
            for(int j=0;j<N;++j)
            {
                getline(_stream,single_data,',');
                data[i][j]=atoi(single_data.c_str());
            }
        }
    }
    file.close();

    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            result[i][j]=1000000;
        }
    }
    result[0][0]=data[0][0];

    bool flag=true;
    int tmp;
    while(flag)
    {
        flag=false;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                tmp=1000000;
                if(i!=0)
                {
                    if(result[i-1][j]<tmp) tmp=result[i-1][j];
                }
                if(i!=N-1)
                {
                    if(result[i+1][j]<tmp) tmp=result[i+1][j];
                }
                if(j!=0)
                {
                    if(result[i][j-1]<tmp) tmp=result[i][j-1];
                }
                if(j!=N-1)
                {
                    if(result[i][j+1]<tmp) tmp=result[i][j+1];
                }
                if(data[i][j]+tmp<result[i][j])
                {
                    result[i][j]=data[i][j]+tmp;
                    flag=true;
                }
            }
        }
    }


    cout<<result[N-1][N-1];
    return 0;
}
