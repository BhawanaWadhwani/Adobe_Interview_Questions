class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums.size()<=1)
        {
            return 0;
        }
        //there would be a pivot element before which each num would be increased by k and after which each num would be reduced by k
        //our ans could be the diff between max and min
        int ans=nums[nums.size()-1]-nums[0]; //all added by k
        int maxi, mini;
        for(int i=0;i<nums.size()-1;i++)
        {
            int x=nums[i];
            int y=nums[i+1];
            
            //pivot at x : x+=k
            //             y-=k
            //now the max element could be either last element-k or x+=k
            //.   the min element could be either first element or y-=k
            
            maxi=max(nums[nums.size()-1]-k, x+k);
            mini=min(nums[0]+k, y-k);
            
            ans=min(ans, maxi-mini);
        }
        return ans;
    }
};
