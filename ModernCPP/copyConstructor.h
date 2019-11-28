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


/*
���� ���� ���� ����

���� ���� : ��ü�� ���� �ɹ������� ���� ���ο� ��ü�� �����ϴµ� ���� ��ü�� ����Ÿ���� ����� ������ �ִٸ�
�������� ����˴ϴ�. ��, ���� �޸𸮸� ����Ű�� �������� ����� ��ü�� ������ �˴ϴ�.
�̴� ���� ���� ��ü�� �ɹ��� �����ϸ� ����� ��ü�� �ɹ��� �����Ǵ� Ư���� �����ϴ�.

���� ���� : ��ü�� ���� �ɹ������ ���� ���ο� ��ü�� ������ �� �����Ǵ� ��ü ��ü�� ���簡 �˴ϴ�.
���� ���� ������ ��ü�� �ɹ��� �����ص� ����� ��ü�� �ɹ����� ������ ���� �ʽ��ϴ�. 
*/
class CopyConstWithString {
private:
	const char* constStr;
	char* charStr;
	string stringStr;
public:
	/*
	shallow copy
	*/
	CopyConstWithString(const char* _constrStr, char* _charStr, string _stringStr) {
		constStr = _constrStr;
		charStr = _charStr;
		stringStr = _stringStr;
	}
	/*
	depp copy : �����Ǵ� ��ü�� new�� ���� ����� ������ �����ϱ�
	*/
	CopyConstWithString(const CopyConstWithString& copy) {
		constStr = copy.constStr;
		charStr = new char[strlen(copy.charStr + 1)];
		strcpy(charStr, copy.charStr);
		stringStr = copy.stringStr;
	}
	void printStr(void) {
		cout << constStr << "\n";
		cout << charStr<< "\n";
		cout << stringStr << "\n";
	}
	void setConstStr(const char* _constStr) {
		constStr = _constStr;
	}
	void setCharStr(char* _charStr) {
		strcpy(charStr, _charStr);
	}
	void setStringStr(string _stringStr) {
		stringStr = _stringStr;
	}
	
	CopyConstWithString returnThis(void) {
		return (CopyConstWithString )*this;
	}
	CopyConstWithString returnCopyObject(CopyConstWithString param) {
		return param;
	}
};

void whatIsDeepCopy(void) {
	//���� ���� & ���� ����
	const char* constStr = "niklas";
	char charStr[30] = "charString";
	string stringStr("stringStr");
	CopyConstWithString cs(constStr, charStr, stringStr);
	CopyConstWithString objA(constStr, charStr, string("stringStr"));
	CopyConstWithString objB(objA);
	objA.printStr();
	objB.printStr();
	cout << "\n";
	objA.setConstStr("setConstStr");
	char charStr2[30] = "setCharStr2";
	objA.setCharStr(charStr2); //copy constructor�� deep copy�� �����ؼ� ���� �ٲ㵵 ������ ����.
	objA.setStringStr(string("setStringStr"));
	cout << "\n";
	objA.printStr();
	objB.printStr();
	cout << "\n";
	cin >> charStr;
	objA.printStr(); //objA�� �⺻ �����ڴ� shallowcopy�̱� ������ charStr�� �ٲٸ� ���� �ٲ��.
	cout << "\n";

	//���� �������� ȣ�� ���� �� ����
	CopyConstWithString ccsA(constStr, charStr, stringStr);
	CopyConstWithString ccsB(ccsA); //1. �⺻ copy ������

	CopyConstWithString ccsC = ccsB.returnCopyObject(ccsA); //2. ccsA�� param���� ������ �� ȣ��
	//                       <-- 3. returnCopyObject�� return�� ccsC�� ���� �� ȣ��
	/*
	�Լ��� ���� ��ȯ�ϸ�, ������ �޸� ������ �Ҵ�ǰ�, 
	�� ������ ��ȯ ���� ����ȴ�.(��ȯ ������ �ʱ�ȭ�ȴ�.) <-- �� ���� ������ �� copy ȣ����� ����.
	�̷��� ����� ���� ccsC�� assign�� ���� copy constructor�� ȣ���. 
	*/
}


void whatIsTemporaryobject(void) {
	const char* constStr = "niklas";
	char charStr[30] = "charString";
	string stringStr("stringStr");
	CopyConstWithString (constStr, charStr, stringStr); //�ӽð�ü ����
	CopyConstWithString copyedObject  = CopyConstWithString(constStr, charStr, stringStr).returnThis();
}