#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;
    queue<int> q;
    
    for(int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    cout << "<";
    while(q.size() != 1)
    {
        for(int i = 0; i < k - 1; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int pick = q.front();
        cout << pick << ", ";
        q.pop();
    }

    cout << q.front() << ">" << endl;


    return 0;
}