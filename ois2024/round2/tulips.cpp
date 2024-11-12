#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<long long> T;

// Subtask 1
long long int solve()
{
	if ( K == 1 ) return *min_element(T.begin(), T.end());
	if (K == 2)
	{
		long long curr_min_left = T[0];
		long long curr_min_right = *min_element(T.begin()+1, T.end());
		long long curr_max_sum = curr_min_left + curr_min_right;
		for (int i = 1; i < N; i++)
		{
			curr_min_left = min(curr_min_left, T[i]);
			if (T[i] == curr_min_right)
			{
				if (i+1 < N)
					curr_min_right = *min_element(T.begin()+i+1, T.end());
			}
			curr_max_sum = max(curr_max_sum, curr_min_left + curr_min_right);
		}
		return curr_max_sum;
	}
	return -1;
}


int main()
{
	cin >> N >> K;
	T = vector<long long>(N);
	for (int i = 0; i < N; ++i) cin >> T[i];
	
	long long M = solve(); 
	cout << M << endl;

	return 0;
}
