class Solution {
private:
    int dfs(array<array<int, 10>, 10>& jumps, array<bool, 10>& visited, int num, int remaining) {
        if (remaining < 0) {
            return 0;
        } else if (remaining == 0) {
            return 1;
        }

        visited[num] = true;
        int count = 0;

        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[num][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                count += dfs(jumps, visited, next, remaining - 1);
            }
        }

        visited[num] = false;
        return count;
    }
public:
    int numberOfPatterns(int m, int n) {
        array<array<int, 10>, 10> jumps{};
        jumps[1][3] = jumps[3][1] = 2;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[3][9] = jumps[9][3] = 6;
	    jumps[1][9] = jumps[9][1] = jumps[3][7] = jumps[7][3] = 5;

        array<bool, 10> visited{};

        int count = 0;
        for (int i = m; i <= n; ++i) {
            count += dfs(jumps, visited, 1, i - 1) * 4;
            count += dfs(jumps, visited, 2, i - 1) * 4;
            count += dfs(jumps, visited, 5, i - 1);
        }

        return count;
    }
};
