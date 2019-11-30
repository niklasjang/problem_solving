/*
LCS : Longest Common Sequence
https://niklasjang.github.io/algorithm/Longest-Common-Subsequence/
�κ� ���� : �־��� �������� 0�� �̻��� ���ڸ� ������ ���� �� �ִ� ����
���� �κ� ���� : �� ������ �־����� �� ���� �� �ִ� ����� �κ� ����

Ǯ�� 1 ����Ž��:
�κм����� �� ���ڰ� ���Եǰų� �ȵǱ� ������ 2^N���� �κ� ������ �����Ѵ�. �̰͵��� ��� �Ǵ��غ��� ��Ž�� �����ϴ�.

Ǯ�� 2 DP :
���� �� ���ڿ��� ���̰� 1�̶��, �� ���ڰ� ���� �� LCS�� ���̴� 1�̰� �� ���ڰ� �ٸ� �� 0�̴�.
�� ���ڿ��� ���̰� 1 �̻��� ���� �������� �������� ���ڿ� ���� LCS�� ����� �޶�����. 
A ���ڿ����� i ��°���� B ���ڿ����� j���� ���ؼ� ������� ���� LCS���� 
���� i+1�� j+1��°�� ���ڸ� ���� �� �� �� ���ڰ� ������ LCS�� +1�ǰ� �ƴ϶�� �״�� ���´�.

���ڿ� A[0,i] B[0,j]�� ���ؼ� LCS�� ���̸� LCS ������ �־���� ��
1. A[0,i+1] B[0,j+1]������ LCS = A[i+1]�� B[j+1]�� ���� �� LCS+1
2. 1.���� �����ϸ� A[0,i+1] B[0,j]������ LCS, A[0,i] B[0,j+1]������ LCS �� ū ���� ���´�. 

�Ѱ�:
������ ��ġ���� ���� ���ڿ��� ����� �κ� �����̾ƴ϶�,
���ӵ� ���� ���ڿ��� �ִ� ���̸� ���ϴ� ������ �� �ڵ�� Ǯ �� ����. 
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
option : -1 r==0 || c == 0
option : 0 �������� �߰��� ���ڿ��� ���Ƽ�       : ���� �밢������ �ö󰣴�.
option : 1 [r-1][c]�� [r][c-1] �� ���ڰ� �� Ŀ�� : ���� �ö󰣴�.
option : 2 [r-1][c]�� [r][c-1] �� ���ڰ� �� Ŀ�� : �������� ����.
*/
pair<int, int> table[1010][1010]; //<[r][c]������ ����, ������ LCS�� ��� ���������� option>

void LCS(const string& A, const string& B) {
	for (int r = 0; r <= A.size(); r++) {
		for (int c = 0; c <= B.size(); c++) {
			if (r == 0 || c == 0) {
				table[r][c] = make_pair(0, -1);
				continue;
			}
			if (A[r - 1] == B[c - 1]) {
				table[r][c] = make_pair(table[r - 1][c - 1].first+1, 0);
			}
			else if (table[r - 1][c] < table[r][c - 1]) {
				table[r][c] = make_pair(table[r][c - 1].first, 2);
			}
			else {
				table[r][c] = make_pair(table[r - 1][c].first, 1);
			}
		}
	}
	return;
}

int main(void) {
	string A, B;
	cin >> A >> B;
	string lcs = "";
	LCS(A, B);

	//for (int r = 1; r <= A.size(); r++) {
	//	for (int c = 1; c <= B.size(); c++) {
	//		cout << table[r][c].first<<","<< table[r][c].second << " ";
	//	}
	//	cout << "\n";
	//}

	int nr = A.size();
	int nc = B.size();
	stack<char> s;
	while (table[nr][nc].second != -1) {
		if (table[nr][nc].second == 0) s.push(A[nr-1]);
		switch (table[nr][nc].second) {
		case 0:
			nr -= 1;
			nc -= 1;
			break;
		case 1:
			nr -= 1;
			break;
		case 2:
			nc -= 1;
			break;
		default:
			cout << "End\n";
		}
	}
	while (!s.empty()) {
		lcs += s.top();
		s.pop();
	}

	//lcs�� ����
	cout << lcs.size() << "\n";
	//lcs
	cout << lcs << "\n";
	return 0;
}