#include <string>
#include <vector>

using namespace std;
#define endl "\n"

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int answer = health;
    int max_time = attacks.back().front();
    size_t attack_idx = 0;
    int continuity = 0;
    for (int i = 0; i <= max_time; i++, continuity++)
    {
        if (i == attacks[attack_idx].front())
        {
            continuity = 0;
            answer -= attacks[attack_idx].back();
            if (answer <= 0)
                return -1;
            attack_idx++;
        }
        else
        {
            answer += bandage[1];
            if (continuity == bandage[0])
            {
                answer += bandage[2];
                continuity = 0;
            }
            if (answer > health)
                answer = health;
        }
    }

    return answer;
    
}

int main()
{
    vector<int> bandage = {5, 1, 5};
    int health = 30;
    vector<vector<int>> attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};
    solution(bandage, health, attacks);
    return 0;
}