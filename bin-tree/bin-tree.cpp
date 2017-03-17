// binary tree implementation

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *curr = NULL;

int addNode(Node *, Node *);
int inorder(Node *);
int preorder(Node *);
int postorder(Node *);

int main()
{
  char c;
  int v;

  cout << std::string(50, '\n');

  do
  {
    cout << "Select" << endl;
    cout << "1 - Add Node" << endl;
    cout << "2 - inorder traversal" << endl;
    cout << "3 - preorder traversal" << endl;
    cout << "4 - postorder traversal" << endl;
    cout << "0 - Exit" << endl;
    cin >> c;
    cout << std::string(50, '\n');
    switch(c)
    {
      case '0':
        return 0;
      case '1':
        Node *temp;
        temp = new Node;
        cout << "Enter data to store: ";
        cin >> temp->data;
        if (curr == NULL)
        {
          curr = new Node;
          curr->data = temp->data;
          curr->left = NULL;
          curr->right = NULL;
          cout << "The root has been added" << endl;
        } 
        else 
        {
          v = addNode(curr, temp);
          cout << v << endl;
          if(v==1)
            cout<<"  The node is added to the left" << endl;
          if(v==2)
            cout<<"  The node is added to the right" <<endl;
          if (v==3)
            cout<<"  The same value exists" <<endl;
        }
        break;
      default:
        cout << "invalid entry" << endl;
        
    }

  } while(c != 0);

  return 0;
}

int addNode(Node *fcurr, Node *fnew )
{
  if(fcurr->data==fnew->data)
  {
   return 3;
  }
  else
  {
    if(fcurr->data > fnew->data)
    {
      if(fcurr->left != NULL)
        addNode(fcurr->left, fnew);
      else
      {
        fcurr->left = fnew;
        (fcurr->left)->left=NULL;
        (fcurr->left)->right=NULL;
        return 1;
      }
    }
    else
    {
      if(fcurr->right != NULL)
        addNode(fcurr->right, fnew);
      else
      {
        fcurr->right = fnew;
        (fcurr->right)->left=NULL;
        (fcurr->right)->right=NULL;
        return 2;
      }
    }
  }
}