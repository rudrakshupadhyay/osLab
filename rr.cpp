#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Process{
    int id, at, bt, rt, wt, tat;
};

int main() {
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i=0; i<n; i++){
        p[i].id = i+1;

        cout << "Enter AT and BT for P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;

        p[i].rt = p[i].bt;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    queue<int> q;
    vector<int> visited(n,0);

    int currentTime = 0;
    int completed = 0;

    while(completed < n){

        // Add arrived processes
        for(int i=0; i<n; i++){
            if(p[i].at <= currentTime && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }

        if(q.empty()){
            currentTime++;
            continue;
        }

        int i = q.front();
        q.pop();

        // Execute process
        if(p[i].rt <= tq){

            currentTime += p[i].rt;
            p[i].rt = 0;

            completed++;

            p[i].tat = currentTime - p[i].at;
            p[i].wt = p[i].tat - p[i].bt;
        }
        else{

            currentTime += tq;
            p[i].rt -= tq;
        }

        // Add newly arrived processes
        for(int j=0; j<n; j++){
            if(p[j].at <= currentTime && !visited[j]){
                q.push(j);
                visited[j] = 1;
            }
        }

        // Put unfinished process back
        if(p[i].rt > 0)
            q.push(i);
    }

    cout << "\nP\tAT\tBT\tWT\tTAT\n";

    for(int i=0; i<n; i++){
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].wt << "\t"
             << p[i].tat << endl;
    }

    return 0;
}