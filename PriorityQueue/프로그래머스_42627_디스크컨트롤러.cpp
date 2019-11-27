/*
1. �� ���� Shortest Job First�� ���� �˾Ҵµ�,
�ҿ�ð����θ� �����ؼ� ������� ó���ϸ� [[0,5],[6,1]]�� ���� ��츦 Ŀ������ ���Ѵ�.
2. �ذ����� ������ �ð����� ��û�� �۾��� ��� priority queue�� �ְ�
�� �߿��� ���� �ҿ� �ð��� ª�� ���� �ϳ� �����Ѵ�.
3. �׸��� ���ο� �ð����� �߰������� ��û�� ���� ������ �ٽ� pq�� �ְ� top()�� �ִ� ���� �����Ѵ�.
4. ��� job�� pq�� �־����� �׶����ʹ� pq�� ���ؼ� ���ĵǴ� top�� pq�� �������� �����ϸ� �ȴ�.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int time = 0, idx = 0;
	vector<pair<int, int> > v;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	//1. ��û�� �ð���� �����ϱ� ���ؼ� vector�� �ִ´�.
	for (int i = 0; i < jobs.size(); i++) {
		v.push_back(make_pair(jobs[i][0], jobs[i][1])); //���⼭ [i][j]�� ������ �ȵȴ�. [0][1]�ֱ�
	}
	sort(v.begin(), v.end());
	
	while (idx < v.size()) {
		//2. ����ð����� ��û�� �͵��� pq�� �ִ´�.
		while (idx < v.size() && v[idx].first <= time) {
			pq.push(make_pair(v[idx].second, v[idx].first));
			++idx;
		}
		//3. pq���� top�� �ִ� ���� �ϳ� �����Ѵ�.
		if (pq.empty()) {
			time++;
		}else {
			time += pq.top().first;
			answer += (time - pq.top().second);
			pq.pop();
		}
	}
	//job�� ��� pq�� �־����� �ϳ��� �����Ѵ�. 
	while(!pq.empty()) {
		time += pq.top().first;
		answer += (time - pq.top().second);
		pq.pop();
	}
	return answer / jobs.size();
}