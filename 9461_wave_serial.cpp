#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    int wave[101];
    for(int i = 0; i < t; i++)
    {
        cin >> wave[i];
    }

    long long int dp[101];

    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i = 6; i <= 100; i++)
    {
        dp[i] = dp[i-1] + dp[i-5];
    }

    for(int i = 0; i < t; i++)
    {
        cout << dp[wave[i]] << endl;
    }



    return 0;
}