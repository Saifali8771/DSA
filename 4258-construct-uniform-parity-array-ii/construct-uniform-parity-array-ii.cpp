class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        for (int target = 0; target <= 1; target++) {
            bool seen[2] = {false, false};
            bool possible = true;

            for (int x : nums1) {
                int p = x & 1;

                // We can keep x itself
                if (p == target) {
                    seen[p] = true;
                }
                else {
                    // Need x - y to have target parity
                    int needed = p ^ target;

                    if (!seen[needed]) {
                        possible = false;
                        break;
                    }

                    seen[p] = true;
                }
            }

            if (possible)
                return true;
        }

        return false;
    }
};
