#include <iostream>
#include <vector>
using namespace std;

struct Process{
    int id, at, bt, wt, tat;
};

int main() {
    int n;
    cin >> n;

    vector<Process> p(n);

    for(int i=0; i<n; i++){
        p[i].id = i+1;

        cout<<"AT and BT for P"<<i+1<<": ";
        cin>>p[i].at>>p[i].bt;
    }

    int currentTime = 0;
    int completed = 0;
    vector<int> done(n,0);

    while(completed < n){

        int idx = -1;
        int minBT = 9999;

        for(int i=0; i<n; i++){

            if(!done[i] &&
               p[i].at <= currentTime &&
               p[i].bt < minBT){

                minBT = p[i].bt;
                idx = i;
            }
        }

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

    cout<<"\nP\tAT\tBT\tWT\tTAT\n";

    for(auto x : p){
        cout<<"P"<<x.id<<"\t"
            <<x.at<<"\t"
            <<x.bt<<"\t"
            <<x.wt<<"\t"
            <<x.tat<<endl;
    }
}