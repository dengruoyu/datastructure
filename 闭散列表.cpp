#include<iostream>
using namespace std;

class hashtable
{
    struct node
    {
        int data;
        int state=0;    //0--empty,1--active,2--delete

        node(int m=0,int n=0):data(n),state(n){}
    };

    node *array;
    int size;
public:
    hashtable(int a=10)
    {
        size=a;
        array=new node[size];
    }
    ~hashtable()
    {
        delete[]array;
    }
    bool find(int x)
    {
        int start,pos;
        start=pos=x%size;
        do
        {
            if(array[pos].state==0)
                return 0;
            if(array[pos].state==1 && array[pos].data==x)
                return 1;
            pos=(pos+1)%size;
        }while(pos!=start);
        return 0;
    }
    bool insert(int x)
    {
        int start,pos;
        start=pos=x%size;
        do
        {
            if(array[pos].state!=1)
            {
                array[pos].data=x;
                array[pos].state=1;
                return 1;
            }
            else if(array[pos].state==1 && array[pos].data==x)
                return 1;
            pos=(pos+1)%size;
        }while(pos!=start);
        return 0;
    }
    bool remove(int x)
    {
        int start,pos;
        start=pos=x%size;
        do
        {
            if(array[pos].state==0)
                return 0;
            if(array[pos].state==1 && array[pos].data==x)
            {
                array[pos].state=2;
                return 1;
            }
            pos=(pos+1)%size;
        }while(pos!=start);
        return 0;
    }
    void rehash()
    {
        node *tmp=array;
        array=new node[size];
        for(int i=0;i<size;++i)
        {
            if(tmp[i].state==1)
                insert(tmp[i].data);
        }
        delete []tmp;
    }
    void print()
    {
        for(int i=0;i<size;++i)
            cout<<array[i].data<<" ";
        cout<<endl;
    }
};

int main()
{
    hashtable a;
    a.insert(5);//a.print();
    a.insert(1);
    a.insert(2);
    a.insert(7);
    a.insert(12);
    a.insert(5);
    a.remove(5);
    cout<<a.find(12);
}
