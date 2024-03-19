// https://school.programmers.co.kr/learn/courses/30/lessons/132265
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define endl "\n"

int solution(vector<int> topping)
{
    int answer = 0;

    unordered_map<int, int> m_cut_front;
    unordered_map<int, int> m_cut_back;

    for (auto item : topping)
        m_cut_back[item]++;

    for (size_t i = 0; i < topping.size(); i++)
    {
        m_cut_front[topping[i]]++;
        m_cut_back[topping[i]]--;
        if (!m_cut_back[topping[i]])
            m_cut_back.erase(topping[i]);

        if (m_cut_front.size() == m_cut_back.size())
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> topping{1, 2, 3, 1, 4};
    solution(topping);
    return 0;
}