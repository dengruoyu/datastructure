#include<iostream>
#include<queue>
using namespace std;

struct bian
{
    int edge1;
    int edge2;
    int weight;
    bool operator>(const bian &rp)const
    {
        return weight>rp.weight;
    }
    bool operator<(const bian &rp)const
    {
        return weight<rp.weight;
    }
    bian(int a=0,int b=0,int c=0)
    {
        edge1=a;
        edge2=b;
        weight=c;
    }
};

template<class T>
class priorityQueue
{
private:
    T* array;
    int size=0;
    int maxsize=100;
    void doublesize()
    {
        T* tmp=array;
        array=new T[2*maxsize];
        for(int i=0;i<=size;i++)
            array[i]=tmp[i];
        maxsize*=2;
        delete[] tmp;
    }
    void build()
    {
        for(int i=size/2;i>=1;i--)
            precolateDown(i);
    }
    void precolateDown(int hole)
    {
        while(hole*2<=size)
        {
            int child=2*hole;
            if(array[child+1]<array[child])
                child++;
            if(array[hole]>array[child])
            {
                T tmp=array[hole];
                array[hole]=array[child];
                array[child]=tmp;
                hole=child;
            }
            else
                break;
        }
    }
public:
    priorityQueue(){array=new T[maxsize];}
    priorityQueue(T data[],int a=100)
    {
        size=a;
        maxsize=2*size;
        array=new T[maxsize];
        for(int i=0;i<size;i++)
            array[i+1]=data[i];
        build();
    }
    bool isEmpty()
    {
        return size==0;
    }
    void enQueue(T a)
    {
        if(size==maxsize-1)
        {
            doublesize();
        }
        size++;
        int tmp=size;
        while(tmp>1 && a<array[tmp/2])
        {
            array[tmp]=array[tmp/2];
            array[tmp/2]=a;
            tmp=tmp/2;
        }
        array[tmp]=a;
    }
    T deQueue()
    {
        T res=array[1];
        array[1]=array[size];
        size--;
        precolateDown(1);
        return res;
    }
    void print()
    {
        for(int i=1;i<=size;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    int getsize()
    {
        return size;
    }
    int getmaxsize()
    {
        return maxsize;
    }
};

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

template <class T>
class graph
{
private:
    struct edge
    {
        int end;
        int weight;
        edge *next;
        edge(int a=0,int b=0,edge *c=NULL):end(a),weight(b),next(c){}
    };
    struct node
    {
        T vertics;
        edge *head;
        node(edge* b=NULL)
        {
            head=b;
        }
    };
    node* nodeList;
    int edges=0,nodes=0;
public:
    graph(int a,T b[])
    {
        nodes=a;
        edges=0;
        nodeList=new node[a];
        for(int i=0;i<nodes;i++)
            nodeList[i].vertics=b[i];
    }
    ~graph()
    {
        for(int i=0;i<nodes;++i)
        {
            edge *tmp=nodeList[i].head;
            while(tmp!=NULL)
            {
                edge *d=tmp;
                tmp=tmp->next;
                delete d;
            }
        }
        delete [] nodeList;
    }
    void insert(int u,int v,int l)
    {
        edges++;
        nodeList[u].head=new edge(v,l,nodeList[u].head);
    }
    void remove(int u,int v)
    {
        edge *a=nodeList[u].head;
        if(a==NULL)
            return;
        if(a->end==v)
        {
            nodeList[u].head=a->next;
            delete a;
            edges--;
            return;
        }
        while(a->next&&a->next->end!=v)
            a=a->next;
        if(a->next!=NULL)
        {
            edge *tmp=a->next;
            a->next=tmp->next;
            delete tmp;
            edges--;
            return;
        }
        return;
    }
    int exist(int u,int v)
    {
        edge *a=nodeList[u].head;
        while(a&&a->end!=v)
            a=a->next;
        if(a==NULL)
            return 0;
        return 1;
    }
    void dfs()
    {
        bool *visited=new bool[nodes];
        for(int i=0;i<nodes;++i)
            visited[i]=0;
        for(int i=0;i<nodes;i++)
        {
            if(visited[i])
                continue;
            else
                dfs(i,visited);
            cout<<endl;
        }
    }

    void kruskal()
    {
        priorityQueue<bian> a;
        set b(nodes);
        bian c;
        for(int i=0;i<nodes;i++)
        {
            edge* tmp=nodeList[i].head;
            while(tmp!=NULL)
            {
                a.enQueue(bian(i,tmp->end,tmp->weight));
                tmp=tmp->next;
            }
        }
        int cnt=0;
        while(cnt<nodes-1)
        {
            bian tmp=a.deQueue();
            int x=tmp.edge1;
            int y=tmp.edge2;
            if(b.Find(x)==b.Find(y))
                continue;
            cout<<nodeList[x].vertics<<" "<<nodeList[y].vertics<<" ";
            b.Union(x,y);
            cnt++;

        }
    }
};
int main()
{
    graph<char> a(6,"abcdef");
    a.insert(0,1,2);
    a.insert(1,2,3);
    a.insert(2,3,4);
    a.insert(3,4,5);
    a.insert(4,5,6);
    a.insert(5,0,7);
    a.kruskal();
}
