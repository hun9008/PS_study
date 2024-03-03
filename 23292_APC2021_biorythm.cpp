#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

string birth;

int bioValue(string day){
    int value = 0;
    int y = 0;
    int m = 0;
    int d = 0;
    for(int i = 0; i < 4; i++)
    {
        y += (birth[i] - day[i]) * (birth[i] - day[i]);
    }
    for(int i = 4; i < 6; i++)
    {
        m += (birth[i] - day[i]) * (birth[i] - day[i]);
    }
    for(int i = 6; i < 8; i++)
    {
        d += (birth[i] - day[i]) * (birth[i] - day[i]);
    }
    value = y * m * d;
    return value;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> birth;
    int n;
    cin >> n;
    map<int,string> days;

    for(int i = 0; i < n; i++)
    {
        string tDay;
        cin >> tDay;
        int value = bioValue(tDay);
        days[value] = tDay;
    }

    vector<string> maxDay;
    int max = prev(days.end())->first;
    for(auto iter = days.begin(); iter != days.end(); ++iter)
    {
        if(max == iter->first)
        {
            maxDay.push_back(iter->second);
        }
    }

    sort(maxDay.begin(), maxDay.end());

    cout << maxDay[0] << endl;

    return 0;
}