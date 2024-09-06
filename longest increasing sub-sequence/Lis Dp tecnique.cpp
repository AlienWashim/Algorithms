#include <iostream>
using namespace std;

int longestSubSeq(int subArr[], int n) {
   int length[n] = { 0 };
   length[0] = 1;

   for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
         if (subArr[j] < subArr[i] && length[j] > length[i])
            length[i] = length[j];
      }
      length[i]++;
   }
   int lis = 0;
   for (int i = 0; i<n; i++)
      lis = max(lis, length[i]);
   return lis;
}
int main() {
    int arr[100],p,n;
    cin>>p;
    for(int i=1; i<=p; i++)
    {
        cin>>arr[i];
    }

   //int arr[] =  {9, 2, 5, 3, 7, 11, 8, 10, 13, 6 };
   cin>>n;
   cout << "Length of Longest Increasing Subsequence is: " << longestSubSeq(arr, n);
   return 0;
}
