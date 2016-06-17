#include<iostream>
using namespace std;

class set
{
private:
    int size;
    int *parent;
public:
    set(int s=10)
    {
        size=s;
        parent=new int[size];
        for(int i=0;i<size;i++)
            parent[i]=-1;
    }
    ~set()
    {
        delete [] parent;
    }
    int Find(int x)
    {
        if(parent[x]<0)
            return x;
        return parent[x]=Find(parent[x]);
    }
    void Union(int a,int b)
    {
        if(a==b)
            return;
        if(parent[a]>parent[b])
        {
            parent[b]+=parent[a];
            parent[a]=b;
        }
        else
        {
            parent[a]+=parent[b];
            parent[b]=a;
        }
    }
};
