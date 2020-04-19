// C++ implementation of FIFO page replacement 
#include<bits/stdc++.h> 
using namespace std; 
int pageFaults(int pages[], int n, int capacity){  
	unordered_set<int> s; queue<int> indexes; int page_faults = 0; 
	for (int i=0; i<n; i++){ 
		if (s.size() < capacity) { 
			if (s.find(pages[i])==s.end()) 
			{ 
				s.insert(pages[i]);  page_faults++; indexes.push(pages[i]); 
			} 
		} 
		else{ 
			if (s.find(pages[i]) == s.end()) { 
				int val = indexes.front(); indexes.pop(); s.erase(val); indexes.push(pages[i]); page_faults++; 
			} 
		} 
	} 
	return page_faults; 
} 
int main() 
{   int n; cin>>n;
	int pages[n];
	int capacity; cin>>capacity; 
	cout << pageFaults(pages, n, capacity); 
	return 0; 
} 
