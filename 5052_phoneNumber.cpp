#include <iostream>
#include <unordered_map>
#include <string.h>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    unordered_map<string, int> book;
    vector<string> phone;
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        int verified = 1;
        for(int i = 0; i < n; i++)
        {
            string number;
            cin >> number;
            phone.push_back(number);
            book[number] = 1;
        }

        for(int i = 0; i < phone.size(); i++)
        {
            for(int j = 0; j < phone[i].size() - 1; j++)
            {
                string subs = phone[i].substr(0, j + 1);
                if(book[subs]){
                    verified = 0;
                }
            }
        }

        if(verified == 0){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }

        book.clear();
        phone.clear();

    }

    return 0;
}