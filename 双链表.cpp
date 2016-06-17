#include<iostream>
using namespace std;

struct node
{
    int number;
    node* next=NULL;
    node* before=NULL;
    node(int a=0,node *b=NULL,node *c=NULL):number(a),next(b),before(c){}
};
class link
{
private:
    node *head;
    node *tail;
    int length=0;
public:
    link()
    {
        head=new node;
        tail=new node;
        length=0;
        head->next=tail;
        tail->before=head;
    }
    void insert(int place,int value)
    {
        node *tmp=head;
        for(int i=0;i<place;i++)
            tmp=tmp->next;
        node *tmp2=tmp->next;
        node *a=new node(value,tmp2,tmp);
        tmp->next=a;
        tmp2->before=a;
        length++;
    }
    void remove(int place)
    {
        node *tmp=head;
        for(int i=0;i<place;i++)
            tmp=tmp->next;
        node *tmp2=tmp->next;
        tmp->next=tmp2->next;
        tmp2->next->before=tmp;
        delete tmp2;
        length--;
    }
    int len()
    {
        return length;
    }
    int get(int place)
    {
        node *tmp=head;
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
    ~link()
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
        node *tmp=head->next;
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
    link a;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin>>tmp;
        a.insert(i,tmp);
    }
    a.print();
}
