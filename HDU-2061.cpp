#include <iostream>
#include <iomanip>
using namespace std;
struct Student
{
	int num;
	char s[30];
	double Ccredit;
	double Grade;
};
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int flag = 0;
		double c = 0, g = 0;
		Student ss;
		cin >> ss.num;
		while (ss.num--)
		{
			memset(ss.s, 0, sizeof(ss.s));
			cin >> ss.s >> ss.Ccredit >> ss.Grade;
			if (ss.Grade < 60)
			{
				flag = 1;
			}
			c += ss.Ccredit;
			g += ss.Ccredit*ss.Grade;
		}
		if (!flag)
		{
			cout << setiosflags(ios::fixed) << setprecision(2) << g / c << endl;
		}
		else
		{
			cout << "Sorry!" << endl;
		}
		if (n != 0)
		{
			cout << endl;
		}	
	}
	system("pause");
	return 0;
}
