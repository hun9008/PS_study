#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, k;
vector<int> coin;
int map[10001];
int minUsed = 100000;

void bfs()
{
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(coin[i] <= k){
            map[coin[i]] = 1;
            q.push(coin[i]);
        }
    }

    while(!q.empty() && map[k] == -1) 
    {
        int sum = q.front();
        // cout << "[" << sum << "]\n";
        q.pop();
        
        // if(sum == k){
        //     if(used < minUsed){
        //         minUsed = used;
        //     }
        // }

        for(int i = 0; i < n; i++)
        {
            if(sum + coin[i] <= 10000 && map[sum + coin[i]] == -1){
                map[sum + coin[i]] = map[sum] + 1;
                q.push(sum + coin[i]);
            }
        }
    }
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        coin.push_back(tmp);
    }
    memset(map, -1, sizeof(map));
    sort(coin.begin(), coin.end());
    bfs();


    cout << map[k] << endl;
    
    return 0;
}