#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	// 배열 A, B 오름차순 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int accumulate = 0;
	for (int i = 0; i < A.size(); i++)
	{
		int Temp = 0;
		Temp = A[i] * B[B.size() - 1 - i];
		accumulate += Temp;
	}

	return accumulate;
}