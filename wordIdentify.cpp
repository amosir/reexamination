#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    // 输入的句子
    string phrase;

    // 存储单词--次数的映射
    map<string, int> wordMap;
    getline(cin, phrase);
    int len = phrase.length();
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        // 没遇到逗号,句点或空格则表明一个单词还没结束
        if (phrase[i] != ',' && phrase[i] != '.' && phrase[i] != ' ')
        {
            temp += tolower(phrase[i]);
        }
        // 一个单词结束
        else
        {
            if (temp != "")
            {
                wordMap[temp]++;
            }
            temp = "";
        }
    }

    for (map<string, int>::iterator p = wordMap.begin(); p != wordMap.end(); p++)
    {
        cout << p->first << ":" << p->second << endl;
    }
    return 0;
}