#include<iostream>
using namespace std;

template<class T>
class queue
{
private:
    int head=0;
    int rear=0;
    int size=0;
    int maxsize=3;
   void doublesize()
    {
        maxsize=maxsize*2;
        T* tmp=store;
        store=new T[maxsize];
        for(int i=1;i<=size;i++)
            store[i]=tmp[(i+head)%(maxsize/2)];
        delete tmp;
    }
    T* store=new T[maxsize];
public:
    void enQueue(T a)
    {
        size=size+1;
        if(size==maxsize)
            doublesize();
        rear=(rear+1)%maxsize;
        store[rear]=a;
    }
    T deQueue()
    {
        size=size-1;
        head=(head+1)%maxsize;
        return store[head];
    }
    T getHead()
    {
        return store[head+1];
    }
    T get(int a)
    {
        return store[head+1+a];
    }
    bool isEmpty()
    {
        if(head==rear)
            return 1;
        return 0;
    }
    bool isFull()
    {
        if(head==(rear+1)%maxsize)
            return 1;
        return 0;
    }
    void print()
    {
        for(int i=head+1;i<=rear;i++)
            cout<<store[i]<<" ";
            cout<<endl;
    }
    queue(){}
    ~queue()
    {
        delete [] store;
    }
};

int main()
{
    queue<int> a;
    a.enQueue(1);//a.print();
    int b=a.deQueue();
    cout<<b;
}
