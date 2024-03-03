#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[101][101];
int maze[101][101];
queue<pair<int, int> > q;
long long int cnt = 0;

void init(){
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            visited[i][j] = 0;
        }
    }
}

void bfs(int n){

    visited[0][0] = 1;
    q.push(make_pair(maze[0][0], 0));
    q.push(make_pair(0, maze[0][0]));

    while(!q.empty()){
        int posX = q.front().first;
        int posY = q.front().second;
        // if(posX == n-1 && posY == n-1){
        //     cnt++;
        //     q.pop();
        //     continue;
        // }
        visited[posX][posY] = 1;
        int nX = posX + maze[posX][posY];
        int nY = posY;
        if(nX == n-1 && nY == n-1){
            cnt++;
        }
        else if(nX < n ){
            q.push(make_pair(nX, nY));
        }
        nX = posX;
        nY = posY + maze[posX][posY];
        if(nX == n-1 && nY == n-1){
            cnt++;
        }
        else if(nY < n ){
            q.push(make_pair(nX, nY));
        }
        q.pop();

    }
}

int main(){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    init();
    bfs(n);

    cout << cnt << endl;

    return 0;
}