#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main ()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    std::vector<int> B;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int m;
            cin >> m;
            B.push_back(m);
        }
    }

    sort(B.begin(), B.end());

    cout << B[K-1] << endl;
    
}