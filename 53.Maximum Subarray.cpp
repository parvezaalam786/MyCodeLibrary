class Solution {
public:
    int maxSubArray(vector<int>& arr) {
            int i,n = arr.size(),ans=0,ans1=0;
        for(i=0;i<n;i++){
            ans += arr[i];
            if(ans>ans1)
                ans1 = ans;
            if(ans<0)
                ans = 0;    
        }
        if(ans1==0){
            ans1 = *(max_element(arr.begin(),arr.end()));
        }
        return ans1;

        }
};