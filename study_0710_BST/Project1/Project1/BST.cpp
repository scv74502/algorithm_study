#include<iostream>

class Node
{
public:
	int data; // value of node
	Node* leftChild = NULL;
	Node* rightChild = NULL;

	Node(int _data, Node* _leftChild, Node* _rightChild)
		:data(_data), leftChild(_leftChild), rightChild(_rightChild) 
	{}	// generator, should ask about this grammer

	bool isLeaf()
	{
		if (!leftChild && !rightChild)	// if pointer is null value, return false
			return true;
		else
			return false;
	}

}; 

// ��忡 ã�� ���� ������ true, ������ false ����
bool BST_SerachNode(Node* tree, int findingVal)
{
	if (tree == NULL)
		return false;
	else if (tree->data == findingVal)
		return true;
	else if (tree->data > findingVal)
		return BST_SerachNode(tree->leftChild, findingVal);
	else if (tree->data < findingVal)
		return BST_SerachNode(tree->rightChild, findingVal); 
} 

// ��忡 ã�� ���� ������ �ش� ��带 ����
Node* BST_SearchNode(Node* tree, int findingVal)
{
	if (tree == NULL)
		return NULL;

	if (tree->data == findingVal)
		return tree;
	else if (tree->data > findingVal)
		return BST_SearchNode(tree->leftChild, findingVal);
	else if (tree->data < findingVal)
		return BST_SearchNode(tree->rightChild, findingVal);
}

void BST_InsertNode(Node* tree, Node* node)
{
	if (node->data < tree->data) {	// �� �ܰ迡�� Ʈ���� �� ũ��� ����� �� ũ�� ��
		if (tree->leftChild == NULL) {	// �� �ܰ迡�� Ʈ���� ������ ������� ���ʿ� ����
			tree->leftChild = node;
			return;
		}
		else
			BST_InsertNode(tree->leftChild, node);	// ��� �߰�, ��Ʈ�� ������ ������ ���ʿ� �ڽ��� ������ ���� �ڽĿ� ���Ͽ� ���� �߰� ����
	}

	else if (node->data > tree->data) {	// �� �ܰ迡�� Ʈ���� �� ũ��� ����� �� ũ�� ��
		if (tree->rightChild == NULL) {	// �� �ܰ迡�� Ʈ���� �������� ������� �����ʿ� ����
			tree->rightChild = node;
			return;
		}
		else
			BST_InsertNode(tree->rightChild, node);	// ��� �߰�, ��Ʈ ������ ū�� �����ʿ� �ڽ� ������ ������ �ڽĿ� ���Ͽ� �߰� ������ ������
	}
}

