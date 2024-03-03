#include <iostream>
#include <map>
#include <string.h>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    vector<string> book;
    cin >> t;
    
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        int verified = 1;
        for(int i = 0; i < n; i++)
        {
            string phone;
            cin >> phone;
            book.push_back(phone);
        }

        sort(book.begin(),book.end());

        for(int i = 0; i < book.size(); i++)
        {
            cout << book[i] << endl;
        }

        // for(auto iter = book.begin(); iter != prev(book.end()); ++iter)
        // {
        //     string head = iter->first;
        //     int size = iter->second;
        //     cout << head << endl;
        //     // for(auto next_iter = next(iter); next_iter != book.end(); ++next_iter)
        //     // {
        //     //     string cmp = next_iter->first;
        //     //     int cmp_size = next_iter->second;
        //     //     if(cmp_size > size){
        //     //         if(head.compare(0,size,cmp,0,size) == 0){
        //     //             verified = 0;
        //     //             break;
        //     //         }
        //     //     }
        //     // }
        //     // if(verified == 0){
        //     //     break;
        //     // }
        // }

        if(verified == 0){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }

        book.clear();

    }

    return 0;
}