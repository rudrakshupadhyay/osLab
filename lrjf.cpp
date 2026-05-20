// SRTF code + max instead of min = LRTF
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process{
    int id, at, bt, rt, wt, tat;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i=0; i<n; i++) {
        p[i].id = i+1;

        cout << "Enter AT and BT for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;

        p[i].rt = p[i].bt; // Remaining Time = Burst Time initially
    }

    int currentTime = 0;
    int completed = 0;

    while(completed < n) {

        int idx = -1;
        int maxRT = INT_MIN;

        // Find process with maximum remaining time
        for(int i=0; i<n; i++) {

            if(p[i].at <= currentTime &&
               p[i].rt > 0 &&
               p[i].rt > maxRT) {

                maxRT = p[i].rt;
                idx = i;
            }
        }

        // No process available
        if(idx == -1) {
            currentTime++;
            continue;
        }

        // Execute for 1 unit
        p[idx].rt--;
        currentTime++;

        // Process completed
        if(p[idx].rt == 0) {

            completed++;

            p[idx].tat = currentTime - p[idx].at;

            p[idx].wt = p[idx].tat - p[idx].bt;
        }
    }

    cout << "\nP\tAT\tBT\tWT\tTAT\n";

    for(int i=0; i<n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].wt << "\t"
             << p[i].tat << endl;
    }

    return 0;
}