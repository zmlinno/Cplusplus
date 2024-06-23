
#pragma once
#include<assert.h>
#include<vector>

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
class AVLTree
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
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		//在看下面代码的时候一定要先注意这个旋转的代码
		//先进行右旋
		RotateL(parent);
		//然后在左旋parent
		//然后在看下面的代码

		subRL->_bf = 0;
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else
		{
			parent->_bf = 0;
			subR->_bf = 0;
		}
	}

	void RotateLR(Node* parent)
	{
		Node* subR = parent->_left;
		Node* subLR = subR->_right;

		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			subR->_bf = -1;
		}

		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}


	bool Height()
	{
		return _Height(_root);
	}

	int Size()
	{
		return _Size(_root);
	}

	

private:
	int _Size(Node* root)
	{
		return root == nullptr ? 0 : _Size(root->_left) + _Size(root->_right) + 1;
	}

	int _Height(Node* root)
	{
		return max(_Height(root->_left), _Height(root->_right)) + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == NULL)
		{
			return true;
		}
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		//不平衡
		if (abs(leftHeight - rightHeight >= 2))
		{
			cout << root->_kv.first << endl;
			return false;
		}


		//顺便检查一下平衡因子是否正确
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << root->_kv.first << endl;
			return false;
		}
		return _IsBalance(root->_left) && _IsBalance(root->_right);
	}

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
	//int a[] = { 8,3,1,10,6,4,7,14,13 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int>t1;
	for (auto e : a)
	{
		t1.Insert({e,e});
		cout << "Insert:" << e << "->" << t1.IsBalance() << endl;
	}
	t1.InOrder();
	cout << t1.IsBalance() << endl;
}


void TestAVLTree2()
{
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
		//cout << v.back() << endl;
	}

	size_t begin2 = clock();
	AVLTree<int, int> t;
	for (auto e : v)
	{
		t.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end2 = clock();

	cout << "Insert:" << end2 - begin2 << endl;
	//cout << t.IsBalance() << endl;

	cout << "Height:" << t.Height() << endl;
	cout << "Size:" << t.Size() << endl;

	size_t begin1 = clock();
	// 确定在的值
	for (auto e : v)
	{
		t.find(e);
	}

	// 随机值
	/*for (size_t i = 0; i < N; i++)
	{
		t.Find((rand() + i));
	}*/

	size_t end1 = clock();

	cout << "Find:" << end1 - begin1 << endl;
}


