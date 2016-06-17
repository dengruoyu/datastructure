#include <iostream>
using namespace std;

void connect(int a[],int left,int middle,int high)
{
    int *tmp=new int[high-left+1];

    int i=left,j=middle,k=0;
    while(i<middle&&j<=high)
    {
        if(a[i]<a[j])
        {
            tmp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            tmp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<middle)
    {
        tmp[k++]=a[i++];
    }
    while(j<=high)
    {
        tmp[k++]=a[j++];
    }
    for(i=0,k=left;k<=high;)
        a[k++]=tmp[i++];
}

void merge(int a[],int low,int high)
{
    int mid=(low+high)/2;
    if(high==low) return;
    merge(a,low,mid);
    merge(a,mid+1,high);
    connect(a,low,mid+1,high);
}

void sort(int a[],int size)
{
    merge(a,0,size-1);
}

int main()
{
    int a[10]={4,8,1,0,-8,9,62,7,12,3};
    sort(a,10);
 for(int i=0;i<10;++i)
            cout<<a[i]<<" ";
        cout<<endl;
}
