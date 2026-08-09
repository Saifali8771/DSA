import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(candidates);
      
        backtrack(candidates, target, 0, new ArrayList<>(), result);
        
        return result;
    }

    private void backtrack(int[] candidates, int remain, int startIndex, 
                           List<Integer> currentCombination, List<List<Integer>> result) {

        if (remain == 0) {
            result.add(new ArrayList<>(currentCombination));
            return;
        }

        for (int i = startIndex; i < candidates.length; i++) {

            if (candidates[i] > remain) {
                break;
            }

            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }


            currentCombination.add(candidates[i]);
            backtrack(candidates, remain - candidates[i], i + 1, currentCombination, result);

      
            currentCombination.remove(currentCombination.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] candidates = {10, 1, 2, 7, 6, 1, 5};
        int target = 8;
        
        List<List<Integer>> result = sol.combinationSum2(candidates, target);
        System.out.println(result);
      
    }
}