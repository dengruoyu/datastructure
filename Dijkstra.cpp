#include<iostream>
#include<stack>
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
    void dijkstra(T a)
    {
        int start=-1;
        for(int i=0;i<nodes;i++)
            if(nodeList[i].vertics==a)
            {
                start=i;
                break;
            }
        if(start==-1)
            return;
        int *isVisited=new int[nodes];
        int *v=new int[nodes];
        int *distance=new int[nodes];
        int *parent=new int[nodes];
        for(int i=0;i<nodes;i++)
        {
            isVisited[i]=0;
            distance[i]=99999;
        }
        int included=0;
        isVisited[start]=1;
        v[included]=start;
        distance[start]=0;
        parent[start]=start;
        while(included!=nodes-1)
        {
            for(int i=0;i<=included;i++)
            {
                edge *tmp=nodeList[v[i]].head;
                while(tmp)
                {
                    if(isVisited[tmp->end]==0)
                    {
                        included++;
                        v[included]=tmp->end;
                        isVisited[tmp->end]=1;
                    }
                    int cnt=distance[v[i]]+tmp->weight;
                    if(cnt<distance[tmp->end])
                    {
                        distance[tmp->end]=cnt;
                        parent[tmp->end]=v[i];
                    }
                    tmp=tmp->next;
                }
            }
        }
        for(int i=0;i<nodes;++i)
        {
            int tmp=i;
            cout<<distance[i]<<" "<<nodeList[tmp].vertics;
            while(parent[tmp]!=start)
            {
                tmp=parent[tmp];
                cout<<"<-"<<nodeList[tmp].vertics;
            }
            cout<<"<-"<<nodeList[parent[tmp]].vertics;
            cout<<endl;
        }
    }
    /*void dijkstra(T a)
    {
        int start=-1;
        for(int i=0;i<nodes;i++)
            if(nodeList[i].vertics==a)
            {
                start=i;
                break;
            }
        if(start==-1)
            return;
        int *isVisited=new int[nodes];
        int *v=new int[nodes];
        int *distance=new int[nodes];
        int *parent=new int[nodes];
        for(int i=0;i<nodes;i++)
        {
            isVisited[i]=0;
            distance[i]=99999;
        }
        int included=0;
        distance[start]=0;
        parent[start]=start;
        while(included!=nodes-1)
        {
            int min=99999,minone;
            for(int i=0;i<nodes;i++)
            {
                if(distance[i]<min&&!isVisited[i])
                {
                    min=distance[i];
                    minone=i;
                }
            }
            isVisited[minone]=1;
            included++;
            edge *tmp=nodeList[minone].head;
            while(tmp)
            {
                if(distance[minone]+tmp->weight<distance[tmp->end])
                {
                    distance[tmp->end]=tmp->weight+distance[minone];
                    parent[tmp->end]=minone;
                }
                tmp=tmp->next;
            }
        }
        for(int i=0;i<nodes;++i)
        {
            int tmp=i;
            cout<<distance[i]<<" "<<nodeList[tmp].vertics;
            while(parent[tmp]!=start)
            {
                tmp=parent[tmp];
                cout<<"<-"<<nodeList[tmp].vertics;
            }
            cout<<"<-"<<nodeList[parent[tmp]].vertics;
            cout<<endl;
        }
    }*/
};

int main()
{
    graph<char> a(4,"abcd");
    a.insert(0,1,5);
    a.insert(0,2,1);
    a.insert(1,3,0);
    a.insert(2,3,-30);
    a.dijkstra('a');
}
