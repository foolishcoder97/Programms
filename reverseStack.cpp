#include<bits/stdc++.h>
using namespace std;
void InsertStack(stack<int>& s, int temp)
{
    if(s.size()==0)
    {
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    InsertStack(s, temp);
    s.push(val);
}
void ReverseStack(stack<int> &s)
{
    if(s.size()==1)
    {
        return;
    }
    int temp=s.top();
    s.pop();
    ReverseStack(s);
    InsertStack(s, temp);
}
int main()
{
    stack<int> s;

    s.push(5);
    s.push(2);
    s.push(1);
    s.push(14);
    s.push(8);

    ReverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}