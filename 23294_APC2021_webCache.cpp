#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n, q, c;
int usedCache = 0;
int cap[2001];
vector<int> backC;
vector<int> frontC;
int now = 0;

int main()
{
    cin >> n >> q >> c;
    for(int i  = 1; i <= n; i++)
    {
        cin >> cap[i];
    }

    for(int i = 0; i < q; i++)
    {
        string act;
        cin >> act;
        if(act.compare("B") == 0){
            if(!backC.empty()){
                if(now >= 1 && now <= 2000){
                    frontC.push_back(now);
                    now = backC.back();
                    backC.pop_back();
                }
            }
        }
        if(act.compare("F") == 0){
            if(!frontC.empty()){
                if(now >= 1 && now <= 2000){
                    backC.push_back(now);
                    now = frontC.back();
                    frontC.pop_back();
                }
            }
        }
        if(act.compare("A") == 0)
        {
            int index;
            cin >> index;
            int used = 0;
            for(int i = 0; i < frontC.size(); i++)
            {
                used += cap[frontC[i]];
            }
            usedCache -= used;
            if(usedCache < 0){
                usedCache = 0;
            }
            frontC.clear();
            if(now != 0)
            {
                backC.push_back(now);
            }
            now = index;
            usedCache += cap[now];
            while(usedCache > c && !backC.empty()){
                usedCache -= cap[backC.front()];
                backC.erase(backC.begin());
            }
        }
        if(act.compare("C") == 0){
            if(!backC.empty()){
 
                for(int i = 0; i < backC.size(); i++)
                {
                    usedCache -= cap[backC[i]];
                } 
                backC.erase(unique(backC.begin(), backC.end()), backC.end());
                for(int i = 0; i < backC.size(); i++)
                {
                    usedCache += cap[backC[i]];
                }
                if(usedCache < 0)
                {
                    usedCache = 0;
                }
            }

        }
    }

    cout << now << endl;
    if(backC.empty()){
        cout << -1 << endl;
    } else{
        reverse(backC.begin(), backC.end());
        for(int i = 0; i < backC.size(); i++)
        {
            cout << backC[i] << " ";
        }
        cout << "\n";
    }
    if(frontC.empty()){
        cout << -1 << endl;
    } else{
        reverse(frontC.begin(), frontC.end());
        for(int i = 0; i < frontC.size(); i++)
        {
            cout << frontC[i] << " ";
        }
        cout << "\n";
    }

    return 0;

}