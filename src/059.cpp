#include <iostream>
#include <fstream>

using namespace std;

int decryption(int cypher[],int key[],int text[],int len)
{
    int sum=0;
    for(int i=0;i<len;++i)
    {
        text[i]=cypher[i]^key[i%3];
        sum+=text[i];
        cout<<(char)text[i];
    }
    cout<<endl;
    return sum;
}

int main()
{
    ifstream file;
    char buf[4500];
    file.open("../data/p059_cipher.txt");
    if(file.is_open())
    {
        file.getline(buf,4500);
    }
    file.close();

    int chpertext[1500],plaintext[1500];
    int len=0;
    int i=0;
    int tmp=0;
    while(buf[i]!='\0')
    {
        if(buf[i]==',')
        {
            chpertext[len]=0;
            for(int j=tmp;j<i;++j)
                chpertext[len]=chpertext[len]*10+buf[j]-'0';
            ++len;
            tmp=i+1;
        }
        ++i;
    }
    chpertext[len]=0;
            for(int j=tmp;j<i;++j)
                chpertext[len]=chpertext[len]*10+buf[j]-'0';
            ++len;

    
    /* Why do I know that the key is exp?
    In fact, I traversed all possible keys 
    I restricted the decrypted ciphertext to be only spaces, a-z, A-Z or 0-9 
    Then calculate the number of legal characters in the plaintext 
    The key, whose plaintext contains the most legal characters is the correct answer
    */
    int key[3]={101,120,112};
    cout<<(char)key[0]<<(char)key[1]<<(char)key[2]<<endl;
    cout<<decryption(chpertext,key,plaintext,len);
    return 0;
}
