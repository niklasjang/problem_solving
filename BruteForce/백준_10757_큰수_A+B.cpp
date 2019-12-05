#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string a, b;
	string ans = "";
	cin >> a >> b;
	int carry = 0;
	int big = a.size(), small = b.size();
	if (big < small) {
		int t = big;
		big = small;
		small = t;
		string temp = b;
		b = a;
		a = temp;
	}
	int carr = 0, sum=0;
	for (int i = 0; i < big; i++) {
		if (i < small) {
			sum = a[big - i - 1] - '0' + b[small - i - 1] - '0' + carry;
		}
		else {
			sum = a[big - i - 1] - '0' + carry;
		}
		if (sum < 10) {
			ans =  to_string((sum)) + ans;
			carry = 0;
		}
		else {
			ans = to_string((sum - 10)) + ans;
			carry = 1;
		}
	}
	if (carry) ans = "1" + ans;
	cout << ans << "\n";
	return 0;
}