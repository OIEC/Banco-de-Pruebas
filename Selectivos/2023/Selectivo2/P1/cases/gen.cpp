#include<iostream>
#include<random>

using namespace std;

int main()
{

    int primos[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(0, 9);
    
    int iN = distr(generator);
    int iP;
    int iQ;

    while (true)
    {
        iP = distr(generator);
        if (iP != iN) break;
    }

    while (true)
    {
        iQ = distr(generator);
        if (iQ != iN && iQ != iP) break;
    }

    int N = primos[iN];
    int P = primos[iP]; 
    int Q = primos[iQ];
    

    std::vector<int> vec;
    std::uniform_int_distribution<int>  distr2(2, 9999);
    for (int i = 0; i < 15; ++i)
    {
        vec.push_back(distr2(generator));
    }

    cout << N << " " << P << " " << Q << endl;


    for (int i = 0; i < 15; ++i)
    {
        cout << vec[i] << endl;
    }
}