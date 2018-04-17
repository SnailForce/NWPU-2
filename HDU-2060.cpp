#include <iostream>
using namespace std;
int main()
{
	int n;
	int t[] = { 0,7,13,18,22,25,27 };
	cin >> n;
	while (n--)
	{
		int num, s1, s2;
		int res = 0;
		cin >> num >> s1 >> s2;
		if (num >= 6)
		{
			res = (num - 6) * 8 + 27;
		}
		else
		{
			res = t[num];
		}
		s1 += res;
		if (s1 >= s2)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	system("pause");
	return 0;
}
// 提交代码一定要看清楚YES还是Yes-.-