//Problem Statement::
/*
Construct an Expression Tree from postfix and prefix expression. Perform recursive and non-
recursive In-order, pre-order and post-order traversals.
*/

#include<iostream>
using namespace std;

typedef struct node
{
    char data;
    struct node *left,*right;
}node;

class Node
{
    public:
    node *data;
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

    void push(node* data)
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

    node* pop()
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
            node *x=temp->data;
            root=root->next;
            count-=1;
            free(temp);
            return x;
        }
        
    }

    node* top()
    {
        node *temp;
        if (root==NULL)
        {
            cout<<"Stack underflow"<<endl;
            return temp;
       }
        else
        {
            node *a=root->data;
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

node* create_pre(char prefix[10]);
node* create_post(char postfix[10]);
void inorder_non_recursive(node *t);
void inorder(node *p);
void preorder(node *p);
void postorder(node *p);
void preorder_non_recursive(node *t);
void postorder_non_recursion(node *t);

node* create_post(char postfix[10])
{node *p;
stack s;
	for(int i=0;postfix[i]!='\0';i++)
	{
		char token=postfix[i];
		if(isalnum(token))
		{
			p=new node();
			p->data=token;
			p->left=NULL;
			p->right=NULL;
			s.push(p);		
		}	
		else
		{
			p=new node();
			p->data=token;
			p->right=s.pop();
			p->left=s.pop();
			s.push(p);		
		}
	}
	return s.pop();
	
		
}

node* create_pre(char prefix[10])
{node *p;
stack s;
int i;
		for(i=0;prefix[i]!='\0';i++)
		{}
		i=i-1;
	for(;i>=0;i--)
	{
		char token=prefix[i];
		if(isalnum(token))
		{
			p=new node();
			p->data=token;
			p->left=NULL;
			p->right=NULL;
			s.push(p);		
		}	
		else
		{
			p=new node();
			p->data=token;
			p->left=s.pop();
			p->right=s.pop();
			s.push(p);		
		}
	}
	return s.pop();
	
		
}

int main()
{
	node *r=NULL,*r1;
	char postfix[10],prefix[10];
	int x;
int ch,choice;
do
{
	cout<<"\n1.Construct tree from postfix expression/ prefix expression"
		  "\n2.Inorder traversal"
		  "\n3.Preorder traversal"
		  "\n4.Postorder traversal"
		  "\n5.Exit"
		  "\nEnter your choice=";
	cin>>ch;	
	switch(ch)
	{
		case 1:cout<<"Enter Choice:"
					"\n1.Postfix expression"
					"\n2.Prefix expression"
					"\nchoice=";
			cin>>choice;
			if(choice==1)
			{
				cout<<"\nEnter postfix expression=";
				cin>>postfix;
				r=create_post(postfix);
			}
			else
			{	
				cout<<"\nEnter prefix expression=";
				cin>>prefix;
				r=create_pre(prefix);
			}	
			cout<<"\n\nTree created successfully";
			break;
		case 2:
				inorder(r);
				cout<<"\n Without recursion:\t";
				inorder_non_recursive(r);
				break;
		case 3:
				preorder(r);
				cout<<"\npreorder traversal without recursion:\t";
				preorder_non_recursive(r);
				break;
		case 4:
				postorder(r);
				cout<<"\npostorder traversal without recursion";
				postorder_non_recursion(r);
				break;
	}
}while(ch!=5);
	return 0;
}

void inorder(node *p)
{
		if(p!=NULL)
		{
			inorder(p->left);
			cout<<p->data;
			inorder(p->right);	
		}
}

void preorder(node *p)
{
		if(p!=NULL)
		{
			cout<<p->data;
			preorder(p->left);
			preorder(p->right);	
		}
}


void postorder(node *p)
{
		if(p!=NULL)
		{
			postorder(p->left);
			postorder(p->right);
			cout<<p->data;	
		}
}




void inorder_non_recursive(node *t)
{

	stack s;
	while(t!=NULL)
	{
		s.push(t);
		t=t->left;
	}

	while(!s.isEmpty())
	{
		t=s.pop();
		cout<<t->data;
		t=t->right;
		while(t!=NULL)
	{
		s.push(t);
		t=t->left;
	}


	}


}



void preorder_non_recursive(node *t)
{

	stack s;
	while(t!=NULL)
	{
		cout<<t->data;
		s.push(t);
		t=t->left;
	}

	while(!s.isEmpty())
	{
		t=s.pop();
		
		t=t->right;
		while(t!=NULL)
	{
		cout<<t->data;
		s.push(t);
		t=t->left;
	}


	}
}

void postorder_non_recursion(node *t)
{stack s,s1;
node *t1;
	while(t!=NULL)
	{
		s.push(t);
		s1.push(NULL);
		t=t->left;			
	}
	while(!s.isEmpty())
	{
		t=s.pop();
		t1=s1.pop();
		if(t1==NULL)
		{
			s.push(t);
			s1.push((node *)1);
			t=t->right;		
				while(t!=NULL)
				{
					s.push(t);
					s1.push(NULL);
					t=t->left;			
				}	
			
		}
		else
		cout<<t->data;	
	}


}
