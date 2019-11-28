#include <iostream>
#include <string>
#pragma once
/*
1.우리가 지금까지 초기화를 했던 방식과 조금 다른 방식으로 선언 및 초기화가 가능합니다.
2. Member Initializer에서 사용했던 SimpleClass(int n) : num(n)을 생각하면 조금 더 친숙하게 느껴집니다.
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
명시적으로 정의한 copy constructor
즉, 복사 생성사를 정의하지 않으면, 멤버 대멤버의 복사를 진행하는 디폴트 복사 생성자가 자동으로 삽입됩니다. 
받아들이기 쉬운 개념입니다. 받아들이고 넘어갑니다.

default copy constructor를 사용하고 싶지 않은 경우가 있을 것입니다. 
그럴 때는 명시적으로 복사 생성자를 정의한 뒤에 explicit 키워드를 추가하면 됩니다.
*/
//CopyConstructorClass::CopyConstructorClass(const CopyConstructorClass& copy) : num1(copy.num1), num2(copy.num2) {
//	cout << "Copy Constructor called" << endl;
//}

//함수의 선언부에만 expicit을 사용하고 정의부에는 explicit을 사용하면 안된다.
//이 프로젝트는 편의상 코드 분할을 하고 있지만, header에서 선언하면서 explicit하고, cpp에서는 explicit을 명시하면 안된다.
CopyConstructorClass::CopyConstructorClass(const CopyConstructorClass& copy) : num1(copy.num1), num2(copy.num2) {
	cout << "Copy Constructor called" << endl;
}

void howToUseCopyConstructor(void) {
	//기본 변수 생성
	int num = 20;
	int& ref = num;

	//cpp 스타일의 변수 생성
	int num2(20);
	int& ref2(num2);

	CopyConstructorClass sc1(10, 20);
	CopyConstructorClass sc2(sc1);
	sc1.ShowSimpleData(); //10\n20 출력
	sc2.ShowSimpleData(); //10\n20 출력
	/*
	1. 그런데 sc2를 생성하는 과정에서 (sc1)을 전달합니다. 분명히 CopyConstructorClass형 매개변수를 받는 생성자는 없는데 말이죠.
	2. 이 문장을 제일 위에서 언급한 것과 같이 초기화문으로 이해를 해야합니다. 
	CopyConstructorClass sc1 = sc2;
	바로 위에서는  SimpleClass형 매개변수를 받는 생성자가 없다고 했지만 사실  
	SimpleClass형 매개변수를 받는 생성자를 호출해서 객체생성을 완료합니다.
	좀더 정확히는 다음 코드가
	CopyConstructorClass sc2 = sc1;
	아래의 코드와 같은 형태로 묵시적으로 형태 변환이 일어나서 객체가 생성됩니다.
	CopyConstructorClass sc2(sc1);
	*/
	//CopyConstructorClass sc2 = sc1; //이렇게 적으면
	//CopyConstructorClass sc2(sc1); //이렇게 변환이 된다. 
	//위와 같이 자동 형태 변환이 일어날 때 생성되는 default 생성자를 Copy Constructor라고 합니다.

	//CopyConstructorClass sc3 = sc1; // defulat copy constructor를 막기위해 선언부에 explicit을 추가했다. 
	CopyConstructorClass sc4(sc1); // sc3 = sc1를 sc4(sc1)으로 묵시적 변환하는 것을 막는 것이지, copy 생성자를 호출하는 것은 가능하다.
}


/*
얕은 복사 깊은 복사

얕은 복사 : 객체가 가진 맴버들을의 값을 새로운 객체로 복사하는데 만약 객체가 참조타입의 멤버를 가지고 있다면
참조값만 복사됩니다. 즉, 같은 메모리를 가리키는 참조값을 복사된 객체도 가지게 됩니다.
이는 복사 전의 객체의 맴버를 수정하면 복사된 객체의 맴버도 수정되는 특정을 가집니다.

깊은 복사 : 객체가 가진 맴버들들의 값을 새로운 객체로 복사할 때 참조되는 객체 자체도 복사가 됩니다.
따라서 복사 이전의 객체의 맴버를 수정해도 복사된 객체의 맴버에는 영향을 주지 않습니다. 
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
	depp copy : 참조되는 객체를 new로 새로 만들고 내용을 복사하기
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
	//깊은 복사 & 얕은 복사
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
	objA.setCharStr(charStr2); //copy constructor는 deep copy로 정의해서 값을 바꿔도 영향이 없다.
	objA.setStringStr(string("setStringStr"));
	cout << "\n";
	objA.printStr();
	objB.printStr();
	cout << "\n";
	cin >> charStr;
	objA.printStr(); //objA의 기본 생성자는 shallowcopy이기 때문에 charStr를 바꾸면 값이 바뀐다.
	cout << "\n";

	//복사 생성자의 호출 시점 세 가지
	CopyConstWithString ccsA(constStr, charStr, stringStr);
	CopyConstWithString ccsB(ccsA); //1. 기본 copy 생성자

	CopyConstWithString ccsC = ccsB.returnCopyObject(ccsA); //2. ccsA를 param으로 전달할 때 호출
	//                       <-- 3. returnCopyObject의 return을 ccsC에 넣을 때 호출
	/*
	함수가 값을 반환하면, 별도의 메모리 공간이 할당되고, 
	이 공간에 반환 값이 저장된다.(반환 값으로 초기화된다.) <-- 이 떄는 저장일 뿐 copy 호출되지 않음.
	이렇게 저장된 값을 ccsC에 assign할 때는 copy constructor가 호출됨. 
	*/
}


void whatIsTemporaryobject(void) {
	const char* constStr = "niklas";
	char charStr[30] = "charString";
	string stringStr("stringStr");
	CopyConstWithString (constStr, charStr, stringStr); //임시객체 생성
	CopyConstWithString copyedObject  = CopyConstWithString(constStr, charStr, stringStr).returnThis();
}