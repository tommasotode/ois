#include <bits/stdc++.h>
using namespace std;

int main()
{
	uint64_t N, K;
	cin >> N >> K;
	vector<uint64_t> P(N);
	for (int i = 0; i < N; ++i) cin >> P[i];

	uint64_t sum = 0;
	uint64_t prod = N * K;
	for (int i = 0; i < N; i++) sum += P[i];

	uint64_t r = 1;
	if (sum < prod) cout << r << endl;
	else if (sum > prod)
	{
		sort(P.rbegin(), P.rend());
		for (int i = 0; i < N; i++)
		{
			sum -= (P[i] - 1);
			if (sum <= prod)
			{
				cout << r << endl;
				break;
			}
			r++;
		}
	}
	else cout << 0 << endl;

	return 0;
}