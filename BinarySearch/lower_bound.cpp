/*
lower_bound : key������	���ĵ� �迭�� ����Ʈ�� �Ǿ��־�� �Ѵ�.
key�� ���ų� ū �� �� ���� ���� ���� ����Ű�� iterator�� return �Ѵ�.
-------------------------------------
= key���� ������ key ������ ���� ���� ���� ū ���� ����Ű�� iterator�� ��ȯ�Ѵ�.

-> �迭�� ���� ū ������ ū ���� key�� �ΰ� ã���� vector.size()�� �ش��ϴ� iterator�� return �Ѵ�. 
���� ���Ұ� ������ �־ ��� ������, �׻� ������ �ظ� ���� �� �ִ�.


�ᱹ while���� ���������� left == right�̰� �� �� ����Ű�� ��ġ��
key���� ���ų� ū �� �� ���� ���� ���� ����Ű���� ���������Ƿ�,
v[mid]�� key�� ���� �� right�� mid�� ���δ�. 
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
		if (arr[mid] < key) { // �߰��� < ã������ ��
			left = mid + 1;
		}else{ //ã������ �� <= �߰��� 
			right = mid;
		}
	}
	//�� while�� ������ �׻� left�� right�� ����. 
	//if (left == right) cout << "same!\n";
	return right;
}



int main(void) {
	//              0,1,2,3,4,5,6,7,8,9
	int arr[10] = { 1,2,4,5,6,6,7,7,7,9 };
	vector<int> v = { 1,2,4,5,6,6,7,7,7,8 };
	cout << v[0] << "\n";
	/*
	vector lower_bound : - v.begin()�� �ָ�

	*/
	for (int i = 0; i <= 20; i++) {
		auto it = lower_bound(v.begin(), v.end(), i);
		if (it != v.end()) {//v.end()�� ���� ��� �������� ����.
			cout << "vector lower_bound(" << i << ") : " << it -v.begin() << "\n";
		}
		else {
			cout << "�������� �ʽ��ϴ�.\n";
		}
	}
	cout << "\n";

	/*
	arr lower_bound : - arr�� �ָ�
	*/
	for (int i = 0; i <= 10; i++) {
		auto it = lower_bound(arr, arr + 10, i);
		if(it != arr+10)	cout << "lower_bound(" << i << ") : " << it - arr << "\n";
		else cout << "�������� �ʽ��ϴ�.\n";
	}
	cout << "\n";

	for (int i = 0; i <= 20; i++) {
		auto it = myupper_bound(arr, 10, i);
		if (it != 10) cout << "mylower_bound(" << i << ") : " << it << "\n";
		else cout << "�������� �ʽ��ϴ�.\n";
	}
	cout << "\n";
	return 0;
}