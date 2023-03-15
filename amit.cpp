#include <bits/stdc++.h>
using namespace std;
int findMinimumTime(vector<vector<int>> &tasks)
{
    sort(tasks.begin(), tasks.end());
    vector<vector<int>> v;
    for (auto i : tasks)
    {
        if (v.empty())
        {
            v.push_back(i);
        }
        else
        {
            if (i[0] <= (v.back())[1])
            {
                int x=v.back()[1]-i[0]+1;
                if((i[1]-x) >0)
                v.back()[2]+=(i[1]-x);
                
                v.back()[1]=max(v.back()[1], i[1]);
                
            }
            else
            {
                v.push_back(i);
            }
        }
    }
    int ans = 0;
    for (auto i : v)
    {
        ans += (i[2]);
    }
    return ans;
}
int main()
{

    return 0;
}