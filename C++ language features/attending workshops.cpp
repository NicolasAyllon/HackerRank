#include<bits/stdc++.h>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
//Define the structs Workshops and Available_Workshops.
struct Workshop {
    private:
        int m_startTime;
        int m_duration;
        int m_endTime;
    public:
        // Default 0-argument Constructor
        Workshop() {
            m_startTime = 0;
            m_duration = 0;
            m_endTime = 0;
        }
        // 2-Parameter Constructor
        Workshop(int startTime, int duration): m_startTime(startTime), m_duration(duration) {
            m_endTime = startTime + duration;
        }
        // 3-Parameter Constructor
        Workshop(int startTime, int duration, int endTime): m_startTime(startTime), m_duration(duration), m_endTime(endTime) {}
        // Getters
        int get_endTime() const { return m_endTime; }
        int get_startTime() const { return m_startTime; }
        int get_duration() const { return m_duration; }
};

// Use to sort workshop end times from latest to earliest (back of vector)
bool compareWorkshopEndTimes(const Workshop& lhs, const Workshop& rhs) {
    return (lhs.get_endTime() > rhs.get_endTime());
}

// Available_Workshops holds a vector of Workshop objects and its length
struct Available_Workshops {
    private:
        int n;
    public:
        vector<Workshop> workshops;
        // array argument constructor
        Available_Workshops(int start_times[], int durations[], int n) {
            for(int i = 0; i < n; ++i) {
                workshops.push_back(Workshop(start_times[i], durations[i]));
            }
        }
};

// forward to array-argument constructor
Available_Workshops* initialize(int start_times[], int durations[], int n) {
    Available_Workshops* aw = new Available_Workshops(start_times, durations, n);
    return aw;
}

// Calculate maximum workshops student can attend
int CalculateMaxWorkshops(Available_Workshops* available_workshops) {
    vector<Workshop> maximizedSchedule;
    vector<Workshop> w_list = available_workshops->workshops;
    // sort by finishing time
    sort(w_list.begin(), w_list.end(), compareWorkshopEndTimes);
    // find earliest finishing time
    while(!w_list.empty()) {
        // The workshop at the back of the vector has the earliest finishing time
        Workshop workshopFinishingEarliest = w_list.back();
        maximizedSchedule.push_back(workshopFinishingEarliest);
        int earliestFinishingTime = workshopFinishingEarliest.get_endTime();
        // remove all colliding workshops
        while((!w_list.empty()) && (w_list.back().get_startTime() < earliestFinishingTime)) {
            w_list.pop_back();
        }
    }
    return maximizedSchedule.size();
}


// From HackerRank
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}