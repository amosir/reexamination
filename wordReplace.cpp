#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string sentence, toBeReplaced, replaceWord;
    getline(cin, sentence);
    cin >> toBeReplaced;
    cin >> replaceWord;
    int len = sentence.length();
    if (len == 0)
    {
        cout << "" << endl;
    }

    // 分割单词
    vector<string> words;
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        if (sentence[i] == ' ')
        {
            words.push_back(temp);
            temp = "";
        }
        else
        {
            temp += sentence[i];
        }
    }
    words.push_back(temp);
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == toBeReplaced)
        {
            words[i] = replaceWord;
        }
    }
    for (int i = 0; i < words.size(); i++)
    {
        if (i < words.size() - 1)
        {
            cout << words[i] << " ";
        }
        else
        {
            cout << words[i] << endl;
        }
    }
}