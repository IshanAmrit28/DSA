#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "enter the data  :";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inseriting in left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inseriting in right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        
        q.pop();

        if (temp == NULL)
        { // old level complete
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(node *root){

    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
    
}
void Preorder(node *root){

    //base case
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
    
    
}

void Postorder(node *root){

    //base case
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
    
    
}

void buildFromLevelOrder(node* &root){
     queue<node*> q;
     cout<<"enter data from root"<<endl;
     int data;
     cin>> data;
     root=new node(data);
     q.push(root);

     while (!q.empty())
     {
        node* temp=q.front();
        q.pop();
        cout<<"Enter left node: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node:"<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
     }
     

}

int main()
{
    node *root = NULL;
    // root = buildtree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5  17 -1 -1 -1
    // levelOrderTraversal(root);

    // cout<<"inorder traversal output is :"<<endl;
    // inorder(root);
    // cout<<"preorder traversal output is :"<<endl;
    // Preorder(root);
    // cout<<"Postorder traversal output is :"<<endl;
    // Postorder(root);
    buildFromLevelOrder(root);
    return 0;
}