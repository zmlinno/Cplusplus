
#pragma once
#include<assert.h>

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V>_kv;

	int _bf;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
		//在这里bf代表平衡因子
	{}
};

template<class K,class V>
class AVTree
{
	typedef AVLTreeNode<K, V>Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = cur;


		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				

				//当前子树出问题了，需要旋转平衡一下
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{

				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{

				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	Node* find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else if(cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
		
	}
	
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	//函数签名定义了右旋转操作
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = parent->_right;

		parent->_left = subLR;
		//将 subLR 变为 parent 的左子节点。
		//如果 subLR 存在，将它的父节点更新为 parent
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;

		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_left = parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}


	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		Node* ppNode = parent->_parent;

		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (ppNode->_right = parent)
			{
				ppNode->_right = subR;
			}
			else
			{
				ppNode->_left = subR;
			}
			subR->_parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
		
	}

	void RotateRL(Node* parent)
	{
		RotateR(parent->_right);
		RotateL(parent);
	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
private:
	Node* _root = nullptr;
};



void TestAVLTree1()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	AVTree<int, int>t1;
	for (auto e : a)
	{
		t1.Insert({e,e});
	}
	t1.InOrder();
}


//#include<assert.h>
//#pragma once
//
//template<class K, class V>
//struct AVLTreeNode
//{
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//	pair<K, V> _kv;
//
//	int _bf;  // balance factor
//
//	AVLTreeNode(const pair<K, V>& kv)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _kv(kv)
//		, _bf(0)
//	{}
//};
//
//template<class K, class V>
//class AVLTree
//{
//	typedef AVLTreeNode<K, V> Node;
//public:
//	// logN
//	bool Insert(const pair<K, V>& kv)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(kv);
//			return true;
//		}
//
//		Node* parent = nullptr;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_kv.first < kv.first)
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first > kv.first)
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		cur = new Node(kv);
//		if (parent->_kv.first < kv.first)
//		{
//			parent->_right = cur;
//		}
//		else
//		{
//			parent->_left = cur;
//		}
//		cur->_parent = parent;
//
//		//...
//		// 更新平衡因子
//		while (parent)
//		{
//			if (cur == parent->_left)
//			{
//				parent->_bf--;
//			}
//			else
//			{
//				parent->_bf++;
//			}
//
//			if (parent->_bf == 0)
//			{
//				// 更新结束
//				break;
//			}
//			else if (parent->_bf == 1 || parent->_bf == -1)
//			{
//				// 继续往上更新
//				cur = parent;
//				parent = parent->_parent;
//			}
//			else if (parent->_bf == 2 || parent->_bf == -2)
//			{
//				// 当前子树出问题了，需要旋转平衡一下
//				if (parent->_bf == -2 && cur->_bf == -1)
//				{
//					RotateR(parent);
//				}
//				else if (parent->_bf == 2 && cur->_bf == 1)
//				{
//					RotateL(parent);
//				}
//				else if (parent->_bf == 2 && cur->_bf == -1)
//				{
//
//				}
//				else if (parent->_bf == -2 && cur->_bf == 1)
//				{
//
//				}
//
//				break;
//			}
//			else
//			{
//				// 理论而言不可能出现这个情况
//				assert(false);
//			}
//		}
//
//
//		return true;
//	}
//
//	Node* Find(const K& key)
//	{
//		Node* cur = _root;
//		while (cur)
//		{
//			if (cur->_kv.first < key)
//			{
//				cur = cur->_right;
//			}
//			else if (cur->_kv.first > key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//
//		return nullptr;
//	}
//
//
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	void RotateR(Node* parent)
//	{
//		Node* subL = parent->_left;
//		Node* subLR = subL->_right;
//
//		parent->_left = subLR;
//		if (subLR)
//			subLR->_parent = parent;
//
//		subL->_right = parent;
//
//		Node* ppNode = parent->_parent;
//		parent->_parent = subL;
//
//		if (parent == _root)
//		{
//			_root = subL;
//			_root->_parent = nullptr;
//		}
//		else
//		{
//			if (ppNode->_left == parent)
//			{
//				ppNode->_left = subL;
//			}
//			else
//			{
//				ppNode->_right = subL;
//			}
//
//			subL->_parent = ppNode;
//		}
//
//		parent->_bf = subL->_bf = 0;
//	}
//
//	void RotateL(Node* parent)
//	{
//		Node* subR = parent->_right;
//		Node* subRL = subR->_left;
//
//		parent->_right = subRL;
//		if (subRL)
//			subRL->_parent = parent;
//
//		subR->_left = parent;
//		Node* ppNode = parent->_parent;
//
//		parent->_parent = subR;
//
//		if (parent == _root)
//		{
//			_root = subR;
//			_root->_parent = nullptr;
//		}
//		else
//		{
//			if (ppNode->_right == parent)
//			{
//				ppNode->_right = subR;
//			}
//			else
//			{
//				ppNode->_left = subR;
//			}
//			subR->_parent = ppNode;
//		}
//
//		parent->_bf = subR->_bf = 0;
//	}
//
//	void RotateRL(Node* parent)
//	{
//		RotateR(parent->_right);
//		RotateL(parent);
//	}
//
//private:
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//
//		_InOrder(root->_left);
//		cout << root->_kv.first << ":" << root->_kv.second << endl;
//		_InOrder(root->_right);
//	}
//private:
//	Node* _root = nullptr;
//};
//
//void TestAVLTree1()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	AVLTree<int, int> t1;
//	for (auto e : a)
//	{
//		t1.Insert({ e,e });
//	}
//
//	t1.InOrder();
//}