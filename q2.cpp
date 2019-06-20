#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define INF 1024478854
using namespace std;

int transformation(vector<int> A, vector<int> B) {
//   vector<int> A = {4, 2, 42, 3, 5, 1};
//   vector<int> B = {43, 1, 2, 3, 4, 5};

  // vector<int> A = {1, 2, 7};
  // vector<int> B = {7, 2, 1};

  // vector<int> A = {0, 4, 7, 1, 2, 6, 3, 5};
  // vector<int> B = {0, 1, 2, 3, 4, 5, 6, 7};

  // vector<int> A = {3, 7, 9, 4};
  // vector<int> B = {4, 7, 1, 3};

  // vector<int> A = {1};
  // vector<int> B = {2, 3};

  // vector<int> A = {0, 4, 7, 6, 3, 5};
  // vector<int> B = {0, 1, 2, 7, 11, 4, 5};

//   vector<int> A = {0, 4, 7, 6, 3, 5, 45, 77, 55, 321, 781, 71};
//   vector<int> B = {0, 1, 2, 321, 55, 7, 11, 4, 5};
    
    // for (int i = 0; i < A.size(); i++){
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < B.size(); i++){
    //     cout << B[i] << " ";
    // }
    
    
  int ans = 0;
  unordered_map<int, int> cA, cB, rank;
  for (int i = 0; i < A.size(); i++) cA[A[i]] = i;
  for (int i = 0; i < B.size(); i++) cB[B[i]] = i;

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
    
    // for (int i = 0; i < l1.size(); i++){
    //     cout << l1[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < l2.size(); i++){
    //     cout << l2[i] << " ";
    // }
    
    
    transformation(l1, l2);
    
    return 0;
}