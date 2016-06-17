#include<iostream>
#include<queue>
using namespace std;

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
        //nodeList[v].head=new edge(u,l,nodeList[v].head);
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
    void prim()
    {
        int *isVisited=new int[nodes];
        int *v=new int[nodes];
        for(int i=0;i<nodes;++i)
            isVisited[i]=0;
        int complete=1;
        v[0]=0;
        isVisited[0]=1;
        while(complete<nodes)
        {
            int min=9999,minone,mintwo;
            for(int i=0;i<complete;i++)
            {
                edge* tmp=nodeList[v[i]].head;
                while(tmp)
                {
                    if(tmp->weight<=min && isVisited[tmp->end]==0)
                    {
                        min=tmp->weight;
                        minone=tmp->end;
                        mintwo=i;
                    }
                    tmp=tmp->next;
                }
            }
            isVisited[minone]=1;
            cout<<nodeList[mintwo].vertics<<" "<<nodeList[minone].vertics<<" "<<endl;
            v[complete]=minone;
            complete++;
        }
    }
};
int main()
{
    graph<char> a(4,"abcd");
    a.insert(0,1,1);
    a.insert(2,1,1);
    a.insert(3,1,1);
    a.insert(0,2,3);
    a.insert(0,3,3);
    a.insert(2,3,3);
    a.prim();
}
