#include<bits/stdc++.h>
using namespace std;
void Insert(vector<int>& v, int temp)
{
    if(v.size()==0 or v.back()<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val=v.back();
    v.pop_back();
    Insert(v,temp);
    v.push_back(val);
}
void SortArray(vector<int>& v)
{
    if(v.size()==1)
    {
        return;
    }
    int temp=v.back();
    v.pop_back();
    SortArray(v);
    Insert(v,temp);
    
}
int main()
{
    vector<int>v={5,8,2,4};
    // int n=sizeof(arr)/sizeof(int);

    SortArray(v);
    Insert(v,1);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
}