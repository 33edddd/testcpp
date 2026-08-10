#include <bits/stdc++.h>
using namespace std;


// 回溯函数
bool dfs(vector<int>& nums, vector<bool>& used, int k, int start, int sum, int target)
{
    // 已经找到 k-1 个满足条件的子集
    // 剩下的数字一定组成最后一个子集
    if (k == 1)
        return true;


    // 当前子集和满足要求，开始寻找下一个子集
    if (sum == target)
    {
        return dfs(nums, used, k - 1, 0, 0, target);
    }


    for (int i = start; i < nums.size(); i++)
    {
        if (used[i])
            continue;


        // 当前数字加入后超过目标
        if (sum + nums[i] > target)
            continue;


        used[i] = true;


        if (dfs(nums, used, k, i + 1, sum + nums[i], target))
            return true;


        // 回溯
        used[i] = false;


        // 如果当前桶为空，放当前数字失败，
        // 后面更小的数字也不需要尝试
        if (sum == 0)
            break;


        // 跳过重复数字
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
    }


    return false;
}



// 判断是否可以划分为 k 个和相等的子集
bool canPartitionKSubsets(vector<int>& nums, int k)
{
    int total = 0;

    for (int x : nums)
        total += x;


    // 总和不能被 k 整除
    if (total % k != 0)
        return false;


    int target = total / k;


    // 从大到小排序，提高剪枝效率
    sort(nums.begin(), nums.end(), greater<int>());


    // 最大元素超过目标，不可能
    if (nums[0] > target)
        return false;


    vector<bool> used(nums.size(), false);


    return dfs(nums, used, k, 0, 0, target);
}



int main()
{
    int n;
    cin >> n;


    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];


    int k;
    cin >> k;


    if (canPartitionKSubsets(nums, k))
        cout << "true";
    else
        cout << "false";


    return 0;
}