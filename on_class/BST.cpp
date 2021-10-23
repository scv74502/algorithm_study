#include<iostream>
#include<vector>
#include<string>

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

void BST_InsertValue(Node* tree, int val)
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

Node* BST_SearchMinNode(Node* tree)	// 수정하기
{
	if (tree == NULL)
		return NULL;

	if (tree->leftChild == NULL)
		return NULL;
	else
		return BST_SearchMinNode(tree->leftChild);
}

Node* BST_RemoveNode(Node* tree, Node* parent, int target)
{
	// target 값을 가진 노드가 삭제할 노드
	// tree에 삭제할 위치에 있는 노드가, 삭제할 노드 부모를 parent에 저장
	// 삭제할 노드는 나중에 리턴
	// tree값을 새롭게 세팅해 새로운 노드로 대체

	if (tree == NULL)
		return NULL;

	Node* removedNode = NULL;

	// 삭제할 노드를 탐색
	if (tree->data > target)
		removedNode = BST_RemoveNode(tree->leftChild, tree, target);
	else if (tree->data < target)
		removedNode = BST_RemoveNode(tree->rightChild, tree, target);
	else if (tree->data == target)	// 삭제할 값을 찾음
	{
		removedNode = tree;	// 삭제된 노드를 반환 예정, 삭제 작업 전에 저장함

		// 1. 삭제하려는 노드의 자식 서브트리가 0개인 리프 노드일 때
		if (tree->leftChild == NULL && tree->rightChild == NULL) {
			if (parent->leftChild == tree)
				parent->leftChild = NULL;
			if (parent->rightChild == tree)
				parent->rightChild == NULL;
		}

		// 2. 삭제하려는 노드의 자식 서브트리가 1개일 때
		else if (tree->leftChild == NULL || tree->rightChild == NULL) {
			Node* tempNode = NULL;
			if (tree->leftChild != NULL)
				tempNode = tree->leftChild;
			else
				tempNode = tree->rightChild;

			if (parent->leftChild == tree)
				parent->leftChild = tempNode;
			else
				parent->rightChild = tempNode;
		}
		// 3. 삭제하려는 노드의 자식 서브트리가 2개일 때
		// 큰 노드의 서브트리 최소값, 또는 작은 노드의 서브트리 최대값을 찾는다
		else if (tree->leftChild != NULL && tree->rightChild != NULL)
		{
			Node* mob = BST_SearchMinNode(tree->rightChild);	// mob = minNode of BiggerNode
			mob = BST_RemoveNode(tree, NULL, mob->data);
			tree->data = mob->data;
		}
	}

	return removedNode;
} 


// 중위 순회(정렬된 순서대로 출력
void BST_InOrder(Node* tree, std::vector<int>& pos)
{
	if (tree == NULL)
		return;
	BST_InOrder(tree->leftChild, pos);
	pos.push_back(tree->data);	// 출력
	BST_InOrder(tree->rightChild, pos);
} 

// 후위 순회
void BST_PostOrder(Node* tree, std::vector<int>& pos)
{
	if (tree == NULL)
		return;
	BST_PostOrder(tree->leftChild, pos);
	BST_PostOrder(tree->rightChild, pos);
	pos.push_back(tree->data); // 출력
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	Node* root = NULL;
	int val;
	std::vector<int> pos;
	while (std::cin >> val) {
		if (val == EOF) break;
		BST_InsertValue(root, val);
	}
	BST_PostOrder(root, pos); 
	for (int i = 0; i < pos.size(); i++)
		std::cout << pos[i] << "\n";

	return 0;
}
