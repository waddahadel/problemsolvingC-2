// Output file will be a.out in both cases
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

typedef long long ll;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

bool customCompare(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
int main(int argc, const char **argv)
{
    int n_of_inputs;
    vector<vector<int>> our_matrix;
    cin >> n_of_inputs;
    int maximum_gain = 0;
    int what_we_have = 0;
    int bottles_to_be_borrowed = 0;

    for (int i = 0; i < n_of_inputs; i++)
    {
        int d;
        int v;
        cin >> d >> v;
        our_matrix.push_back({d, v});
    }

    sort(our_matrix.begin(), our_matrix.end(), customCompare);

    for (const auto &row : our_matrix)
    {
        int di = row[0];
        int vi = row[1];
        int gain = vi - di;
        if (gain > 0)
        {

            bottles_to_be_borrowed += (what_we_have < di) ? (di - what_we_have) : 0;
            maximum_gain += gain;
            what_we_have += vi;
        }
    }

    cout << bottles_to_be_borrowed << " " << maximum_gain;
}