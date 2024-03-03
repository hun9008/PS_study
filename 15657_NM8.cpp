#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue <vector<int> > q;
vector <vector<int> > answer;
vector <int> ins;
int n, m;

void promising(vector<int> v)
{
    int size = v.size();

    if(size == m){
        answer.push_back(v);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        vector<int> add(v);
        if(add.back() <= ins[i]) {
            add.push_back(ins[i]);
            q.push(add);
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        vector<int> v;
        int in;
        cin >> in;
        v.push_back(in);
        ins.push_back(in);
        q.push(v);
    }

    while(!q.empty()){
        int qsize = q.size();
        //cout << "q_size : " << qsize << endl;
        for(int i = 0; i < qsize; i++)
        {
            vector<int> t = q.front();
            q.pop();
            promising(t);

        }
    }

    sort(answer.begin(), answer.end());
    for(int i = 0; i < answer.size(); i++)
    {
        vector<int> out = answer[i];
        for(int j = 0; j < out.size(); j++)
        {
            printf("%d ", out[j]);
        }
        printf("\n");
    }
    
    return 0;
}