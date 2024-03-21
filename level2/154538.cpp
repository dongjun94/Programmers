// https://school.programmers.co.kr/learn/courses/30/lessons/154538

#include <string>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"

const int MAX_SIZE = 1000001;
int arr[MAX_SIZE] = { 0, };

void push_queue(queue<int> &q, const int &max, const int &next, const int &cur)
{
    if (max < next)
        return;
    if(arr[next] == 0)
    {
        arr[next] = MAX_SIZE;
        q.push(next);
    }
    arr[next] = min(arr[next], arr[cur] + 1);
}

int solution(int x, int y, int n)
{
    if (x == y)
        return 0;

    queue<int> q;
    q.push(x);
    arr[x] = 0;

    while (q.size())
    {
        int temp = q.front();
        q.pop();

        push_queue(q, y, temp + n, temp);
        push_queue(q, y, temp * 2, temp);
        push_queue(q, y, temp * 3, temp);
    }

    return arr[y] == 0 ? -1 : arr[y];
}

int main()
{
    int x = 10, y = 40, n = 5;
    solution(x, y, n);
    return 0;
}