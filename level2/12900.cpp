// https://school.programmers.co.kr/learn/courses/30/lessons/12900
#include <string>
#include <vector>

using namespace std;
#define endl "\n"

int arr[600001] = { 0, };

int solution(int n) {
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;
    return arr[n];
}

int main()
{
    solution(4);
    return 0;
}