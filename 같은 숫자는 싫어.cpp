#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr = { 1, 1, 3, 3, 0, 1, 1 };
	vector<int> answer;

	int saveNum = INT_MAX;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != saveNum)
		{
			saveNum = arr[i];
			answer.push_back(arr[i]);
		}
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i];
	}
}