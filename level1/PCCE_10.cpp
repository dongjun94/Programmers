#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define endl "\n"

map<string, int> m_ext = {
    {"code", 0},
    {"date", 1},
    {"maximum", 2},
    {"remain", 3},
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    vector<vector<int>> answer;
    for (auto item : data)
        if (item.at(m_ext[ext]) <= val_ext)
            answer.emplace_back(item);

    sort(answer.begin(), answer.end(), [&](const vector<int> &a, const vector<int> &b)
         { return a.at(m_ext[sort_by]) < b.at(m_ext[sort_by]); });

    return answer;
    
}

int main()
{
    vector<vector<int>> data = {{1, 20300104, 100, 80}, {2, 20300804, 847, 37}, {3, 20300401, 10, 8}};
    string ext = "date";
    int val_ext = 20300501;
    string sort_by = "remain";
    solution(data, ext, val_ext, sort_by);
    return 0;
}