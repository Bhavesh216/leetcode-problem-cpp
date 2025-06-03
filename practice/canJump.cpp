bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > farthest) return false; // can't reach this point
        farthest = max(farthest, i + nums[i]);
    }
 }