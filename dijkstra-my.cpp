#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int >
vector<pii>g[200];
long long d[200],n;
void dijkstra()
{
    int i;
    for(i=1;i<=100;i++)
    {
        d[i]=9999999999;
    }

    priority_queue< pii, vector< pii >, greater<pii> >q;
    q.push(pii(0,1));
    d[1]=0;
    while(!q.empty())
    {
        int u,c;
        u=q.top().second;
        c=q.top().first;
        q.pop();
        if(d[u] < c) continue;
        for(i=0;i<g[u].size();i++)
        {
            int w,v;
            v=g[u][i].first;
            w=g[u][i].second;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push(pii(d[v],v));
            }
        }
    }
        if(d[n]==9999999999)cout<<"Impossible"<<endl;
        else cout<<d[n]<<endl;
}
int main()
{
    int u,v,w,test,t=1,i,e,s;
    cin>>test;
    while(test--)
    {

        cin>>n>>e;

        for(i=0;i<e;i++)
        {
            cin>>u>>v>>w;
            g[u].push_back(pii(v,w));
            g[v].push_back(pii(u,w));
        }
        printf("Case %d: ",t++);
        dijkstra();

         //cout<<d[temp]<<endl;
    for(i=0;i<200;i++)g[i].clear();
    }
    return 0;
}
