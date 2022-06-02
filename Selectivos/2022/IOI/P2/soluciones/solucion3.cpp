#include <iostream>
using namespace std;

vector<vector<int>>v;
vector<int>v1;

void printPascal(int n)
{
	for (int line = 1; line <= n; line++)
	{
		long long C = 1;

		for (int i = 1; i <= line; i++)
		{

            v1.push_back(C);
			C = C * (line - i) / i;
		}

        v.push_back(v1);
        v1.clear();
	}
}

int main()
{
	int n;
	cin >> n;
	printPascal(n);
    for(int i=0; i<v[n-1].size(); i++)
    {
        cout << v[n-1][i] << ' ';
    }
	return 0;
}