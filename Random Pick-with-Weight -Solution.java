class Solution {
    private int[] cumSum;
    private int n;
    private Random rand;

    public Solution(int[] w) {
        n = w.length;
        cumSum = new int[n];
        rand = new Random();
        cumSum[0] = w[0];
        for (int i = 1; i < n; i++) cumSum[i] = cumSum[i - 1] + w[i];
    }

    public int pickIndex() {
        int r = rand.nextInt(cumSum[n - 1]) + 1;
        int i = Arrays.binarySearch(cumSum, r);
        if (i < 0) i = -(i + 1);
        return i;
    }
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
