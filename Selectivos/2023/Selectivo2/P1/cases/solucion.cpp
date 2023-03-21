#include<iostream>

using namespace std;

int main()
{
    int N;
    int P;
    int Q;

    cin >> N;
    cin >> P;
    cin >> Q;

    int count = 0;

    for (int i = 0; i < 15; ++i)
    {
        int num;
        cin >> num;
        if ((num % N == 0) && (num % P != 0) && (num % Q != 0))
        {
            ++count;
        }
    }
    cout << count;
}