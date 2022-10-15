#include<bits/stdc++.h>
using namespace std;
int search(int arr[],int n,int x);
    for (int i = 0; i < n; i++)
           {
        if (arr[i] == x)
            return i;
           }
    return -1;
           }
int main()
{
  int arr[] = { 4,6,2 7,8,5 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    int result = search(arr, n, x);
    if(result == -1)
      cout << "Element is not present in array"<<endl;
  else
      cout << "Element is present at index " << result;
    return 0;
}
