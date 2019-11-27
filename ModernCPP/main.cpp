/**
@author niklasjang
@date 2019-11-26

https://blog.naver.com/niklasjang 의 C++ 문법 정리를 보고 cpp reference가 될만한 프로그램을 작성하는 것을 목표로 합니다.

1. cpp의 기본 개념을 나타내는 프로그램
2. 기존 cpp와 cpp11차이점을 표현하는 프로그램

본 프로그램은 1번 프로그램입니다.

단축키
찾고자하는 함수의 이름을 선택하고 F12를 누르면 해당 함수의 정의로 이동합니다. 
주석 :ctrl k c
주석 해제 : ctrl k u
*/

/*
헤더파일
1. cpp의 헤더파일도 확장자는 .h
2. 표준 헤더파일에서는 확장자를 생략
3. 외부에 선언된 변수나 함수에 접근하기 위해서 필요한 선언들이지만 매번 삽입하는 것은 번거로우니 
이들 선언을 헤더파일에 모아두고 필요할 때마다 헤더파일을 포함시키는 방법을 선택한다
4. 구조체의 정의도 헤더파일에서 작성하고, 구조체를 여러 개의 소스 파일에서 사용하도록 한다.
*/
#include <iostream> //표준 헤더 : 표준 헤더파일(C의 표준에서 정의하고 있는, 기본적으로 제공되는 헤더파일)이 저장되어 있는 디렉터리
#ifndef __SIMPLE_CONCEPTS_H__
#define __SIMPLE_CONCEPTS_H__
#include "simpleConcepts.h" //사용자 정의 헤더 : 기본적으로 소스코드와 같은 경로에 위치함
//#include "./simpleConcepts.h"  //상대주소
//#include "D:\problem_solving\ModernCPP\simpleConcepts.h" //절대주소 
#endif

#ifndef __CLASS_CONCEPTS_H__
#define __CLASS_CONCEPTS_H__
#include "classConcepts.h"
#endif
/*
extern 키워드
의미
컴파일은 파일 단위로 진행된다. 다른 파일에서 해당 변수 또는 함수를 정의했음을 알림

사용법
1. int형 변수 num이 외부에 선언되어있음을 알린다.
2. Increment 함수가 외부에 선언되어있음을 알린다.
3. 함수의 경우 extern 선언을 생략할 수 있다.
*/
//extern int externInt;
//extern int externFunctionTest ();
//int exterFunctinoTest2();

/*
static 키워드

1. 외부 파일에서 접근하는 것을 막는다.
2. 혹은 현재의 파일에섬나 사용할 변수이다.
*/
static int staticInt = 0;

int main(void) {
	/*----simpleConcepts----*/
	//문자열 입출력
	//howToPrintString();
	
	//함수 오버로딩
	//functionOverLoadingExample(1);
	//functionOverLoadingExample(1, 2);
	//functionOverLoadingExample(1.1);

	//default parameter
	//howToSetDefaultParameter(1);
	//howToSetDefaultParameter(1, 2);
	//howToSetDefaultParameter(1, 2,3);

	//매크로 사용법
	//howToUseMacro();
	
	//inline 함수 사용법
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

	//const 키워드
	//howToUseConst();

	//bool
	//howToUseBoolType();

	//enum
	//howToUserEnum();

	//Reference 참조자	
	//howToUseNew(3);
	return 0;
}