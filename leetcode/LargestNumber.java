import java.util.*;
import java.util.stream.*;

public class LargestNumber {
    class IntComparator implements Comparator<Integer> {
        private int getIntLength(int number) {
            int length = 0;
            while (number > 0) {
                ++length;
                number /= 10;
            }

            return length;
        }

//        @Override
//        public int compare(Integer l, Integer r) {
//            int ldivider = (int) Math.pow(10, getIntLength(l) - 1);
//            int rdivider = (int) Math.pow(10, getIntLength(r) - 1);
//
//            int ls = l / ldivider;
//            int rs = r / rdivider;
//
//            int ld, rd;
//            while (ldivider > 0 || rdivider > 0) {
//                if (ldivider > 0) {
//                    ld = l / ldivider;
//                    l %= ldivider;
//                    ldivider /= 10;
//                } else {
//                    ld = ls;
//                }
//
//                if (rdivider > 0) {
//                    rd = r / rdivider;
//                    r %= rdivider;
//                    rdivider /= 10;
//                } else {
//                    rd = rs;
//                }
//
//                if (ld > rd) {
//                    return 1;
//                } else if (ld < rd) {
//                    return -1;
//                }
//            }
//
//            return 0;
//        }

        @Override
        public int compare(Integer l, Integer r) {
            long lmul = (long) Math.pow(10, getIntLength(l));
            long rmul = (long) Math.pow(10, getIntLength(r));

            long rs = (long) r * lmul + (long) l;
            long ls = (long) l * rmul + (long) r;

            if (rs < ls) {
                return 1;
            } else if (ls < rs) {
                return -1;
            } else {
                if (r < l) {
                    return 1;
                } else if (l < r) {
                    return -1;
                }

                return 0;
            }
        }
    }

    private String solve(int[] nums) {
        String[] snums = Arrays.stream(nums).boxed().sorted(new IntComparator().reversed()).map(String::valueOf).toArray(String[]::new);

        if (snums[0].equals("0")) {
            return "0";
        }

        return String.join("", snums);
    }

    class StringComparator implements Comparator<String> {
        @Override
        public int compare(String l, String r) {
            String ls = l + r;
            String rs = r + l;

            return ls.compareTo(rs);
        }
    }

//    private String solve(int[] nums) {
//        String[] snums = Arrays.stream(nums).mapToObj(String::valueOf).toArray(String[]::new);
//
//        Arrays.sort(snums, new StringComparator().reversed());
//
//        if (snums[0].equals("0")) {
//            return "0";
//        }
//
//        return String.join("", snums);
//    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] nums = new int[n];

        for (int i = 0; i < n; ++i) {
            nums[i] = scanner.nextInt();
        }

        LargestNumber solution = new LargestNumber();
        System.out.println(solution.solve(nums));
    }
}
