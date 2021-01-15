class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] indices = new int[2];

    
        boolean loop = true;
        for(int i = 0; i < nums.length - 1 && loop; i++) {
            for(int j = i + 1; j < nums.length && loop; j++) {
                if (nums[i] + nums[j] == target) {
                    indices[0] = i;
                    indices[1] = j;
                    loop = false;
                }
            }
        }
        return indices;
    }
}
