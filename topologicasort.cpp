#include<bits/stdc++.h>
using namespace std;
vector< int >graph[500];
vector<int>solution;
int indegree[1000];
void tpsort(int n)
{
    queue<int>q;
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);

        }
    }
    while(!q.empty())
    {
        int top;
        top=q.front();
        q.pop();
        solution.push_back(top);
        for(int i=0; i<graph[top].size(); i++)
        {
            int temp;
            temp=graph[top][i];
            indegree[temp]--;
            if(indegree[temp]==0)q.push(temp);
        }
    }
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
        int a,b,i;
        for(i=0; i<500; i++)indegree[i]=0;
        if(n==0&&m==0)break;

        while(m--)
        {
            cin>>a;
            cin>>b;
            graph[a].push_back(b);
            indegree[b]++;
        }

        tpsort(n);
        printf("%d",solution[0]);
        for(int i=1; i<solution.size(); i++)printf(" %d",solution[i]);
        printf("\n");
        for(int i=1; i<400; i++)graph[i].clear();
        solution.clear();
    }
    return 0;
}
