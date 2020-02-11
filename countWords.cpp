#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string phrase;
    vector<int> len_word;
    getline(cin, phrase);
    int len = phrase.length();
    string temp = "";
    for (int i = 0; i < len; i++)
    {
        if (phrase[i] != ' ' && phrase[i] != '.')
        {
            temp += phrase[i];
        }
        else
        {
            len_word.push_back(temp.length());
            temp = "";
        }
    }

    int vec_size = len_word.size();
    for (int i = 0; i <= vec_size - 1; i++)
    {
        cout << len_word[i] << " ";
    }
    return 0;
}