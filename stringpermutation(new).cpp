#include<bits/stdc++.h>
using namespace std;
int a[10],n;
vector<int>v;
int colour[100];
void strng(int pos)
{
    if(pos>=n)
    {
        for(int i=0;i<v.size();i++)printf("%d ",v[i]);
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        if(colour[i]==0)
        {
            colour[i]=1;
            v.push_back(a[i]);
            strng(pos+1);
            v.pop_back();
            colour[i]=0;
        }
    }
}
int main()
{
    a[0]=1;
    a[1]=2;
    a[2]=3;
    a[3]=4;
    a[4]=5;
    n=5;
    memset(colour,0,sizeof(colour));
    strng(0);
}
