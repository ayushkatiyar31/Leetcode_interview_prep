class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size();

        while (start < end) {
            if (nums[start] == val) {
                nums[start] = nums[end - 1];
                end--;
            } else {
                start++;
            }
        }
        return end;
    }
};
