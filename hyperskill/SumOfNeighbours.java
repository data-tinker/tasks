import java.util.*;
import java.util.stream.*;

class SumOfNeighbours {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] neigbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        List<List<Integer>> matrix = new ArrayList<>();
        while (scanner.hasNextInt()) {
            matrix.add(
                Arrays.stream(scanner.nextLine().split(" ")).map(Integer::valueOf).collect(Collectors.toList())
            );
        }

        int n = matrix.size();
        int m = matrix.get(0).size();
        int nbI;
        int nbJ;
        int sum;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sum = 0;
                for (var nb: neigbours) {
                    nbI = i + nb[0];
                    nbJ = j + nb[1];
                    if (nbI >= n) {
                        nbI = 0;
                    } else if (nbI < 0) {
                        nbI = n - 1;
                    } else if (nbJ >= m) {
                        nbJ = 0;
                    } else if (nbJ < 0) {
                        nbJ = m - 1;
                    }

                    sum += matrix.get(nbI).get(nbJ);
                }

                System.out.print(sum + " ");
            }
            System.out.println();
        }
    }
}

