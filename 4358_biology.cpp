#include <iostream>
#include <string.h>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<string, float> species;
    string in;
    int sum = 0;

    getline(cin, in);
    while(in.size() != 0){
        // species.push_back(make_pair(in, 1.0000));
        species[in]++;
        sum++;
        getline(cin, in);
    }
    
    map<string, float>::iterator iter;
    cout << fixed;
    cout.precision(4);

    for(iter = species.begin(); iter != species.end(); ++iter)
    {
        cout << iter->first << " " << iter->second * 100 / sum << "\n";
    }


    return 0;
}