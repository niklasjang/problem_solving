//class AAA;
//class BBB; //class BBB�� ������ ����ؼ� ������ ���� �ʰ���.
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
//method�� friend ������ �� ���� �ش� method�� ���ǰ� ���� �ڿ� friend�� ����ؾ��Ѵ�.
//�̰� ���� �Ⱦ��� �� ����. �������� ��û ������ �� ����.
//friend ��ü�� ���������� �ı��ϴ� �����̶� ���� �������� ���� �� ����. 
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
//	numB = aaa.numA; //AAA���� BBB�� friend�� �������� ������ AAA�� �ɹ��� �������� ���Ѵ�. 
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
//		//num1 += n; //������ ����!!
//		/*
//		static�� instance ���̵� �����ؾ��ϱ� ������ static ������ ��� �����ϴ�
//		*/
//		num2 += n;
//	}
//};
//int SoStatic::num2 = 2;
//void howToUseStatic(void) {
//
//	/*
//	-static function-
//	static ������ ���������� ������ ���� Ư������ �����ϴ�.
//	1. ����� Ŭ������ ��� ��ü�� �����Ѵ�
//	2. public���� ������ �Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ���� �����ϴ�.
//	3. ��ü�� ����� �����ϴ� ���� �ƴϴ�.
//	*/
//}

/*
���
*/
void whatIsInheritance(void) {
/*
1. ���� Ŭ������ ��ü ������������ ���� Ŭ������ �����ڰ� 100% ȣ��ȴ�.
2. ���� Ŭ������ �����ڿ��� ���� Ŭ������ ������ ȣ���� ������� ������, ���� Ŭ������ void �����ڰ� ȣ��ȴ�.
���� Ŭ������ ��ü�� �Ҹ�� ����, ���� Ŭ������ �Ҹ��ڰ� ����ǰ� �� ������ ���� Ŭ������ �Ҹ��ڰ� ����˴ϴ�. 
���ÿ� ������ ��ü�� �Ҹ������ ���������� �ݴ��̱� �����Դϴ�.

-> ���� Ư���� ����ؼ� �� ��ü���� �����Ҵ��� �޸𸮴� �ش� Ŭ������ �Ҹ��ڿ����� �����ϸ� �˴ϴ�.

- protected�� ����� ��������� �̸� ����ϴ� ���� Ŭ�������� ������ �����մϴ�.
- ��, C++���� AAA�� ������ ������ AAA��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ������ ��ü�� ����ų �� �ֵ�.(��ü�� �ּҰ��� ������ �� �ִ�.)
- Student�� Person�� ����ϸ� Student is a Person�̶�� ���谡 �����˴ϴ�.
�� Student�� Person ��ü�� �����Դϴ�. �̿� ���� ������ Person*�� student�� ����ų �� �ִ� ���Դϴ�.
*/
}

class First {
public:
	void FirstFunc() {
		cout << "FirstFUnc" << endl;
	};
	/*
	���࿡ First Ŭ������ Second�� Third���� ��ӵǴ� �����θ� �ǹ̰� �ְ� First ��ü ��ü�θ� �ǹ̰� �ִٸ�,
	First��ü�� �����ϴ� ���� ���� �� �־���մϴ�.
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
	AAA�� BBB��, BBB�� CCC��  ����Ѵٰ� �� ��, � �����͸� �������� ���� override�� 
	�Լ� ��� � �Լ��� ȣ����� �����ȴٰ� �� �� �ֽ��ϴ�.
	�̰��� ���� ������ �־�Դϴ�. �����ϴ� ��ü�� ���� ȣ��Ǵ� �Լ��� �����ϰ� �; �Լ� �������̵��� �ߴµ�, 
	�����Ǵ� ��ü�� �ƴ϶� �������� Ÿ�Կ� ���� ȣ��Ǵ� �Լ��� �����Ǵϱ��.

	First class�� MyFunc���� virtual Ű���带 �߰��մϴ�. �׷��� First�� MyFunc�� virtual�� �˴ϴ�.
	�Դٰ�  �� �Լ��� �������̵��ϴ� �Լ� ���� virtual�Լ��� �˴ϴ�.

	�̷��� virtual ������ �ϸ� �������� �ڷ����� ������� ȣ�� ����� �������� �ʰ�, 
	������ ������ ������ ����Ű�� ��ü�� �����Ͽ� ȣ���� ����� �����մϴ�.
	*/
	Third* tptr2 = new Third();
	Second* sptr2 = tptr2;
	First* fptr2 = sptr2;
	tptr2->MyFunc(); //virtual �־ ��ü Third�� method ȣ��, ������ �������� Ÿ�Կ� ���� �޼��� ȣ��
	sptr2->MyFunc(); //virtual �־ ��ü Third�� method ȣ��, ������ �������� Ÿ�Կ� ���� �޼��� ȣ��
	fptr2->MyFunc(); //virtual �־ ��ü Third�� method ȣ��, ������ �������� Ÿ�Կ� ���� �޼��� ȣ��

	Second* sptr3 = new Third();
	sptr3->MyFunc(); 

	/*
	-������-

	������ �����ߴ� Ư���� �������̶�� �մϴ�. ����δ� Polymorphism�Դϴ�.

	���ڷδ� �����̻�, Ǯ� �����ϸ� ���ϸ� ���������� �� ����� �ٸ� ���� �ǹ��մϴ�.
	
	*/

	//TODO polymorphism �� �� �ڼ���
	//https://blog.naver.com/niklasjang/221447622119 ����Ҹ���
}