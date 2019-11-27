#include <iostream>
#include <string>
#pragma once
/*
1.�츮�� ���ݱ��� �ʱ�ȭ�� �ߴ� ��İ� ���� �ٸ� ������� ���� �� �ʱ�ȭ�� �����մϴ�.
2. Member Initializer���� ����ߴ� SimpleClass(int n) : num(n)�� �����ϸ� ���� �� ģ���ϰ� �������ϴ�.
*/
class CopyConstructorClass {
private:
	int num1;
	int num2;
public:
	CopyConstructorClass(int n1, int n2);
	explicit CopyConstructorClass(const CopyConstructorClass& copy);
	void ShowSimpleData();
	~CopyConstructorClass();
};

CopyConstructorClass::CopyConstructorClass(int n1, int n2) : num1(n1), num2(n2) {

}
void CopyConstructorClass::ShowSimpleData() {
	cout << num1 << endl;
	cout << num2 << endl;
}

CopyConstructorClass::~CopyConstructorClass() {

}

/*
��������� ������ copy constructor
��, ���� �����縦 �������� ������, ��� ������ ���縦 �����ϴ� ����Ʈ ���� �����ڰ� �ڵ����� ���Ե˴ϴ�. 
�޾Ƶ��̱� ���� �����Դϴ�. �޾Ƶ��̰� �Ѿ�ϴ�.

default copy constructor�� ����ϰ� ���� ���� ��찡 ���� ���Դϴ�. 
�׷� ���� ��������� ���� �����ڸ� ������ �ڿ� explicit Ű���带 �߰��ϸ� �˴ϴ�.
*/
//CopyConstructorClass::CopyConstructorClass(const CopyConstructorClass& copy) : num1(copy.num1), num2(copy.num2) {
//	cout << "Copy Constructor called" << endl;
//}

//�Լ��� ����ο��� expicit�� ����ϰ� ���Ǻο��� explicit�� ����ϸ� �ȵȴ�.
//�� ������Ʈ�� ���ǻ� �ڵ� ������ �ϰ� ������, header���� �����ϸ鼭 explicit�ϰ�, cpp������ explicit�� ����ϸ� �ȵȴ�.
CopyConstructorClass::CopyConstructorClass(const CopyConstructorClass& copy) : num1(copy.num1), num2(copy.num2) {
	cout << "Copy Constructor called" << endl;
}

void howToUseCopyConstructor(void) {
	//�⺻ ���� ����
	int num = 20;
	int& ref = num;

	//cpp ��Ÿ���� ���� ����
	int num2(20);
	int& ref2(num2);

	CopyConstructorClass sc1(10, 20);
	CopyConstructorClass sc2(sc1);
	sc1.ShowSimpleData(); //10\n20 ���
	sc2.ShowSimpleData(); //10\n20 ���
	/*
	1. �׷��� sc2�� �����ϴ� �������� (sc1)�� �����մϴ�. �и��� CopyConstructorClass�� �Ű������� �޴� �����ڴ� ���µ� ������.
	2. �� ������ ���� ������ ����� �Ͱ� ���� �ʱ�ȭ������ ���ظ� �ؾ��մϴ�. 
	CopyConstructorClass sc1 = sc2;
	�ٷ� ��������  SimpleClass�� �Ű������� �޴� �����ڰ� ���ٰ� ������ ���  
	SimpleClass�� �Ű������� �޴� �����ڸ� ȣ���ؼ� ��ü������ �Ϸ��մϴ�.
	���� ��Ȯ���� ���� �ڵ尡
	CopyConstructorClass sc2 = sc1;
	�Ʒ��� �ڵ�� ���� ���·� ���������� ���� ��ȯ�� �Ͼ�� ��ü�� �����˴ϴ�.
	CopyConstructorClass sc2(sc1);
	*/
	//CopyConstructorClass sc2 = sc1; //�̷��� ������
	//CopyConstructorClass sc2(sc1); //�̷��� ��ȯ�� �ȴ�. 
	//���� ���� �ڵ� ���� ��ȯ�� �Ͼ �� �����Ǵ� default �����ڸ� Copy Constructor��� �մϴ�.

	//CopyConstructorClass sc3 = sc1; // defulat copy constructor�� �������� ����ο� explicit�� �߰��ߴ�. 
	CopyConstructorClass sc4(sc1); // sc3 = sc1�� sc4(sc1)���� ������ ��ȯ�ϴ� ���� ���� ������, copy �����ڸ� ȣ���ϴ� ���� �����ϴ�.
}

class CopyConstWithString {
private:
	char* str1;
	char str2[30];
	string str3;
public:
	CopyConstWithString(char* _str1, char* _str2, string _str3) {
		/*this->str1 = _str1;
		strcpy(str2, _str2);
		str3 = _str3;
		cout << str1 << "\n";
		cout << str2 << "\n";
		cout << str3 << "\n";*/
	}
};
//
//void whatIsDeepCopy(void) {
//	char* str1 = "niklas";
//	char str2[30];
//	string str3;
//	cin >> str2 >> str3;
//	CopyConstWithString cs(str1, str2, str3);
//}
