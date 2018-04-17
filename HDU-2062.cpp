#include <iostream>
using namespace std;
int main()
{
	int n;
	int s[30];
	long long m;
	long long g[30];
	memset(g , 0 , sizeof(g));
	for (int i = 0; i < 21; ++i)
	{
		g[i] = g[i - 1] * (i - 1) + 1;
	}
	while (cin >> n >> m)
	{
		for (int i = 0; i < 30; ++i)
		{
			s[i] = i;
		}
		while (n > 0 && m > 0)
		{
			int t = m / g[n] + (m%g[n] > 0 ? 1 : 0);
			cout << s[t];
			for (int i = t; i < n; ++i)
			{
				s[i] = s[i + 1];
			}
			m = m - (t - 1) * g[n] - 1;
			if(!m)
			{
				cout<<endl;
			}
			else
			{
				cout<<" ";
			}
			--n;
		}
	}
	system("pause");
	return 0;
}
/*
+的优先级比:高
1. t = 100+(m % g[n] > 0 ? 1 : 0);
2. t = 100+m % g[n] > 0 ? 1 : 0;
3. t = 100+(m % g[n] > 0) ? 1 : 0;
若没有前面的100.则1 = 2 = 3
但存在100,2 = 3.
2和3的取值只能为0/1,而1可以为100/101
https://blog.csdn.net/lianqi15571/article/details/8877014
*/