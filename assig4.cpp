/*Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i.Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv.Mirror
v. Search a value*/

#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
class node{
	public:
		int data;
	    node *left,*right;
};
class bst
{
	public:
		node *root;
		
		bst()
		{
			root=NULL;
		}
		void create();
		void insert();
		void inorder(node *);
		int max_no_node(node *);
		int min_data(node *);
		int max_data(node *);
		void mirror(node *);
		void search(int);
		void non_rec_inorder(node *);
		void non_rec_preorder(node *root);
		
};

void bst::create()
{
	root=new node;
	root->left=root->right=NULL;
	cout<<"enter the data of root:";
	cin>>root->data;
}
void bst::insert()
{
	node *temp,*p;
	if(root==NULL)
	{
		create();
	}
	else
	{
		p=new node;
		p->left=p->right=NULL;
		cout<<"enter the data to be inserted==>";
		cin>>p->data;
		temp=root;
		while(temp!=NULL)
		{
			if(p->data>temp->data)
			{
				if(temp->right==NULL)
				{
					temp->right=p;
					break;
				}
				else
				{
					temp=temp->right;
				}
			}
			else if(p->data<temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=p;
					break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else
			{
				cout<<"node is already inserted..!";
			}
		}
	}
}

void bst::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

class stack1
{
    node *data[30];
    int top;

public:
    stack1()
    {
        top = -1;
    }
    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
    void push(node *p)
    {
        data[++top] = p;
    }
    node *pop()
    {
        return (data[top--]);
    }
};

void bst::non_rec_inorder(node *root)
{
	stack1 s1;
	node *temp=root;
	
	do{
		while(temp!=NULL)
		{
			s1.push(temp);
			temp=temp->left;
		}
		if(s1.empty())
		{
			break;
		}
	
		temp=s1.pop();
		cout<<temp->data<<" " ;
		temp=temp->right;
	}while(1);
}
void bst::non_rec_preorder(node *root)
{
	//stack<node*>s1;
	stack1 s1;
	node *temp=root;
	
	do{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			s1.push(temp);
			temp=temp->left;
		}
		if(s1.empty())
		{
			return;
		}
	
		temp=s1.pop();
		temp=temp->right;
	}while(1);
}
int bst::max_no_node(node *root)
{
	int hl,hr,height;
    if(root==NULL)
    {
        return 0;
    }
    
    else{
    hl=max_no_node(root->left);
    hr=max_no_node(root->right);
    }
    if(hr>hl)
    {
        height=hr+1;
    }
    else
    {
        height=hl+1;
    }
    return (pow(2,height)-1);
    
}
	
int bst::min_data(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->left==NULL)
	{
		return (root->data);
	}
	else
	{
		return min_data(root->left);
	}
}
int bst::max_data(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else if(root->right==NULL)
	{
		return (root->data);
	}
	else 
	{
		return max_data(root->right);
	}
}

void bst::mirror(node *root)
{
	node *temp;
	if(root!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);	
	}
}
void bst::search(int key)
{
	node *temp=root;
	int count=0;
	if(temp==NULL)
	{
		cout<<"empty...!";
		
	}
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			count++;
			break;
		}
		else if(key<temp->data)
		{
			temp=temp->left;
			count++;
		}
		else
		{
			temp=temp->right;
			count++;	
		}
		
	}
	if(temp==NULL)
	{
		cout<<"\n--------element not found-------\n";
	}
	else
	{
		cout<<"\n--------element found-----------\n";
		 cout << "\nNo of comparisons required are: " << count << endl;
	}
}

int main()
{
	bst obj;
	int ch,key;
	do{
		
		cout<<"\n\n1]insert node "<<endl
				<<"2]max no of nodes in a tree"<<endl
				<<"3]value of min node from tree"<<endl
				<<"4] value of max node from tree"<<endl
				<<"5]search for a node"<<endl
				<<"6]mirror of tree:"<<endl
				<<"7]display"<<endl
				<<"8]display with non_recursive inorder:"<<endl
				<<"9]display with non_recursive preorder:"<<endl
				<<"0]exit"<<endl;
		cout<<"enter ch:";
		cin>>ch;
				switch(ch)
				{
					case 1:obj.insert();
						break;
					case 2:cout<<"max no of nodes:"<<obj.max_no_node(obj.root);
						break;
					case 3:cout<<"min data:"<<obj.min_data(obj.root);
						break;
					case 4:cout<<"Max data:"<<obj.max_data(obj.root);
						break;
					case 5:cout<<"enter the key that uh want to search==>";
					 		cin>>key;
					 		obj.search(key);
							break;
				    case 6:obj.mirror(obj.root);
							break;
					case 7:obj.inorder(obj.root);
							break;
					case 8:obj.non_rec_inorder(obj.root);
							break;
					case 9:obj.non_rec_preorder(obj.root);
							break;
				}
			}
	while(ch!=0);
	return 0;
}

