#include<bits/stdc++.h>
using namespace std;
int tree[400000];
int a[100000];
void binarytree(int node,int beg,int endd)
{
    if(beg==endd)
    {
        tree[node]=a[beg];
        return ;
    }
    int left,right,mid;
    mid=(beg+endd)/2;
    left=2*node;
    right=2*node+1;
    binarytree(left,beg,mid);
    binarytree(right,mid+1,endd);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int beg,int endd,int i,int j)
{
    if(i>endd||j<beg)return 0;
    if(beg>=i&&endd<=j)return tree[node];
    int left,right,mid;
    mid=(beg+endd)/2;
    left=2*node;
    right=2*node+1;
    int p1,p2;
    p1=query(left,beg,mid,i,j);
    p2=query(right,mid+1,endd,i,j);
    return p1+p2;
}
void update(int node,int beg,int endd,int i,int newvalue)
{
    if(i>endd||i<beg)return ;
    if(i==beg&&i==endd)
    {
        tree[node]=newvalue;
        return ;
    }
    int left,right,mid;
    mid=(beg+endd)/2;
    left=2*node;
    right=2*node+1;
    update(left,beg,mid,i,newvalue);
    update(right,mid+1,endd,i,newvalue);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    for(int i=1;i<8;i++)cin>>a[i];
    binarytree(1,1,7);
    update(1,1,7,4,10);
    int sum=query(1,1,7,2,5);
    cout<<sum<<endl;
    return 0;
}
