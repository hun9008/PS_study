#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > graph[10001];
int visited[10001];
int maxNode, maxWeight;

void init()
{
    for(int i = 0; i < 10001; i++)
    {
        visited[i] = 0;
    }
    maxWeight = 0;
}

void dfs(int node, int weight){
    if(visited[node]){
        return;
    }
    if(maxWeight < weight){
        maxNode = node;
        maxWeight = weight;
    }

    visited[node] = 1;
    for(int i = 0; i < graph[node].size(); i++)
    {
        dfs(graph[node][i].first, graph[node][i].second + weight);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        graph[f].push_back(make_pair(s, w));
        graph[s].push_back(make_pair(f, w));
    }
    init();
    maxNode = 0;
    dfs(1, 0);
    init();
    dfs(maxNode, 0);

    cout << maxWeight << endl;



    return 0;
}