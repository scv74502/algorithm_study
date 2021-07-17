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

// 노드에 찾는 값이 있으면 true, 없으면 false 리턴
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

// 노드에 찾는 값이 있으면 해당 노드를 리턴
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
	if (node->data < tree->data) {	// 현 단계에서 트리의 값 크기와 노드의 값 크기 비교
		if (tree->leftChild == NULL) {	// 현 단계에서 트리의 왼쪽이 비었으면 왼쪽에 삽입
			tree->leftChild = node;
			return;
		}
		else
			BST_InsertNode(tree->leftChild, node);	// 재귀 추가, 루트의 값보다 작은데 왼쪽에 자식이 있으면 왼쪽 자식에 대하여 연산 추가 수행
	}

	else if (node->data > tree->data) {	// 현 단계에서 트리의 값 크기와 노드의 값 크기 비교
		if (tree->rightChild == NULL) {	// 현 단계에서 트리의 오른쪽이 비었으면 오른쪽에 삽입
			tree->rightChild = node;
			return;
		}
		else
			BST_InsertNode(tree->rightChild, node);	// 재귀 추가, 루트 값보다 큰데 오른쪽에 자식 있으면 오른쪽 자식에 대하여 추가 연산을 수행함
	}
}

