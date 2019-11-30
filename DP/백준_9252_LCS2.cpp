/*
LCS : Longest Common Sequence
https://niklasjang.github.io/algorithm/Longest-Common-Subsequence/
부분 서열 : 주어진 서열에서 0개 이상의 문자를 지워서 만들 수 있는 서열
공통 부분 서열 : 두 서열이 주어졌을 때 만들 수 있는 공통된 부분 서열

풀이 1 완전탐색:
부분서열은 각 문자가 포함되거나 안되기 때문에 2^N개의 부분 서열이 존재한다. 이것들을 모두 판단해보면 완탐이 가능하다.

풀이 2 DP :
만약 두 문자열의 길이가 1이라면, 두 문자가 같을 때 LCS의 길이는 1이고 두 문자가 다를 때 0이다.
두 문자열의 길이가 1 이상일 때는 마지막에 덧붙히는 문자에 따라서 LCS의 결과가 달라진다. 
A 문자열에서 i 번째까지 B 문자열에서 j까지 비교해서 현재까지 얻은 LCS에서 
각각 i+1와 j+1번째의 문자를 붙힐 때 이 두 문자가 같으면 LCS가 +1되고 아니라면 그대로 남는다.

문자열 A[0,i] B[0,j]에 대해서 LCS의 길이를 LCS 변수에 넣어놨을 때
1. A[0,i+1] B[0,j+1]까지의 LCS = A[i+1]와 B[j+1]가 같을 때 LCS+1
2. 1.번이 실패하면 A[0,i+1] B[0,j]까지의 LCS, A[0,i] B[0,j+1]까지의 LCS 중 큰 값을 적는다. 

한계:
임의의 위치에서 지운 문자열의 결과인 부분 수열이아니라,
연속된 공통 문자열의 최대 길이를 구하는 문제는 본 코드로 풀 수 업다. 
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
option : -1 r==0 || c == 0
option : 0 마지막에 추가된 문자열이 같아서       : 왼쪽 대각선으로 올라간다.
option : 1 [r-1][c]와 [r][c-1] 중 전자가 더 커서 : 위로 올라간다.
option : 2 [r-1][c]와 [r][c-1] 중 후자가 더 커서 : 왼쪽으로 간다.
*/
pair<int, int> table[1010][1010]; //<[r][c]까지의 길이, 현재의 LCS가 어떻게 구해졌는지 option>

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

	//lcs의 길이
	cout << lcs.size() << "\n";
	//lcs
	cout << lcs << "\n";
	return 0;
}