#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string word;
//	//cin >> word;
//	while (cin >> word)
//	{
//		cout << word << endl;
//		//�������һ����ѭ�������뷨��
//		//���������������ĸ֮������ո�Ļ�������������ʽ
//	}
//	return 0;
//}



//int main()
//{
//	//string a(10, 'c');
//	//string a1("value");
//	//
//	//cout << a << endl;
//	//cout << a1 << endl;
//	
//	//string a2 = "zhang";//�����ڿ�����ʼ��
//	//string a3{ "mu" };//ֱ�ӳ�ʼ��
//	//string a4(10, 'b');//��Ҳ��ֱ�ӳ�ʼ��
//
//
//	//string temp(11, 'b');
//	//string a = temp;
//	//cout << a << endl;
//	//return 0;
//
//
//
//	//string s1, s2;
//	//cin >> s1 >> s2;
//	//cout << s1 << s2 << endl;
//	//return 0;
//
//
//	string s1;
//	cin >> s1;
//	cout << s1 << endl;
//	return 0;
//	//����hello world�Ļ�ֻ�ܴ�ӡ��hello��
//	//�����ո�ͽ���������
//
//
//}





int main()
{
	//string line;
	////cin >> line;
	//while (getline(cin, line))
	//{
	//	cout << line << endl;
	//}

	//return 0;


	string line;
	while (getline(cin, line))
	{
		if (!line.empty())
		{
			cout << line << endl;
		}
	}
	return 0;
}