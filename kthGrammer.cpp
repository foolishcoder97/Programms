#include<bits/stdc++.h>
using namespace std;
int kthGrammer(int n, int k)
{
    if(n==1 and k==1)
    {
        return 0;
    }
    int mid=(pow(2,n-1))/2;
    if(k<=mid)
    {
        return kthGrammer(n-1, k);
    }else{
        return !(kthGrammer(n-1, k-mid));
    }
}
int main()
{
    int n=4;
    int k=2;

    cout<<kthGrammer(n, k)<<endl;

    return 0;
}