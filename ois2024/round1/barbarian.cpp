#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream cin("input.txt");
	// ofstream cout("output.txt");

	int N;
	cin >> N;

	vector<long long> D(N);
	for (int i = 0; i < N; i++)
		cin >> D[i];

	// INSERT YOUR CODE HERE
	for (int i = 0; i < N; i++)
	{
		bool visited[N] = {};
		int curr = i;
		while (true)
		{
			visited[curr] = true;

			int left = curr - 1;
			for (; left >= 0; left--)
			{
				if (!visited[left])
					break;
			}

			int right = curr + 1;
			for (; right < N; right++)
			{
				if (!visited[right])
					break;
			}

			if (left == -1)
			{
				if (right == N)
					break;
				curr = right;
			}
			else
			{
				if (right == N)
				{
					curr = left;
					continue;
				}
				curr = abs(D[left] - D[curr]) <= abs(D[right] - D[curr]) ? left : right;
			}
		}
		cout << curr << ' ';
	}
	cout << endl;

	return 0;
}
