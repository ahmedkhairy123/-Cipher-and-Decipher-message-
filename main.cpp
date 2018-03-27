// FCI � Programming 1 � 2018 - Assignment 2
// Program Name:  Rail fence Cipher.cpp
// Last Modification Date: 2/3/2018
// Author1 and ID and Group: Ahmed thabet Khairy  20160009
// Teaching Assistant: Ashraf Mohey
// Purpose: Encrypt messages

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout <<"hello user!"<<endl;

    string text;
    string firstmessage = "";
    string lastmessage  = "";
    int key ;

    cout << "Please enter your message: ";
    getline (cin,text);
    cout << "Please enter your key: ";
    cin>>key;
    for(int i = 0;i < text.size();i++)
    {
        if(text[i] != ' ')
        {
            firstmessage += text[i];
        }
    }

    int N = key;
    int M = firstmessage.size();
    char** arr = new char*[N];
    for(int i = 0; i < N; ++i)
        arr[i] = new char[M];
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            arr[i][j] = 0;
        }
    }
    int row = 0;
    int col = 0;
    int type = 0 ;
    while(col < M)
    {
        arr[row][col] = firstmessage[col];
        if(type == 0)
        {
            row += 1;
            if(row == (N-1))
            {
                type = 1;
            }
        }
        else if(type == 1)
        {
            row -= 1;
            if(row == 0)
            {
                type = 0;
            }
        }
        col++;
    }
    for(int i = 0;i < N;i++)
    {
        for(int j = 0;j < M;j++)
        {
            if(arr[i][j] != 0)
            {
                lastmessage +=  tolower(arr[i][j]);
            }
        }
    }
    cout<<lastmessage<<endl;

  return 0;
}
