#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    int serial[1001];

    for(int i = 0; i < n; i++)
    {
        cin >> serial[i];
    }

    int max_cnt = 0;
    int dp[1001];

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(serial[i] > serial[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_cnt = max(max_cnt, dp[i]);
    }

    cout << max_cnt << endl;

    return 0;
}