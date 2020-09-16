import java.util.*;

class IsAnagram {
    public boolean solution(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> charsCount = new HashMap<>();

        for (char c : s.toCharArray()) {
            charsCount.merge(c, 1, Integer::sum);
        }

        for (char c : t.toCharArray()) {
            Integer count = charsCount.get(c);
            if (count == null || count == 0) {
                return false;
            }
            charsCount.put(c, count - 1);
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        IsAnagram isAnagram = new IsAnagram();

        System.out.println(isAnagram.solution(scanner.nextLine(), scanner.nextLine()));
    }
}
