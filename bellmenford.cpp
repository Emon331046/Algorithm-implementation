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
long long inf=999999999999,node,edge;
int update_happen;
long long d[500];
vector<long long>v;
struct lol
{
    int x;
    int y;
    int w;
} g[500];
void relaxation()
{
        for(int j=0; j < edge ; j++)
        {
            int u,v,cost;
            u=g[ j].x;
            v=g[ j].y;
            cost=g[ j].w;
            if(d[u]+cost<d[v])
            {
                update_happen=1;
                d[v]=d[u]+cost;
                //par[v]=u;
            }
        }
}
void bellmenford()
{
    v.pb(inf);
    for(int i=0;i<=node;i++)d[i]=inf;

    d[1]=0;
    for(int i=0 ; i<node -1; i++)
    {
        update_happen=0;
        relaxation();
        cout<<d[node]<<endl;
        v.push_back(d[node]);
        //d[node]=inf;
    }

    //cheking for cycle

    //update_happen=0;
    //relaxaion();

}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin ("");
    ofstream fout ("");
    int tst,query;
    cin>>tst;
    while(tst--)
    {
        cin>>node;
        map< string ,int > mp;
        for(int i=1;i<=node;i++)
        {
            string s;
            cin>>s;
            mp[s]=i;
        }
        cin>>edge;
        for(int j =0; j<edge;j++)
        {
            string a,b;
            int cost;
            cin>>a>>b>>cost;
            g[ j].x=mp[a];
            g[ j].y=mp[b];
            g[ j].w=cost;
        }

        bellmenford();

        cin>>query;
        for(int i=0; i < query ; i++)
        {
            int r;
            cin>>r;
            cout<<v[r-1]<<endl;
        }
    }
    return 0;
}

