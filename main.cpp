#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 获取长度为k的最大子序列
    vector<int> getMax(vector<int>& nums,int k)
    {
        vector<int> st;
        int remove=nums.size()-k;

        for(int x:nums)
        {
            while(!st.empty() && remove>0 && st.back()<x)
            {
                st.pop_back();
                remove--;
            }
            st.push_back(x);
        }

        st.resize(k);

        return st;
    }


    // 合并两个数组
    vector<int> merge(vector<int>& a,vector<int>& b)
    {
        vector<int> res;

        int i=0,j=0;

        while(i<a.size() || j<b.size())
        {
            if(compare(a,i,b,j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        return res;
    }


    // 判断a[i...]是否大于b[j...]
    bool compare(vector<int>& a,int i,vector<int>& b,int j)
    {
        while(i<a.size() && j<b.size())
        {
            if(a[i]!=b[j])
                return a[i]>b[j];

            i++;
            j++;
        }

        return (a.size()-i)>(b.size()-j);
    }


    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2,int k)
    {
        vector<int> ans;

        for(int i=0;i<=k;i++)
        {
            if(i<=nums1.size() && k-i<=nums2.size())
            {
                vector<int> a=getMax(nums1,i);
                vector<int> b=getMax(nums2,k-i);

                vector<int> temp=merge(a,b);

                if(ans.empty() || compare(temp,0,ans,0))
                    ans=temp;
            }
        }

        return ans;
    }
};


int main()
{
    int m,n,k,data;

    vector<int> nums1,nums2;

    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>data;
        nums1.push_back(data);
    }


    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>data;
        nums2.push_back(data);
    }


    cin>>k;


    vector<int> res=Solution().maxNumber(nums1,nums2,k);


    for(int i=0;i<res.size();i++)
        cout<<res[i];


    return 0;
}