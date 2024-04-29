#include<iostream>
#include<string>
#include<list>
#include<vector>
using namespace std;

void Test_String01()
{
	string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;


	//查看扩容机制
	string s;
	s.reserve(100);

	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << endl;
	cout << "making s grow:\n ";

	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;


	//缩容
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
}




void test_string4()
{
	string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;

	// 查看扩容机制
	string s;
	s.reserve(100);

	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;


	s1.clear();
	cout << s1 << endl;
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

	// 缩容
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
	cout << s1.size() << endl;
}



void Test_String05()
{
	
	string s1("hello worldxxxxx");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	//cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

	//比当前capacity大才会扩容
	s1.reserve(200);

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;


	string s2("hello worldxxxxxxx");
	cout << s2.size()<< endl;
	cout << s2.capacity() << endl << endl;

	s2.resize(10);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;

	s2.resize(20);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
	//在这里的话,capacity是不变的
	//但是size会发生变化


	s2.resize(100, 'x');

	cout << s2.size() << endl;
	cout << s2.capacity() << endl << endl;
}


void Test_String06()
{
	string s1("hello world");
	cout << s1[2] << endl;
	cout << s1.at(5) << endl;//这个一会查一下

	try
	{

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}

void Test_String07()
{
	string s1("hello world");
	s1.push_back('!');
	//这个是直接从后面加入一个!号
	cout << s1 << endl;

	s1.append("hello bit");
	//这个也是在后面加入这句话
	cout << s1 << endl;

	s1.append(10, 'x');
	cout << s1 << endl;


	string s2("  apple");
	s1.append(++s2.begin(), --s2.end());
	cout << s1 << endl;

	string s3("1234567");
	(++s3.begin(), --s3.end());
	cout << s3 << endl;


	string s4("hello world");
	s4 += ' ';
	s4 += "apple";
	cout << s4 << endl;
}



void Test_String08()
{
	string s1("hello world");
	cout << s1 << endl;
	
	s1.assign(" xxxxx");
	cout << s1 << endl;
	s1.insert(0, "yyyy");
	cout << s1 << endl;
	s1.erase(5,3);
	cout << s1 << endl;
	s1.erase();
	cout << s1 << endl;
}

int main()
{
	//Test_String01();
	//test_string4();
	//Test_String05();
	//Test_String06();
	//Test_String07();
	Test_String08();
	return 0;
}