class Solution {
private:
    static double distance(const vector<int>& point) {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    vector<vector<int>> kClosestSort(vector<vector<int>>& points, int k) {
        sort(begin(points), end(points), [](const auto& lhs, const auto& rhs) {
            return distance(lhs) < distance(rhs);
        });

        vector<vector<int>> result;
        for (size_t i = 0; i < k; ++i) {
            result.push_back(points[i]);
        }

        return result;
    }

    void quickselect(vector<vector<int>>& points, int l, int r, int k) {
        if (l >= r) {
            return;
        }

        int pivot = (l + r) / 2;
        pivot = partition(points, l, r, pivot);
        int leftLength = pivot - l + 1;
        if (k < leftLength) {
            quickselect(points, l, pivot, k);
        } else if (k > leftLength) {
            quickselect(points, pivot + 1, r, k - leftLength);
        }
    }

    int partition(vector<vector<int>>& points, int l, int r, int pivot) {
        double pivotValue = distance(points[pivot]);
        points[l].swap(points[pivot]);
        int p = l;

        for (size_t i = l + 1; i < r; ++i) {
            if (distance(points[i]) <= pivotValue) {
                ++p;
                points[i].swap(points[p]);
            }
        }
        points[l].swap(points[p]);

        return p;
    }

    vector<vector<int>> kClosestQuickselect(vector<vector<int>>& points, int k) {
        quickselect(points, 0, points.size(), k);

        vector<vector<int>> result;
        for (size_t i = 0; i < k; ++i) {
            result.push_back(points[i]);
        }

        return result;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return kClosestQuickselect(points, k);
    }
};
