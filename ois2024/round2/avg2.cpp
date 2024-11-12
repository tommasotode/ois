#include <bits/stdc++.h>
using namespace std;

int main()
{
	uint64_t N, K;
	cin >> N >> K;
	vector<uint64_t> P(N);
	for (int i = 0; i < N; ++i) cin >> P[i];

	uint64_t media = N * K, somma = 0, C = 0;
	for (int i = 0; i < N; i++) somma += P[i];
	if (somma < media)
	{
		C = (uint64_t)ceil( (double)(media - somma) / (double)N );
	}
	
	while (somma > media)
	{
		for (int i = 0; i < N; i++)
		{
			if (somma == media) break;
			if (P[i] > 1)
			{
				P[i]--;
				somma--;
			}
		}
		C++;
	}
	
	cout << C << endl;

	return 0;
}