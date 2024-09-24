#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool html(const string& file)
{
    if(file.length()>=5)
    {
       return file.substr(file.length()-5)==".html";
    }
    return false;
}

bool file2(const string& file)
{
    ifstream filee(file);
    return filee.good();
}

bool tag(const string& file)
{
    ifstream filee(file);
    char ta;
    while(filee.get(ta))
    {
        if(ta=='<')
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string file;
    cout<<"Файл: ";
    getline(cin,file);
    if(file2(file))
    {
        cout<<"Файл есть"<<endl;
        if (html(file))
        {
            cout << "Файл есть HTML файлом"<<endl;
            if(tag(file))
            {
                cout<<"тег < есть в файле"<<endl;
            }
            else
            {
                cout<<"тега < нету в файле"<<endl;
            }
        }
        else
        {
            cout << "Файл не есть HTML файлом"<<endl;
        }
    }
    else
    {
        cout<<"Такого файла нету"<<endl;
    }
}
