#include<iostream> 
using namespace std; 
void findWaitingTime(int processes[], int n,  
                          int bt[], int wt[]) 
{ 
    wt[0] = 0; 
    for (int  i = 1; i < n ; i++ ) 
        wt[i] =  bt[i-1] + wt[i-1] ; 
} 
void findTurnAroundTime( int processes[], int n,  
                  int bt[], int wt[], int tat[]) 
{ 
    for (int  i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
void findavgTime( int processes[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
    findWaitingTime(processes, n, bt, wt); 
    findTurnAroundTime(processes, n, bt, wt, tat); 
    cout << "Processes  "<< " Burst time  "
         << " Waiting time  " << " Turn around time\n"; 
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t\t" << bt[i] <<"\t\t\t"
            << wt[i] <<"\t\t\t\t" << tat[i] <<endl; 
    } 
    cout << "Average waiting time = " 
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " 
         << (float)total_tat / (float)n; 
} 
int main() 
{ 
    //process id's 
    int sizeofprocess;
    cin>>sizeofprocess;
    
    int processes[sizeofprocess];
    
    for(int i=0; i<sizeofprocess; i++){
     cin>>processes[i];
    }
    //Burst time of all processes 
    int burst_time_size;
    cin>>burst_time_size;
    
    int  burst_time[burst_time_size];
  
   for(int i=0; i<burst_time_size; i++){
     cin>>burst_time[i];
    }
    
    findavgTime(processes, sizeofprocess,  burst_time); 
    return 0; 
} 