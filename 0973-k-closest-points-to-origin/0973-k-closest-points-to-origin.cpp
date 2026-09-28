class Solution {
    struct PointComparator{
        bool operator()(const vector<int>& p1, const vector<int>& p2) const {
            double d1 = sqrt(p1[0]*p1[0]+p1[1]*p1[1]);
            double d2 = sqrt(p2[0]*p2[0]+p2[1]*p2[1]);
            return d1 < d2;
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), PointComparator{});
        vector<vector<int>> res(points.begin(), points.begin()+k);
        return res;
    }
};
