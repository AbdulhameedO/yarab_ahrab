#include <iostream>
#include <vector>

using std::pair;
using std::cout;
using std::cin;
using std::vector;

pair<unsigned long long,int> emshy(int x,int y, vector<pair<int, int>>& available_steps, int boundry, int max, int count, vector<vector<vector<unsigned long long>>> & map)
{
    pair<unsigned long long, int> result;
    unsigned long long total = 0, adder=0;
    pair<unsigned long long, int> z;
    
    if ((x < 0 || y < 0) || (x >= boundry || y >= boundry))
    {
        result.first = 1;
        result.second = count;
        return result;
    }
    if (count == max)
    {
        result.first = 0;
        return result;
    }
    
    if (map[x][y].size())
    {
        for (int i = 0; i < map[x][y].size(); i++)
        {
            if (map[x][y][i] + count <= max)
                adder++;
        }
        result.first = adder;
        return result;
    }
    for (int i = 0; i < available_steps.size(); i++)
    {
        z = emshy(x + available_steps[i].first, y + available_steps[i].second, available_steps, boundry, max, count + 1, map);
        if (z.first)
        {
            total += z.first;
            map[x][y].push_back(z.second);
            z.first = 0;
            z.second = 0;
        }
    }
    result.first = total;
    return result;
}
int main()
{
    pair<int, int> step;
    int x, y;
    int a5ry, maxmoves, R;

    cin >> a5ry;
    cin >> maxmoves;
    cin >> R;
    cin >> x;
    cin >> y;


    vector<pair<int, int>> ta7arokat;

    int max_x = 0, max_y = 0;
    for (int i = 0; i < R; i++)
    {

        cin >> step.first;
        cin >> step.second;
        if (step.first > max_x)
            max_x = step.first;

        if (step.second> max_y)
            max_y = step.second;

        ta7arokat.push_back(step);
    }

    vector<vector<vector<unsigned long long>>> map(a5ry+max_x, vector<vector< unsigned long long >>(a5ry+max_y));

    cout << emshy(x, y, ta7arokat, a5ry, maxmoves, 0, map).first;

    return 0;

}
