#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int bin_search(int num, int start ,int end){

    int half = (end + start) / 2;

    if(start > end){
        return 0;
    }

    if(arr[half] == num){
        return 1;
    } else if(arr[half] < num){
        return bin_search(num, half + 1, end);
    } else{
        return bin_search(num, start, half - 1);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    cin >> m;

    for(int i = 0; i < m ; i++)
    {
        int temp;
        cin >> temp;
        // cout << bin_search(temp, 0, n-1) << endl;
        printf("%d\n", bin_search(temp, 0, n-1));
    }


    return 0;
}