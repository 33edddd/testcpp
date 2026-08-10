#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<int>& candidates,
             int target,
             int start,
             vector<int>& path,
             vector<vector<int>>& res)
    {
        if (target ==0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {

            if (candidates[i]>target) {
                break;
            }
            path.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i,path,res);
            path.pop_back();
        }
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;

        vector<int> path;


        // 排序用于剪枝
        sort(candidates.begin(), candidates.end());


        dfs(candidates, target, 0, path, res);


        return res;
    }
};



int main()
{
    int n;
    cin >> n;


    vector<int> candidates(n);

    for(int i = 0; i < n; i++)
        cin >> candidates[i];


    int target;
    cin >> target;


    Solution s;


    vector<vector<int>> res = s.combinationSum(candidates, target);


    cout << res.size() << endl;


    return 0;
}