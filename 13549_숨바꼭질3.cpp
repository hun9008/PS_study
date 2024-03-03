#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int visited[100001];
queue<pair<int, int> > q;
vector<int> fast;

void bfs(int start)
{
    visited[start] = 1;
    q.push(make_pair(start, 0));

    while(!q.empty())
    {
        int pos = q.front().first;
        int sec = q.front().second;
        cout << pos << endl;
        if(pos == k){
            fast.push_back(sec);
        }
        visited[pos] = 1;
        q.pop();

        if(pos - 1 >= 0 && pos - 1 <= 100000 && visited[pos - 1] == 0)
        {
            q.push(make_pair(pos - 1, sec + 1));
        }
        if(pos + 1 >= 0 && pos + 1 <= 100000 && visited[pos + 1] == 0)
        {
            q.push(make_pair(pos + 1, sec + 1));
        }
        if(pos * 2 >= 0 && pos * 2 <= 100000 && visited[pos * 2] == 0)
        {
            q.push(make_pair(pos * 2, sec));
        }
    }

}


int main()
{
    cin >> n >> k;
    
    bfs(n);
    sort(fast.begin(),fast.end());

    cout << fast[0] << endl;

    return 0;
}