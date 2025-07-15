class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> meetingCount(n, 0); 


        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        }

    
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            long long duration = end - start;

    
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int freedRoom = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(freedRoom);
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                ++meetingCount[room];
                busyRooms.push({end, room});
            } else {
                auto [freeAt, room] = busyRooms.top();
                busyRooms.pop();
                ++meetingCount[room];
                busyRooms.push({freeAt + duration, room});
            }
        }

        
        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
