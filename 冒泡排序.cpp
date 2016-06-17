#include<iostream>
using namespace std;

void sort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int tmp=a[j+1];
                a[j+1]=a[j];
                a[j]=tmp;
            }
        }
    }
}

int main()
{
    int a[10]={4,8,1,0,-8,9,62,7,12,3};
    sort(a,10);
 for(int i=0;i<10;++i)
            cout<<a[i]<<" ";
        cout<<endl;
}
