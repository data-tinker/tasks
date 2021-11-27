class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Boolean[] memo = new Boolean[s.length()];

        Set<String> wordSet = new HashSet<>();

        for (var word : wordDict) {
            wordSet.add(word);
        }

        return canBeSegmented(s, 0, wordSet, memo);
    }

    private boolean canBeSegmented(String s, int startIdx, Set<String> wordSet, Boolean[] memo) {
        if (startIdx == s.length()) {
            return true;
        }

        if (memo[startIdx] != null) {
            return memo[startIdx];
        }

        for (int i = startIdx; i <= s.length(); ++i) {
            if (wordSet.contains(s.substring(startIdx, i))) {
                if (canBeSegmented(s, i, wordSet, memo)) {
                    memo[startIdx] = true;
                    return true;
                }
            }
        }

        memo[startIdx] = false;
        return false;
    }
}
