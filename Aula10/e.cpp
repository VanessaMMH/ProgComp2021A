#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stack>
using namespace std;
const int maxx = 2e5+10;
int a[maxx];
int b[maxx];

int main()
{
    int n;
    while(cin>>n)
    {
        int i;
        n*=2;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int k = -1;
       i = 0;
       while(i<n)
       {
           if(k==-1)
           {
               b[++k] = a[i];
               i++;
               printf("%d\n if",k);
           }
           else
           {
               if(b[k]==a[i])
               {
                   i++;
                   k--;
               }
               else
               {
                   b[++k] = a[i];
                   i++;
               }
           }
       }
       if(k==-1)
        printf("%d\n",n);
       else{
        printf("impossible\n");
        printf("%d el\n",k);
       }
    }
    return 0;
}