#include <iostream>
#include <mutex>
#include <thread>
#include "Tree.hpp"

using namespace std;

ariel::Node *root;

void ariel::Tree::insert(int x)
    {
       Node temp = insert(x, root);
    }

    bool ariel::Tree::remove(int x)
    {
      Node temp = remove(x, root);
      if(temp == NULL) return false;
      else return true;
    }


    bool ariel::Tree::contains(int x)
    {
        Node temp = find(root, x);
        if(temp==NULL)return false;
        else 
        return true ;
    }

    int ariel::Tree::root(){
       return root->data;
    }
    int ariel::Tree::parent (int x){
        Node temp =parent(root,x);
        if (temp==NULL) {
            cout <<"No Parent found"<<endl;
        return -1;
        }
        else return temp->data;
    

    }
    
    int ariel::Tree::size(){
        return size(root);
}

int ariel::Tree::left(int x){
    return left(x,root);
}
int ariel::Tree::right(int x){
    return right(x,root);
}

private:
Node* parent(Node* root, int n) {
  if (root == NULL)
    return NULL;
  else
    if ( (root->left!=NULL && root->left->inf == n) || (root->right!=NULL) && (root->right->inf == n)){
      return root;
    }
    else {
      Node* result= parent(root->left, n);
      if (result!=NULL){
        return result;
      }
      else{
        return parent(root->right, n);
      }
    }

}



    Node* insert(int x, Node* t)
    {
        if(t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

  
    Node* remove(int x, Node* t)
    {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }


    Node* find(Node* t, int x)
    {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

 Node* makeEmpty(Node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

int size(Node* root)  
{  
    if (root == NULL)  
        return 0;  
    else
        return(sizef(root->left) + 1 + size(root->right));  
}


int left(int x ,Node* root){

    if(x == root->data){
       if(root->left == NULL){
           cout << "No Left Child for" x << endl;
           return -1;
       }
       else {
           return root->left->data;
    }           

    if(x < root->data){
        left(x,root->left);
    }
    else{
        left(x,root->right)
    }
    }

}
int right(int x ,Node* root){

    if(x == root->data){
       if(root->right == NULL){
           cout << "No right Child for" x << endl;
           return -1;
       }
       else {
           return root->right->data;
    }         

    if(x < root->data){
        right(x,root->right);
    }
    else{
        right(x,root->right)
    }
    }
