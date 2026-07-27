#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;

        vector<int> nums(n);
        unordered_map<int,int> cnt;
        unordered_map<int,int> tail;

        for(int i=0;i<n;i++)
        {
                cin>>nums[i];
                cnt[nums[i]]++;
        }

        for(int x:nums)
        {
                if(cnt[x]==0)
                        continue;

                if(tail[x-1]>0)
                {
                        tail[x-1]--;
                        tail[x]++;
                        cnt[x]--;
                }
                else if(cnt[x+1]>0 && cnt[x+2]>0)
                {
                        cnt[x]--;
                        cnt[x+1]--;
                        cnt[x+2]--;
                        tail[x+2]++;
                }
                else
                {
                        cout<<"false";
                        return 0;
                }
        }

        cout<<"true";

        return 0;
}