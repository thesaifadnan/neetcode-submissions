class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int l= 0, r=height.size()-1, res=0, leftMax = height[l], rightMax = height[r];

        while(l<r){
            if(height[l] < height[r]){
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }else{
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

//METHOD 2 USING PREFIX & SUFFIX ARRAYS
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if(height.empty()) return 0;

//         int n = height.size();
//         int res = 0;
//         vector<int> leftMax(n);
//         vector<int> rightMax(n);

//         leftMax[0] = height[0];
//         rightMax[n-1] = height[n-1];

//         for(int i=1;i<n; i++){
//             leftMax[i] = max(leftMax[i-1], height[i]);
//         }

//         for(int i=n-2;i>=0; i--){
//             rightMax[i] = max(rightMax[i+1], height[i]);
//         }

//         for(int i=0;i<n; i++){
//             res += min(leftMax[i], rightMax[i]) - height[i];
//         }
//         return res;
//     }
// };