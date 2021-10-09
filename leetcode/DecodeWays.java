public class Solution {
    public int numDecodings(String s) {

        if (s.charAt(0) == '0') {
            return 0;
        }

        Set<Character> validForTwo = new HashSet<>();
        for (int i = 0; i < 7; i++) {
            validForTwo.add(Integer.toString(i).charAt(0));
        }

        int[] dp = new int[s.length() + 1];
        dp[0] = 1;

        for (int i = 1; i < s.length() + 1; i++) {
            if (s.charAt(i - 1) != '0') {
                dp[i] += dp[i - 1];
            }

            if (i - 2 >= 0 && (s.charAt(i - 2) == '1' ||
                               s.charAt(i - 2) == '2' && validForTwo.contains(s.charAt(i - 1)))) {

                dp[i] += dp[i - 2];
            }
        }
        return dp[s.length()];
    }
}
