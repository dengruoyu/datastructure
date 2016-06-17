#include<iostream>
using namespace std;

void sort(int a[],int size)
{
    for(int i=1;i<size;++i)
    {
        int j;
        int tmp=a[i];
        for(j=i-1;j>=0&&a[j]>tmp;j--)
            a[j+1]=a[j];
        a[j+1]=tmp;
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
