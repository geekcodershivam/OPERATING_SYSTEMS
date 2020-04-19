#include<iostream> 
using namespace std; 
void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum){ 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 
	int t = 0; // Current time 
	while (1){ 
		bool done = true; 
		for (int i = 0 ; i < n; i++) { 
			if (rem_bt[i] > 0){ 
				done = false;
				if (rem_bt[i] > quantum) { 
					t += quantum; rem_bt[i] -= quantum; 
				} 
				else{ 
					t = t + rem_bt[i]; wt[i] = t - bt[i]; rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
} 
void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[]) { 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 
void findavgTime(int processes[], int n, int bt[],int quantum){ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	findWaitingTime(processes, n, bt, wt, quantum); 
	findTurnAroundTime(processes, n, bt, wt, tat); 
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 
	for (int i=0; i<n; i++) { 
		total_wt = total_wt + wt[i]; total_tat = total_tat + tat[i]; 
		cout << " " << i+1 << "\t\t\t  " << bt[i] <<"\t\t\t "<< wt[i] <<"\t\t\t" << tat[i] <<endl; 
	} 
	cout << "Average waiting time = " << (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)n; 
} 

int main(){ 
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

	// Time quantum 
	int quantum; cin>>quantum; 
	findavgTime(processes, sizeofprocess, burst_time, quantum); 
	return 0; 
} 
