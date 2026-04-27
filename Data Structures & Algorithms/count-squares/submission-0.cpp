class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        cnt[x][y]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;

        for (auto &[col, yMap] : cnt) {
            if (col == x) continue;

            int d = col - x;

            // upper square
            res += yMap[y] * cnt[x][y + d] * cnt[col][y + d];

            // lower square
            res += yMap[y] * cnt[x][y - d] * cnt[col][y - d];
        }

        return res;
    }
};