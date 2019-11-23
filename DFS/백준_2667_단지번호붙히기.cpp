/*
2019-11-23

dfs로 돌면서 단지 번호를 붙히고,
전체를 다시 돌면서 각 단지에 속한 집의 숫자를 셈.

*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n = 0;
int map[25][25];
bool visited[25][25];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y, int dnum) {
	visited[x][y] = true;
	map[x][y] = dnum;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= n) continue;
		if (map[nx][ny] && !visited[nx][ny]) {
			dfs(nx, ny, dnum);
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	int dnum = 1; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visited[i][j]) {
				dfs(i, j, dnum++);
			}
		}
	}
	printf("%d\n", dnum - 1);
	vector<int> answer(dnum, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(map[i][j]) answer[map[i][j]] += 1;
		}
	}
	sort(answer.begin(), answer.end());
	for (int i = 1; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}