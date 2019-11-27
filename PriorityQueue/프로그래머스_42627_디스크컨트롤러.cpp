/*
1. 딱 보고 Shortest Job First인 것은 알았는데,
소요시간으로만 정렬해서 순서대로 처리하면 [[0,5],[6,1]]와 같은 경우를 커버하지 못한다.
2. 해결방법은 현재의 시간까지 요청된 작업을 모두 priority queue에 넣고
이 중에서 가장 소요 시간이 짧은 것을 하나 실행한다.
3. 그리고 새로운 시간까지 추가적으로 요청된 것이 있으면 다시 pq에 넣고 top()에 있는 것을 실행한다.
4. 모든 job을 pq에 넣었으면 그때부터는 pq에 의해서 정렬되는 top을 pq가 빌때까지 수행하면 된다.
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
	//1. 요청된 시간대로 정렬하기 위해서 vector에 넣는다.
	for (int i = 0; i < jobs.size(); i++) {
		v.push_back(make_pair(jobs[i][0], jobs[i][1])); //여기서 [i][j]를 넣으면 안된다. [0][1]넣기
	}
	sort(v.begin(), v.end());
	
	while (idx < v.size()) {
		//2. 현재시간까지 요청된 것들을 pq에 넣는다.
		while (idx < v.size() && v[idx].first <= time) {
			pq.push(make_pair(v[idx].second, v[idx].first));
			++idx;
		}
		//3. pq에서 top에 있는 것을 하나 실행한다.
		if (pq.empty()) {
			time++;
		}else {
			time += pq.top().first;
			answer += (time - pq.top().second);
			pq.pop();
		}
	}
	//job을 모두 pq에 넣었으면 하나씩 실행한다. 
	while(!pq.empty()) {
		time += pq.top().first;
		answer += (time - pq.top().second);
		pq.pop();
	}
	return answer / jobs.size();
}