#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		long long N;
		cin >> N;

		long long ans = 0;
		long long nCr = 1;
		for (long long k = 0; k <= N; k++)
		{
			if (k > 0)
				nCr = nCr * (N - k + 1) / k;
			if ((N + k * 4) % 3 == 0)
				ans += nCr;
		}

		cout << ans << endl;
	}

	return 0;
}
