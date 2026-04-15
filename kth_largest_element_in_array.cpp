#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;   // minheap

        for (int num : nums) {
            minHeap.push(num);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth largest element is: " << sol.findKthLargest(nums, k) << endl;

    return 0;
}
