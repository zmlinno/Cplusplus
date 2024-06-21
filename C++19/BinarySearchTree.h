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
		//ɾ�����ص�
		Node* parent = nullptr;
		Node* cur = _root;
		//_root������Ľڵ�
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
				//�����￪ʼ���ɾ���Ĳ���
				//1.���ж����ӽڵ��Ƿ�Ϊ��
				//2.���ж����ӽڵ��Ƿ�Ϊ��
				//3.������ж������ڵ㶼�ǿ�

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
					//1.��������������Ҷ���Ϊ��
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
	// ����ģ���࣬K �� V �ֱ��ʾ����ֵ������
	template<class K, class V>

	// ��������������ڵ�Ľṹ��ģ��
	struct BSTreeNode
	{
		// ���ӽڵ�ָ�룬ָ���������ĸ��ڵ�
		BSTreeNode<K, V>* _left;

		// ���ӽڵ�ָ�룬ָ���������ĸ��ڵ�
		BSTreeNode<K, V>* _right;

		// �������ڽڵ�����������
		K _key;

		// ֵ���洢��������������
		V _value;

		// ���캯������ʼ���ڵ�ļ���ֵ�����������ӽڵ�ָ���ʼ��Ϊ nullptr
		BSTreeNode(const K& key, const V& value)
			: _left(nullptr)     // �����ӽڵ�ָ���ʼ��Ϊ nullptr
			, _right(nullptr)    // �����ӽڵ�ָ���ʼ��Ϊ nullptr
			, _key(key)          // ��ʼ���ڵ�ļ�
			, _value(value)      // ��ʼ���ڵ��ֵ
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
				//1.������ڵ�Ϊ��
				//2.��ô����һ�����ڵ�
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
						//���ɾ��
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
							//1������Ҷ���Ϊ��
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
							
								//��Ϊ���������ɾ��
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
		dict.Insert("string", "�ַ���");
		dict.Insert("left", "���");
		dict.Insert("insert", "����");
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
				std::cout << "�޴˵��ʣ�����������" <<std:: endl;
			}
		}
	}
	void TestBSTree3()
	{
		// ͳ�ƴ���
		std::string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "�㽶","ƻ��","��ݮ", "ƻ��","��ݮ" };
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
