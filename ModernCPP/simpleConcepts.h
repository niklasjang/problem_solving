#include <iostream>
#include <string>
using namespace std;

#define SQUARE(x) ((x)*(x))
#define COMPLEX_MACRO SQUARE(5)
#define INITIALIZING_VARIABLES \
	x = 10, \
	y = 20, \
	z =30
#define SIMPLE_SWITCH_MACRO(x) \
	case (x) : \
	cout<<(x)<<","<<20<<","<<30<<"\n"; \
	cout<<(x)<<","<<20<<","<<30<<"\n";

//default 매개변수는 함수의 선언부에서만 작성한다. 정의부에서 재정의하지 않는다.
void howToSetDefaultParameter(int num1, int num2 = 20, int num3 = 30);

/*
문자열 입출력 방법
*/
void howToPrintString(void) {
	char str[10];
	cout << "char형 배열을 입력받습니다. 최대 길이는 10입니다." << endl;
	cout << "char형 배열의 마지막 원소는 널문자이므로 9개의 문자만 입력받을 수 있습니다." << endl;
	cin >> str;
	cout << str << "\n";

	/*1. const string ㅣiteral
	string literal은 c에서는 char array, cpp에서는 const char array
	*/
	const char* str2 = "I am niklasjang"; //char*로 적을꺼면 꼭 const char*로 적어야 한다.
	char str3[] = "I am niklasjang"; //char []로 적을꺼면 const를 붙히지 않아도 된다. 
	for (int i = 0; i < 3; i++) cout << str2[i] << "\n";
	//str2[0] = 'z'; error
	for (int i = 0; i < 3; i++) cout << str3[i] << "\n";
	str3[0] = 'z';
	cout << str2 << "\n";
	cout << str3 << "\n";
	/*
	2. string
	*/
}

/*
함수 오버로딩
개념 : 함수 호출시 정의되는 매개변수를 통해서 호출하고자하는 함수의 구분이 가능하다.
매개변수의 형태가 다르다면, **동일한 이름의 함수**를 정의하는 것이 가능하다.
단, 함수의 이름과 매개변수는 같고 반환타입만 다른 경우는 오버로딩이 불가능하다.
*/
void functionOverLoadingExample(int x) {
	cout << x << "\n";
}
void functionOverLoadingExample(int x, int y) {
	cout << x << y << "\n";
}
void functionOverLoadingExample(double x) {
	cout << x << "\n";
}

/*
default 매개변수
매개변수의 기본값이 정의가 되어있으면, 선언된 매개변수보다 적은 수의 매개변수를 전달하는 것이 가능하다.
전달되는 인자는 왼쪽부터 채워져 나가고 부족한 것은 default 값으로 채워진다.
만약 함수의 선언을 작성하면, 함수의 정의 부분에서는 default 값을 재정의하면(다시 적으면)안된다.
*/
void howToSetDefaultParameter(int num1, int num2, int num3) {
	cout << num1 << "," << num2 << "," << num3 << "\n";
}

/*
매크로 함수 : #define으로 정의한 함수
장점 : 실행속도에 이점이 있다.
동작 : 메크로를 정의한대로 함수의 몸체부분이 함수의 호출문을 대체한다.
단점 : 매크로를 정의하기가 어렵고, 가독성이 떨어지고, 협업자가 싫어할 수 있다. 디버깅이 어려울 수 있다.
특징 : 전달되는 인자에 type이 없다.
*/
void howToUseMacro(void) {
	cout << SQUARE(5) << "\n";
	cout << ((5) * (5)) << "\n";
	cout << COMPLEX_MACRO << "\n";
	int x = 0, y = 0, z = 0;
	INITIALIZING_VARIABLES;
	cout << x << "," << y << "," << z << "\n";
	int opt = 3;
	switch (opt) {
		SIMPLE_SWITCH_MACRO(3);
		break;
	default:
		cout << "default" << "\n";
	}

	//여러 개의 매개변수를 받는데, 여러 개 중 몇 개만 바뀌고 대부분 똑같은 매개변수를 받는 경우
	//https://github.com/nnsuite/nnstreamer/blob/master/ext/nnstreamer/tensor_decoder/tensordec-boundingbox.c#L723
}

