#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int num = 666;
	int copy;
	int count = 0;
	int prev = 0 , cur = 0, next = 0;
	vector<int> arr;

	cin >> n;

	while (count != 10000)
	{
		copy = num;

		while (copy != 0)
		{
			prev = cur;
			cur = copy % 10;
			next = (copy / 10) % 10;

			copy /= 10;

			if (prev == cur && prev == next && prev == 6) {
				count++;
				arr.push_back(num);
				break;
			}

		}

		num++;
		prev = 0;
		cur = 0;
		next = 0;

	}

	cout << arr[n - 1];
}
