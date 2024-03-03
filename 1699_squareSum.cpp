// #include <iostream>
// #include <queue>
// #include <vector>
// #include <math.h>
// using namespace std;

// int n, sq;
// int minNum = 100000;
// // bool visited[100001] = { 0, };
// int map[100001];

// int bfs(int start)
// {
//     queue<int> q;
//     q.push(start*start);
//     map[start*start] = 1;

//     while(!q.empty())
//     {
//         int sum = q.front();
//         int num = map[sum];
//         // cout << "sum : " << sum << endl;
//         q.pop();
//         // visited[sum] = true;
//         if(num > minNum){
//             return -1;
//         }
//         if(sum == n)
//         {
//             return num;
//         }

//         for(int i = sqrt(sum); i >= 1; i--)
//         {
//             if(sum + i*i <= n)
//             {
//                 q.push(sum + i*i);
//                 map[sum + i*i] = map[sum] + 1;
//             }
//         }
        
//     }
//     return -1;
// }

// int main()
// {
//     cin >> n;
//     sq = sqrt(n);

//     for(int i = sq; i >= 1; i--)
//     {
//         int result = bfs(i);
//         if(result < minNum && result != -1){
//             minNum = result;
//         }
//     }

//     cout << minNum << endl;


//     return 0;
// }

// dp

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int dp[100001];
    for(int i = 0; i < 100001; i++)
    {
        dp[i] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j*j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}