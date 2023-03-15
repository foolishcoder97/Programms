#include<bits/stdc++.h>
using namespace std;
void DeleteMiddle(stack<int>&s, int n)
{
    if(s.size()==0)
    {
        return;
    }
    if(s.size()==(n/2 +1))
    {
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    DeleteMiddle(s, n);
    s.push(temp);
}
int main()
{
    stack<int> s;

    s.push(5);
    s.push(2);
    s.push(1);
    s.push(14);
    s.push(8);
    s.push(20);

    DeleteMiddle(s, s.size());
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}