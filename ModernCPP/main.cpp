/**
@author niklasjang
@date 2019-11-26

https://blog.naver.com/niklasjang �� C++ ���� ������ ���� cpp reference�� �ɸ��� ���α׷��� �ۼ��ϴ� ���� ��ǥ�� �մϴ�.

1. cpp�� �⺻ ������ ��Ÿ���� ���α׷�
2. ���� cpp�� cpp11�������� ǥ���ϴ� ���α׷�

�� ���α׷��� 1�� ���α׷��Դϴ�.

����Ű
ã�����ϴ� �Լ��� �̸��� �����ϰ� F12�� ������ �ش� �Լ��� ���Ƿ� �̵��մϴ�. 
�ּ� :ctrl k c
�ּ� ���� : ctrl k u
*/

/*
�������
1. cpp�� ������ϵ� Ȯ���ڴ� .h
2. ǥ�� ������Ͽ����� Ȯ���ڸ� ����
3. �ܺο� ����� ������ �Լ��� �����ϱ� ���ؼ� �ʿ��� ����������� �Ź� �����ϴ� ���� ���ŷο�� 
�̵� ������ ������Ͽ� ��Ƶΰ� �ʿ��� ������ ��������� ���Խ�Ű�� ����� �����Ѵ�
4. ����ü�� ���ǵ� ������Ͽ��� �ۼ��ϰ�, ����ü�� ���� ���� �ҽ� ���Ͽ��� ����ϵ��� �Ѵ�.
*/
#include <iostream> //ǥ�� ��� : ǥ�� �������(C�� ǥ�ؿ��� �����ϰ� �ִ�, �⺻������ �����Ǵ� �������)�� ����Ǿ� �ִ� ���͸�
#ifndef __SIMPLE_CONCEPTS_H__
#define __SIMPLE_CONCEPTS_H__
#include "simpleConcepts.h" //����� ���� ��� : �⺻������ �ҽ��ڵ�� ���� ��ο� ��ġ��
//#include "./simpleConcepts.h"  //����ּ�
//#include "D:\problem_solving\ModernCPP\simpleConcepts.h" //�����ּ� 
#endif

#ifndef __CLASS_CONCEPTS_H__
#define __CLASS_CONCEPTS_H__
#include "classConcepts.h"
#endif
/*
extern Ű����
�ǹ�
�������� ���� ������ ����ȴ�. �ٸ� ���Ͽ��� �ش� ���� �Ǵ� �Լ��� ���������� �˸�

����
1. int�� ���� num�� �ܺο� ����Ǿ������� �˸���.
2. Increment �Լ��� �ܺο� ����Ǿ������� �˸���.
3. �Լ��� ��� extern ������ ������ �� �ִ�.
*/
//extern int externInt;
//extern int externFunctionTest ();
//int exterFunctinoTest2();

/*
static Ű����

1. �ܺ� ���Ͽ��� �����ϴ� ���� ���´�.
2. Ȥ�� ������ ���Ͽ����� ����� �����̴�.
*/
static int staticInt = 0;

int main(void) {
	/*----simpleConcepts----*/
	//���ڿ� �����
	//howToPrintString();
	
	//�Լ� �����ε�
	//functionOverLoadingExample(1);
	//functionOverLoadingExample(1, 2);
	//functionOverLoadingExample(1.1);

	//default parameter
	//howToSetDefaultParameter(1);
	//howToSetDefaultParameter(1, 2);
	//howToSetDefaultParameter(1, 2,3);

	//��ũ�� ����
	//howToUseMacro();
	
	//inline �Լ� ����
	//howToUseInline(1);
	//howToUseInline('a');

	//namespace
	/*jang::nameSpaceTest();
	niklas::nameSpaceTest();
	AAA::BBB::aaabbb();
	using namespace AAA::BBB;
	aaabbb();
	using namespace std;
	namespace AB = AAA::BBB;
	AB::aaabbb();
	using namespace AB;
	aaabbb();*/

	//const Ű����
	//howToUseConst();

	//bool
	//howToUseBoolType();

	//enum
	//howToUserEnum();

	//Reference ������	
	//howToUseNew(3);
	return 0;
}