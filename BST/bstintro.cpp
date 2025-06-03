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

void inorder(node *root)
{

  // base case
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void Preorder(node *root)
{

  // base case
  if (root == NULL)
  {
    return;
  }
  cout << root->data << " ";
  Preorder(root->left);
  Preorder(root->right);
}

void Postorder(node *root)
{

  // base case
  if (root == NULL)
  {
    return;
  }
  Postorder(root->left);
  Postorder(root->right);
  cout << root->data << " ";
}

node *insertIntoBST(node *&root, int data)
{
  // base case
  if (root == NULL)
  {
    root = new node(data);
    return root;
  }

  if (data > root->data)
  {
    // insert in right part;
    root->right = insertIntoBST(root->right, data);
  }
  else
  {
    // insert in left part
    root->left = insertIntoBST(root->left, data);
  }
  return root;
}

int minVal() {}

void takeInput(node *&root)
{

  int n;

  cin >> n;
  while (n != -1)
  {
    root = insertIntoBST(root, n);
    cin >> n;
  }
}

node *deletefrombst(node *root, int val)
{

  if (root == NULL)
  {
    return root;
  }
  if (root->data == val)
  {
    // 0 child
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    // 1 child

    // left child
    if (root->left != NULL && root->right == NULL)
    {
      node *temp = root->left;
      delete root;
      return temp;
    }
    // right child
    if (root->left == NULL && root->right != NULL)
    {
      node *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->left != NULL && root->right != NULL)
    {
      // int mini=minVal(root->right)->data;
      // root->data=mini;
      // root->right=deletefrombst(root->right,mini);
      return root;
    }
  }
  else if (root->data > val)
  {
    root->left = deletefrombst(root->left, val);
    return root;
  }
  else
  {

    root->right = deletefrombst(root->right, val);
    return root;
  }
}

int main()
{

  node *root = NULL;
  cout << "enter data to createt bst" << endl;

  takeInput(root);

  return 0;
}