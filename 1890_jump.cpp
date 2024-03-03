#include <iostream>
using namespace std;

long long dp[101][101];
int maze[101][101];


void init(){
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
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

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int move = maze[i][j];
            if(move == 0 || dp[i][j] == 0){
                continue;
            }
            if(i+move < n){
                dp[i+move][j] += dp[i][j];
            }
            if(j+move < n){
                dp[i][j+move] += dp[i][j];
            }
        }
    }

    cout << dp[n-1][n-1] << endl;

    return 0;
}