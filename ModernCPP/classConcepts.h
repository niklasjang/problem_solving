/*
#ifnder #define #endifó�� ������� �ߺ� ���Թ����� ����.
������ �����Ϸ��� ���󼭴� ����� �������� ���� �� ����.
*/
#pragma once 

/*
����ü
default ���������� : public
*/

struct Car {
	//���� cpp
	int num;
	char name[10];
	//cpp11������ default ���� �� �� �ְ� �Ǿ���.
	int num11 = 11;
	char name11[10] = { 'n','i','k','l','a','s' };
};

void howToUserStructure(void) {
	Car myCar = { 10, "niklas" };
	cout << myCar.num << "\n";
	cout << myCar.name << "\n";
	cout << myCar.num11 << "\n";
	cout << myCar.name11 << "\n";
	//cpp11 ������ = ���� uniform initialization�� ��� �����ϴ�.
	Car cpp11Object{ 10,"niklas",11,"jang" };
	cout << cpp11Object.num << "\n";
	cout << cpp11Object.name << "\n";
	cout << cpp11Object.num11 << "\n";
	cout << cpp11Object.name11 << "\n";
}

struct StructWithEnum {
	enum color {
		COLOR_WHITE,
		COLOR_BLACK,
	};
	int num = 0;
	color myColor;
	/*
	�޽�Ʈ�� �������� �����ִ� ����
	*/
	void structMethodOne(void) {
		cout << "structMethodOne \n";
	}

	void structMethodTwo(void);
};

/*
�޼����� ���Ǹ� ������ ���� �޼�Ʈ�� �м��� �����ϰ� �� ����
*/
void StructWithEnum::structMethodTwo(void) {
	cout << "structMethodTwo \n";
}

void howToUserStructureWithEnum(void) {
	StructWithEnum myStruct = { 1, StructWithEnum::COLOR_WHITE };
	cout << myStruct.COLOR_BLACK << "\n"; // 1
	cout << myStruct.COLOR_BLACK << "\n"; // 1
	cout << myStruct.myColor << "\n";  // 0
	myStruct.structMethodOne();
	myStruct.structMethodTwo();
}

/*

default ���������� : 
*/

class ClassWithEnum {
public:
	enum color {
		COLOR_WHITE,
		COLOR_BLACK,
	};
	int num = 0;
	color myColor;

	/*
	�޽�Ʈ�� �������� �����ִ� ����
	*/
	void classMethodOne(void) {
		cout << "classMethodOne \n";
	}

	void classMethodTwo(void);
};

/*
�޼����� ���Ǹ� ������ ���� �޼�Ʈ�� �м��� �����ϰ� �� ����
*/
void ClassWithEnum::classMethodTwo(void) {
	cout << "classMethodTwo \n";
}

void howToUserClassWithEnum(void) {
	//�̷��� public �ɹ������� ������ �̷��� �ʱ�ȭ�� �����ϱ��ϴ�.
	//������ private �ɹ��� ������ �Ұ����ϰ� �����ڸ� ����ؾ� �Ѵ�.
	ClassWithEnum myClassObejct = { 1, ClassWithEnum::COLOR_WHITE };
	cout << myClassObejct.COLOR_BLACK << "\n"; // 1
	cout << myClassObejct.COLOR_BLACK << "\n"; // 1
	cout << myClassObejct.myColor << "\n";  // 0
	myClassObejct.classMethodOne();
	myClassObejct.classMethodTwo();
}

/*
getter/setter pattern
const function

1.�Ű�������, ���������� �ƴ�, ��������� ���� �������� �ʴ� ���̴�.
2. ������ ���� const�Լ����� �����ϴ� �Լ��� ��� const �Լ� ������ ȣ��Ǵ� �Լ��� const ������ �Ǿ� �־�� �Ѵ�.
3. ��, const �Լ� �������� const�� �ƴ� �Լ��� ȣ���� ���ѵȴ�.
*/
class EasyClass {
private:
	int num;
public:
	void InitNum(int n) {
		num = n;
	}
	int GetNum() const { //�� ���� const ������ ���� ������
		return num;
	}
	int SetNum(int n) {
		num = n;
	}
};

class LiveClass {
private:
	int num;
public:
	void InitNum(const EasyClass& easy) {
		num = easy.GetNum();  //�̰����� ������ �߻��Ѵ�.
	}
};

void howToUseConstFunction(void) {
	EasyClass easy;
	LiveClass live;
	live.InitNum(easy);
}


/*
Encapsulation
�������� : �ʿ��� ������ ���ظ� ����ϰ� �ϸ� �ȴ�. 
*/
class pillOne {
public:
	void take(void) const {
		cout << "take pill one\n";
	}
};

class pillTwo {
public:
	void take(void) const {
		cout << "take pill two\n";
	}
};

class pillThree {
public:
	void take(void) const {
		cout << "take pill three\n";
	}
};

class coldPill {
private:
	pillOne pone;
	pillTwo ptwo;
	pillThree pthree;
public:
	void take(void) const {
		pone.take();
		ptwo.take();
		pthree.take();
	}
};

