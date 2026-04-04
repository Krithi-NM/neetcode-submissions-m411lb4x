class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> pq(stones.begin(), stones.end());

    // Keep smashing until one or none left
    while (pq.size() > 1) {
        int y = pq.top(); pq.pop(); // largest
        int x = pq.top(); pq.pop(); // second largest

        if (y != x) {
            pq.push(y - x);
        }
    }
    return pq.empty() ? 0 : pq.top();
}
};