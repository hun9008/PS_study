#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[2][4] = {{0, 0, 1, -1}, {1,-1,0,0}};
int visited[51][51];
int ground[51][51];
int cnt = 0;

void init()
{
    for(int i = 0; i < 51; i++)
    {
        for(int j = 0; j < 51; j++)
        {
            visited[i][j] = 0;
            ground[i][j] = 0;
        }
    }
}

void bfs(int x, int y, int m, int n){
    queue <pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()){
        int pos_x = q.front().first;
        int pos_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = pos_x + dir[0][i];
            int ny = pos_y + dir[1][i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(visited[nx][ny] == 0 && ground[nx][ny] == 1){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    cnt++;
}

int main(){

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int m, n, k;
        init();
        cin >> m >> n >> k;
        for(int j = 0; j < k; j++)
        {
            int t_m, t_n;
            cin >> t_m >> t_n;
            ground[t_m][t_n] = 1;
        }
        for(int e = 0; e < m; e++)
        {
            for(int r = 0; r < n; r++){
                if(ground[e][r] == 1 && visited[e][r] == 0){
                    bfs(e,r,m,n);
                }
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }

    return 0;
}