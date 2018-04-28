#include<stdio.h>
#include<math.h>
int a[20000001];
long long b[100001][3];
int main()
{
    long long n,i,j,z,k,d=0;
    for(i=2; i<=sqrt(2001); i++)
    {
        if(a[i]==0)
        {
            for(j=2; (i*j)<=2001; j++)a[i*j]=1;
        }
    }
    for(i=2; i<100; i++)if(a[i]==0)printf("%d ",i);
    for(k=3; k<=18409199 ; k=k+2)
    {
        if(a[k]==1&&a[k+2]==1)
        {
            b[d][0]=k;
            b[d][1]=k+2;
            d++;
        }
    }
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==0)break;
        int count;
        count=n-1;
        printf("(%lld, %lld)\n",b[count][0],b[count][1]);
    }
    return 0;
}
/*

int a[20000001]={0};
int main()
{
for(i=2;i<=sqrt(20000001);i++){
            if(a[i]==0){
                for(j=2;i*j<=n;j++){
                    a[i*j]=1;
                }
            }
        }
}
