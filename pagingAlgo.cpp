#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printMemory(vector<int> memory,int frames){

    for(int i=0;i<frames;i++){

        if(i<memory.size())
            cout<<memory[i]<<"\t";
        else
            cout<<"_\t";
    }

    cout<<endl;
}

void fifo(vector<int> pages, int frames) {

    vector<int> memory;
    int faults = 0;
    int index = 0;

    cout<<"\nFrames State:\n";

    for(int page : pages){

        if(find(memory.begin(), memory.end(), page) == memory.end()){

            faults++;

            if(memory.size() < frames)
                memory.push_back(page);

            else{
                memory[index] = page;
                index = (index + 1) % frames;
            }
        }

        printMemory(memory,frames);
    }

    cout<<"Page Faults = "<<faults<<endl;
}

void optimal(vector<int> pages, int frames){

    vector<int> memory;
    int faults=0;

    cout<<"\nFrames State:\n";

    for(int i=0;i<pages.size();i++){

        int page=pages[i];

        if(find(memory.begin(),memory.end(),page)==memory.end()){

            faults++;

            if(memory.size()<frames)
                memory.push_back(page);

            else{

                int replace=-1;
                int farthest=-1;

                for(int j=0;j<frames;j++){

                    int nextUse=9999;

                    for(int k=i+1;k<pages.size();k++){

                        if(memory[j]==pages[k]){
                            nextUse=k;
                            break;
                        }
                    }

                    if(nextUse>farthest){
                        farthest=nextUse;
                        replace=j;
                    }
                }

                memory[replace]=page;
            }
        }

        printMemory(memory,frames);
    }

    cout<<"Page Faults = "<<faults<<endl;
}

void lru(vector<int> pages, int frames){

    vector<int> memory;
    int faults=0;

    cout<<"\nFrames State:\n";

    for(int i=0;i<pages.size();i++){

        int page=pages[i];

        if(find(memory.begin(),memory.end(),page)==memory.end()){

            faults++;

            if(memory.size()<frames)
                memory.push_back(page);

            else{

                int replace=-1;
                int least=9999;

                for(int j=0;j<frames;j++){

                    int lastUse=-1;

                    for(int k=i-1;k>=0;k--){

                        if(memory[j]==pages[k]){
                            lastUse=k;
                            break;
                        }
                    }

                    if(lastUse<least){
                        least=lastUse;
                        replace=j;
                    }
                }

                memory[replace]=page;
            }
        }

        printMemory(memory,frames);
    }

    cout<<"Page Faults = "<<faults<<endl;
}

void mru(vector<int> pages, int frames){

    vector<int> memory;
    int faults=0;

    cout<<"\nFrames State:\n";

    for(int i=0;i<pages.size();i++){

        int page=pages[i];

        if(find(memory.begin(),memory.end(),page)==memory.end()){

            faults++;

            if(memory.size()<frames)
                memory.push_back(page);

            else{

                int replace=-1;
                int recent=-1;

                for(int j=0;j<frames;j++){

                    int lastUse=-1;

                    for(int k=i-1;k>=0;k--){

                        if(memory[j]==pages[k]){
                            lastUse=k;
                            break;
                        }
                    }

                    if(lastUse>recent){
                        recent=lastUse;
                        replace=j;
                    }
                }

                memory[replace]=page;
            }
        }

        printMemory(memory,frames);
    }

    cout<<"Page Faults = "<<faults<<endl;
}

int main(){

    int n,frames,choice;

    cout<<"Enter number of pages: ";
    cin>>n;

    vector<int> pages(n);

    cout<<"Enter page reference string: ";

    for(int i=0;i<n;i++)
        cin>>pages[i];

    cout<<"Enter number of frames: ";
    cin>>frames;

    do{

        cout<<"\n------MENU------\n";
        cout<<"1. FIFO\n";
        cout<<"2. Optimal\n";
        cout<<"3. LRU\n";
        cout<<"4. MRU\n";
        cout<<"5. Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                fifo(pages,frames);
                break;

            case 2:
                optimal(pages,frames);
                break;

            case 3:
                lru(pages,frames);
                break;

            case 4:
                mru(pages,frames);
                break;

            case 5:
                cout<<"Program Ended";
                break;

            default:
                cout<<"Invalid Choice";
        }

    }while(choice!=5);

    return 0;
}