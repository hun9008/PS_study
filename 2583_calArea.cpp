#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
int visited[101][101];
int dir[2][4] = {{0,0,1,-1},{1,-1,0,0}};
vector<int> area;
int cnt = 0;

void init(){
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            visited[i][j] = 0;
        }
    }
}

void sq(int LX, int LY, int RX, int RY){

    for(int i = LY; i < RY; i++)
    {
        for(int j = LX; j < RX; j++)
        {
            visited[i][j] = 1;
        }
    }
}

void bfs(int a1, int b1){
    queue<pair<int, int> > q;
    q.push(make_pair(a1, b1));
    visited[a1][b1] = 1;
    int size = 1;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4;i++){
            int n_x = x + dir[0][i];
            int n_y = y + dir[1][i];
            if (n_x < n && n_x >= 0 && n_y < m && n_y >= 0){
                if(!visited[n_y][n_x]){
                    q.push(make_pair(n_y, n_x));
                    visited[n_y][n_x] = true;
                    size++; //영역넓이 + 1
                }
            } 
        }
    }
    area.push_back(size);
}

void print_visit()
{
    cout << endl;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();

    cin >> m >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        sq(lx, ly, rx, ry);
    }

    // print_visit();

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] == 0){
                // cout << "pos" << i << " " << j << endl;
                bfs(i,j);
                // print_visit();
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    sort(area.begin(), area.end());
    for(int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
    }

    return 0;
}