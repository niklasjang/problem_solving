//class AAA;
//class BBB; //class BBB가 있음을 명시해서 에러가 나지 않게함.
//
//class AAA {
//private:
//	friend class BBB;
//	int numA;
//public:
//	AAA(int n);
//	int SetNumA(BBB& bbb);
//	void ShowContents();
//	~AAA();
//};
//
//AAA::AAA(int n) : numA(n) {
//	//Empty
//}
//
//int AAA::SetNumA(BBB& bbb) {
//	numA = bbb.numB;
//	return numA;
//}
//
//void AAA::ShowContents() {
//	std::cout << "num is..." << numA << endl;
//}
//AAA::~AAA()
//{
//}
//
///*
//method의 friend 선언을 할 때는 해당 method의 정의가 끝난 뒤에 friend를 사용해야한다.
//이건 많이 안쓰일 것 같다. 가독성이 엄청 떨어질 것 같다.
//friend 자체가 정보은닉을 파괴하는 개념이라 많이 쓰이지는 않을 것 같다. 
//*/
//
//class BBB {
//private:
//	int numB;
//	friend int AAA::SetNumA(BBB& bbb); 
//public:
//	BBB(int n);
//	int SetNumB(AAA& aaa);
//	void ShowContents();
//	~BBB();
//};
//
//BBB::BBB(int n) : numB(n) {
//	//Empty
//}
//
//int BBB::SetNumB(AAA& aaa) {
//	numB = aaa.numA; //AAA에서 BBB를 friend로 선언하지 않으면 AAA의 맴버에 접근하지 못한다. 
//	return numB;
//}
//
//void BBB::ShowContents() {
//	std::cout << "num is..." << numB << endl;
//}
//BBB::~BBB()
//{
//}
//
//
//void howToUseFriendClass(void) {
//	AAA aaa(5);
//	BBB bbb(7);
//
//	aaa.SetNumA(bbb);
//	bbb.SetNumB(aaa);
//
//	aaa.ShowContents();
//	bbb.ShowContents();
//}
//
//
///*
//static 
//*/
//
//class SoStatic {
//private:
//	int num1;
//	static int num2;
//public:
//	SoStatic(int n) : num1(n) {}
//	static void Adder(int n) {
//		//num1 += n; //컴파일 에러!!
//		/*
//		static은 instance 없이도 동작해야하기 때문에 static 변수만 사용 가능하다
//		*/
//		num2 += n;
//	}
//};
//int SoStatic::num2 = 2;
//void howToUseStatic(void) {
//
//	/*
//	-static function-
//	static 변수와 마찬가지로 다음과 같은 특성ㅇ르 가집니다.
//	1. 선언된 클래스의 모든 객체가 공유한다
//	2. public으로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능하다.
//	3. 객체의 멤버로 존재하는 것이 아니다.
//	*/
//}

/*
상속
*/
void whatIsInheritance(void) {
/*
1. 유도 클래스의 객체 생성과정에서 기초 클래스의 생성자가 100% 호출된다.
2. 유도 클래스의 생성자에서 기초 클래스의 생성자 호출을 명시하지 않으면, 기초 클래스의 void 생성자가 호출된다.
유도 클래스의 객체가 소멸될 때는, 유도 클래스의 소멸자가 실행되고 난 다음에 기초 클래스의 소멸자가 실행됩니다. 
스택에 생성된 객체의 소멸순서는 생성순서와 반대이기 때문입니다.

-> 위의 특성을 사용해서 각 객체에서 동적할당한 메모리는 해당 클래스의 소멸자에서만 진행하면 됩니다.

- protected로 선언된 멤버변수는 이를 상속하는 유도 클래스에서 접근이 가능합니다.
- 즉, C++에서 AAA형 포인터 변수는 AAA객체 또는 AAA를 직접 혹은 간접적으로 상속하는 무도느 객체를 가리킬 수 있따.(객체의 주소값을 저장할 수 있다.)
- Student가 Person을 상속하면 Student is a Person이라는 관계가 형성됩니다.
즉 Student는 Person 객체의 일종입니다. 이와 같은 이유로 Person*가 student를 가리킬 수 있는 것입니다.
*/
}

class First {
public:
	void FirstFunc() {
		cout << "FirstFUnc" << endl;
	};
	/*
	만약에 First 클래스가 Second와 Third에게 상속되는 것으로만 의미가 있고 First 객체 자체로만 의미가 있다면,
	First객체를 생성하는 것을 막을 수 있어야합니다.
	*/
	virtual void MyFunc() = 0;
	/*virtual void MyFunc() {
		cout << "FirstFunc" << endl;
	}*/


};

class Second : public First {
public:
	void SecondFunc() {
		cout << "SecondFunc" << endl;
	}
	void MyFunc() {
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second {
public:
	void ThirdFunc() {
		cout << "ThridFunc" << endl;
	}
	void MyFunc() {
		cout << "ThirdFunc" << endl;
	}
};



void whatIsInheritance2(void) {
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	tptr->FirstFunc(); //(O)
	tptr->SecondFunc();// (O)
	tptr->ThirdFunc(); //(O)

	sptr->FirstFunc(); //(O)
	sptr->SecondFunc();// (O)
	//sptr->ThirdFunc(); //(X)

	fptr->FirstFunc(); //(O)
	//fptr->SecondFunc();// (X)
	//fptr->ThirdFunc(); //(X)

	/*
	AAA를 BBB가, BBB를 CCC가  상속한다고 할 때, 어떤 포인터를 쓰는지에 따라서 override된 
	함수 가운데 어떤 함수가 호출될지 결정된다고 할 수 있습니다.
	이것은 조금 문제가 있어보입니다. 참조하는 객체에 따라서 호출되는 함수를 선택하고 싶어서 함수 오버라이딩을 했는데, 
	참조되는 객체가 아니라 포인터의 타입에 따라서 호출되는 함수가 결정되니까요.

	First class의 MyFunc에만 virtual 키워드를 추가합니다. 그러면 First의 MyFunc은 virtual이 됩니다.
	게다가  이 함수를 오버라이딩하는 함수 또한 virtual함수가 됩니다.

	이렇게 virtual 선언을 하면 포인터의 자료형을 기반으로 호출 대상을 결정하지 않고, 
	포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정합니다.
	*/
	Third* tptr2 = new Third();
	Second* sptr2 = tptr2;
	First* fptr2 = sptr2;
	tptr2->MyFunc(); //virtual 있어서 객체 Third의 method 호출, 없으면 포인터의 타입에 따른 메서드 호출
	sptr2->MyFunc(); //virtual 있어서 객체 Third의 method 호출, 없으면 포인터의 타입에 따른 메서드 호출
	fptr2->MyFunc(); //virtual 있어서 객체 Third의 method 호출, 없으면 포인터의 타입에 따른 메서드 호출

	Second* sptr3 = new Third();
	sptr3->MyFunc(); 

	/*
	-다형성-

	위에서 설명했던 특성을 다형성이라고 합니다. 영어로는 Polymorphism입니다.

	한자로는 동질이상, 풀어서 설명하면 동일만 문장이지만 그 기능이 다른 것을 의미합니다.
	
	*/

	//TODO polymorphism 좀 더 자세히
	//https://blog.naver.com/niklasjang/221447622119 가상소멸자
}