/*
#ifnder #define #endif처럼 헤더파일 중복 삽입방지를 막음.
하지만 컴파일러에 따라서는 제대로 동작하지 않을 수 있음.
*/
#pragma once 

/*
구조체
default 접근제어자 : public
*/

struct Car {
	//기존 cpp
	int num;
	char name[10];
	//cpp11에서는 default 값을 줄 수 있게 되었다.
	int num11 = 11;
	char name11[10] = { 'n','i','k','l','a','s' };
};

void howToUserStructure(void) {
	Car myCar = { 10, "niklas" };
	cout << myCar.num << "\n";
	cout << myCar.name << "\n";
	cout << myCar.num11 << "\n";
	cout << myCar.name11 << "\n";
	//cpp11 에서는 = 없이 uniform initialization도 사용 가능하다.
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
	메스트의 종속적을 보여주는 형태
	*/
	void structMethodOne(void) {
		cout << "structMethodOne \n";
	}

	void structMethodTwo(void);
};

/*
메서드의 정의만 밖으로 빼서 메서트의 분석을 용이하게 한 형태
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

default 접근제어자 : 
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
	메스트의 종속적을 보여주는 형태
	*/
	void classMethodOne(void) {
		cout << "classMethodOne \n";
	}

	void classMethodTwo(void);
};

/*
메서드의 정의만 밖으로 빼서 메서트의 분석을 용이하게 한 형태
*/
void ClassWithEnum::classMethodTwo(void) {
	cout << "classMethodTwo \n";
}

void howToUserClassWithEnum(void) {
	//이렇게 public 맴버변수만 있으면 이렇게 초기화도 가능하긴하다.
	//하지만 private 맴버가 있으면 불가능하고 생성자를 사용해야 한다.
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

1.매개변수도, 지역변수도 아닌, 멤버변수의 값을 변경하지 않는 것이다.
2. 다음과 같이 const함수에서 선언하는 함수의 경우 const 함수 내에서 호출되는 함수도 const 선언이 되어 있어야 한다.
3. 즉, const 함수 내에서는 const가 아닌 함수의 호출이 제한된다.
*/
class EasyClass {
private:
	int num;
public:
	void InitNum(int n) {
		num = n;
	}
	int GetNum() const { //이 곳에 const 선언을 하지 않으면
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
		num = easy.GetNum();  //이곳에서 에러가 발생한다.
	}
};

void howToUseConstFunction(void) {
	EasyClass easy;
	LiveClass live;
	live.InitNum(easy);
}


/*
Encapsulation
정보은닉 : 필요한 정보의 수준만 기억하게 하면 된다. 
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
	//정보은닉전 : 약을 먹어야하는 순서를 기억해야 한다.
	IAMSICK.takePillOne(pillOne());
	IAMSICK.takePillTwo(pillTwo());
	IAMSICK.takePillThree(pillThree());

	//정보은닉후: 약을 먹기만 하면 된다.
	coldPill cpill;
	IAMSICK.takePills(cpill);
}

/*
constructor

1. 클래스의 이름과 함수의 이름이 동일하다.
2. 반환형이 선언되어 있지 않으며, 실제로 반환하지 않는다.
3. 객체 생성시 딱 한 번 호출된다.
4. 생성자도 함수의 일종이니 오버로딩이 가능하다.
5. 생성자도 함수의 일종이니 매개변수에 default 값 설정이 가능하다.

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
	//생성자 오버로딩
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
		//num = x;와 같음
		//this->num = x;와 같음
		cptr = new char[3];
		
	}
	//rnum = y; Error! 참조자 맴버변수는 initializer를 사용해서 초기화 해야한다.
	//ACLASS(int x, int y) : num(x), rnum(y) {	}
	ACLASS() {
		cout << this << "\n"; //자신의 주소값 출력
		cout << "AAA is constructed\n";
	}

	~ACLASS() {
		delete cptr;
		cout << "AAA is destructed\n";
	}
};


void howToUseConstructor(void) {
	SimpleClass sc0; //default 생성자 SimpleClass(void) { num = 10; }
	SimpleClass sc(20);
	sc.PrintMemberValue();
	SimpleClass sc1(10); // 가능
	SimpleClass* scPtr = new SimpleClass(); // 가능
	SimpleClass* scPtr2 = new SimpleClass(10); // 가능
	//SimepleClass sc1(); // 불가능 < -----------주의
	/*
	SimpleClas sc1();과 같이 객체를 만들려고 하면 이것이  
	반환형이 SimpleClass이고 함수 이름이 sc1이고 
	매개변수가 void인 함수의 원형 선언↓으로 해석될 수 있어서 안된다. 
				SimpleClass nestedFunction(void);
	*/

	ACLASS aaa; //생성자 1번 실행
	ACLASS* aptr = new ACLASS; //생성자 1번 실행
	ACLASS* aptr2 = new ACLASS[3]; //빈 생성자만 자동실행, 다른 생성자는 일일이 실행해주어야 함.
	ACLASS aab(4);
	int y = 100;
	//ACLASS abc(5,y); 참조자를 맴버변수로 가질 때의 constructor 호출

	//객체 배열 포인터 만들고 하나씩 원하는 생성자 실행
	ACLASS* aClssArray[3]; // ACLASS형 포인터임에 주의!
	for (int i = 0; i < 3; i++) {
		aClssArray[i] = new ACLASS(3);
	}

	//일단 객체  배열 만들고 원하는 생성자 실행
	ACLASS* myPtr = new ACLASS[3];
	for (int i = 0; i < 3; i++) {
		myPtr[i] = ACLASS(300);
	}
}

/*
자신을 반환하는 클래스

매서드를 여러개 붙혀서 사용할 수 있도록 하기.
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
	//메서드 여러개 붙혀서 사용해버리기
	cout << sc.Adder(2).ReturnSelfReference().Adder(3).GetNum() << endl;
}