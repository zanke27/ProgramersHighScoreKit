#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int answer = 0;

int DFS(vector<int> &numbers, int depth, int &target, int sumNum, int plusMinus)
{
	// numbers에서 depth를 인덱스로 가져오기
	// 가져온 숫자 * plusMinus해서 sum해줘
	// DFS추가 실행 

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

	// 숫자를 받고 / depth도 추가해서 숫자 위치 받아줘 / target넘버도 넘겨주고 / 지금까지 추가한 값 넘겨줘 / +연산할지 -연산할지 넘겨
}