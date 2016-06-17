#include<iostream>
using namespace std;

class hashtable
{
private:
    struct node
    {
        int data;
        node* next;
        node(int a=0,node*b=NULL)
        {
            data=a;
            next=b;
        }
    };
    node* *array;
    int size;
public:
    hashtable(int a=10)
    {
        size=a;
        array=new node*[size];
        for(int i=0;i<size;++i)
            array[i]=new node;
    }
    ~hashtable()
    {
        node *p,*q;
        for(int i=0;i<size;++i)
        {
            p=array[i];
            do
            {
                q=p->next;
                delete p;
                p=q;
            }while(p!=NULL);
        }
        delete[]array;
    }
    bool find(int x)
    {
        int pos=x%size;
        node *p=array[pos];
        while(p->next!=NULL && !(p->next->data==x))
            p=p->next;
        if(p->next!=NULL)
            return 1;
        return 0;
    }
    bool insert(int x)
    {
        int pos=x%size;
        node *p=array[pos]->next;
        while(p!=NULL && !(p->data==x))
        {
            p=p->next;
        }
        if(p==NULL)
        {
            p=new node(x);
            p->next=array[pos]->next;
            array[pos]->next=p;
            return 1;
        }
        return 0;
    }
    bool remove(int x)
    {
        int pos=x%size;
        node *p=array[pos];
        while(p->next!=NULL && !(p->next->data==x))
        {
            p=p->next;
        }
        if(p->next==NULL)return 0;
        else
        {
            node *q;
            q=p->next;
            p->next=q->next;
            delete q;
            return 1;
        }
        return 0;
    }
    void print()
    {
        for(int i=0;i<size;i++)
        {
            node *tmp=array[i]->next;
            while(tmp)
            {
                cout<<tmp->data<<" ";
                tmp=tmp->next;
            }
        }
        cout<<endl;
    }
};
int main()
{
    hashtable a;
    a.insert(5);a.print();
    a.insert(1);a.print();
    a.insert(2);a.print();
    a.insert(7);a.print();
    a.insert(12);a.print();
    a.insert(5);a.print();
    a.remove(7);a.print();
    cout<<a.find(7);
}
