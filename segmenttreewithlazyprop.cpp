#include<bits/stdc++.h>
using namespace std;
int a[100000];
struct lol
{
    int sum;
    int prop;
} tree[400000];
void input(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=a[b];
        return ;
    }
    int mid,left,right;
    mid=(b+e)/2;
    left=2*node;
    right=2*node+1;
    input(left,b,mid);
    input(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(i>e||j<b)return ;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return ;
    }
    int mid,left,right;
    mid=(b+e)/2;
    left=2*node;
    right=2*node+1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int j,int carry)
{
    if(b>j||i>e)return 0;
    if(b>=i&&e<=j)
    {
        return tree[node].sum+carry*(e-b+1);
    }
    int mid,left,right;
    mid=(b+e)/2;
    left=2*node;
    right=2*node+1;
    int p1,p2;
    p1=query(left,b,mid,i,j,carry+tree[node].prop);
    p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{

}
