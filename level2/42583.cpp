// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 1;
    int total_weight = truck_weights.front();
    int truck_idx = 0;

    queue<pair<int, int>> q_bridge;
    q_bridge.push(make_pair(time, truck_weights[truck_idx++]));

    while (q_bridge.size())
    {
        time++;
        if (time - q_bridge.front().first >= bridge_length)
        {
            total_weight -= q_bridge.front().second;
            q_bridge.pop();
        }

        if (truck_idx < truck_weights.size() && total_weight + truck_weights[truck_idx] <= weight)
        {
            total_weight += truck_weights[truck_idx];
            q_bridge.push(make_pair(time, truck_weights[truck_idx++]));
        }
    }

    return time;
}

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7,4,5,6};
    solution(bridge_length, weight, truck_weights);
    return 0;
}