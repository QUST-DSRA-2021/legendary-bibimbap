#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int a[100],b[100],c[100],d[100];

int total;

int n;

int print()
{
    if(total<=2)
    {
        for(int k=1;k<=n;k++)
        cout<<a[k]<<" ";
        cout<<endl;
    }
    total++;
}

void queen(int i)
{
    if(i>n)
    {
        print();
        return;
    }
    else
    {
        for(int j=1;j<=n;j++)
        {
            if((!b[j])&&(!c[i+j])&&(!d[i-j+n]))
            {
                a[i]=j;
                
                b[j]=1;
                c[i+j]=1;
                d[i-j+n]=1;
                
                queen(i+1);
                
                b[j]=0;
                c[i+j]=0;
                d[i-j+n]=0;
            }
        }
    }
}

int main()
{    
    cin>>n;
    queen(1);
    cout<<total;
    return 0;
}
