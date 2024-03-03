#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, from, to;
vector<int> family[101];
int visited[101];

void init()
{
    for(int i = 0; i < 101; i++)
    {
        visited[i] = 0;
    }
}

int bfs(int start)
{
    queue<pair<int, int> > q;
    q.push(make_pair(start, 0));

    while(!q.empty())
    {
        int pos = q.front().first;
        int num = q.front().second;
        visited[pos] = 1;
        q.pop();

        if(pos == to)
        {
            return num;
        }

        for(int i = 0; i < family[pos].size(); i++)
        {
            int next = family[pos][i];
            if(visited[next] == 0){
                q.push(make_pair(next, num + 1));
            }
        }

    }
    return -1;

}

int main()
{
    cin >> n;
    cin >> from >> to;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }
    init();

    cout << bfs(from) << endl;

    return 0;
}