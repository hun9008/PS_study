#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > graph[100001];
int visited[100001];
int maxDis, maxNode;

void init(){
    for(int i = 0; i < 100001; i++)
    {
        visited[i] = 0;
    }
    maxDis = 0;
}

void dfs(int start, int weight){
    if(visited[start] == 1){
        return;
    }
    if(maxDis < weight){
        maxDis = weight;
        maxNode = start;
    }
    visited[start] = 1;
    for(int i = 0; i < graph[start].size(); i++)
    {
        dfs(graph[start][i].first, graph[start][i].second + weight);
    }
}

int main(){

    int n; 
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int num, index, weight;
        cin >> num >> index;

        while(index != -1){
            cin >> weight;
            graph[num].push_back(make_pair(index, weight));
            graph[index].push_back(make_pair(num, weight));
            cin >> index;
        }
    }
    init();
    dfs(1, 0);
    init();
    dfs(maxNode, 0);
    
    cout << maxDis << endl;

    return 0;
}