#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N;
	cin >> N;

	vector<long long> S(N);
	for (int i = 0; i < N; ++i) cin >> S[i];

	sort(S.rbegin(), S.rend());
	vector<long long> p;
	for (int i = 0; i < N-1; i++)
	{
		if (S[i+1] == S[i])
		{
			if (p.size() == 1)
			{
				cout << p[0] * S[i];
				return 0;
			}

			if (p.size() == 0)
			{
				p.push_back(S[i]);
				i++;
			}
		}
	}

	cout << 0 << endl;
	return 0;
}
