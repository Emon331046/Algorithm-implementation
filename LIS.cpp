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
int n;
int a[100005];
int lis[100005];
void LIS()
{
    for(int i=1;i<n;i++)lis[i]=999999999;
    lis[0]=-9999999;
    int lislength=0;
    for(int i=0;i<n;i++)
    {
        int low=0,high=lislength,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(lis[mid]<a[i])low=mid+1;
            else high=mid-1;
        }
        if(low>lislength)lislength=low;
        lis[low]=a[i];
    }
    cout<<lislength<<endl;
    return ;
}
int main()
{
    ios::sync_with_stdio(false);
    //ifstream fin ("");
    //ofstream fout ("");
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    LIS();
    return 0;
}


