/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
#include<iostream>
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
int sparse[32][100000];
int parent[100000];
int level[100000];
vector<int>graph[100000];
void dfs(int from,int node,int depth)
{
    level[node]=depth;
    parent[node]=from;
    for(int i=0; i < graph[node].size() ;i++)
    {
        int v=graph[node][ i ];
        if(v==from) continue ;
        dfs( node , v , depth+1 );
    }
}
void lca(int n )
{
    //memset ( sparse , -1 , sizeof(sparse) );
    for(int i=0 ; i < n ; i++ )sparse[0][i]=parent[i];
    for(int j=1; (1<<j) < n ; j++ )
    {
        for(int i=0 ; i < n ;i++)
        {
            if(sparse[ j -1 ][ i ]!= -1)sparse[ j ][i]=sparse[ j-1 ][ sparse[j-1][i] ];
        }
    }
}
int lca_query(int p,int q )
{
    if(level[p]<level[q])swap(p,q);
    int lg=1;
    while(1)
    {
        if( (1<<lg) > level[p] )break;
        lg++;
    }
    for(int i=lg ; i>=0 ;i--)
    {
        if( level[p] - (1<<i) >= level[q] )p=sparse[i][p];
    }
    if(p==q)return p;
    for(int i=lg;i>=0;i--)
    {
        if( sparse[i][p] != -1 && sparse[i][p] != sparse[i][q] )
        {
            p=sparse[i][p];
            q=sparse[i][q];
        }
    }
    return parent[p];
}
int main()
{
    ios::sync_with_stdio(false);
    //ifstream fin ("");
    //ofstream fout ("");
    int tst,t=1;

    return 0;
}



