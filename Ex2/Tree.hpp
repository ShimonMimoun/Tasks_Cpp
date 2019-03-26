#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


namespace ariel{

	class Tree{
	public:
	Node* myroot;

	Tree();
	void insert(int);
	void print();
	int parent (int x);
	int right(int x);
	int left(int x);
	int size();
	int root();
	bool contains(int x);
	bool remove(int x);
	~Tree();
	};
}
namespace fun{

	Node* insert(int,Node*);
	void display(Node*,int);
	Node* parent(Node* myroot, int n);
	int right(int x ,Node* myroot);
	int left(int x ,Node* myroot);
	int size(Node* myroot);
	Node* find(Node* t, int x);
	Node* remove(Node* t,int x);
	Node* makeEmpty(Node*);
    Node* findMin(Node* t);




}