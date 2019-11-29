/*
lower_bound : key값으로	정렬된 배열과 리스트가 되어있어야 한다.
key와 같거나 큰 수 중 가장 작은 수를 가리키는 iterator를 return 한다.
-------------------------------------
= key값이 없으면 key 값보다 작지 않은 가장 큰 수를 가리키는 iterator를 반환한다.

-> 배열의 가장 큰 값보다 큰 수를 key로 두고 찾으면 vector.size()에 해당하는 iterator를 return 한다. 
같은 원소가 여러개 있어도 상관 없으며, 항상 유일한 해를 구할 수 있다.


결국 while문을 빠져나오면 left == right이고 이 때 가르키는 위치를
key보다 같거나 큰 수 중 가장 작은 수를 가리키도록 정의했으므로,
v[mid]와 key가 같을 때 right를 mid로 줄인다. 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int myupper_bound(int* arr, int n, int key) {
	int left = 0;
	int right = n;
	int mid = n;

	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] < key) { // 중간값 < 찾으려는 값
			left = mid + 1;
		}else{ //찾으려는 값 <= 중간값 
			right = mid;
		}
	}
	//위 while을 나오면 항상 left와 right가 같다. 
	//if (left == right) cout << "same!\n";
	return right;
}



int main(void) {
	//              0,1,2,3,4,5,6,7,8,9
	int arr[10] = { 1,2,4,5,6,6,7,7,7,9 };
	vector<int> v = { 1,2,4,5,6,6,7,7,7,8 };
	cout << v[0] << "\n";
	/*
	vector lower_bound : - v.begin()에 주목

	*/
	for (int i = 0; i <= 20; i++) {
		auto it = lower_bound(v.begin(), v.end(), i);
		if (it != v.end()) {//v.end()와 같은 경우 존재하지 않음.
			cout << "vector lower_bound(" << i << ") : " << it -v.begin() << "\n";
		}
		else {
			cout << "존재하지 않습니다.\n";
		}
	}
	cout << "\n";

	/*
	arr lower_bound : - arr에 주목
	*/
	for (int i = 0; i <= 10; i++) {
		auto it = lower_bound(arr, arr + 10, i);
		if(it != arr+10)	cout << "lower_bound(" << i << ") : " << it - arr << "\n";
		else cout << "존재하지 않습니다.\n";
	}
	cout << "\n";

	for (int i = 0; i <= 20; i++) {
		auto it = myupper_bound(arr, 10, i);
		if (it != 10) cout << "mylower_bound(" << i << ") : " << it << "\n";
		else cout << "존재하지 않습니다.\n";
	}
	cout << "\n";
	return 0;
}