/*
인라인 함수 사용법
설명 : 매크로 함수 장점(실행속도)는 유지하고 단점(정의하기 어려움)을 제거한 것
매크로 : 함수의 inline화를 전처기리에서 처리
inline 함수 : 함수의 inline화를 컴파일러가 처리.
컴파일러는 함수의 인라인화가 오히려 성능에 해가 된다고 판단할 경우, 이 키워드를 무시하기도 한다.
또한 컴파일러는 필요한 경우 일부 함수를 임의로 인라인 처리하기도 한다.
특징1 : 전달되는 인자에 type이 있는데, 이를 template를 사용해서 보완할 수 있다.
특징2 :  inline 함수는 해당 함수가 호출된 곳에서 함수의 몸체로 대체되어야하는데  
car.cpp에서 inline으로 만들어 버리면 main.cpp에서 inline 함수를 찾을 수 없다.

전처리기?
- 전처리기는 컴파일이 진행되기 전에 전처리 operation을 수행한다.
- 하지만 사실 전처리 과정을 진행하기 전에 compiler가 먼저 소스코드파일을 준비시킨다.

1. compiler : 필요없는 \(줄바꿈)을 제거해서 전처리기가 논리적인 단위로 코드를 볼 수 있도록 한다.
2. 전처리기 : 주석을 제거하고, 메크로를  호출된 부분에 대체하고, 헤더파일을 가져오고, text적인 오류를 검사한다.
* 전처리기가 실행되는 것은 compiler가 이를 컴파일 하기 전의 단계로 호출했기 때문이다. 
*/
template <class T>
inline void howToUseInline(T x) {
	cout << x << "\n";
}

/*
namespace
프로젝트를 진행하기 전에 함수 및 변수의 이름을 모두 정해서 이름 충돌이 발생하지 않게 할 수 있지만 근복적인 해결책이 되진 않는다.
*/

namespace niklas {
	void nameSpaceTest(void) {
		cout << "niklas::nameSpaceTest" << "\n";
	}
}

namespace jang {
	void nameSpaceTest(void) {
		cout << "jang::nameSpaceTest" << "\n";
	}
}

namespace AAA {
	namespace BBB {
		void aaabbb(void) {
			cout << "foo" << "\n";
		}
	}
}

/*
const keyword
https://www.geeksforgeeks.org/difference-between-const-int-const-int-const-and-int-const/
오른쪽에서 왼쪽으로 읽으면 의미를 알 수 있다. 
1. const int * == int const * : pointer to const int
2. int * const : const pointer to int
3. int const * const : const pointer to const int
*/
void howToUseConst(void) {
	//int const * : const int 를 담는 pointer
	const int cnum = 10;
	int const* ptr = &cnum;
	cout << *ptr << "\n";

	//int * const : int를 담는 const pointer
	int num1 = 10;
	int* const cptr = &num1;
	cout << *cptr << "\n";
	int num2 = 20;
	//cptr = &num2; Error! 다시 주소를 assign 할 수 없음

	//int const * const : const int를 담는 const pointer
	const int cnum1 = 10;
	const int cnum2 = 20;
	int const* const ccptr = &cnum1;
	cout << *ccptr << "\n";
	//ccptr = &cnum2; Error! 다시 주소를 assign 할 수 없음
}

/*
bool type
1. The default numeric value of true is 1 and false is 0. // int x = false + true + 6;
2. 이 둘을 정수의 형태로 출력할 때는 1,0으로 변환되도록 정의가 되어있는 것이다.
3. true/false는 각각 1바이트 크기의 데이터일 뿐이다. 
*/
void howToUseBoolType(void) {
	bool x = 0;  // false 
	bool y = 100;  // true 
	bool z = 15.75;  // true
	if (x == false) {
		cout << "x is false\n";
	}
}

/*
열거형, enum
개발자가 자신만의 '자료형'을 만들 수 있도록 해주는 기능

기본 :열거형 자료형 : 모든 값이 기호 상수로 정의되는 자료형, enum 키워드를 사용
*/

	
 enum Color { 
	// 열거자(enumerator) 
	// 각 열거자는 세미콜론(;)이 아니라 쉼표(,)로 구분된다. 
	COLOR_BLACK, 
	COLOR_RED, 
	COLOR_BLUE, 
	COLOR_GREEN, 
	COLOR_WHITE, 
	COLOR_CYAN, 
	COLOR_YELLOW, 
	COLOR_MAGENTA, 
}; 
// 그러나 enum 자체는 세미콜론으로 끝나야 한다. 
// 열거형 Color의 변수들 정의 

 enum ParseResult {
	 SUCCESS,
	 ERROR_ON_READING,
	 ERROR_ON_WRITEING,
	 ERROR_ON_PARSING,
 };

