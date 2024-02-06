#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];
int visited[100001];
int parent[100001];

void init()
{
    for(int i = 0; i < 100001; i++)
    {
        visited[i] = 0;
        parent[i] = 0;
    }
    // cout << "init!" << endl;
}

void bfs()
{
    queue<int> q;
    int size = tree[1].size();
    visited[1] = 1;
    for(int i = 0; i < size; i++)
    {
        int child = tree[1][i];
        visited[child] = 1;
        parent[child] = 1;
        q.push(child);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        int n_size = tree[node].size();
        for(int i = 0; i < n_size; i++)
        {
            int child = tree[node][i];
            if(visited[child] == 0){
                visited[child] = 1;
                parent[child] = node;
                q.push(child);
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int f, s;
        cin >> f >> s;
        tree[f].push_back(s);
        tree[s].push_back(f);
    }
    init();
    bfs();

    for(int i = 2; i <= n; i++)
    {
        cout << parent[i] << "\n";
    }


}