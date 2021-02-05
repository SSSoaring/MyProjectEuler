#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("../data/p082_matrix.txt");
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

    for(int i=0;i<N;++i) result[i][0]=data[i][0];

    for(int j=1;j<N;++j)
    {
        result[0][j]=result[0][j-1]+data[0][j];
        for(int i=1;i<N;++i)
        {
            if(result[i][j-1]>result[i-1][j]) result[i][j]=result[i-1][j]+data[i][j];
            else result[i][j]=result[i][j-1]+data[i][j];
        }
        for(int i=N-2;i>=0;--i)
        {
            if(result[i+1][j]+data[i][j]<result[i][j]) result[i][j]=result[i+1][j]+data[i][j];
        }
    }

    int minimal=result[0][N-1];
    for(int i=1;i<N;++i)
    {
        if(result[i][N-1]<minimal) minimal=result[i][N-1];
    }

    cout<<minimal;
    return 0;
}
