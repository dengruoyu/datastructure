#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n=7;
    char value[14]={' ',' ',' ',' ',' ',' ',' ','a','e','i','s','t','k','h'};
    int weight[14]={0,0,0,0,0,0,0,10,15,12,3,4,13,1};
    int parent[14]={0};
    int left[14]={0};
    int right[14]={0};
    /*for(int i=0;i<2*n;++i)
    {
        value[n]=weight[n]=parent[n]=left[n]=right[n]=0;
    }
    for(int i=n;i<2*n;++i)
    {
        cin>>value[n]>>weight[n];
        parent[n]=left[n]=right[n]=0;
    }*/

    for(int i=n-1;i>0;i--)
    {
        int min1=10000,min2=10000;
        int place1,place2;
        for(int j=i+1;j<2*n;j++)
        {
            if(weight[j]<min1)
            {
                min2=min1;
                place2=place1;
                min1=weight[j];
                place1=j;
            }
            else if(weight[j]<=min2)
            {
                min2=weight[j];
                place2=j;
            }
        }
        cout<<place1<<" "<<place2<<endl;
        weight[i]=weight[place1]+weight[place2];
        weight[place1]=100000;
        weight[place2]=100000;
        left[i]=place1;
        right[i]=place2;
        parent[place1]=parent[place2]=i;
    }

    string *code=new string[2*n];
    for(int i=0;i<2*n;i++)
        code[i]="";
    int start=1;
    queue<int> a;
    a.push(start);
    while(!a.empty())
    {
        int tmp=a.front();
        a.pop();
        if(left[tmp]!=0)
        {
           code[left[tmp]]="0"+code[tmp];
           a.push(left[tmp]);
        }
        if(right[tmp]!=0)
        {
           code[right[tmp]]="1"+code[tmp];
           a.push(right[tmp]);
        }
    }
    for(int i=n;i<2*n;i++)
        cout<<value[i]<<" "<<code[i]<<endl;
    /*for(int i=1;i<n;i++)
        cout<<weight[i]<<" ";
    cout<<endl;
    for(int i=1;i<n;i++)
        cout<<parent[i]<<" ";
    cout<<endl;
    for(int i=1;i<n;i++)
        cout<<left[i]<<" ";
    cout<<endl;
    for(int i=1;i<n;i++)
        cout<<right[i]<<" ";
    cout<<endl;*/
}
