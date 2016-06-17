#include<iostream>
using namespace std;

template<class T>
class stack
{
private:
    struct node
    {
        T number;
        node* next=NULL;
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


template<class T>
class queue
{
private:
    int head=0;
    int rear=0;
    int size=0;
    int maxsize=30;
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

template <class T>
class tree
{
    struct node
    {
        node *left;
        node *right;
        T data;
        node(T a,node *b=NULL,node *c=NULL):data(a),left(b),right(c){}
    };
    int number=0;
    node *root=NULL;
public:
    tree(){}
    tree(T a)
    {
        root=new node(a);
    }
    void create()
    {
        queue<node*> s;
        node *tmp;
        T rootValue;
        cin>>rootValue;
        root=new node(rootValue);
        number++;
        s.enQueue(root);
        while(!s.isEmpty())
        {
            tmp=s.deQueue();
            T l,r;
            cout<<tmp->data<<':';
            cin>>l>>r;
            if(l!=0)
            {
                number++;
                tmp->left=new node(l);
                s.enQueue(tmp->left=new node(l));
            }
            if(r!=0)
            {
                number++;
                tmp->right=new node(r);
                s.enQueue(tmp->right=new node(r));
            }
        }
    }
    ~tree()
    {
        clear();
    }
    void clear()
    {
        if(root!=NULL)
            clear(root);
        root=NULL;
    }
    void clear(node*a)
    {
        if(a->left)
            clear(a->left);
        if(a->right)
            clear(a->right);
        delete a;
    }
    int getNumber()
    {
        return number;
    }
    void preOrder()
    {
        preOrder(root);
    }
    void preOrder(node *t)
    {
        if(t)
        {
            cout<<t->data<<" ";
            preOrder(t->left);
            preOrder(t->right);
        }
    }
    void midOrder()
    {
        midOrder(root);
    }
    void midOrder(node *t)
    {
        if(t)
        {
            midOrder(t->left);
            cout<<t->data<<" ";
            midOrder(t->right);
        }
    }
    void postOrder()
    {
        postOrder(root);
    }
    void postOrder(node *t)
    {
        if(t)
        {
            postOrder(t->left);
            postOrder(t->right);
            cout<<t->data<<" ";
        }
    }
    void preOrder2()
    {
        stack<node *> a;
        a.push(root);
        node *tmp;
        while(!a.isEmpty())
        {
            tmp=a.pop();
            cout<<tmp->data<<" ";
            if(tmp->right)
                a.push(tmp->right);
            if(tmp->left)
                a.push(tmp->left);
        }
    }
    void midOrder2()
    {
       stack<node *>a;
       stack<int>b;
       a.push(root);
       b.push(0);
       while(!a.isEmpty())
       {
           node *tmp=a.top();
           if(b.top()==0)
           {
               if(tmp->left)
               {
                   a.push(tmp->left);
                   b.pop();
                   b.push(1);
                   b.push(0);
               }
               else
               {
                   cout<<tmp->data<<" ";
                   a.pop();
                   b.pop();
                   if(tmp->right)
                   {
                       a.push(tmp->right);
                       b.push(0);
                   }
               }

           }
           else
           {
               cout<<tmp->data<<" ";
               a.pop();
               b.pop();
               if(tmp->right)
               {
                   a.push(tmp->right);
                   b.push(0);
               }
           }
       }
    }
    void postOrder2()
    {
        stack<node *>a;
        stack<int>b;
        a.push(root);
        b.push(0);
        while(!a.isEmpty())
        {
            node *tmp=a.top();
            if(b.top()==0)
            {
                if(tmp->right)
                {
                    a.push(tmp->right);
                    b.pop();
                    b.push(1);
                    b.push(0);
                }
                if(tmp->left)
                {
                    a.push(tmp->left);
                    if(!tmp->right)
                    {
                        b.pop();
                        b.push(1);
                    }
                    b.push(0);
                }
                if(tmp->left==NULL && tmp->right==NULL)
                {
                    cout<<tmp->data<<" ";
                    a.pop();
                    b.pop();
                }

            }
            else
            {
                cout<<tmp->data<<" ";
                a.pop();
                b.pop();
            }
        }
    }
};

int main()
{
    tree<int> a;
    a.create();
    a.postOrder();
    cout<<endl;
    a.postOrder2();
}
