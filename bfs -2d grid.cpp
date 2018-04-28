#include<bits/stdc++.h>
using namespace std;
#define pii pair< int ,int >

int  vis[500][500];
int n,m;
int flag;
void bfs(int x,int y)
{
    int fx[]= {-2,-2,-1};
    int fy[]= {1,-1,-2};
    queue< pii >q;
    int level[200][200]={0};
    q.push(pii(x,y));
    level[x][y]=1;
    int flag=0;
    while(!q.empty())
    {
        pii tp=q.front();
        q.pop();
        for(int i=0; i<3; i++)
        {
            int tx,ty;
            tx=tp.first+fx[i];
            ty=tp.second+fy[i];
            if(tx<16&&ty<16&&tx>=1&&ty>=1)
            {
                q.push(pii(tx,ty));
                level[tx][ty]=level[tp.first][tp.second]+1;
                if(tx<=2&&ty<=2)
                {
                cout<<level[tx][ty]<<tx<<ty<<endl;
                     if(level[tx][ty]%2==0)flag=2;
                     else flag=1;
                     break;
                }
            }
        }
            if(flag==1||flag==2)break;
    }
    if(flag==1)cout<<"first"<<endl;
    else if(flag==2)cout<<"second"<<endl;
    //else
}
int main()
{
    int a,b,c,d;
    int test,t=1;
    while(cin>>a>>b)
    {
        bfs(a,b);
    }
    return 0;
}

