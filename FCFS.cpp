#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    // {Arrival Time, Burst Time, Process ID}
    vector<pair<pair<int,int>,int>> p;

    for(int i = 0; i < n; i++) {
        int at, bt;

        cout << "Enter Arrival Time and Burst Time for P" 
             << i+1 << ": ";

        cin >> at >> bt;

        p.push_back({{at, bt}, i+1});
    }

    // Sort according to arrival time
    sort(p.begin(), p.end());

    vector<int> wt(n), tat(n);

    int currentTime = 0;

    for(int i = 0; i < n; i++) {

        int at = p[i].first.first;
        int bt = p[i].first.second;

        if(currentTime < at)
            currentTime = at;

        wt[i] = currentTime - at;

        currentTime += bt;

        tat[i] = wt[i] + bt;
    }

    cout << "\nProcess\tAT\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].second << "\t"
             << p[i].first.first << "\t"
             << p[i].first.second << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}