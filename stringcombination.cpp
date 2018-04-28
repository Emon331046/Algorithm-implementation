#include<bits/stdc++.h>
using namespace std;
int a[10],n;
vector<int>v;
int colour[100];
void strng(int pos)
{

    for(int i=pos;i<n;i++)
    {
        if(colour[i]==0)
        {
            colour[i]=1;
            v.push_back(a[i]);
            for(int j=0;j<v.size();j++)printf("%d ",v[j]);
            cout<<endl;
            strng(i+1);
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
    n=3;
    memset(colour,0,sizeof(colour));
    strng(0);
}
