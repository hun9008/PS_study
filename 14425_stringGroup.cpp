#include <iostream>
#include <map>
#include <string.h>
#include <iterator>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    int cnt = 0;
    map<string, bool> s;
    string notS[10001];
    cin >> n >> m;


    string in;
    for(int i = 0; i < n; i++)
    {
        cin >> in;
        s[in] = true;
    }    
    for(int i = 0; i < m; i++)
    {
        cin >> in;
        notS[i] = in;
    }

    for(int i = 0; i < m; i++)
    {
        if(s.find(notS[i]) != s.end())
        {
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}