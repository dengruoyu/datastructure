#include<iostream>
using namespace std;

template<class T>
class stack
{
private:
    struct node
    {
        T number;
        node* next;
        node(T a,node *b=NULL):number(a),next(b){}
    };
    node *head;
    T length;
public:
    stack()
    {
        head=NULL;
        length=0;
    }
    bool isEmpty()
    {
        if(length==0)
            return 1;
        return 0;
    }
    void push(T a)
    {
        node* tmp=new node(a,head);
        head=tmp;
        length++;
    }
    T pop()
    {
        node *tmp=head;
        T x=head->number;
        head=head->next;
        length--;
        delete tmp;
        return x;
    }
    T top()
    {
        return head->number;
    }
    int len()
    {
        return length;
    }
    T get(int place)
    {
        node*tmp=head;
        for(int i=0;i<=place;i++)
            tmp=tmp->next;
        return tmp->number;
    }
    node *move(int place)
    {
        node *tmp=head;
        for(int i=0;i<=place;i++)
            tmp=tmp->next;
        return tmp;
    }
    ~stack()
    {
        while(head!=NULL)
        {
            node *tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    void print()
    {
        node *tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->number<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
};

int main()
{
    stack<char> a;
    a.push('a');
    a.push('s');
    a.pop();
    a.push('d');
    a.push('f');
    a.print();
    cout<<a.top();
}