class coldPatient {
private:
	int theNumberOfPillHaveToken = 0;
public:
	void takePillOne(const pillOne& pone) {
		pone.take();
	}
	void takePillTwo(const pillTwo& pone) {
		pone.take();
	}
	void takePillThree(const pillThree& pone) {
		pone.take();
	}
	void takePills(const coldPill& cpill) {
		cpill.take();
	}
};

void whatIsEncapsulation(void) {
	coldPatient IAMSICK;
	//���������� : ���� �Ծ���ϴ� ������ ����ؾ� �Ѵ�.
	IAMSICK.takePillOne(pillOne());
	IAMSICK.takePillTwo(pillTwo());
	IAMSICK.takePillThree(pillThree());

	//����������: ���� �Ա⸸ �ϸ� �ȴ�.
	coldPill cpill;
	IAMSICK.takePills(cpill);
}

/*
constructor

1. Ŭ������ �̸��� �Լ��� �̸��� �����ϴ�.
2. ��ȯ���� ����Ǿ� ���� ������, ������ ��ȯ���� �ʴ´�.
3. ��ü ������ �� �� �� ȣ��ȴ�.
4. �����ڵ� �Լ��� �����̴� �����ε��� �����ϴ�.
5. �����ڵ� �Լ��� �����̴� �Ű������� default �� ������ �����ϴ�.

*/

class SimpleClass {
private:
	int num = 10;
public:
	SimpleClass(void) {
		num = 10;
	}
	SimpleClass(int n) {
		num = n;
	}
	//������ �����ε�
	SimpleClass(int n1, int n2) {
		num = n1 * n2;
	}
	void PrintMemberValue() {
		cout << num << endl;
	}
	int GetNum() {
		return num;
	}
};

class ACLASS {
private:
	int num = 10;
	//int& rnum;
	char* cptr = NULL;
	
	
public:
	//Memberinitializer 
	ACLASS(int x) : num(x){
		//num = x;�� ����
		//this->num = x;�� ����
		cptr = new char[3];
		
	}
	//rnum = y; Error! ������ �ɹ������� initializer�� ����ؼ� �ʱ�ȭ �ؾ��Ѵ�.
	//ACLASS(int x, int y) : num(x), rnum(y) {	}
	ACLASS() {
		cout << this << "\n"; //�ڽ��� �ּҰ� ���
		cout << "AAA is constructed\n";
	}

	~ACLASS() {
		delete cptr;
		cout << "AAA is destructed\n";
	}
};


void howToUseConstructor(void) {
	SimpleClass sc0; //default ������ SimpleClass(void) { num = 10; }
	SimpleClass sc(20);
	sc.PrintMemberValue();
	SimpleClass sc1(10); // ����
	SimpleClass* scPtr = new SimpleClass(); // ����
	SimpleClass* scPtr2 = new SimpleClass(10); // ����
	//SimepleClass sc1(); // �Ұ��� < -----------����
	/*
	SimpleClas sc1();�� ���� ��ü�� ������� �ϸ� �̰���  
	��ȯ���� SimpleClass�̰� �Լ� �̸��� sc1�̰� 
	�Ű������� void�� �Լ��� ���� ��������� �ؼ��� �� �־ �ȵȴ�. 
				SimpleClass nestedFunction(void);
	*/

	ACLASS aaa; //������ 1�� ����
	ACLASS* aptr = new ACLASS; //������ 1�� ����
	ACLASS* aptr2 = new ACLASS[3]; //�� �����ڸ� �ڵ�����, �ٸ� �����ڴ� ������ �������־�� ��.
	ACLASS aab(4);
	int y = 100;
	//ACLASS abc(5,y); �����ڸ� �ɹ������� ���� ���� constructor ȣ��

	//��ü �迭 ������ ����� �ϳ��� ���ϴ� ������ ����
	ACLASS* aClssArray[3]; // ACLASS�� �������ӿ� ����!
	for (int i = 0; i < 3; i++) {
		aClssArray[i] = new ACLASS(3);
	}

	//�ϴ� ��ü  �迭 ����� ���ϴ� ������ ����
	ACLASS* myPtr = new ACLASS[3];
	for (int i = 0; i < 3; i++) {
		myPtr[i] = ACLASS(300);
	}
}

/*
�ڽ��� ��ȯ�ϴ� Ŭ����

�ż��带 ������ ������ ����� �� �ֵ��� �ϱ�.
*/

class SelfReturnClass {
private:
	int num;
public:
	SelfReturnClass() {
		num = 0;
	}
	SelfReturnClass(int num) {
		this->num = num;
		cout << "Address is..." << this << endl;
	}
	int& GetNum() {
		return num;
	}
	SelfReturnClass* ReturnItSelf() {
		return this;
	}
	SelfReturnClass& ReturnSelfReference() {
		return *this;
	}
	SelfReturnClass& Adder(int n) {
		num += n;
		return *this;
	}
};

void howToUserSelfReturnClass(void) {
	SelfReturnClass sc;
	SelfReturnClass& sc2 = sc.ReturnSelfReference();
	cout << sc.GetNum() << endl;
	cout << sc2.GetNum() << endl;
	//�޼��� ������ ������ ����ع�����
	cout << sc.Adder(2).ReturnSelfReference().Adder(3).GetNum() << endl;
}