#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl);

// meet in the middle!
long long countSubsets(vector<int> &nums, int target)
{
    int n = nums.size();
    int mid = n / 2;

    vector<long long> subsetSums1;
    for (int mask = 0; mask < (1 << mid); ++mask)
    {
        long long sum = 0;
        for (int i = 0; i < mid; ++i)
        {
            if (mask & (1 << i))
            {
                sum += nums[i];
            }
        }
        subsetSums1.push_back(sum);
    }

    vector<long long> subsetSums2;
    for (int mask = 0; mask < (1 << (n - mid)); ++mask)
    {
        long long sum = 0;
        for (int i = 0; i < (n - mid); ++i)
        {
            if (mask & (1 << i))
            {
                sum += nums[mid + i];
            }
        }
        subsetSums2.push_back(sum);
    }

    sort(subsetSums2.begin(), subsetSums2.end());

    long long count = 0;
    for (long long sum : subsetSums1)
    {
        long long complement = target - sum;
        auto lower = lower_bound(subsetSums2.begin(), subsetSums2.end(), complement);
        auto upper = upper_bound(subsetSums2.begin(), subsetSums2.end(), complement);
        count += (upper - lower);
    }

    return count;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    long long result = countSubsets(nums, x);
    cout << result << endl;
    return 0;
}