enum ItemType { 
	ITEMTYPE_SWORD,
	ITEMTYPE_TORCH,
	ITEMTYPE_POTION
};

void howToUserEnum(void) {
	Color paint = COLOR_WHITE;
	int indexColorWhite = COLOR_WHITE;
	cout << indexColorWhite << "\n";
	cout << paint << "\n";
	Color house(COLOR_BLUE);
	cout << house << "\n";
	Color apple{ COLOR_RED };
	cout << apple << "\n";
	//Color colorWhite = 5; // will cause compiler error
	Color color = static_cast<Color>(5); //가능은 하지만 ugly하다. 

	//사용 목적은 아래와 같이 가독성을 높히기 위해서 사용한다. 
	int parsingResponse = 0;
	switch (parsingResponse) {
	case SUCCESS:
		cout << "SUCCESS" << "\n";
		break;
	case ERROR_ON_READING:
		cout << "ERROR_ON_READING" << "\n";
		break;
	case ERROR_ON_WRITEING:
		cout << "ERROR_ON_WRITEING" << "\n";
		break;
	case ERROR_ON_PARSING:
		cout << "ERROR_ON_PARSING" << "\n";
		break;
	}

	int dropedItem = 0;
	switch (dropedItem) {
	case ITEMTYPE_SWORD :
		cout<< "ITEMTYPE_SWORD" <<"\n";
		break;
	case ITEMTYPE_TORCH:
		cout<< "ITEMTYPE_TORCH" <<"\n";
		break;
	case ITEMTYPE_POTION:
		cout<< "ITEMTYPE_POTION" <<"\n";
		//함수 정의에 따라서 return String("ITEMTYPE_POTION")도 가능함
		break;
	}
}

/*
reference
1. 변수 : 할당된 메모리 공간에 붙혀진 이름. 그 이름을 통해서 해당 메모리 공간에 접근이 가능
2. 참조자 :할당된 메모리 공간에 또 다른 이름을 붙히는 것
3. 포인터 : 포인터는 포인터지

참조자
1. 보통 매개변수 전달에 사용
2. 항상 참조하는 메모리에만 접근
3. 
포인터
1. 보통 프로그래밍을 용이하게 하는데 사용될 수 있음
2. 여러 주소로 접근가능

매개변수에서 변수와 참조자의 차이점
인자로 int num을 받는 것과 const int &num을 받는 것은 엄연히 다르다. 
데이터를 복사해서 가져오는 것과 외부의 변수에 접근을 하지만 
그 데이터의 내용을 바꾸지 않는 것은 주소값에 접근할 수 있는지의 유무 등 
확연한 차이를 보인다.

예시
아래의 함수는 함수의 내용에 따라서 Call-by-value/reference 둘 다 될 수 있다.
int * SimepleFunc(int * ptr){
	//Call-by-value형태
	return ptr+1;
	//Call-by-reference 형태
	if(ptr == NULL){
        return NULL;
    }
    *ptr = 20;
    return ptr;
}

*/
void referenceTest(int& x) {
	++x;
	cout << &x << "\n";
}

void constReferenceTest(const int& x) {
	//1. const에 의해서 x의 값이 변하지 않는다는 것을 함수의 내부를 보지 않아도 알 수 있다.
	//2. constReferenceTest(3); 과 같이 상수가 전달될 때 3을 굳이 변수에 저장하지 않고 사용할 수 있다.
	cout << x << "\n";
}

int& returnReferenceTest(int& x) {
	int num = 0;
	//return num; 지역변수의 참조자를 return하면 참조자가 참조하는 메모리가 사라진다.
	return x;
}

void howToUseReference(void) {
	int num1 = 10;
	int& rnum = num1;
	cout << rnum << "\n";
	cout << &rnum << "\n";
	referenceTest(rnum);
	cout << &rnum << "\n\n";

	int num2 = 10;
	rnum = num2;
	cout << &num2 << "\n";
	cout << rnum << "\n";
	cout << &rnum << "\n";
	referenceTest(rnum);
	cout << &rnum << "\n";
	constReferenceTest(rnum);
}

void howToUseNew(int x) {
	int* arrPtr = new int[x];
	for (int i = 0; i < x; i++) {
		arrPtr[i] = i * 10;
		cout << *(arrPtr + i) << "\n";
	}
	delete[] arrPtr;
	double* ptr = new double;
	*ptr = 10.02;
	cout << *ptr << "\n";
	delete ptr;
}

