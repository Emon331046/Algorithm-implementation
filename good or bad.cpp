#include<bits/stdc++.h>
using namespace std;
char a[3][3];
int check(char ch)
{
    if (a[0][0] == ch && a[0][1] == ch && a[0][2] == ch)
        return 0;

    if (a[1][0] == ch && a[1][1] == ch && a[1][2] == ch)
        return 0;

    if (a[2][0] == ch && a[2][1] == ch && a[2][2] == ch)
        return 0;

    if (a[0][0] == ch && a[1][0] == ch && a[2][0] == ch)
        return 0;

    if (a[0][1] == ch&& a[1][1] == ch && a[2][1] == ch)
        return 0;

    if (a[0][2] == ch && a[1][2] == ch && a[2][2] == ch)
        return 0;

    if (a[0][0] == ch&& a[1][1] == ch&& a[2][2] == ch)
        return 0;

    if (a[0][2] == ch&&a[1][1] == ch && a[2][0] == ch)
        return 0;

    return 1;
}
int main()
{
    int t,i,j,xc=0,oc=0;
    cin>>t;
    while(t--)
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                cin>>a[i][j];
            }
        }
        //cout<<endl;
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(a[i][j]=='X')xc++;
                else if(a[i][j]=='O')oc++;
            }
        }
        if(oc==xc)
        {
            int flag=check('X');
            if(flag)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        else if(xc-1==oc)
        {
            int flag=check('O');
            if(flag)cout<<"yes"<<endl;
            else cout<<"no"<<endl;

        }
        else
        {
            cout<<"no"<<endl;
        }
        oc=0,xc=0;
    }
    return 0;
}
/*
1
XXX
OO.
XO.*/
