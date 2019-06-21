#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INF 1024478854
using namespace std;

int transformation(vector<int> A, vector<int> B) {
    
  int ans = 0;
  unordered_map<int, int> cA, cB, rank;

  // Create hashmap from 2 input arrays
  for (int i = 0; i < A.size(); i++) cA[A[i]] = i;
  for (int i = 0; i < B.size(); i++) cB[B[i]] = i;

  // Create 2 vectors, a and b, 
  // a and b are the common elements among A and B (maintaining the relative order)
  // Increment ans for extra elements in A and B (Addition and deletion operation)
  vector<int> a, b;
  for (int i = 0; i < A.size(); i++) {
    if (cB.find(A[i]) != cB.end()) {
      a.push_back(A[i]);
      cB.erase(A[i]);
    } else
      ans++;
  }
  for (int i = 0; i < B.size(); i++) {
    if (cA.find(B[i]) != cA.end()) {
      b.push_back(B[i]);
      cA.erase(B[i]);
    } else
      ans++;
  }

  // Minimum number of moves required to convert a to b.
  // Approach: We use the technique of Longest Increasing Subsequence method on vector a. 
  // We compare on the basis of rank of vector b.
  for (int i = 0; i < b.size(); i++) rank[b[i]] = i;

  vector<int> d(b.size() + 1, INF);
  d[0] = -INF;
  for (int i = 0; i < b.size(); i++) {
    int j = upper_bound(d.begin(), d.end(), rank[a[i]]) - d.begin();
    if (d[j - 1] < rank[a[i]] && rank[a[i]] < d[j]) d[j] = rank[a[i]];
  }
  int len = 0;
  for (int i = 0; i <= b.size(); i++)
    if (d[i] < INF) len = i;

  cout << ans + b.size() - len << endl;

  return 0;
}

int main() {
    int n, m;
    cin >> n >> m ;
    vector<int> l1(n), l2(m);
    
   // cout << m << n << endl;
    for(int i=0; i<n; i++){
       
        cin>>l1[i];
        
    }
    
    for(int i=0; i<m; i++){
        
        cin>>l2[i];
      
    }
    
    transformation(l1, l2);
    
    return 0;
}