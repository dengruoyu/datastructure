#include<iostream>
using namespace std;
void precolateDown(int a[],int start,int size)
{
    int tmp=a[start];
    while(start*2+1<size)
    {
        int child=2*start+1;
        if(child!=size-1&&a[child]>a[child+1])
            child++;
        if(a[child]>tmp)
            break;
        else
        {
            a[start]=a[child];
            start=child;
        }
    }
    a[start]=tmp;
}
void sort(int a[],int size)
{
    for(int i=size/2-1;i>=0;i--)
        precolateDown(a,i,size);

    for(int i=size-1;i>0;i--)
    {
        int tmp=a[0];
        a[0]=a[i];
        a[i]=tmp;
        precolateDown(a,0,i);
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
