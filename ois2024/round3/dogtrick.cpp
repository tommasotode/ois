#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N, K;
	cin >> N >> K;
	vector<int> T(N);
	for (int i = 0; i < N; ++i) cin >> T[i];
	int M;
	cin >> M;
	vector<int> A(M), B(M);
	for (int i = 0; i < M; ++i) cin >> A[i] >> B[i];

	int P = 0;
	for (int i = 0; i < N; i++)
	{
		if (T[i] == 1)
		{
			P++;
			continue;
		}

		if (i > 0 && T[i - 1] == 2)
		{
			cout << '0' << endl;
			return 0;
		}
	}
	cout << P << endl;
	return 0;
}
