#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		int A, B;
		cin >> A >> B;

		vector<pair<int, int>> matches(5);
		int match_count = 3;

		if (B > 52)
		{
			cout << -1 << "" << -1 << endl;
			return 0;
		}

		matches[0].first = 11;
		matches[1].first = 11;
		matches[2].first = 11;

		for (int i = 0; i < 3; i++)
		{
			int remaining = min(B, 10);
			B = max(B - remaining, 0);
			matches[i].second = remaining;
		}

		for (int i = 0; i < match_count; i++)
			cout << matches[i].first << " " << matches[i].second << endl;
	}

	return 0;
}