#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
	int bracket = 0;

	for (char k : s)
	{
		if (k == '(')
		{
			bracket++;
		}
		else
		{
			bracket--;
		}

		if (bracket < 0)
		{
			return false;
		}
	}

	if (bracket == 0)
	{
		return true;
	}
	else return false;
}