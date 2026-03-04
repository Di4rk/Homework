#include <bits/stdc++.h>
using namespace std;

vector<string> rotate(const vector<string>& mat, int n) 
{
    vector<string> newMat(n, string(n, ' '));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            newMat[j][n - 1 - i] = mat[i][j];
        }
    }
    return newMat;
}
int countAppearances(const vector<string>& big, const vector<string>& small, int N, int n) 
{
    int count = 0;
    for (int i = 0; i <= N - n; ++i) 
    {
        for (int j = 0; j <= N - n; ++j) 
        {
            bool match = true;
            for (int r = 0; r < n; ++r) 
            {
                for (int c = 0; c < n; ++c) 
                {
                    if (big[i + r][j + c] != small[r][c]) 
                    {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                count++;
            }
        }
    }
    return count;
}
int main() 
{
    int N, n;
    while (cin >> N >> n && (N != 0 || n != 0)) 
    {
        vector<string> big(N);
        vector<string> small(n);
        for (int i = 0; i < N; ++i) cin >> big[i];        
        for (int i = 0; i < n; ++i) cin >> small[i];
        for (int k = 0; k < 4; ++k) 
        {
            cout << countAppearances(big, small, N, n);            
            if (k < 3) 
            {
                cout << " ";
                small = rotate(small, n);
            }
        }
        cout << endl;
    }
    return 0;
}