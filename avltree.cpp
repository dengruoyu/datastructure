#include<iostream>
using namespace std;

template<class T>
class tree
{
private:
    struct node
    {
        T data;
        node *left;
        node *right;
        int height;
        node(T a,node* b=NULL,node *c=NULL,int d=0):data(a),left(b),right(c),height(d){}
    };
    node* root;
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
    bool find(T x)
    {
        node *t=root;
        while(t!=NULL && t->data!=x)
            if(t->data>x)
                t=t->left;
            else
                t=t->right;
        if(t) return 1;
        else
            return 0;
    }
    void insert(T x)
    {
        insert(x,root);
    }
    void insert(T x,node *&t)
    {
        if(t==NULL)
        {
            t=new node(x,NULL,NULL);
        }
        else if(t->data>x)
        {
            insert(x,t->left);
            if(height(t->left)-height(t->right)==2)
            {
                if(t->left->data>x)
                    LL(t);
                else
                    LR(t);
            }
        }
        else if(t->data<x)
        {
            insert(x,t->right);
            if(height(t->right)-height(t->left)==2)
            {
                if(t->right->data>x)
                    RL(t);
                else
                    RR(t);
            }
        }
        t->height=max(height(t->right),height(t->left))+1;
    }
    void LL(node *&t)
    {
        node *tmp=t->left;
        t->left=tmp->right;
        tmp->right=t;
        t->height=max(height(t->left),height(t->right))+1;
        tmp->height=max(height(tmp->left),height(tmp->right))+1;
        t=tmp;
    }
    void RR(node *&t)
    {
        node *tmp=t->right;
        t->right=tmp->left;
        tmp->left=t;
        t->height=max(height(t->left),height(t->right))+1;
        tmp->height=max(height(tmp->left),height(tmp->right))+1;
        t=tmp;
    }
    void LR(node *&t)
    {
        RR(t->left);
        LL(t);
    }
    void RL(node *&t)
    {
        LL(t->right);
        RR(t);
    }
    void remove(T a)
    {
        remove(a,root);
    }
    bool remove(T x,node *&t)
    {
        bool stop=0;
        int subTree;  //1表示删除左子数，2表示右子树

        if(t==NULL) return 1;
        if(x<t->data)
        {
            stop=remove(x,t->left);
            subTree=1;
        }
        else if(x>t->data)
        {
            stop=remove(x,t->right);
            subTree=2;
        }
        else if(t->left!=NULL && t->right!=NULL)
        {
            node *tmp=t->right;
            while(tmp->left)
                tmp=tmp->left;
            t->data=tmp->data;
            stop=remove(t->data,tmp->right);
            subTree=2;
        }
        else
        {
            node *tmp=t;
            t=(t->left)?t->left:t->right;
            delete tmp;
            return 0;
        }
        if(stop)
            return 1;
        int bf;
        switch(subTree)
        {
            case 1: bf=height(t->left)-height(t->right)+1;
            if(bf==0)
                return 1;
            if(bf==1)
                return 0;
            if(bf==-1)
            {
                int bfr=height(t->right->left)-height(t->right->right);
                switch(bfr)
                {
                    case 0:RR(t);return 1;
                    case -1:RR(t);return 0;
                    default:RL(t);return 0;
                }
            }
            break;
            case 2: bf=height(t->left)-height(t->right)+1;
            if(bf==0)
                return 1;
            if(bf==-1)
                return 0;
            if(bf==1)
            {
                int bfl=height(t->left->left)-height(t->left->right);
                switch(bfl)
                {
                    case 0:LL(t);return 1;
                    case 1:LL(t);return 0;
                    default:LR(t);return 0;
                }
            }
        }
    }
    int height(node *a)
    {
        if(a==NULL)
            return -1;
        else
            return a->height;
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
