#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

template<class T>
struct node
{
    T number;
    node* next=NULL;
    node(T a,node *b=NULL):number(a),next(b){}
};
template<class T>
class stack
{
private:
    node<T> *head;
    int length;
public:
    stack()
    {
        head=NULL;
        length=0;
    }
    void push(T a)
    {
        node<T>* tmp=new node<T>(a,head);
        head=tmp;
        length++;
    }
    T pop()
    {
        node<T> *tmp=head;
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
        node<T> *tmp=head;
        for(int i=0;i<=place;i++)
            tmp=tmp->next;
        return tmp->number;
    }
    node<T> *move(int place)
    {
        node<T> *tmp=head;
        for(int i=0;i<=place;i++)
            tmp=tmp->next;
        return tmp;
    }
    ~stack()
    {
        while(head!=NULL)
        {
            node<T> *tmp=head;
            head=head->next;
            delete tmp;
        }
    }
    void print()
    {
        node<T> *tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->number<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
    bool isEmpty()
    {
        if(length==0)
            return 1;
        return 0;
    }
};

class calc
{
    char *expression;
    enum token{OPAREN,ADD,SUB,MULTI,DIV,EXP,CPAREN,VALUE,EOL};

    void BinaryOp(token op,stack<int> &dataStack)
    {
        int number2=dataStack.pop();
        int number1=dataStack.pop();
        switch(op)
        {
            case ADD:dataStack.push(number1+number2);break;
            case SUB:dataStack.push(number1-number2);break;
            case MULTI:dataStack.push(number1*number2);break;
            case DIV:dataStack.push(number1/number2);break;
            case EXP:dataStack.push(pow(number1,number2));break;
        }
    }
    token getOp(int &value)
    {
        while(*expression)
        {
            while(*expression && *expression==' ')
                ++expression;
            if(*expression<='9' && *expression>='0')
            {
                value=0;
                while(*expression<='9' && *expression>='0')
                {
                    value=value*10+*expression-'0';
                    ++expression;
                }
                return VALUE;
            }
            switch(*expression)
            {
                case'(':++expression;return OPAREN;
                case')':++expression;return CPAREN;
                case'+':++expression;return ADD;
                case'-':++expression;return SUB;
                case'*':++expression;return MULTI;
                case'/':++expression;return DIV;
                case'^':++expression;return EXP;
            }
        }
        return EOL;
    }
public:
    calc(char *s)
    {
        expression=new char[strlen(s)+1];
        strcpy(expression,s);
    }
    ~calc()
    {
        delete expression;
    }
    int result()
    {
        token lastOp,topOp;
        int result_value,currentValue;
        stack<token> opStack;
        stack<int> dataStack;
        char * str=expression;

        while(1)
        {
            /*dataStack.print();
            opStack.print();*/
            lastOp=getOp(currentValue);
            if(lastOp==EOL)
                break;
            switch(lastOp)
            {
                case VALUE:dataStack.push(currentValue);break;
                case CPAREN:
                    while(!opStack.isEmpty()&&opStack.pop()!=OPAREN)
                        BinaryOp(topOp,dataStack);
                    break;
                case OPAREN:
                    opStack.push(OPAREN);break;
                case EXP:
                    opStack.push(EXP);break;
                case MULTI:case DIV:
                    while(!opStack.isEmpty()&&opStack.top()>=MULTI)
                    {
                        BinaryOp(opStack.pop(),dataStack);
                    }

                    opStack.push(lastOp);
                    break;
                case ADD:case SUB:
                    while(!opStack.isEmpty()&&opStack.top()!=OPAREN)
                        BinaryOp(opStack.pop(),dataStack);
                    opStack.push(lastOp);
            }
        }

        while(!opStack.isEmpty())
            BinaryOp(opStack.pop(),dataStack);
        result_value=dataStack.pop();
        cout<<result_value<<endl;
        expression=str;
        return result_value;
    }
};

int main()
{
    calc exp1("2^6");
    exp1.result();
}

