#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    cout << N << endl;
    cout << K << endl;

    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(0,N-1);

    //unsigned long long A[N][N];
    vector<vector<unsigned long long>> A;
    A.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        A[i].reserve(N);
    }

    // firstRow
    for (int j = 0; j < N; ++j)
    {
        A[0][j] = j+1;
    }

    for (int i = 1; i < N; ++i)
    {
        int idxCut = distribution(generator);
        //cout << "idxCut = " << idxCut << endl;

        // copy that idx as first element.
        A[i][0] = A[i-1][idxCut];

        // increment from there
        for (int j = 1; j < N; ++j)
        {
            A[i][j] = A[i][j-1] + 1;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}