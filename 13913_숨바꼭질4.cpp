#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001];
int n, k;
int parent[100001];
queue<pair<int, int> > q;
vector<int> fast;

void bfs(int start)
{
    visited[start] = true;
    q.push(make_pair(start, 0));

    while(!q.empty())
    {
        int pos = q.front().first;
        int sec = q.front().second;
        q.pop();
        // cout << pos << endl;
        if(pos == k){
            cout << sec << endl;
            while(pos != n)
            {
                fast.push_back(pos);
                pos = parent[pos];
            }
            fast.push_back(n);
            reverse(fast.begin(), fast.end());
            for(int i = 0; i < fast.size(); i++)
            {
                cout << fast[i] << " ";
            }
            break;
        }

        if(pos - 1 >= 0 && pos - 1 <= 100000 && visited[pos - 1] == 0)
        {
            q.push(make_pair(pos - 1, sec + 1));
            parent[pos - 1] = pos;
            visited[pos -1] = true;
        }
        if(pos + 1 >= 0 && pos + 1 <= 100000 && visited[pos + 1] == 0)
        {
            q.push(make_pair(pos + 1, sec + 1));
            parent[pos + 1] = pos;
            visited[pos + 1] = true;
        }
        if(pos * 2 >= 0 && pos * 2 <= 100000 && visited[pos * 2] == 0)
        {
            q.push(make_pair(pos * 2, sec + 1));
            parent[pos * 2] = pos;
            visited[pos * 2] = true;
        }
    }
}

int main()
{
    cin >> n >> k;

    bfs(n);

    return 0;
}
