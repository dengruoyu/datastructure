#include<iostream>
using namespace std;

void sort(int a[],int size)
{
    int step=size/2;
    for(step;step>0;step=step/2)
    {
        for(int j=step;j<size;j++)
        {
            int tmp=a[j];
            int i;
            for(i=j-step;i>=0&&a[i]>tmp;i-=step)
                a[i+step]=a[i];
            a[i+step]=tmp;
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
