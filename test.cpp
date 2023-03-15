#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<pair<int, char>> p;
    unordered_map<char, int> umap;
    string s="aabebbbAA";
    string ans;
    for(auto i : s)
    {
        umap[i]++;
    }
    for(auto i: umap)
    {
        p.push(make_pair(i.second, i.first));
    }
    while(!p.empty())
    {
        int i=0;
        while(i<(p.top().first))
        {
            ans.push_back(p.top().second);
            i++;
        }
        p.pop();
    }

    cout<<ans;

    


    return 0;
}