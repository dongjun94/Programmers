// https://school.programmers.co.kr/learn/courses/30/lessons/131704
#include <string>
#include <vector>
#include <stack>

using namespace std;
#define endl "\n"

int solution(vector<int> order) {
    stack<int> stk;
    int answer = 0;

    int idx = 1;
    for (size_t i = 0; i < order.size(); i++)
    {
        while (idx <= order.at(i))
            stk.push(idx++);

        if (!stk.size() || stk.top() != order.at(i))
            break;

        stk.pop();
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> order{5, 4, 3, 2, 1};
    solution(order);
    return 0;
}