#define _CRT_SECURE_NO_WARNINGS
#pragma
template<class K>

struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

template<class K>

class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		
		while (cur)
		{
			if (cur->_key < key)
			{
				//����ط���������Ƚϼ�ֵ�͸��ڵ��ֵ
				//�����ֵ11���ڸ��ڵ��ֵ10
				//��ô���ƶ������ڵ�����ӽڵ㡣
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				//����ط���������Ƚϼ�ֵ�͸��ڵ��ֵ
				//�����ֵ5С�ڸ��ڵ��ֵ10
				//��ô���ƶ������ڵ�����ӽڵ�
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& key)
	{

	}

	void InOrder()
	{
		_InOrder(_root);
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		std::cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};



void TestBSTreel()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BSTree<int>t1;
	for (auto e : a)
	{
		t1.Insert(e);
	}
	t1.InOrder();
}


