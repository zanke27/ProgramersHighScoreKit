#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	vector<int> priorities = { 2,1,3,2 };
	int location, maxNum, answer;
	location = maxNum = answer = 0;

	queue<int> q;

	for (int i = 0; i < priorities.size(); i++)
		q.push(priorities[i]);

	while (true)
	{
		maxNum = q.front();
		for (int i = 0; i < q.size(); i++)
		{
			if (q.front() > maxNum) maxNum = q.front();

			q.push(q.front());
			q.pop();
		}

		if (q.front() == maxNum)
		{
			if (location == 0)
				break;

			q.pop();
			location--;
			answer++;
		}
		else if (q.front() < maxNum)
		{
			q.push(q.front());
			q.pop();
			location--;
			if (location < 0) location = q.size() - 1;
		}
	}

	answer++;

	cout << answer;

	/*
	int result = 0;

	for (int i = 0; i < priorities.size(); i++)
	{
		if (priorities[i] > priorities[location]) result++;
		if (i > location && priorities[i] == priorities[location]) result++;
	}

	result++;

	cout << result;
	*/
}