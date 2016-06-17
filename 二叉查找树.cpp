#include<iostream>
using namespace std;

template<class T>
class tree
{
private:
    struct node
    {
        node *left;
        node *right;
        T data;
        node(T a,node *b=NULL,node *c=NULL)
        {
            data=a;
            left=b;
            right=c;
        }
    };
    node *root;
public:
    tree(){root=NULL;}
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
    void insert(T a)
    {
        node *tmp=new node(a);
        node *start=root;
        if(root==NULL)
        {
            root=tmp;
            return;
        }
        while(start->data!=a)
        {
            if(start->data<a)
            {
                if(start->right)
                    start=start->right;
                else
                {
                    start->right=tmp;
                    return;
                }
            }
            if(start->data>a)
            {
                if(start->left)
                    start=start->left;
                else
                {
                    start->left=tmp;
                    return;
                }
            }
        }
    }
    int find(T a)
    {
        node *start=root;
        if(root==NULL)
        {
            return 0;
        }
        while(start->data!=a)
        {
            if(start->data<a)
            {
                if(start->right)
                    start=start->right;
                else
                {
                    return 0;
                }
            }
            if(start->data>a)
            {
                if(start->left)
                    start=start->left;
                else
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    void remove(T a)
    {
        remove(a,root);
    }
    void remove(T a,node *&r)
    {
        if(r==NULL)
            return;
        if(r->data<a)
            remove(a,r->right);
        else if(r->data>a)
            remove(a,r->left);
        else if(r->data==a)
        {
            if(r->left && r->right)
            {
                node *tmp=r->right;
                while(tmp->left)
                    tmp=tmp->left;
                r->data=tmp->data;
                remove(tmp->data,r->right);
            }
            else
            {
                node *tmp=r;
                r=(r->left)?r->left:r->right;
                delete tmp;
            }
        }
    }
    void print()
    {
        print(root);
    }
    void print(node *a)
    {
        if(a)
        {
            print(a->left);
            cout<<a->data<<" ";
            print(a->right);
        }
    }
};

int main()
{
    tree<int> a;
    a.insert(1);a.print();cout<<endl;
    a.insert(5);a.print();cout<<endl;
    a.insert(2);a.print();cout<<endl;
    a.insert(8);a.print();cout<<endl;
    a.insert(1);a.print();cout<<endl;
    a.insert(10);a.print();cout<<endl;
    a.insert(19);a.print();cout<<endl;
    a.remove(5);a.print();cout<<endl;
    cout<<a.find(5);
}
