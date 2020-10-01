import java.util.*;

class LetterCombinations {
    static final Map<Character , Character[]> numberToLetters = new HashMap() {{
        put('2', new Character[]{'a', 'b', 'c'});
        put('3', new Character[]{'d', 'e', 'f'});
        put('4', new Character[]{'g', 'h', 'i'});
        put('5', new Character[]{'j', 'k', 'l'});
        put('6', new Character[]{'m', 'n', 'o'});
        put('7', new Character[]{'p', 'q', 'r', 's'});
        put('8', new Character[]{'t', 'u', 'v'});
        put('9', new Character[]{'w', 'x', 'y', 'z'});
    }};

    public static void main(String[] args) {
        LetterCombinations main = new LetterCombinations();

        System.out.println(main.letterCombinations("23"));
    }

    public List<String> letterCombinations(String digits) {
        List<String> combinations = new ArrayList();

        combinationsHelper(digits, 0, combinations, "");

        return combinations;
    }

    private void combinationsHelper(String digits, int idx, List<String> combinations, String currentCombination) {
        if (idx == digits.length()) {
            if (!currentCombination.isEmpty()) {
                combinations.add(currentCombination);
            }
            return;
        }

        for (char c: numberToLetters.get(digits.charAt(idx))) {
            combinationsHelper(digits, idx + 1, combinations, currentCombination + c);
        }
    }
}
