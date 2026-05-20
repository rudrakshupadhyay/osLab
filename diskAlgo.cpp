#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void printResult(vector<int> order,int total){

    cout<<"\nSeek Sequence: ";

    for(int x:order)
        cout<<x<<" ";

    cout<<"\nTotal Seek Time = "<<total<<endl;
}


void fcfs(vector<int> req,int head){

    vector<int> order;
    int total=0;

    for(int x:req){

        total+=abs(head-x);
        head=x;

        order.push_back(x);
    }

    printResult(order,total);
}


void sstf(vector<int> req,int head){

    vector<int> order;
    int total=0;

    while(!req.empty()){

        int idx=0;
        int mn=abs(head-req[0]);

        for(int i=1;i<req.size();i++){

            if(abs(head-req[i])<mn){

                mn=abs(head-req[i]);
                idx=i;
            }
        }

        total+=abs(head-req[idx]);

        head=req[idx];

        order.push_back(head);

        req.erase(req.begin()+idx);
    }

    printResult(order,total);
}


void scan(vector<int> req,int head,int maxCylinder,int dir){

    vector<int> left,right,order;
    int total=0;

    for(int x:req){

        if(x<head)
            left.push_back(x);
        else
            right.push_back(x);
    }

    // CHANGED HERE
    if(dir==0)
        left.push_back(0);
    else
        right.push_back(maxCylinder-1);

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    if(dir==0){

        for(int i=left.size()-1;i>=0;i--){

            total+=abs(head-left[i]);
            head=left[i];

            order.push_back(head);
        }

        for(int i=0;i<right.size();i++){

            total+=abs(head-right[i]);
            head=right[i];

            order.push_back(head);
        }
    }
    else{

        for(int i=0;i<right.size();i++){

            total+=abs(head-right[i]);
            head=right[i];

            order.push_back(head);
        }

        for(int i=left.size()-1;i>=0;i--){

            total+=abs(head-left[i]);
            head=left[i];

            order.push_back(head);
        }
    }

    printResult(order,total);
}


void cscan(vector<int> req,int head,int maxCylinder,int dir){

    vector<int> left,right,order;
    int total=0;

    for(int x:req){

        if(x<head)
            left.push_back(x);
        else
            right.push_back(x);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    if(dir==1){

        right.push_back(maxCylinder-1);

        for(int x:right){

            total+=abs(head-x);
            head=x;

            order.push_back(head);
        }

        // CHANGED HERE
        total += abs(head-0);

        head=0;

        order.push_back(0);

        for(int x:left){

            total+=abs(head-x);
            head=x;

            order.push_back(head);
        }
    }

    else{

        left.push_back(0);

        sort(left.begin(),left.end());

        for(int i=left.size()-1;i>=0;i--){

            total+=abs(head-left[i]);
            head=left[i];

            order.push_back(head);
        }

        // CHANGED HERE
        total += abs(head-(maxCylinder-1));

        head=maxCylinder-1;

        order.push_back(maxCylinder-1);

        for(int i=right.size()-1;i>=0;i--){

            total+=abs(head-right[i]);
            head=right[i];

            order.push_back(head);
        }
    }

    printResult(order,total);
}


void look(vector<int> req,int head,int dir){

    vector<int> left,right,order;
    int total=0;

    for(int x:req){

        if(x<head)
            left.push_back(x);
        else
            right.push_back(x);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    if(dir==0){

        for(int i=left.size()-1;i>=0;i--){

            total+=abs(head-left[i]);
            head=left[i];

            order.push_back(head);
        }

        for(int x:right){

            total+=abs(head-x);
            head=x;

            order.push_back(head);
        }
    }

    else{

        for(int x:right){

            total+=abs(head-x);
            head=x;

            order.push_back(head);
        }

        for(int i=left.size()-1;i>=0;i--){

            total+=abs(head-left[i]);
            head=left[i];

            order.push_back(head);
        }
    }

    printResult(order,total);
}


void clook(vector<int> req,int head,int dir){

    vector<int> left,right,order;
    int total=0;

    for(int x:req){

        if(x<head)
            left.push_back(x);
        else
            right.push_back(x);
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    if(dir==1){

        for(int x:right){

            total+=abs(head-x);
            head=x;

            order.push_back(head);
        }

        // CHANGED HERE
        if(!left.empty()){

            total+=abs(head-left[0]);

            head=left[0];

            order.push_back(head);
        }

        for(int x:left){

            total+=abs(head-x);
            head=x;

            order.push_back(head);
        }
    }

    else{

        for(int i=left.size()-1;i>=0;i--){

            total+=abs(head-left[i]);
            head=left[i];

            order.push_back(head);
        }

        // CHANGED HERE
        if(!right.empty()){

            total+=abs(head-right.back());

            head=right.back();

            order.push_back(head);
        }

        for(int i=right.size()-1;i>=0;i--){

            total+=abs(head-right[i]);
            head=right[i];

            order.push_back(head);
        }
    }

    printResult(order,total);
}


int main(){

    int n,head,maxCylinder,dir,choice;

    cout<<"Enter number of requests: ";
    cin>>n;

    vector<int> req(n);

    cout<<"Enter requests: ";

    for(int i=0;i<n;i++)
        cin>>req[i];

    cout<<"Enter head position: ";
    cin>>head;

    cout<<"Enter maximum cylinder: ";
    cin>>maxCylinder;

    cout<<"Direction (0=Left,1=Right): ";
    cin>>dir;

    do{

        cout<<"\n-----MENU-----\n";
        cout<<"1.FCFS\n";
        cout<<"2.SSTF\n";
        cout<<"3.SCAN\n";
        cout<<"4.C-SCAN\n";
        cout<<"5.LOOK\n";
        cout<<"6.C-LOOK\n";
        cout<<"7.Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){

            case 1: fcfs(req,head); break;
            case 2: sstf(req,head); break;
            case 3: scan(req,head,maxCylinder,dir); break;
            case 4: cscan(req,head,maxCylinder,dir); break;
            case 5: look(req,head,dir); break;
            case 6: clook(req,head,dir); break;
            case 7: break;

            default:
                cout<<"Invalid Choice";
        }

    }while(choice!=7);

    return 0;
}