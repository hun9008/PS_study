#include <iostream>
#include <algorithm>
using namespace std;

int parent[51] = {0, };
int leaves[51] = {0, };

void delete_node(int del, int n){
    // leaves[del] = 0;
    parent[del] = -2;
    for(int i = 0; i < n; i++)
    {
        if(parent[i] == del){
            delete_node(i, n);
        }
    }
}

void find_leaf(int n)
{
    for(int i = 0; i < n; i++)
    {
        int not_leaf = 0;
        if(parent[i] != -2){
            for(int j = 0; j < n; j++)
            {
                if(parent[j] == i){
                    not_leaf = 1;
                    break;
                }
            }
            if(not_leaf == 0){
                leaves[i] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> parent[i];
    }
    int del;
    cin >> del;

    delete_node(del, n);
    find_leaf(n);
    // for(int i = 0; i < n; i++)
    // {
    //     cout << leaves[i] << " ";
    // }

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(leaves[i] == 1){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
