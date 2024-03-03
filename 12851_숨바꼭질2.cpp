#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int visited[100001] = { 0, };
int minM = 100000;
vector<int> findM;

void bfs(int start)
{
    queue<pair<int, int> > q;
    visited[start] = 1;
    q.push(make_pair(start, 0));

    while(!q.empty())
    {
        int pos = q.front().first;
        int move = q.front().second;
        // cout << pos << endl;
        if(pos == k){
            findM.push_back(move);
            // if(move <= minM){
            //     minM = move;
            // }else{
            //     q.pop();
            //     continue;
            // }
        }
        q.pop();
        visited[pos] = 1;
        int nPos[3] = {pos - 1, pos + 1, pos * 2};
        for(int i = 0; i < 3; i++)
        {
            if(nPos[i] >= 0 && nPos[i] <= 100000){
                if(visited[nPos[i]] == 0){
                    q.push(make_pair(nPos[i], move + 1));
                    
                }
            }   
        }

    }   
    
}


int main()
{
    cin >> n >> k;

    bfs(n);
    sort(findM.begin(), findM.end());

    // for(int i = 0; i < findM.size(); i++)
    // {
    //     cout << findM[i] << " ";
    // }

    int wayM = 0;
    for(int i = 0; i < findM.size(); i++)
    {
        if(findM[0] == findM[i]){
            wayM++;
        }
    }

    cout << findM[0] << endl;
    cout << wayM << endl;

    return 0;
}