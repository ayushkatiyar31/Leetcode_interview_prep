class Solution {
public:
    int findMin(vector<int>& arr) {

        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[end])
                start = mid + 1;

            else {
                end = mid;
            }
        }
        return arr[start];
    }
};