#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<int> adj[501];
int visited[501] = { 0, };

void init(){
    for(int i = 0; i < 501; i++)
    {
        adj[i].clear();
        visited[i] = 0;
    }
}

int bfs(int start){

    int cycle = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(start, -1));
    visited[start] = 1;

    while(!q.empty())
    {
        int now = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int i = 0; i < adj[now].size(); i++)
        {
            int next = adj[now][i];
            if(next != parent){
                if(visited[next]){
                    cycle = true;
                    break;
                }
                else{
                    q.push(make_pair( next, now ));
                }
            }
        }
        if(cycle) break;
    }
    if(cycle){
        return 0;
    } else{
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int cnt = 1;

    while(n != 0 || m != 0){

        int from, to;
        int tree = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> from >> to;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        // cout << "input done\n";
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == 0){
                if(bfs(i) == 1){
                    tree++;
                }
            }
        }
		string answer = "";
		if (!tree) {
			answer = "No trees.\n";
		}
		else if (tree == 1) {
			answer = "There is one tree.\n";
		}
		else {
			answer = "A forest of " + to_string(tree) + " trees.\n";
		}
		cout << "Case " << cnt << ": " << answer;
        cnt++;
        init();
        cin >> n >> m;
    }

}