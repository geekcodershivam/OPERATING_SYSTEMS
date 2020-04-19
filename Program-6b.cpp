// C++ implementation of Best - Fit algorithm 
#include<bits/stdc++.h> 
using namespace std; 
void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
	int allocation[n]; 
	memset(allocation, -1, sizeof(allocation)); 
	for (int i=0; i<n; i++) 
	{ 
		int bestIdx = -1; 
		for (int j=0; j<m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				if (bestIdx == -1) 
					bestIdx = j; 
				else if (blockSize[bestIdx] > blockSize[j]) 
					bestIdx = j; 
			} 
		} 
		if (bestIdx != -1) 
		{ 
			// allocate block j to p[i] process 
			allocation[i] = bestIdx; 

			// Reduce available memory in this block. 
			blockSize[bestIdx] -= processSize[i]; 
		} 
	} 
	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t\t " << processSize[i] << "\t\t\t "; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

// Driver code 
int main() { 
    int m; cin>>m;
    int n; cin>>n;
	int blockSize[m];
	int processSize[n];
	for(int i=0; i<m; i++){
	    cin>>blockSize[i];
	}
	for(int i=0; i<n; i++){
	    cin>>processSize[i];
	}
	
cout << "Best-Fit"; 
	bestFit(blockSize, m, processSize, n); 

	return 0 ; 
} 
