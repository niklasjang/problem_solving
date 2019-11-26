#include <iostream>
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

//default �Ű������� �Լ��� ����ο����� �ۼ��Ѵ�. ���Ǻο��� ���������� �ʴ´�.
void howToSetDefaultParameter(int num1, int num2 = 20, int num3 = 30);

/*
���ڿ� ����� ���
*/
void howToPrintString(void) {
	char str[10];
	cout << "char�� �迭�� �Է¹޽��ϴ�. �ִ� ���̴� 10�Դϴ�." << endl;
	cout << "char�� �迭�� ������ ���Ҵ� �ι����̹Ƿ� 9���� ���ڸ� �Է¹��� �� �ֽ��ϴ�." << endl;
	cin >> str;
	cout << str << "\n";
}

/*
�Լ� �����ε�
���� : �Լ� ȣ��� ���ǵǴ� �Ű������� ���ؼ� ȣ���ϰ����ϴ� �Լ��� ������ �����ϴ�.
�Ű������� ���°� �ٸ��ٸ�, **������ �̸��� �Լ�**�� �����ϴ� ���� �����ϴ�.
��, �Լ��� �̸��� �Ű������� ���� ��ȯŸ�Ը� �ٸ� ���� �����ε��� �Ұ����ϴ�.
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
default �Ű�����
�Ű������� �⺻���� ���ǰ� �Ǿ�������, ����� �Ű��������� ���� ���� �Ű������� �����ϴ� ���� �����ϴ�.
���޵Ǵ� ���ڴ� ���ʺ��� ä���� ������ ������ ���� default ������ ä������.
���� �Լ��� ������ �ۼ��ϸ�, �Լ��� ���� �κп����� default ���� �������ϸ�(�ٽ� ������)�ȵȴ�.
*/
void howToSetDefaultParameter(int num1, int num2, int num3) {
	cout << num1 << "," << num2 << "," << num3 << "\n";
}

/*
��ũ�� �Լ� : #define���� ������ �Լ�
���� : ����ӵ��� ������ �ִ�.
���� : ��ũ�θ� �����Ѵ�� �Լ��� ��ü�κ��� �Լ��� ȣ�⹮�� ��ü�Ѵ�.
���� : ��ũ�θ� �����ϱⰡ ��ư�, �������� ��������, �����ڰ� �Ⱦ��� �� �ִ�. ������� ����� �� �ִ�.
Ư¡ : ���޵Ǵ� ���ڿ� type�� ����.
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

	//���� ���� �Ű������� �޴µ�, ���� �� �� �� ���� �ٲ�� ��κ� �Ȱ��� �Ű������� �޴� ���
	//https://github.com/nnsuite/nnstreamer/blob/master/ext/nnstreamer/tensor_decoder/tensordec-boundingbox.c#L723
}

/*
�ζ��� �Լ� ����
���� : ��ũ�� �Լ� ����(����ӵ�)�� �����ϰ� ����(�����ϱ� �����)�� ������ ��
��ũ�� : �Լ��� inlineȭ�� ��ó�⸮���� ó��
inline �Լ� : �Լ��� inlineȭ�� �����Ϸ��� ó��.
�����Ϸ��� �Լ��� �ζ���ȭ�� ������ ���ɿ� �ذ� �ȴٰ� �Ǵ��� ���, �� Ű���带 �����ϱ⵵ �Ѵ�.
���� �����Ϸ��� �ʿ��� ��� �Ϻ� �Լ��� ���Ƿ� �ζ��� ó���ϱ⵵ �Ѵ�.
Ư¡ : ���޵Ǵ� ���ڿ� type�� �ִµ�, �̸� template�� ����ؼ� ������ �� �ִ�.
*/
template <class T>
inline void howToUseInline(T x) {
	cout << x << "\n";
}

