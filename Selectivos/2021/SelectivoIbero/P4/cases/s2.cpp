#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct IdxValue
{
    int row;
    int col; 
    int val;

    IdxValue(int i,int j,int value)
    {
        row = i;
        col = j;
        val = value;
    }
};

/*
bool CompareIdxValues(const IdxValue& lhs, const IdxValue& rhs)
{  
    return rhs.val < lhs.val;
}
*/

struct compare 
{ 
    bool operator()(IdxValue const& p1, IdxValue const& p2) 
    { 
        return p1.val > p2.val; 
    } 
};

int main ()
{
    int N;
    int K;
    cin >> N;
    cin >> K;

    int A[N][N];
    bool IsInQueue[N][N];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
            IsInQueue[i][j] = false;
        }
    }

    //auto compare = [](const IdxValue& lhs, const IdxValue& rhs){return rhs.val < lhs.val;};
    priority_queue<IdxValue, std::vector<IdxValue>, compare> q;
    IdxValue v = IdxValue(0, 0, A[0][0]);
    q.push(v);
    IsInQueue[0][0] = true;

    for (int i = 0; i < K-1; ++i)
    {
        /*
        auto pq = q;
        cout << "QUEUE STATE" << endl;
        while(!pq.empty()) 
        {
            std::cout << pq.top().row << "," << pq.top().col << "," << pq.top().val << endl;
            pq.pop();
        } */

        IdxValue val = q.top();
        q.pop();

        if (val.row + 1 <= N-1 && !IsInQueue[val.row+1][val.col])
        {
            v = IdxValue(val.row+1, val.col, A[val.row+1][val.col]);
            q.push(v);
            IsInQueue[val.row+1][val.col] = true;
        }
        
        if (val.col + 1 <= N-1 && !IsInQueue[val.row][val.col+1])
        {
            v = IdxValue(val.row, val.col+1, A[val.row][val.col+1]);
            q.push(v);
            IsInQueue[val.row][val.col+1] = true;
        }
    }

    /*
    auto pq = q;
    cout << "QUEUE STATE AT THE END" << endl;
    while(!pq.empty()) 
    {
        std::cout << pq.top().row << "," << pq.top().col << "," << pq.top().val << endl;
        pq.pop();
    } */

    cout << q.top().val << endl;
}