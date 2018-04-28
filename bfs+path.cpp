#include<bits/stdc++.h>
using namespace std;
map<string,int>level;
map<string,string>parent;
int bfs(string start,string goal,map<string,vector<string> >mymap)
{
    queue<string>q;
    q.push(start);
    level[start]=0;
    while(!q.empty()){
        string u;
        u=q.front();
        if(u==goal)return level[goal];
        q.pop();
        int siz;
        siz=mymap[u].size();
        for(int i=0;i<siz;i++){
                string n=mymap[u][i];
            if(level[n]==-1){
                q.push(n);
                parent[n]=u;
                level[n]=level[u]+1;
            }
        }
    }
    return -1;
}
void path(string start,string goal)
{
      if(start==goal)return;
      path(parent[start],goal);
    cout<<parent[start]<<" "<<start<<'\n';
}

int main()
{
    int test,hh=0;
    while(scanf("%d%*c",&test)==1)
    {
        map<string,vector<string> >mymap;
        if(hh!=0)printf("\n");
        hh=1;
        char s1[1000],s2[1000];
        char c1[1000],c2[1000];

        while(test--)
        {
            scanf("%s%*c%s",s1,s2);
            mymap[s1].push_back(s2);
            level[s1]=-1;
            level[s2]=-1;
            mymap[s2].push_back(s1);
        }
        scanf("%s%*c%s",c1,c2);
            int ans;
            ans=bfs(c1,c2,mymap);
            if(ans==-1)printf("No route\n");
            else {
                path(c2,c1);
            }
            parent.clear();
        }
    return 0;
}
