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

void BST_InsertValue(Node* tree, int val)
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

Node* BST_SearchMinNode(Node* tree)	// �����ϱ�
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
	// target ���� ���� ��尡 ������ ���
	// tree�� ������ ��ġ�� �ִ� ��尡, ������ ��� �θ� parent�� ����
	// ������ ���� ���߿� ����
	// tree���� ���Ӱ� ������ ���ο� ���� ��ü

	if (tree == NULL)
		return NULL;

	Node* removedNode = NULL;

	// ������ ��带 Ž��
	if (tree->data > target)
		removedNode = BST_RemoveNode(tree->leftChild, tree, target);
	else if (tree->data < target)
		removedNode = BST_RemoveNode(tree->rightChild, tree, target);
	else if (tree->data == target)	// ������ ���� ã��
	{
		removedNode = tree;	// ������ ��带 ��ȯ ����, ���� �۾� ���� ������

		// 1. �����Ϸ��� ����� �ڽ� ����Ʈ���� 0���� ���� ����� ��
		if (tree->leftChild == NULL && tree->rightChild == NULL) {
			if (parent->leftChild == tree)
				parent->leftChild = NULL;
			if (parent->rightChild == tree)
				parent->rightChild == NULL;
		}

		// 2. �����Ϸ��� ����� �ڽ� ����Ʈ���� 1���� ��
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
		// 3. �����Ϸ��� ����� �ڽ� ����Ʈ���� 2���� ��
		// ū ����� ����Ʈ�� �ּҰ�, �Ǵ� ���� ����� ����Ʈ�� �ִ밪�� ã�´�
		else if (tree->leftChild != NULL && tree->rightChild != NULL)
		{
			Node* mob = BST_SearchMinNode(tree->rightChild);	// mob = minNode of BiggerNode
			mob = BST_RemoveNode(tree, NULL, mob->data);
			tree->data = mob->data;
		}
	}

	return removedNode;
} 


// ���� ��ȸ(���ĵ� ������� ���
void BST_InOrder(Node* tree, std::vector<int>& pos)
{
	if (tree == NULL)
		return;
	BST_InOrder(tree->leftChild, pos);
	pos.push_back(tree->data);	// ���
	BST_InOrder(tree->rightChild, pos);
} 

// ���� ��ȸ
void BST_PostOrder(Node* tree, std::vector<int>& pos)
{
	if (tree == NULL)
		return;
	BST_PostOrder(tree->leftChild, pos);
	BST_PostOrder(tree->rightChild, pos);
	pos.push_back(tree->data); // ���
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
