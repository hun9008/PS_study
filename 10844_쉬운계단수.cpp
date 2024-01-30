#include <iostream>
using namespace std;

int main(){

    int n;
    int dp[102][10] = {0, };
    cin >> n;

    for(int i = 0; i < 10; i++)
    {
        if(i == 0)
        {
            dp[1][i] = 0;
        }else{
            dp[1][i] = 1;
        }
    }

    for(int j = 2; j <= n; j++)
    {
        for(int i = 0; i < 10; i++){
            if(i == 0){
                dp[j][1] += dp[j-1][0] % 1000000000;
            } else if(i == 9){
                dp[j][8] += dp[j-1][9] % 1000000000;
            } else{
                dp[j][i-1] += dp[j-1][i] % 1000000000;
                dp[j][i+1] += dp[j-1][i] % 1000000000;
            }
        }
    }
    
    long long int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum += dp[n][i];
    }

    cout << sum % 1000000000 << endl;

    return 0;
}