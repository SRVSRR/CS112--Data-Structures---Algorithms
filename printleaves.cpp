#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>

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
void printleaves (BinaryTree <dataType> * bt)
{

	//traverse left child
		inOrderTraverse (bt->left());
	
	if (bt->left() == NULL && bt->right() == NULL)
	{		
		//visit tree
		cout << bt->getData() <<"\t";
	}
	
	//traverse right child
		inOrderTraverse (bt->right());

}

int main()
{
    BinaryTree <char> * root = new BinaryTree <char>();
	root->insert('A');
	
	root->makeLeft(new BinaryTree <char>);
	root->left()->insert('B');
	root->makeRight(new BinaryTree <char>);
	root->right()->insert('C');
	
	root->left()->makeLeft(new BinaryTree <char>);
	root->left()->left()->insert('D');
	root->left()->makeRight(new BinaryTree <char>);
	root->left()->right()->insert('E');
	root->left()->right()->makeRight(new BinaryTree <char>);
	root->left()->right()->right()->insert('H');
	
	root->right()->makeRight(new BinaryTree <char>);
	root->right()->right()->insert('F');
	
	root->left()->left()->makeLeft(new BinaryTree <char>);
	root->left()->left()->left()->insert('G');

	/* binary tree:
			A
		  /  \
		 B    C
		/ \    \
	   D   E   F
	  /    \
	 G     H
    */

	postOrderTraverse(root);
    cout << endl;
    
    //solution:
    cout <<"print the leaves"<<endl;
	//TODO

	printleaves (root);
    
	system("PAUSE");
	return 0;
}
