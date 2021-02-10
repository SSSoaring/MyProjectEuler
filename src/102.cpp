#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("../data/p102_triangles.txt");
    const int N=1000;
    int data[N][6];
    string one_line,single_data;
    if(file.is_open())
    {
        for(int i=0;i<N;++i)
        {
            getline(file,one_line);
            istringstream _stream(one_line);
            for(int j=0;j<6;++j)
            {
                getline(_stream,single_data,',');
                data[i][j]=atoi(single_data.c_str());
            }
        }
    }
    file.close();

    double lambda,mu;
    int cnt=0;
    for(int i=0;i<N;++i)
    {
        lambda=(-data[i][2]*data[i][5]+data[i][3]*data[i][4])/(double)((data[i][0]-data[i][2])*data[i][5]-(data[i][1]-data[i][3])*data[i][4]);
        mu=(-data[i][2]-lambda*(data[i][0]-data[i][2]))/data[i][4];
        if(lambda>=0&&mu>=0&&lambda<=1) ++cnt;
    }
    cout<<cnt;
    return 0;
}
