#include<bits/stdc++.h>
using namespace std;
void Insert(stack<int> &s, int temp)
{
    if(s.size()==0 or s.top()>=temp)
    {
        s.push(temp);
        return;
    }
    int val=s.top();
    s.pop();
    Insert(s, temp);
    s.push(val);
}
void SortStack(stack<int>&s)
{
    if(s.size()==1)
    {
        return;
    }
    int temp=s.top();
    s.pop();
    SortStack(s);
    Insert(s, temp);
}
void InsertRev(stack<int> &s, int temp)
{
    if(s.empty())
    {
        s.push(temp);
    }
    int val=s.top();
    s.pop();
    InsertRev(s,temp);
    s.push(val);
}
void ReverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int temp=s.top();
    s.pop();
    ReverseStack(s);
    InsertRev(s,temp);
}
int main()
{
    stack<int> s;

    s.push(5);
    s.push(2);
    s.push(1);
    s.push(14);
    s.push(8);

    SortStack(s);
    ReverseStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}