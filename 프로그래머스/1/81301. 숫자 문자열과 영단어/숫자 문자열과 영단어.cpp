# include<iostream>
# include<map>
# include<string>

using namespace std;

int solution(string s) {

	map<string, char> number;
	number.insert({ "zero", '0' });
	number.insert({ "one", '1'});
	number.insert({ "two", '2'});
	number.insert({ "three", '3' });
	number.insert({ "four", '4' });
	number.insert({ "five", '5' });
	number.insert({ "six", '6'});
	number.insert({ "seven", '7' });
	number.insert({ "eight", '8' });
	number.insert({ "nine", '9' });

	for (const auto& pair : number) {

		size_t pos;
		while ((pos = s.find(pair.first)) != string::npos) {
			s.replace(pos, pair.first.size(),1, pair.second);
		}
	}

	int answer = stoi(s);
	
	return answer;
}