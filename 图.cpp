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
        /*edge* tmp=new edge(v,l);
        node a=nodeList[u];
        tmp->next=a.head;
        nodeList[u].head=tmp;*/
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
    void dfs(int start,bool visited[])
    {
        edge *p=nodeList[start].head;
        cout<<nodeList[start].vertics<<" ";
        visited[start]=1;
        while(p!=NULL)
        {
            if(visited[p->end]==0)
                dfs(p->end,visited);
            p=p->next;
        }
    }
    void bfs()
    {
        bool *visited=new bool[nodes];
        for(int i=0;i<nodes;++i)
            visited[i]=0;
        queue<int> a;
        for(int i=0;i<nodes;++i)
        {
            if(visited[i])
                continue;
            a.push(i);
            while(!a.empty())
            {
                int tmp=a.front();
                a.pop();
                if(visited[tmp])
                    continue;
                cout<<nodeList[tmp].vertics<<" ";
                edge *p=nodeList[tmp].head;
                while(p)
                {
                    if(visited[p->end]==0)
                        a.push(p->end);
                    p=p->next;
                }
            }
            cout<<endl;
        }
    }
    struct EulerNode
    {
        int NodeNum;
        EulerNode *next;
        EulerNode(int ver){NodeNum=ver;next=NULL;}
    };
    void EulerCircuit(T start)
    {
        EulerNode *beg,*end,*p,*q,*tb,*te;
        int numOfDegree,i;
        edge *r;
        node *tmp;

        if(edges==0)
            return;
        for(int i=0;i<nodes;++i)
        {
            numOfDegree=0;
            r=nodeList[i].head;
            while(r)
            {
                ++numOfDegree;
                r=r->next;
            }
            if(numOfDegree==0 || numOfDegree%2)
                return;
        }

        for(i=0;i<nodes;i++)
            if(nodeList[i].vertics==start)
                break;
        if(i==nodes)
            return;

        tmp=clone();

        beg=EulerCircuit(i,end);
        while(1)
        {
            p=beg;
            while(p->next!=NULL)
                if(nodeList[p->next->NodeNum].head!=NULL)
                    break;
                else
                    p=p->next;
            if(p->next==NULL)
                break;
            q=p->next;
            tb=EulerCircuit(q->NodeNum,te);
            te->next=q->next;
            p->next=tb;
            delete q;
        }
        delete[] nodeList;
        nodeList=tmp;
        while(beg!=NULL)
        {
            cout<<nodeList[beg->NodeNum].vertics<<" ";
            p=beg;
            beg=beg->next;
            delete p;
        }
        cout<<endl;
    }
    node *clone()
    {
        node *tmp=new node[nodes];
        for(int i=0;i<nodes;i++)
        {
            tmp[i].vertics=nodeList[i].vertics;
            edge *p=nodeList[i].head;
            while(p)
            {
                tmp[i].head=new edge(p->end,p->weight,tmp[i].head);
                p=p->next;
            }
        }
        return tmp;
    }
    EulerNode* EulerCircuit(int start,EulerNode*&end)
    {
        EulerNode *beg;
        int nextNode;

        beg=end=new EulerNode(start);
        while(nodeList[start].head!=NULL)
        {
            nextNode=nodeList[start].head->end;
            remove(start,nextNode);
            remove(nextNode,start);
            start=nextNode;
            end->next=new EulerNode(start);
            end=end->next;
        }
        return beg;
    }
    void topSort()
    {
        queue<int> a;
        int *degree=new int[nodes];
        for(int i=0;i<nodes;++i)
        {
            degree[i]=0;
        }
        for(int i=0;i<nodes;++i)
        {
            edge *p=nodeList[i].head;
            for(;p!=NULL;p=p->next)
                degree[p->end]++;
        }
        for(int i=0;i<nodes;++i)
            if(degree[i]==0)
                a.push(i);
        while(!a.empty())
        {
            int tmp=a.front();
            a.pop();
            cout<<nodeList[tmp].vertics<<" ";
            edge *b=nodeList[tmp].head;
            while(b!=NULL)
            {
                degree[b->end]--;
                if(degree[b->end]==0)
                    a.push(b->end);
                b=b->next;
            }
        }

    }
};
int main()
{
    graph<char> a(6,"abcdef");
    a.insert(0,1,2);
    a.insert(1,2,2);
    a.insert(2,3,2);
    a.insert(3,4,2);
    a.insert(4,5,2);
    a.insert(5,0,2);
}
