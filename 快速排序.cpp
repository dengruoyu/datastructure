#include <iostream>
using namespace std;

int divide(int a[],int low,int high)
{
    int mid=low;
    int tmp=a[low];
    do
    {
        while(low<high&&a[high]>tmp)
            high--;
        if(low<high)
        {
            a[low]=a[high];
            ++low;
        }
        while(low<high&&a[low]<=tmp)
            ++low;
        if(low<high)
        {
            a[high]=a[low];
            --high;
        }
    }while(low!=high);
    a[low]=tmp;
    return low;
}

void quicksort(int a[],int start,int end)
{
    if(start>=end)
        return ;
    int mid=divide(a,start,end);
    quicksort(a,start,mid-1);
    quicksort(a,mid+1,end);
}


void sort(int a[],int size)
{
    quicksort(a,0,size-1);
}
int main()
{
    int a[10]={4,8,1,0,-8,9,62,7,12,3};
    sort(a,10);
 for(int i=0;i<10;++i)
            cout<<a[i]<<" ";
        cout<<endl;
}
