#include<iostream>
#include<vector>
#include<map>

using namespace std;

class FurnaceMonitor {
    public:
        // Define types
        typedef int DayNumber;
        typedef double Temp;
        typedef bool Emergency;

        // Add a reading for a day
        void addReading(DayNumber day, Temp temp, Emergency emg) {
            readings[day] = make_pair(temp, emg);
        }

        // Check if an emergency occurred on a given day
        bool wasEmergency(DayNumber day) {
            if (readings.find(day) != readings.end()) {
                return readings[day].second;
            }
            return false;
        }

        // Get Temps for all days with an emergency
        vector<Temp> getTemps() {
            vector<Temp> temps;
            for (auto i : readings) {
                if (i.second.second) {
                    temps.push_back(i.second.first);
                }
            }
            return temps;
        }

        // Get the number of emergencies recorded so far
        int numberOfEmergencies() {
            int count = 0;
            for (auto it : readings) {
                if (it.second.second) {
                    count++;
                }
            }
            return count;
        }

    private:
        map<DayNumber, pair<Temp, Emergency>> readings;
};

int main() {
    // Create a BlastFurnaceMonitor object
    FurnaceMonitor monitor;

    // Variables
    double temp;
    bool emg;
    // Add readings for 30 consecutive days
    for (int day = 1; day <= 30; day++) {
        cout << "Enter maximum Temp for day " << day << ": ";
        cin >> temp;
        cout << "Was there an emergency on day " << day << "? (1 for yes, 0 for no): ";
        cin >> emg;
        monitor.addReading(day, temp, emg);
    }

    // Get the number of emergencies recorded
    int num_emergencies = monitor.numberOfEmergencies();
    cout << "Number of emergencies: " << num_emergencies << endl;

    // Get Temps for all days with an emergency
    vector<double> emg_temps = monitor.getTemps();
    cout << "Temps for all days with an emergency: ";
    for (auto temp : emg_temps) {
        cout << temp << " ";
    }
    cout << endl;

    // Check if an emergency occurred on a specific day
    int day_num;
    cout << "Enter a day number to check if an emergency occurred: ";
    cin >> day_num;
    if (monitor.wasEmergency(day_num)) {
        cout << "An emergency occurred on day " << day_num << endl;
    } else {
        cout << "No emergency occurred on day " << day_num << endl;
    }

    return 0;
}
