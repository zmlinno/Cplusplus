#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#pragma once
#include<utility>
#include<string>
template<class K>

struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
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
				//这个地方就是如果比较键值和根节点键值
				//比如键值11大于根节点键值10
				//那么就移动到根节点的右子节点。
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				//这个地方就是如果比较键值和根节点键值
				//比如键值5小于根节点键值10
				//那么就移动到根节点的左子节点
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
		//删除的重点
		Node* parent = nullptr;
		Node* cur = _root;
		//_root代表根的节点
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//从这里开始添加删除的操作
				//1.先判断左子节点是否为空
				//2.在判断右子节点是否为空
				//3.最后在判断两个节点都是空

				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else

					{
						if (cur->_right == nullptr)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				else
				{
					//1.在这里是如果左右都不为空
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					std::swap(cur->_key, rightMin->_key);

					if (rightMinParent->_left == rightMin)
					{
						rightMinParent->_left = rightMin->_right;
					}
					else
					{
						rightMinParent->_right = rightMin->_right;
					}
					delete rightMin;
				}
				return true;
			}
			return false;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		std::cout << std::endl;
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
	t1.Erase(8);

	t1.InOrder();

	for (auto e : a)
	{
		t1.Erase(e);
		t1.InOrder();
	}
}





namespace key_value
{
	// 定义模板类，K 和 V 分别表示键和值的类型
	template<class K, class V>

	// 定义二叉搜索树节点的结构体模板
	struct BSTreeNode
	{
		// 左子节点指针，指向左子树的根节点
		BSTreeNode<K, V>* _left;

		// 右子节点指针，指向右子树的根节点
		BSTreeNode<K, V>* _right;

		// 键，用于节点的排序和搜索
		K _key;

		// 值，存储与键相关联的数据
		V _value;

		// 构造函数，初始化节点的键和值，并将左右子节点指针初始化为 nullptr
		BSTreeNode(const K& key, const V& value)
			: _left(nullptr)     // 将左子节点指针初始化为 nullptr
			, _right(nullptr)    // 将右子节点指针初始化为 nullptr
			, _key(key)          // 初始化节点的键
			, _value(value)      // 初始化节点的值
		{}
	};


	template<class K,class V>
	class BSTree
	{
	
		typedef BSTreeNode<K, V>Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				//1.如果根节点为空
				//2.那么创建一个根节点
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}


			cur = new Node(key, value);

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

			Node* Find(const K& key)
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
						return cur;
					}
				}
				return cur;
			}

			bool Erase(const K& key)
			{
				Node* parent = nullptr;
				Node* cur = _root;
				while (cur)
				{
					if (cur->_key < key)
					{
						parent = cur;
						cur = cur->_right;
					}
					else if (cur->_key > key)
					{
						parent = cur;
						cur = cur->_left;
					}
					else
					{
						//添加删除
						if (cur->_left == nullptr)
						{
							if (cur == _root)
							{
								_root = cur->_right;
							}
							else
							{
								if (cur == parent->_left)
								{
									parent->_left = cur->_right;
								}
								else
								{
									parent->_right = cur->_right;
								}
							}
							delete cur;
						}
						else if (cur->_right == nullptr)
						{
							if (cur == _root)
							{
								_root = cur->_left;
							}
							else
							{
								if (cur == parent->_left)
								{
									parent->_left = cur->_left;
								}
								else
								{
									parent->_right = cur->_right;
								}
							}
							delete cur;
						}
						else
						{
							//1如果左右都不为空
							Node* rightMinParent = cur;
							Node* rightMin = cur->_right;
							while (rightMin->_left)
							{
								rightMinParent = rightMin;
								rightMin = rightMin->_left;
							}
							std::swap(cur->_key, rightMin->_key);
							if (rightMinParent->_left == rightMin)
							
								rightMinParent->_left = rightMin->_right;

						
							else
							
								//因为是找最左点删除
								rightMinParent->_right = rightMin->_right;
							delete rightMin;
						}
						return true;
					}
				}
				return false;
			}

			void InOrder()
			{
				_InOrder(_root);
				std::cout << std::endl;
			}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			std::cout << root->_key << ":" << root->_value << std::endl;
			_InOrder(root->_right);
		}

		
	private:
		Node* _root = nullptr;
	};

	void TestBSTree2()
	{
		BSTree<std::string, std::string> dict;
		dict.Insert("string", "字符串");
		dict.Insert("left", "左边");
		dict.Insert("insert", "插入");
		//...

		std::string str;
		while (std::cin >> str)
		{
			BSTreeNode<std::string, std::string>* ret = dict.Find(str);
			if (ret)
			{
			std::cout << ret->_value << std::endl;
			}
			else
			{
				std::cout << "无此单词，请重新输入" <<std:: endl;
			}
		}
	}
	void TestBSTree3()
	{
		// 统计次数
		std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "香蕉","苹果","草莓", "苹果","草莓" };
		BSTree<std::string, int> countTree;
		for (const auto& str : arr)
		{
			auto ret = countTree.Find(str);
			if (ret == nullptr)
			{
				countTree.Insert(str, 1);
			}
			else
			{
				ret->_value++;
			}
		}

		countTree.InOrder();
	}


}
