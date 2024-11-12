#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	string S;
	cin >> S;
	int N;
	cin >> N;

	vector<string> U(N);
	for (int i = 0; i < N; ++i) cin >> U[i];

	bool presente = false;
	vector<string> giusti;
	for (int i = 0; i < N; i++)
	{
		if (U[i] == S) presente = true;

		if (U[i].find(S) != string::npos)
			giusti.push_back(U[i]);
	}

	if (!presente)
	{
		cout << S << endl;
		return 0;
	}

	sort(giusti.begin(), giusti.end(), [&](string a, string b) {
		if (a.length() != b.length()) return a.length() < b.length();
		return a < b;
	});

	int massimo = 1;
	string S_old = S;
	for (int i = 0; i < giusti.size(); i++)
	{
		if (S == giusti[i])
		{
			S = S_old + to_string(massimo);
			massimo++;
		}
	}

	cout << S << endl;

	return 0;
}
