#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int proxyIpCnt;
    int serverIpCnt;
    vector<string> proxyIps;
    vector<string> serverIps;
    // 代理服务器地址
    cin >> proxyIpCnt;
    for (int i = 0; i < proxyIpCnt; i++)
    {
        string temp;
        cin >> temp;
        proxyIps.push_back(temp);
    }
    // 服务器地址
    cin >> serverIpCnt;
    for (int i = 0; i < serverIpCnt; i++)
    {
        string temp;
        cin >> temp;
        serverIps.push_back(temp);
    }

    // start记录每一轮从哪个服务器开始代理，changes记录总的变化次数
    // 当没有符合要求的代理方案时flag为false
    int start = 0, changes = 0, flag = 1, j = 0;
    while (start < serverIpCnt && flag)
    {
        // 每一个代理服务器能够代理的最多的服务器数量
        int cnt = 0;
        for (int i = 0; i < proxyIpCnt; i++)
        {
            // 能够代理的情况
            j = start;
            while (j < serverIpCnt && serverIps[j] != proxyIps[i])
            {
                j++;
            }

            // serverIps[j] == proxyIps[i]，计算该代理服务器能够代理的
            // 服务器的数量
            if (j - start > cnt)
            {
                cnt = j - start;
            }
            if (cnt == 0)
            {
                flag = false;
            }
            changes++;
            // 计算下一个代理服务器代理的起始服务器
            start += cnt;
        }
    }
    if (flag)
    {
        // 计算时将第一次也带进去了，所以需要减去
        cout << changes - 1 << endl;
    }
    else
    {
        // 没有符合的代理方式
        cout << -1 << endl;
    }
    return 0;
}