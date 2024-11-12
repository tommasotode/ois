#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string ans;

bool brackets(int A[], int N, string s, int i, int curr)
{
	if (i == N)
	{
		if (curr == 0)
		{
			ans = s;
			return true;
		}
		return false;
	}

	int a = A[i];
	if (a <= curr)
	{
		if (brackets(A, N, s + string(a, ')'), i + 1, curr - a))
			return true;
	}
	if (brackets(A, N, s + string(a, '('), i + 1, curr + a))
		return true;
	return false;
}

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N;
	cin >> N;

	int A[N];
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	if (!brackets(A, N, "", 0, 0))
		cout << "-1" << endl;
	else
		cout << ans << endl;

	return 0;
}