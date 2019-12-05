#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::cout;
using std::vector;

#define MAX 10001
void sum_func_name(const vector<int>::iterator& start, const vector<int>::iterator& end, int* subSetSum) {
	vector<int>::iterator curr = start;
	int result = 0;
	for (curr = start; curr < end; curr++) {
		 result+= *curr;
	}
	*subSetSum = result;
	thread::id thread_id = std::this_thread::get_id();
	printf("%d\n", *subSetSum);
	printf("%x end. from %d to %d : subSetSum is %d\n", thread_id, *start, *(end-1), *subSetSum);
	return;
}

int main(void) {
	vector<int> numbers(MAX,0);
	int subSetSum[4] = { 0,0,0,0 };
	for (int i = 0; i < MAX; i++) {
		numbers[i] = i;
	}
	vector<thread> workers;
	for (int i = 0; i < 4; i++) {
		workers.push_back(thread(sum_func_name, 
			numbers.begin() + i * (MAX/4), 
			numbers.begin() + (i + 1) * MAX/4, 
			&subSetSum[i]));
	}	

	for (int i = 0; i < 4; i++) {
		workers[i].join();
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += subSetSum[i];
	}
	cout << ans << "\n";

	return 0;
}