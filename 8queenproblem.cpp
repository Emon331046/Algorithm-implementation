#include<bits/stdc++.h>
using namespace std;
int coun=0;
int flag[10];
bool check(int row,int c)
{
    for(int i=0;i<row;i++)
    {
        if(flag[i]==c)return 0;
        if(abs(flag[i]-c)==abs(i-row))return 0;
    }
    return 1;
}
void queen(int row)
{
    if(row>=8)
    {
        coun++;
    }
    for(int i=0;i<8;i++)
    {
        if(check(row,i))
        {
            flag[row]=i;
            queen(row+1);
            flag[row]=-1;
        }
    }
}
int main()
{
    queen(0);
    cout<<coun<<endl;
}
