#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int t, n;
vector<int> playerInven[100001];
int playerPos[100001];
vector<int> errorLog;
vector<int> errorPlayer;

int main()
{
    for(int i = 0; i < 100001; i++)
    {
        playerPos[i] = 1;
    }

    cin >> t >> n;
    for(int i = 0; i < t; i++)
    {
        int num;
        int playerNum;
        string active;
        cin >> num >> playerNum >> active;
        if(active.compare("C") == 0){
            int item1, item2;
            cin >> item1 >> item2;
            // playerInven[playerNum].push_back()
            auto iter1 = find(playerInven[playerNum].begin(), playerInven[playerNum].end(), item1);
            if(iter1 == playerInven[playerNum].end())
            {
                errorLog.push_back(num);
                // errorPlayer.push_back(playerNum);
            } else{
                playerInven[playerNum].erase(iter1);
            }

            auto iter2 = find(playerInven[playerNum].begin(), playerInven[playerNum].end(), item2);
            if(iter2 == playerInven[playerNum].end())
            {
                errorLog.push_back(num);
                // errorPlayer.push_back(playerNum);
            } else{
                playerInven[playerNum].erase(iter2);
            }
        } else{
            int act;
            cin >> act;

            if(active.compare("M") == 0)
            {
                playerPos[playerNum] = act;
            } else if(active.compare("F") == 0)
            {
                playerInven[playerNum].push_back(act);

                if(playerPos[playerNum] != act){
                    errorLog.push_back(num);
                    // errorPlayer.push_back(playerNum);
                }
            } else if(active.compare("A") == 0)
            {
                if(playerPos[act] != playerPos[playerNum]){
                    errorLog.push_back(num);
                    errorPlayer.push_back(playerNum);
                }
            }

        }
    }
    
    if(errorLog.empty()){
        cout << "0" << endl;
    } else{
        sort(errorLog.begin(), errorLog.end());
        errorLog.erase(unique(errorLog.begin(), errorLog.end()), errorLog.end());

        cout << errorLog.size() << endl;
        for(int i = 0; i < errorLog.size(); i++)
        {
            cout << errorLog[i] << " ";
        }
        cout << "\n";
    }

    if(errorPlayer.empty()){
        cout << "0" << endl;
    } else{
        sort(errorPlayer.begin(), errorPlayer.end());
        errorPlayer.erase(unique(errorPlayer.begin(), errorPlayer.end()), errorPlayer.end());
        cout << errorPlayer.size() << endl;
        for(int i = 0; i < errorPlayer.size(); i++)
        {
            cout << errorPlayer[i] << " ";
        }
        cout << "\n";
    }



    return 0;
}