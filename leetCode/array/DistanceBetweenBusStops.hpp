// https://leetcode.com/problems/distance-between-bus-stops/
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int len = distance.size();
        if (!len) {
            return 0;
        }
        int dist[2];
        dist[0] = dist[1] = 0;

        //printf("s: %d, d: %d\n", start, destination);
        for (int i = start; i != destination; i = (i + 1) % len) {
            //printf("d0: %d, i: %d\n", dist[0], i);
            dist[0] += distance[i];
        }
        for (int i = start; i != destination; i = (i - 1 + len) % len) {
            //printf("d1: %d, i: %d\n", dist[1], i);
            dist[1] += distance[(i - 1 + len) % len];
        }
        //printf("%d, %d\n", dist[0], dist[1]);
        return min(dist[0], dist[1]);
    }
};
