#include <iostream>
using namespace std;
int line[510][510];
int used[510];
int people[510];
int k, m, n;
bool find(int t)
{
	//男孩t从0~n-1个女孩按序查找第一个自己有意思的女孩
	for (int i = 1; i <= n; ++i)
	{
		//判断男孩t对第i个女孩是否有意思--第二个条件与内部的判断有关
		if ((line[t][i] == 1) && (used[i] == 0))
		{
			//把此时男孩t匹配的女孩置为1
			used[i] = 1;
			//若女孩尚无对象或可以为该女孩的男朋友找到一个新女朋友的话,就将该女孩子的对象变更为新的男孩t
			//女孩原来的男朋友因为从0找到了他现有的女朋友,说明他现在的女朋友之前的女孩因为各种原因无法配对;
			//所以此时不需要对used进行memset重新赋值,从现在的女朋友继续往下查找就可以了;
			//如果找得到返回1,则第i个女孩就可以变更为新的男孩t,若找不到,男孩t继续向下查找
			if ((people[i] == 0) || find(people[i]))
			{
				people[i] = t;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int x, y;
	int sum;
	while (cin >> k >> m >> n)
	{
		if (!k)
		{
			break;
		}
		memset(line, 0, sizeof(line));
		memset(people, 0, sizeof(people));
		for (int i = 0; i < k; ++i)
		{
			cin >> x >> y;
			line[x][y] = 1;
		}
		sum = 0;
		for (int i = 1; i <= m; ++i)
		{
			memset(used, 0, sizeof(used));
			if (find(i))
			{
				++sum;
			}
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}
/*
#include <iostream>
using namespace std;
long long gcd(long a, long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
long long lcm(long a, long b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	long long a, b;
	while (cin >> a >> b)
	{
		long long t;
		t = gcd(a, b);
		cout << t << endl;
		t = lcm(a, b);
		cout << t << endl;
	}
	return 0;
}
*/
