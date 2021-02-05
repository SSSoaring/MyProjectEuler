#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("../data/p081_matrix.txt");
    int data[80][80];
    int result[80][80];
    string one_line,single_data;
    if(file.is_open())
    {
        for(int i=0;i<80;++i)
        {
            getline(file,one_line);
            istringstream _stream(one_line);
            for(int j=0;j<80;++j)
            {
                getline(_stream,single_data,',');
                data[i][j]=atoi(single_data.c_str());
            }
        }
    }
    file.close();


    result[0][0]=data[0][0];
    for(int j=1;j<80;++j) result[0][j]=result[0][j-1]+data[0][j];
    for(int i=1;i<80;++i) result[i][0]=result[i-1][0]+data[i][0];
    for(int i=1;i<80;++i)
    {
        for(int j=1;j<80;++j)
        {
            if(result[i-1][j]<result[i][j-1]) result[i][j]=result[i-1][j]+data[i][j];
            else result[i][j]=result[i][j-1]+data[i][j];
        }
    }
    cout<<result[79][79];
    return 0;
}
