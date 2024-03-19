#include <string>
#include <vector>

using namespace std;
#define endl "\n"

int solution(vector<vector<string>> board, int h, int w)
{
    int answer = 0;
    string center_color = board[h][w];
    answer += h != 0 && center_color == board[h - 1][w] ? 1 : 0;
    answer += h != board.size() - 1 && center_color == board[h + 1][w] ? 1 : 0;
    answer += w != 0 && center_color == board[h][w - 1] ? 1 : 0;
    answer += w != board.size() - 1 && center_color == board[h][w + 1] ? 1 : 0;
    return answer;
}

int main()
{
    vector<vector<string>> board = {{"blue", "red", "orange", "red"}, {"red", "red", "blue", "orange"}, {"blue", "orange", "red", "red"}, {"orange", "orange", "red", "blue"}};
    int h = 1;
    int w = 1;
    return solution(board, h, w);
    
}