#include <iostream>
#include <string>
#include <vector>
#include <map>
#define MALE 1
#define FEMALE 0
using namespace std;
typedef struct Stu
{
    string number;
    string name;
    int sex;
    int age;
} Stu;
int main()
{
    int cnt;
    cin >> cnt;
    Stu stu_map[cnt];
    map<string, int> indexMap;
    for (int i = 0; i < cnt; i++)
    {
        string number;
        string name;
        string sex;
        int age;
        cin >> number >> name >> sex >> age;
        stu_map[i].number = number;
        stu_map[i].name = name;
        if (sex == "男")
        {
            stu_map[i].sex = MALE;
        }
        else
        {
            stu_map[i].sex = FEMALE;
        }
        stu_map[i].age = age;
        indexMap.insert(pair<string, int>(number, i));
    }
    int search_cnt;
    cin >> search_cnt;
    vector<string> vec;
    for (int j = 0; j < search_cnt; j++)
    {
        string number;
        cin >> number;
        vec.push_back(number);
    }

    for (int k = 0; k < search_cnt; k++)
    {
        Stu stu = stu_map[indexMap.find(vec[k])->second];
        cout << stu.number << " " << stu.name << " ";
        stu.sex == MALE ? cout << "男" : cout << "女";
        cout << " " << stu.age << endl;
    }
    return 0;
}