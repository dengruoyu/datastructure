#include<iostream>
using namespace std;

template<class T>
class priorityQueue
{
private:
    T* array;
    int size=0;
    int maxsize=100;
    void doublesize()
    {
        T* tmp=array;
        array=new T[2*maxsize];
        for(int i=0;i<=size;i++)
            array[i]=tmp[i];
        maxsize*=2;
        delete[] tmp;
    }
    void build()
    {
        for(int i=size/2;i>=1;i--)
            precolateDown(i);
    }
    void precolateDown(int hole)
    {
        while(hole*2<=size)
        {
            int child=2*hole;
            if(array[child+1]<array[child])
                child++;
            if(array[hole]>array[child])
            {
                T tmp=array[hole];
                array[hole]=array[child];
                array[child]=tmp;
                hole=child;
            }
            else
                break;
        }
    }
public:
    priorityQueue(){array=new T[maxsize];}
    priorityQueue(T data[],int a=100)
    {
        size=a;
        maxsize=2*size;
        array=new T[maxsize];
        for(int i=0;i<size;i++)
            array[i+1]=data[i];
        build();
    }
    bool isEmpty()
    {
        return size==0;
    }
    void enQueue(T a)
    {
        if(size==maxsize-1)
        {
            doublesize();
        }
        size++;
        int tmp=size;
        while(tmp>1 && a<array[tmp/2])
        {
            array[tmp]=array[tmp/2];
            array[tmp/2]=a;
            tmp=tmp/2;
        }
        array[tmp]=a;
    }
    T deQueue()
    {
        T res=array[1];
        array[1]=array[size];
        size--;
        precolateDown(1);
        return res;
    }
    void print()
    {
        for(int i=1;i<=size;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    int getsize()
    {
        return size;
    }
    int getmaxsize()
    {
        return maxsize;
    }
};

int main()
{
    int m[5]={10,8,5,7,100};

    priorityQueue<int> a;
    a.enQueue(10);a.print();
    a.enQueue(8);a.print();
    a.enQueue(5);a.print();
    a.enQueue(7000);a.print();
    a.enQueue(100);a.print();
    a.deQueue();a.print();
    a.deQueue();a.print();
    a.deQueue();a.print();
    a.deQueue();a.print();
    a.deQueue();a.print();
}
