// https://school.programmers.co.kr/learn/courses/30/lessons/17679
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"

queue<char> q;
vector<pair<int, int>> vec;

bool is_equal(const char &ch1, const char &ch2, const char &ch3, const char &ch4)
{
    return ch1 >= 'A' && ch1 <= 'Z' && ch1 == ch2 && ch2 == ch3 && ch3 == ch4;
}

void change(vector<string> &board, int &answer, int i, int j)
{
    if (board[i][j] != '0') answer++;
    if (board[i + 1][j] != '0') answer++;
    if (board[i][j + 1] != '0') answer++;
    if (board[i + 1][j + 1] != '0') answer++;
    board[i][j] = board[i + 1][j] = board[i][j + 1] = board[i + 1][j + 1] = '0';
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    while (true)
    {
        for (int i = m - 2; i >= 0; i--)
            for (int j = 0; j < n - 1; j++)
                if (is_equal(board[i][j], board[i + 1][j], board[i][j + 1], board[i + 1][j + 1]))
                    vec.emplace_back(make_pair(i, j));

        if (!vec.size())
            break;

        for (auto item : vec)
            change(board, answer, item.first, item.second);

        vec.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (board[j][i] != '0')
                {
                    q.push(board[j][i]);
                    board[j][i] = '0';
                }
            }

            for (int j = m - 1; j >= 0, q.size(); j--)
            {
                board[j][i] = q.front();
                q.pop();
            }
        }
    }

    return answer;
}

int main()
{
    int m = 6;
    int n = 6;
    vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
    solution(m, n, board);
    return 0;
}