#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n,m;

    cout<<"Enter number of processes: ";
    cin>>n;

    cout<<"Enter number of resources: ";
    cin>>m;

    vector<vector<int> > alloc(n,vector<int>(m));
    vector<vector<int> > maxNeed(n,vector<int>(m));
    vector<vector<int> > need(n,vector<int>(m));

    vector<int> avail(m);

    cout<<"\nEnter Allocation Matrix:\n";

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cin>>alloc[i][j];
        }
    }

    cout<<"\nEnter Max Matrix:\n";

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cin>>maxNeed[i][j];
        }
    }

    cout<<"\nEnter Available Resources:\n";

    for(int i=0;i<m;i++)
        cin>>avail[i];


    // Need = Max - Allocation

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            need[i][j]=maxNeed[i][j]-alloc[i][j];
        }
    }

    vector<int> finish(n,0);
    vector<int> safeSequence;

    int completed=0;

    while(completed<n){

        bool found=false;

        for(int i=0;i<n;i++){

            if(!finish[i]){

                bool possible=true;

                for(int j=0;j<m;j++){

                    if(need[i][j]>avail[j]){

                        possible=false;
                        break;
                    }
                }

                if(possible){

                    for(int j=0;j<m;j++)
                        avail[j]+=alloc[i][j];

                    finish[i]=1;

                    safeSequence.push_back(i);

                    completed++;

                    found=true;
                }
            }
        }

        if(!found)
            break;
    }

    if(completed==n){

        cout<<"\nSystem is in Safe State\n";

        cout<<"Safe Sequence: ";

        for(int x:safeSequence)
            cout<<"P"<<x<<" ";
    }

    else{

        cout<<"\nSystem is NOT in Safe State";
    }

    return 0;
}