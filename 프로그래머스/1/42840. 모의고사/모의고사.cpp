#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> person1(answers.size());
	vector<int> person2(answers.size());
	vector<int> person3(answers.size());

	for (int i = 0; i < person1.size(); i++) {
		person1[i] = (i % 5) + 1;
	}

	for (int i = 0; i < person2.size(); i++) {
		if (i % 2 == 0) {
			person2[i] = 2;
		}
		else if (i % 8 == 1) {
			person2[i] = 1;
		}
		else if (i % 8 == 3) {
			person2[i] = 3;
		}
		else if (i % 8 == 5) {
			person2[i] = 4;
		} 
		else if (i % 8 == 7) { 
			person2[i] = 5;
		}
	}

	for (int i = 0; i < person3.size(); i+=2) {
		if (i % 10 == 0) {
			person3[i + 1] = person3[i] = 3;
		}
		else if(i % 10 == 2) {
			person3[i + 1] = person3[i] = 1;
		}
		else if (i % 10 == 4) {
			person3[i + 1] = person3[i] = 2;
		}
		else if (i % 10 == 6) {
			person3[i + 1] = person3[i] = 4;
		}
		else if (i % 10 == 8) {
			person3[i + 1] = person3[i] = 5;
		}
	}
	
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == person1[i]) {
			count1++;
		} 
		if (answers[i] == person2[i]) {
			count2++;
		}
		if (answers[i] == person3[i]) {
			count3++;
		}
	}

	int maxscore = max({ count1, count2, count3 });

	if (count1 == maxscore) answer.push_back(1);
	if (count2 == maxscore) answer.push_back(2);
	if (count3 == maxscore) answer.push_back(3);
	sort(answer.begin(), answer.end());

	return answer;
}