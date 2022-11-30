//Problem Statement::
/*
Implement stack as an abstract data type using singly linked list and use this ADT for conversion of
infix expression to postfix, prefix and evaluation of postfix and prefix expression.
*/

#include<iostream>
# include <cstdlib>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class stack
{
    Node *root;
    int count;

    public:
    stack()
    {
        root=NULL;
        count=0;
    }

    void push(int data)
    {
        Node *temp=new Node();
        temp->data=data;
        temp->next=NULL;
        count+=1;
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            temp->next=root;
            root=temp;
        }
        
    }

    int pop()
    {
        if(root==NULL)
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else
        {
            Node *temp=new Node();
            temp=root;
            int x=temp->data;
            root=root->next;
            count-=1;
            free(temp);
            return x;
        }
        
    }

    int top()
    {
        if (root==NULL)
        {
            cout<<"Stack underflow"<<endl;
            return 0;
       }
        else
        {
            int a=root->data;
            return a;
        }
        
    }

    bool isEmpty()
    {
        if (root==NULL)
            return true;
        return false;
    }

    int size()
    {
        return count;
    }
};

int pre(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else
    {
        return 0;
    }
    
}

string Postfix(string infix)
{
    stack s;
    s.push('#');
    string postfix="";

    for(int i=0;i<infix.length();i++)
    {
        char cha=infix[i];
        if((cha>='a' && cha<='z') || (cha>='A' && cha<='Z'))
            postfix+=cha;
        else if(cha=='(')
            s.push(cha);
        else if(cha==')')
        {
            while(s.top()!='#' && s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            if (pre(cha)>pre(s.top()))
                s.push(cha);
            else
            {
                while(s.top()!='#' && pre(cha)<=pre(s.top()))
                {
                    postfix+=s.top();
                    s.pop();
                }
                s.push(cha);
            }
            
        }
        
    }

    while(s.top()!='#')
    {
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}

string reverse(string exp)
{
    char ch;
    string rev;

    for(int i=exp.length();i>=0;i--)
    {
        ch=exp[i];
        if(ch==')')
            rev+='(';
        else if(ch=='(')
            rev+=')';
        else
        {
            rev+=ch;
        }
    }
    return rev;
}

string infixtoprefix(string infix)
{
    string infix_r=reverse(infix);
    infix_r=Postfix(infix_r);
    return reverse(infix_r);
}

int main()
{
    int choice;
    string exp;
    do{
    cout<<"\nEnter your choice:";
    cout<<"\n1. Infix to Postfix"
          "\n2. Infix to Prefix"
          "\n3. Exit";
          cin>>choice;
          switch(choice)
          {
            case 1:
            {
              cout<<"\nEnter infix expression:";
              cin>>exp;
              cout<<Postfix(exp);
              break;
            }
            case 2:
            {
              cout<<"\nEnter infix expression:";
              cin>>exp;
              cout<<infixtoprefix(exp);
              break;
            }
            case 3:
            {
                break;
            }

          }

    }while(choice!=3);
}
