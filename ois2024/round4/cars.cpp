#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N;
	cin >> N;

	vector<int> P(N);
	for (int i = 0; i < N; ++i)
		cin >> P[i];

	int inizio = P[0];
	int K = 0;

	vector<int> fine(P.end() - (inizio - 1), P.end());
	vector<int> iniz(P.begin(), P.end() - (inizio - 1));

	fine.insert(fine.end(), iniz.begin(), iniz.end());

	if (is_sorted(fine.begin(), fine.end()))
		K = inizio - 1;

	else
		K = -1;

	cout << K << endl;

	return 0;
}
