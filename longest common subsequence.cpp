#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t[10][10],l1,l2,k1,k2;
    char s1[10],s2[10],c1[10],c[2];
    scanf("%s",s1);
    scanf("%s",s2);
    k1=strlen(s1);
    k2=strlen(s2);
    l1=k1;
    l2=k2;
    if(l1<l2)swap(l1,l2);
    int i,j;
    for(i=0;i<10;i++){
        t[0][i]=0;
        t[i][0]=0;
    }
    for(i=1;i<=l1;i++){
        for(j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1]){
                t[i][j]=t[i-1][j-1]+1;
            }
            else {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    printf("lis=%d\n",t[l1][l2]);
    int n,m;
    m=l1;
    n=l2;
    int dumb=t[l1][l2];
    char ne[10];
    ne[dumb]=0;
    dumb--;
    while(dumb>=0){
        if(t[m][n]==t[m][n-1])n--;
        else if(t[m][n]==t[m-1][n])m--;
        else if(t[m][n]==(t[m-1][n-1]+1)){
            ne[dumb]=s1[m-1];
            dumb--;
            m--;
            n--;
        }
    }
    printf("lis is=%s\n",ne);
    return 0;
}

