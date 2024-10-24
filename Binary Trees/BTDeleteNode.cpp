/*
Find the minimum value in the binary tree.
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <limits.h>

using namespace std;

template <class dataType>
class BinaryTree {
	public:
		BinaryTree( );
		bool isLeaf ();
		dataType getData();
		void insert (const dataType & d);
		BinaryTree * left();
		BinaryTree * right();
		void makeLeft (BinaryTree * T1);
		void makeRight (BinaryTree *T1);
	private:
		dataType treeData;
		BinaryTree * leftTree;
		BinaryTree * rightTree;
};

template <class dataType>   //constructor
BinaryTree<dataType>::BinaryTree()
{
	leftTree = NULL;
	rightTree = NULL;
}

template <class dataType>
bool BinaryTree<dataType>::isLeaf()
{
    return ((this->leftTree == NULL) && (this->rightTree == NULL));
}

template <class dataType>
dataType BinaryTree<dataType>::getData()
{
	return treeData;
}

template <class dataType>
void BinaryTree <dataType>::insert (const dataType & d)
{
     treeData = d;
}

template <class dataType>
BinaryTree <dataType> * BinaryTree<dataType> :: left()
{
	return leftTree;
}
template <class dataType>
BinaryTree <dataType> * BinaryTree<dataType> :: right()
{
	return rightTree;
}

template <class dataType>
void BinaryTree <dataType> :: makeLeft (BinaryTree * T1)
{
	leftTree = T1;
}

template <class dataType>
void BinaryTree <dataType> :: makeRight (BinaryTree * T1)
{
	rightTree = T1;
}
template <class dataType>
void preOrderTraverse (BinaryTree <dataType> * bt)
{
	if (!(bt == NULL))
	{
		//visit tree
		cout << bt->getData() <<"\t";
		//traverse left child
		preOrderTraverse (bt->left());
		//traverse right child
		preOrderTraverse (bt->right());
	}
}

template <class dataType>
void inOrderTraverse (BinaryTree <dataType> * bt)
{
	if (!(bt == NULL))
	{
		//traverse left child
		inOrderTraverse (bt->left());
		//visit tree
		cout << bt->getData() <<"\t";
		//traverse right child
		inOrderTraverse (bt->right());
	}
}
template <class dataType>
void postOrderTraverse (BinaryTree <dataType> * bt)
{
	if (!(bt == NULL))
	{
		//traverse left child
		postOrderTraverse (bt->left());
		//traverse right child
		postOrderTraverse (bt->right());
		//visit tree
		cout << bt->getData() <<"\t";
	}
}

template <class dataType>
double postOrderEvaluate ( BinaryTree <dataType> * bt )
{
	double left, right;
	if ( bt != NULL )
	{
		//traverse left child
		left = postOrderEvaluate ( bt->left ( ) );
		//traverse right child
		right = postOrderEvaluate ( bt->right( ) );
		//visit tree
		if ( strcmp(bt -> getData(), "+") == 0 )
		{ 	cout << endl << left << "+" << right;
			return (left + right); }
		else if ( strcmp(bt -> getData(), "-") == 0)
		{ 	cout << endl << left << "-" << right;
			return (left - right); }
        else if ( strcmp(bt -> getData(),"*" ) == 0)
		{ 	cout << endl << left << "*" << right;
			return (left * right); }
		else
			return atof(bt -> getData());
	}
    return 0;
}

template <class dataType>
void postOrderDelete(BinaryTree<dataType> *bt) {
    if (bt != NULL) {
        // Traverse the left subtree
        postOrderDelete(bt->left());
        // Traverse the right subtree
        postOrderDelete(bt->right());
        // Delete the current node
        cout << "Deleting node with data: " << bt->getData() << endl;
        delete bt;  // Free the memory allocated for the node
    }
}


int main()
{
  BinaryTree <int>* root = new BinaryTree<int>;

	root->insert(6);
	root->makeLeft(new BinaryTree<int>);
	root->makeRight(new BinaryTree<int>);
	root->left()->insert(1);
	root->right()->insert(9);
	root->left()->makeLeft(new BinaryTree<int>);
	root->left()->makeRight(new BinaryTree<int>);
	root->left()->left()->insert(4);
	root->left()->right()->insert(8);
  /*
        6
      /   \
     1     9
    / \
   4   8		
  */
  
  postOrderTraverse(root);
  //solution:
  cout << endl;
  postOrderDelete(root);

    postOrderTraverse(root);


    
	system("PAUSE");
	return 0;
}
