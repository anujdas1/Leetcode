class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();

        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long int Dsum=target-1LL*nums[i]-1LL*nums[j]-1LL*nums[k]-1LL*nums[l];
                    if(Dsum<0){
                        l--;
                    }else if(Dsum>0){
                        k++;
                    }else{
                        ans.push_back({nums[i],nums[j], nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};