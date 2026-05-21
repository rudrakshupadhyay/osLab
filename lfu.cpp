#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void printMemory(vector<int> &memory,int frames){
    for(int i=0;i<frames;i++){
        if(i < memory.size())
            cout << memory[i] << "\t";
        else
            cout << "_\t";
    }
    cout << endl;
}

void lfu(vector<int> &pages,int frames){

    vector<int> memory;
    unordered_map<int,int> freq;

    int faults = 0;

    for(int page : pages){

        // Page hit
        if(find(memory.begin(),memory.end(),page) != memory.end()){
            freq[page]++;
        }

        // Page fault
        else{

            faults++;

            // Empty frame available
            if(memory.size() < frames){
                memory.push_back(page);
                freq[page]++;
            }

            // Replace LFU page
            else{

                int replace = 0;
                int leastFreq = freq[memory[0]];

                for(int i=1;i<frames;i++){

                    if(freq[memory[i]] < leastFreq){
                        leastFreq = freq[memory[i]];
                        replace = i;
                    }
                }

                memory[replace] = page;
                freq[page]++;
            }
        }

        printMemory(memory,frames);
    }

    cout << "\nTotal faults = " << faults << endl;
}

int main(){

    vector<int> pages={7,0,1,2,0,3,0,4,2,3,0,3,2};

    int frames=3;

    lfu(pages,frames);

    return 0;
}