#include <iostream>
using namespace std;

int main()
{
    int limite = 100000;
    int dp[limite + 1];
    dp[0] = 0;

    for (int i = 1; i <= limite; ++i) 
    {
        dp[i] = 1e9;
    }

    for (int i = 1; i <= limite; ++i) 
    {
        int num = i;
        while (num > 0) 
        {
            int digito = num % 10;
            dp[i] = min(dp[i], 1 + dp[i - digito]);
            num /= 10;
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int ni;
        cin >> ni;
        cout << dp[ni] << " ";
    }
    
    return 0;
}