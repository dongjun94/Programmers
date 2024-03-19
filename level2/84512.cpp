// https://school.programmers.co.kr/learn/courses/30/lessons/84512

#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
#define endl "\n"

map<char, int> m_index = {{'A', 1}, {'E', 2}, {'I', 3}, {'O', 4}, {'U', 5}, };

vector<int> vec_weight;
void make_weight()
{
    for (int i = 0; i < 5; i++)
    {
        int temp = 0;
        for (int j = 4 - i; j >= 0; j--)
            temp += pow(5, j);
        vec_weight.emplace_back(temp);
    }
}

int solution(string word)
{
    make_weight();

    int answer = word.size();
    for (int i = 0; i < word.size(); i++)
        answer += vec_weight.at(i) * (m_index.at(word.at(i)) - 1);

    return answer;
}

int main()
{
    solution(string("EIO"));
    return 0;
}