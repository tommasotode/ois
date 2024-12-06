#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ifstream cin("input2.txt");
    // ofstream cout("output.txt");

    long long N;
    cin >> N;
    
    vector<long long> S(N);
    for (long long i = 0; i < N; ++i)
        cin >> S[i];
    
    sort(S.begin(), S.end());

    long long temp_sum = 0;
    bool ans = false;

    long long good_index = 0;

    for(long long i = N-4; i >= 0; i--)
    {
        for(long long j = i; j < i+3; j++)
        {
            temp_sum+=S[j]; 
        }
        ans = (S[i+3] < temp_sum);
        if(ans)
        {
            good_index = i;
            break;
        }
        temp_sum = 0;
    }

    if(ans)
    {
        for (long long i = good_index; i < good_index + 4; i++)
            cout << S[i] << " ";
    } 
    else 
        cout << -1 << endl;

    return 0;
}
