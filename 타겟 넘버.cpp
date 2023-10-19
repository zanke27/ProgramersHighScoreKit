#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int answer = 0;

int DFS(vector<int> &numbers, int depth, int &target, int sumNum, int plusMinus)
{
	// numbers���� depth�� �ε����� ��������
	// ������ ���� * plusMinus�ؼ� sum����
	// DFS�߰� ���� 

	sumNum += numbers[depth++] * plusMinus;

	if (numbers.size() != depth)
	{
		DFS(numbers, depth, target, sumNum, 1);
		DFS(numbers, depth, target, sumNum, -1);
	}
	else
	{
		if (sumNum == target)
			return answer++;
		else
			return 0;
	}
}

int main(void)
{
	vector<int> numbers = { 1,1,1,1,1 };
	int target;

	DFS(numbers, 0, 3, 0, 1); 
	DFS(numbers, 0, 3, 0, -1);

	cout << answer;

	// ���ڸ� �ް� / depth�� �߰��ؼ� ���� ��ġ �޾��� / target�ѹ��� �Ѱ��ְ� / ���ݱ��� �߰��� �� �Ѱ��� / +�������� -�������� �Ѱ�
}