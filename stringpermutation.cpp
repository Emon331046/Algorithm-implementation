#include<bits/stdc++.h>
using namespace std;
int test,coun=0,n;
map<string,int>mymap;
void perm(string a,int l,int r)
{
    if(coun==120)return;
    if(l==r){
            coun++;
            mymap[a]=coun;
    }
    else
    {

        for(int i=l;i<=r;i++){
            swap((a[l]),(a[i]));
            perm(a,l+1,r);
            swap(a[i],a[l]);

        }

    }
}
int main()
{
    string a;
    int t,i=0;
    scanf("%d",&t);
    while(t--){
            scanf("%d%d",&test,&n);
    i++;
    cout<<"Case "<<i<<':'<<'\n';
        if(test==26)a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if(test==25)a="ABCDEFGHIJKLMNOPQRSTUVWXY";
        if(test==24)a="ABCDEFGHIJKLMNOPQRSTUVWX";
        if(test==23)a="ABCDEFGHIJKLMNOPQRSTUVW";
        if(test==22)a="ABCDEFGHIJKLMNOPQRSTUV";
        if(test==21)a="ABCDEFGHIJKLMNOPQRSTU";
        if(test==20)a="ABCDEFGHIJKLMNOPQRST";
        if(test==19)a="ABCDEFGHIJKLMNOPQRS";
        if(test==18)a="ABCDEFGHIJKLMNOPQR";
        if(test==17)a="ABCDEFGHIJKLMNOPQ";
        if(test==16)a="ABCDEFGHIJKLMNOP";
        if(test==15)a="ABCDEFGHIJKLMNO";
        if(test==14)a="ABCDEFGHIJKLMN";
        if(test==13)a="ABCDEFGHIJKLM";
        if(test==12)a="ABCDEFGHIJKL";
        if(test==11)a="ABCDEFGHIJK";
        if(test==10)a="ABCDEFGHIJ";
        if(test==9)a="ABCDEFGHI";
        if(test==8)a="ABCDEFGH";
        if(test==7)a="ABCDEFG";
        if(test==6)a="ABCDEF";
        if(test==5)a="ABCDE";
        if(test==4)a="ABCD";
        if(test==3)a="ABC";
        if(test==2)a="AB";
        if(test==1)a="A";
       coun=0;
       perm(a,0,test-1);
       map<string,int>::iterator it;
       int k;
       for(it=mymap.begin(),k=0;k<n;it++,k++){
            if(it==mymap.end())break;
        cout<<it->first<<'\n';
       }
       mymap.clear();
    }
    return 0;
}
