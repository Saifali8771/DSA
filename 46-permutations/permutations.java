import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), nums);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> currentList, int[] nums) {
        if (currentList.size() == nums.length) {
            result.add(new ArrayList<>(currentList));
            return;
        }

        for (int num : nums) {
           
            if (currentList.contains(num)) {
                continue;
            }
          
            currentList.add(num);
           
            backtrack(result, currentList, nums);
       
            currentList.remove(currentList.size() - 1);
        }
    }
}