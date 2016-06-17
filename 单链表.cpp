#include<iostream>
using namespace std;

struct node
{
    int number;
    node* next=NULL;
    node(int a=0,node *b=NULL):number(a),next(b){}
};
class link
{
private:
    node *head;
    int length=0;
public:
    link()
    {
        head=new node;
        length=0;
    }
    void insert(int place,int value)
    {
        node *tmp=head;
        for(int i=0;i<place;i++)
            tmp=tmp->next;
        node *tmp2=tmp->next;
        node *a=new node(value,tmp2);
        tmp->next=a;
        length++;
    }
    void remove(int place)
    {
        node *tmp=head;
        for(int i=0;i<place;i++)
            tmp=tmp->next;
        node *tmp2=tmp->next;
        tmp->next=tmp2->next;
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
    a.insert(0,100);
    cout<<a.get(2);
    a.remove(0);
    cout<<a.move(0)->number;
    a.print();
}
