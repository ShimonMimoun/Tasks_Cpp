#include <iostream> //test
#include "Tree.hpp" 
#include <iomanip>      // std::setw

using namespace std;
using namespace ariel;


                                            // constractor //
    Tree::Tree()
    {
    Tree::myroot = NULL;
    }
                                            // distractor //   
    Tree::~Tree()
    {
        myroot = fun::makeEmpty(myroot);
    }
                                        
                                        ////// public methods ///////

 	void Tree::insert(int x){
		myroot = fun::insert(x,myroot);
	}
	void Tree::print() { 
		fun::display(myroot, 10);
	}
	int Tree::parent (int x){
		Node* temp =fun::parent(myroot,x);
		if (temp==NULL) {
			throw::invalid_argument("No Parent found");
			return -1;
		}
		else return temp->data;
	}
	int Tree::left(int x){
		return fun::left(x,myroot);
	}

	int Tree::right(int x){
		return fun::right(x,myroot);
	}
	int Tree::size(){
		int ans = fun::size(myroot);
		if(myroot == NULL){
			return 0;
		}else{
		return fun::size(myroot);

		}
	}

	int Tree::root(){
		return myroot->data;
	}

	bool Tree::contains(int x)
	{
		Node* temp = fun::find(myroot, x);
		if(temp==NULL)return false;
		else 
			return true ;
	}

	bool Tree::remove(int x)
	{
		if((Tree::contains(x) == false) || (myroot==NULL)){
			throw::invalid_argument("BAD");
			return false;
		}else{
		Node* temp = fun::remove(myroot,x);
	return true;
	
	}
}

                                        ////// end public methods ///////


                                        ////// private methods ///////

	// priting function that took from interent.									

    void fun::display(Node* p, int indent) {

    if (p != NULL) {
    if (p->right) {
      fun::display(p->right, indent + 4);
    }
    if (indent) {
      cout << setw(indent) << ' ';
    }
    if (p->right) cout << " /\n" << setw(indent) << ' ';
    cout << p->data << "\n ";
    if (p->left) {
      cout << setw(indent) << ' ' << " \\\n";
      fun::display(p->left, indent + 4);
    }
  }
}

// empty the tree //
 Node* fun::makeEmpty(Node* t)
    {
        if(t != NULL){
            fun::makeEmpty(t->left);
            fun::makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
 Node* fun::remove(Node* myroot, int data) {
	if(myroot == NULL) return myroot; 
	else if(data < myroot->data) myroot->left = fun::remove(myroot->left,data);
	else if (data > myroot->data) myroot->right = fun::remove(myroot->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(myroot->left == NULL && myroot->right == NULL) { 
			delete myroot;
			myroot = NULL;
		}
		//Case 2: One child 
		else if(myroot->left == NULL) {
			struct Node *temp = myroot;
			myroot = myroot->right;
			delete temp;
		
		}
		else if(myroot->right == NULL) {
			struct Node *temp = myroot;
			myroot = myroot->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = fun::findMin(myroot->right);
			myroot->data = temp->data;
			myroot->right = fun::remove(myroot->right,temp->data);
		}
	}
	return myroot;
}

Node* fun::findMin(Node* t)
{
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else
		return fun::findMin(t->left);
}


Node* fun::insert(int x, Node* p){

	if(p == NULL){
		p = new Node;
		p->data = x;
		p->left = p->right = NULL;
	}
	else if (p->data == x){
	throw invalid_argument("This numer is allready in the Tree");

	}
	else if(x < p->data){
		p->left = fun::insert(x, p->left);
	}
	if(x > p->data)
		p->right = fun::insert(x, p->right);

		return p;
}


Node* fun::parent(Node* myroot, int n) {
	if (myroot == NULL){
		return NULL;
	}
	else if ( (myroot->left!=NULL && myroot->left->data == n) || (myroot->right!=NULL) && (myroot->right->data == n)){
			return myroot;
		}
		else {
			Node* result= fun::parent(myroot->left, n);
			if (result!=NULL){
				return result;
			}
			else{
				return fun::parent(myroot->right, n);
			}
		}

}
int fun::left(int x ,Node* myroot){

    if(x == myroot->data){
       if(myroot->left == NULL){
		   throw::invalid_argument("No left chlid exist");
       }
           else {
           return myroot->left->data;
         }
    }
    if(x < myroot->data){
        fun::left(x,myroot->left);
    }
    else if(x > myroot->data){
        fun::left(x,myroot->right);
    }
}

int fun::right(int x ,Node* myroot){

    if(x == myroot->data){
       if(myroot->right == NULL){
		   throw::invalid_argument("No right chlid exist");
       }
        else {
			cout << "ans is: " <<myroot->right->data << endl;
           return myroot->right->data;
         }
    }
    if(x < myroot->data){
		cout << "the left is: " << myroot->left->data << endl;
        fun::right(x,myroot->left);
    }
    else if(x > myroot->data){
        fun::right(x,myroot->right);
    }
}

int fun::size(Node* myroot)  
{  
	if (myroot == NULL || myroot->data == 0)  
		return 0;  
	else
		return(fun::size(myroot->left) + 1 + fun::size(myroot->right));  
}

Node* fun::find(Node* t, int x)
{
	if(t == NULL)
		return NULL;
	else if(x < t->data)
		return fun::find(t->left, x);
	else if(x > t->data)
		return fun::find(t->right, x);
	else
		return t;
}






                                        ////// end  private methods ///////

