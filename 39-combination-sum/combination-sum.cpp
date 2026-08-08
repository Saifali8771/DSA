#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(const std::vector<int>& candidates, int remainingTarget, int start, 
                   std::vector<int>& currentCombination, std::vector<std::vector<int>>& result) {
        if (remainingTarget == 0) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > remainingTarget) {
                break;
            }

            currentCombination.push_back(candidates[i]);
           
            backtrack(candidates, remainingTarget - candidates[i], i, currentCombination, result);

            
            currentCombination.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        std::sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }
};
