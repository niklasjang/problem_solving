/*
dfs는 백준_2667_단지번호붙히기에서 했던 그대로라서 금방짰는데, 
수학에서의 (0,0)을 기준으로 주어진 좌표를
2차원 배열의 (0,0)을 기준의 좌표로 바꾸는 것이 한참 걸렸다.

결과부터 이야기 하면 (x,y) -> (row갯수 - y, x)이다.
그리고 변환된 두 좌표의 두 x/y좌표의 값을 비교해서 작은 수부터 loop을 돌려야 한다.

(x,y) -> (row갯수 - y, x)
0. 변환 전의 격자평면의 각 사각형의 좌표는 왼쪽 하단의 값을 사용한다고 생각한다.
0. 변환 후의 격자평면의 각 사각형의 좌표는 왼쪽  상단의 값을 사용한다고 생각한다.
1. 변환 전의 x는 변환후의 column을 의미한다.
2. 변환 전의 y는 전체 row 갯수에서 - y된 것을 의미한다. 

너무 어렵게 생각하지말고, 숫자 대입해보고 규칙을 찾으려고 하지말고, x/y축의 개념을 생각해서 멀리로 규칙을 도출해내자.
외울게 아니라 생각하는 방법을 한 번 해봤으니 다음에는 빨리 하겠지.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[100][100] = { 0, };
bool visited[100][100] = { false, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m = 0, n = 0, k = 0;
int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
int dfs(int x, int y) {
	int ans = 1;
	visited[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= m) continue;
		if (ny < 0 || ny >= n) continue;
		if (!map[nx][ny] && !visited[nx][ny]) {
			ans += dfs(nx, ny);
		}
	}
	return ans;
}

int main(void) {
	cin >> m >> n >> k;

	vector<int> ans;
	for (int i = 0; i < k; i++) {
		cin >> a1 >> b1 >> a2 >> b2;
		int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
		r1 = m - b1; c1 = a1, r2 = m - b2, c2 = a2;
		if (r1 > r2) swap(r1, r2);
		if (c1 > c2) swap(c1, c2);
		for (int r = r1; r < r2; r++) {
			for (int c = c1; c < c2; c++) {
				map[r][c] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j] && !visited[i][j])
				ans.push_back(dfs(i, j));
		}
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}