#include <iostream>
#include <vector>

using namespace std;

pair<int, int> neighbours[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    auto oldColor = image[sr][sc];

    if (oldColor == newColor) {
        return image;
    }

    image[sr][sc] = newColor;

    for (auto nb: neighbours) {
        auto nr = sr + nb.first;
        auto nc = sc + nb.second;

        if (nr >= 0 && nr < image.size() && nc >= 0 && nc < image.front().size() && image[nr][nc] == oldColor) {
            floodFill(image, nr, nc, newColor);
        }
    }

    return image;
}

int main() {
    vector<vector<int>> image = {
        {0,0,0}, {0,1,1}
    };

    floodFill(image, 1, 1, 1);

    for (const auto& row: image) {
        for (const auto& cell: row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}
