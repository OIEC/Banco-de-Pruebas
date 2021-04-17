#include<iostream>
#include<algorithm>
using namespace std;

int main ()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    int B[N*N];
    int idx = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> B[idx];
            ++idx;
        }
    }

    sort(B, B+(N*N));

    cout << B[K-1] << endl;
    
}