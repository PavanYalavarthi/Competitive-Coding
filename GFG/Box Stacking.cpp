// https://www.geeksforgeeks.org/problems/box-stacking/1

class Solution {
  public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // Your code here
        vector<vector<int>> boxes;
        
        for(int i = 0; i< length.size(); i++) {
            boxes.push_back({height[i], width[i], length[i]});
            boxes.push_back({width[i], length[i], height[i]});
            boxes.push_back({length[i], height[i], width[i]});
            boxes.push_back({height[i], length[i], width[i]});
            boxes.push_back({width[i], height[i], length[i]});
            boxes.push_back({length[i], width[i],height[i] });
        }
        
        sort(boxes.begin(), boxes.end(), [](vector<int> &a, vector<int> & b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = boxes.size();
        vector<int>dp(n);
        for(int i = 0; i< n; i++) {
            int ans = 0;
            for(int j = 0; j< i; j++) {
                if(boxes[j][1] < boxes[i][1]) 
                    ans = max(ans, dp[j]);
            }
            dp[i] = ans + boxes[i][2];
        }
        return *max_element(dp.begin(), dp.end());
    }
};