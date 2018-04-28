/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;
#define mod 1000000007
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define PI acos(-1.00)
#define pb push_back
#define ppb pop_back
ll sum[5000005],a[5000005];
ll func(ll n)
{
    ll ans=a[0];
    sum[0]=a[0];
    for(ll i=1; i<n; i++)
    {
        sum[i]=sum[i-1]+a[i];
        ans+=a[i];
    }
    if(ans%3!=0)return 0;
    ans/=3;
    llu cnt=0,coun=0;
    if(ans==0)
    {
        for(int i=0;i<n;i++)
        {
          if(sum[i]==0)cnt++;
        }
        cnt=((cnt-2)*(cnt-1))/2;
        return cnt;
    }
    for(ll i=0; i<n-1; i++)
    {
        if(sum[i]==ans)
        {
            coun++;
        }
        if(sum[i]==ans*2)cnt+=coun;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin ("");
    ofstream fout ("");
    int n;
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    cout<<func(n)<<endl;
    return 0;
}

