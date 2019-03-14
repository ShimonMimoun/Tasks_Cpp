#include <iostream>
#include <mutex>
#include <thread>
#include <mutex>


using namespace std;

namespace ariel
{
    struct Node{
        int data;
        struct Node *left;
        struct Node *right;
    };

    class Tree{
        Tree()
    {
        root = NULL;
    }
      ~Tree()
    {
        root = makeEmpty(root);
    }
  
        public:
         void insert(int x);
    bool remove(int x);
    bool contains(int x);
    int root();
    int parent (int x);
    int size();
    int left(int x);
    int right(int x);
    void print();
    
	private:
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
		
	};
}

    


