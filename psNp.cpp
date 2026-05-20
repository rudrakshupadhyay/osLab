#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process{
    int id, at, bt, pr, wt, tat;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i=0; i<n; i++){
        p[i].id = i+1;

        cout << "Enter AT, BT and Priority for P"
             << i+1 << ": ";

        cin >> p[i].at >> p[i].bt >> p[i].pr;
    }

    vector<int> done(n,0);

    int currentTime = 0;
    int completed = 0;

    while(completed < n){

        int idx = -1;
        int highestPriority = INT_MAX;

        // Find highest priority process
        for(int i=0; i<n; i++){

            if(!done[i] &&
               p[i].at <= currentTime &&
               p[i].pr < highestPriority){

                highestPriority = p[i].pr;
                idx = i;
            }
        }

        // No process arrived yet
        if(idx == -1){
            currentTime++;
            continue;
        }

        p[idx].wt = currentTime - p[idx].at;

        currentTime += p[idx].bt;

        p[idx].tat = p[idx].wt + p[idx].bt;

        done[idx] = 1;
        completed++;
    }

    cout << "\nP\tAT\tBT\tPR\tWT\tTAT\n";

    for(int i=0; i<n; i++){
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].pr << "\t"
             << p[i].wt << "\t"
             << p[i].tat << endl;
    }

    return 0;
}