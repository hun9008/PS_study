#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[20001];
queue<int> q;
int visited[20001];

void init(){
    for(int i = 0; i < 20001; i++)
    {
        visited[i] = 0;
        graph[i].clear();
    }
}

int state_change(int state){
    if(state == 1) return 2;
    if(state == 2) return 1;
}

void bfs(int start){

    int state = 1;
    visited[start] = state;
    int size = graph[start].size();
    for(int i = 0; i < size; i++)
    {
        q.push(graph[start][i]);
    }

    while(!q.empty()){
        int q_size = q.size();
        state = state_change(state);
        for(int i = 0; i < q_size; i++)
        {
            if(visited[q.front()] == 0){
                visited[q.front()] = state;
                for(int j = 0; j < graph[q.front()].size(); j++)
                {   
                    if(visited[graph[q.front()][j]] == 0)
                    {
                        q.push(graph[q.front()][j]);
                    }
                }
            }
            q.pop();
        }
    }
    // return 1;
}

int is_bipartite(int v){
    for(int i = 1; i <= v; i++)
    {
        int size = graph[i].size();
        for(int j = 0; j < size; j++)
        {
            if(visited[i] == visited[graph[i][j]]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int v, e;
        cin >> v >> e;
        int f, t;
        init();
        for(int j = 0; j < e; j++)
        {
            cin >> f >> t;
            graph[f].push_back(t);
            graph[t].push_back(f);
        }
        for(int k = 1; k <= v; k++)
        {
            if(visited[k] == 0){
                bfs(k);
            }
        }
        if(is_bipartite(v)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;
}