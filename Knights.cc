// Output file will be a.out in both cases
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> garden(n, vector<int>(n, 0));
    vector<pair<pair<int, int>, pair<int, int>>> rectangles;

    // Read rectangle coordinates
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rectangles.push_back({{a, b}, {c, d}});
    }

    // Place shrubberies in the garden
    for (int i = 0; i < n; ++i)
    {
        bool placed = false;
        for (int x = rectangles[i].first.first; x <= rectangles[i].second.first; ++x)
        {
            for (int y = rectangles[i].first.second; y <= rectangles[i].second.second; ++y)
            {
                if (garden[x - 1][y - 1] == 0)
                {
                    garden[x - 1][y - 1] = i + 1;
                    cout << y << " " << x << endl; // Corrected output format
                    placed = true;
                    break;
                }
            }
            if (placed)
                break;
        }
        if (!placed)
        {
            cout << "NI" << endl;
            return 0;
        }
    }

    return 0;
}