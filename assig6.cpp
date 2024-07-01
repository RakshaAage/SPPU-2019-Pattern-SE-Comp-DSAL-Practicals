/*
"A Dictionary stores keywords and its meanings. 
Provide facility for adding new keywords, deleting keywords, updating values of any entry. 
Provide facility to display whole data sorted in ascending/ Descending order. 
Also find how many maximum comparisons may require for finding any keyword. 
Use Binary Search Tree for Implementation."
*/

#include<iostream>
#include<string>
using namespace std;
class node{
public:
string key,mean;
node *left;
node *right;
        node *next;
         void get_data()
        {
            cout<<"\nEnter the key : ";
            cin>>key;
            cout<<"\nEnter the meaning : ";
            cin.ignore();
            getline(cin,mean);
        }
};
class stack
{
node *key[30];
int top;
public:
   stack()
   {
       top=-1;
   }
   int isEmpty()
   {
       if(top==-1)
       {
           return 1;
       }
       return 0;
   }
   void push(node *root)
   {
       key[++top]=root;
   }
   node *pop()
   {
       return (key[top--]);
   }
};

class bs_tree
{
		public:
			node *root,*newnode;
			node *temp;
			bs_tree()
            {
			root=NULL;
			}

			void create()
            {
			newnode=new(node);
			newnode->left=NULL;
			newnode->right=NULL;
			}
			   
		void insert()
        {
            if(root==NULL)
            {
                create();
                root=newnode;
                root->get_data();
                return ;
            }
            create();
            newnode = new node();
            newnode->get_data();
            temp=root;
            while(temp!=NULL)
            {
                if(newnode->key < temp->key)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        break;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                else if(newnode->key > temp->key)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        break;
                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
		}

void search(string x){
//int count=0;
    temp=root;
    while(temp!=NULL){
        if(temp->key==x){
            break;
        }
        else if(x<temp->key){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
        //count++;
    }
    if(temp==NULL){
        cout<<"\nData is not found!";
    }

    else{
        cout<<"\nData is found!";
    }
}

        void display(node *root)
        {
            int y;
            if (root == NULL)
            {
                cout << "BST is empty!" << endl;
                return;
            }

            cout << "1. For Ascending order \n2. For Descending Order \nEnter your choice: ";
            cin>>y;
            cout << "Keywords and Meanings in BST: " << endl;
            switch (y)
            {
            case 1:
                ascending(root);
                break;
            case 2:
                descending(root);
                break;
            default:
                break;
            }
       

        }

        void ascending(node *root)
        {
       
            stack s1;
            do
            {
                while(root!=NULL)
                {
                    s1.push(root);
                    root=root->left;
                }
                if(s1.isEmpty())
                {
                    break;
                }
                root=s1.pop();
                cout<<"KEYWORD: "<<root->key<<" MEANING: "<<root->mean<<endl;
                root=root->right;
              
               
            }
            while(1);

        }

        void descending(node *root)
        {
           
            stack s1;
            do
            {
                while(root!=NULL)
                {
                    s1.push(root);
                    root=root->right;
                }
                if(s1.isEmpty())
                {
                    break;
                }
                root=s1.pop();
                cout<<"KEYWORD: "<<root->key<<" MEANING: "<<root->mean<<endl;
                root=root->left;
                
            }
            while(1);
        }

        void update(string x)
        {
            if (root == NULL)
            {
                cout << "BST is empty!" << endl;
                return;
            }

            node *temp= root;
            bool found = false;

            while (temp != NULL)
            {
                if (x < temp->key)
                {
                    temp = temp->left;
                }
                else if (x > temp->key)
                {
                    temp = temp->right;
                }
                else
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Keyword not found in BST!" << endl;
                return;
            }
            else {
            cout << "Enter new meaning for the keyword: " << x << "': ";
            string mean_new;
            cin.ignore();
            getline(cin, mean_new);

            temp->mean = mean_new;
            cout << "Meaning updated successfully!" << endl;
            }
        }
                node *inorder_pred(node *root)
                {
                    root=root->left;
                    while(root->right!=NULL)
                    {
                        root=root->right;
                    }
                    return root;
                }
       
        node *delete_node(node *root, string x)
        {
            node *pred;
            if(root==NULL)
            {
                return NULL;
            }
            if(root->left==NULL && root->right==NULL)
            {
                delete(root);
                return NULL;
            }
            if(x<root->key)
            {
                root->left=delete_node(root->left,x);
            }
            else if(x>root->key)
            {
                root->right=delete_node(root->right,x);
            }
            else
            {
                pred=inorder_pred(root);
                root->key=pred->key;
                root->left=delete_node(root->left,pred->key);
            }
            return root;
        }
       
};


int main()
{
int ch,opt;
bs_tree t1;
string str;
do
{
			cout<<"1. Insert \n2. Display \n3. Update \n4.Search \n5.Delete \n6. Exit"<<endl;
			cout<<"Enter choice: ";
			cin>>ch;
			cin.ignore();
			switch(ch)
			{
			case 1:
				t1.insert();
				break;
			case 2:
				t1.display(t1.root);
				break;
			case 3:
				cout<<"Enter the keyword you want to update: ";
				cin>>str;
				t1.update(str);
				break;
            case 4:
                cout<<"Enter the keyword you want to update: ";
				cin>>str;
				t1.search(str);
                break;
            case 5:
                cout<<"\nEnter data of node you want to delete : ";
                cin>>str;
                t1.delete_node(t1.root,str);
                cout<<"\nData at deleted node : "<<t1.root->key;
                break;
			case 6:
			break;
			}

}while(ch!=6);
return 0;
}