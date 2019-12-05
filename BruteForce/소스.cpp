#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> v;
int n = 0;

//출력
void printVector(void) {
	for (int i = 0; i < n; i++) 
		cout << v[i] << "\n";
}
//버블정렬
void bubbleSort(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i] < v[j]) {
				swap(v[i], v[j]);
			}
		}
	}
}

/**/
void quickSort(int low, int high) {
	if (low >= high) return;
	int pivot = low;
	int left = low + 1;
	int right = high;
	while (left <= right) { // =는 {2,1}이 들어와서 left == right일 때 커버해야함
		while (left <= high && v[pivot] >= v[left]) left++;
		while (low < right && v[pivot] <= v[right]) right--;
		if (left <= right) {
			swap(v[left], v[right]);
		}
		else if (left > right) {
			swap(v[pivot], v[right]);
		}
	}
	quickSort(low, right - 1);
	quickSort(right + 1, high);
}

// 삽입 정렬
void insertSort(void) {
	int comp = 0;
	for (int move = 1; move < n; move++) {
		int curr = v[move];
		for (comp = move - 1; comp >= 0; comp--) {
			if (v[comp] < curr) break;
			v[comp + 1] = v[comp];
		}
		v[comp + 1] = curr;
	}
}


int main(void) {
	scanf("%d", &n);
	v.assign(n, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	
	//버블정렬
	//bubbleSort(); printVector();
	
	//삽입정렬
	//insertSort(); printVector();

	//퀵소트
	quickSort(0, n - 1); printVector();
	return 0;
}