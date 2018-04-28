#include<bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long bigmod(int n,int r)
{
    long long d;
    if(r==0)return 1;
    if(r%2==1)
    {
        d=bigmod(n,r-1)%mod;
        return (d*(n%mod))%mod;
    }
    else
    {
        d=bigmod(n,r/2);
        return (d*d)%mod;
    }
}
int main()
{
    int n;
    cin>>n;
    return 0;
}
