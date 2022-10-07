// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;
    int array[];
    int i=0;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

	// Inorder traversal.
	void Inorder(BST*);
    void  printElements(int n);
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(value);
	}

	// Insert data.
	if (value > root->data) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value);
	}
	else if (value < root->data){
		// Insert left node data, if the 'value'
		// to be inserted is smaller than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value);
	}

	// Return 'root' node, after insertion.
	return root;
}
// C++ program to print elements greater than
// the previous and next element in an Array

// Function to print elements greater than
// the previous and next element in an Array
void BST::printElements(int n)
{
	// Traverse array from index 1 to n-2
	// and check for the given condition
	for (int i = 1; i < n - 1; i++) {
		if (array[i] > array[i - 1] && array[i] > array[i + 1])
			cout << array[i] << " ";
	}
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
    array[i]=root->data;
	Inorder(root->right);
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
    cout<<"Countour points are:"<<endl;
    b.printElements(7);
	return 0;
}

// This code is contributed by pkthapa