/*
namespace
������Ʈ�� �����ϱ� ���� �Լ� �� ������ �̸��� ��� ���ؼ� �̸� �浹�� �߻����� �ʰ� �� �� ������ �ٺ����� �ذ�å�� ���� �ʴ´�.
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
�����ʿ��� �������� ������ �ǹ̸� �� �� �ִ�. 
1. const int * == int const * : pointer to const int
2. int * const : const pointer to int
3. int const * const : const pointer to const int
*/
void howToUseConst(void) {
	//int const * : const int �� ��� pointer
	const int cnum = 10;
	int const* ptr = &cnum;
	cout << *ptr << "\n";

	//int * const : int�� ��� const pointer
	int num1 = 10;
	int* const cptr = &num1;
	cout << *cptr << "\n";
	int num2 = 20;
	//cptr = &num2; Error! �ٽ� �ּҸ� assign �� �� ����

	//int const * const : const int�� ��� const pointer
	const int cnum1 = 10;
	const int cnum2 = 20;
	int const* const ccptr = &cnum1;
	cout << *ccptr << "\n";
	//ccptr = &cnum2; Error! �ٽ� �ּҸ� assign �� �� ����
}

/*
bool type
1. The default numeric value of true is 1 and false is 0. // int x = false + true + 6;
2. �� ���� ������ ���·� ����� ���� 1,0���� ��ȯ�ǵ��� ���ǰ� �Ǿ��ִ� ���̴�.
3. true/false�� ���� 1����Ʈ ũ���� �������� ���̴�. 
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
������, enum
�����ڰ� �ڽŸ��� '�ڷ���'�� ���� �� �ֵ��� ���ִ� ���

�⺻ :������ �ڷ��� : ��� ���� ��ȣ ����� ���ǵǴ� �ڷ���, enum Ű���带 ���
*/

	
 enum Color { 
	// ������(enumerator) 
	// �� �����ڴ� �����ݷ�(;)�� �ƴ϶� ��ǥ(,)�� ���еȴ�. 
	COLOR_BLACK, 
	COLOR_RED, 
	COLOR_BLUE, 
	COLOR_GREEN, 
	COLOR_WHITE, 
	COLOR_CYAN, 
	COLOR_YELLOW, 
	COLOR_MAGENTA, 
}; 
// �׷��� enum ��ü�� �����ݷ����� ������ �Ѵ�. 
// ������ Color�� ������ ���� 

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
	Color color = static_cast<Color>(5); //������ ������ ugly�ϴ�. 

	//��� ������ �Ʒ��� ���� �������� ������ ���ؼ� ����Ѵ�. 
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
		//�Լ� ���ǿ� ���� return String("ITEMTYPE_POTION")�� ������
		break;
	}
}

/*
reference
1. ���� : �Ҵ�� �޸� ������ ������ �̸�. �� �̸��� ���ؼ� �ش� �޸� ������ ������ ����
2. ������ :�Ҵ�� �޸� ������ �� �ٸ� �̸��� ������ ��
3. ������ : �����ʹ� ��������

������
1. ���� �Ű����� ���޿� ���
2. �׻� �����ϴ� �޸𸮿��� ����
3. 
������
1. ���� ���α׷����� �����ϰ� �ϴµ� ���� �� ����
2. ���� �ּҷ� ���ٰ���

�Ű��������� ������ �������� ������
���ڷ� int num�� �޴� �Ͱ� const int &num�� �޴� ���� ������ �ٸ���. 
�����͸� �����ؼ� �������� �Ͱ� �ܺ��� ������ ������ ������ 
�� �������� ������ �ٲ��� �ʴ� ���� �ּҰ��� ������ �� �ִ����� ���� �� 
Ȯ���� ���̸� ���δ�.

����
�Ʒ��� �Լ��� �Լ��� ���뿡 ���� Call-by-value/reference �� �� �� �� �ִ�.
int * SimepleFunc(int * ptr){
	//Call-by-value����
	return ptr+1;
	//Call-by-reference ����
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
	//1. const�� ���ؼ� x�� ���� ������ �ʴ´ٴ� ���� �Լ��� ���θ� ���� �ʾƵ� �� �� �ִ�.
	//2. constReferenceTest(3); �� ���� ����� ���޵� �� 3�� ���� ������ �������� �ʰ� ����� �� �ִ�.
	cout << x << "\n";
}

int& returnReferenceTest(int& x) {
	int num = 0;
	//return num; ���������� �����ڸ� return�ϸ� �����ڰ� �����ϴ� �޸𸮰� �������.
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

