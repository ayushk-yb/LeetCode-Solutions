class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int* room = new int[n]{0};
        long long* timings = new long long[n]{0};
        for (int i = 0; i < meetings.size(); i++) {
            int index = -1;
            int minindex = 0;
            for (int j = 0; j < n; j++) {
                if (timings[j] == 0 || timings[j] <= meetings[i][0]) {
                    index = j;
                    break;
                }
            }
            if (index != -1) {
                room[index]++;
                if (timings[index] == 0 || timings[index] < meetings[i][0]) {
                    timings[index] = meetings[i][1];
                    continue;
                }
                timings[index] += (meetings[i][1] - meetings[i][0]);
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (timings[j] < timings[minindex]) {
                    minindex = j;
                }
            }
            room[minindex]++;
            timings[minindex] += (meetings[i][1] - meetings[i][0]);
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (room[j] > room[ans]) {
                ans = j;
            }
        }
        return ans;
    }
};
