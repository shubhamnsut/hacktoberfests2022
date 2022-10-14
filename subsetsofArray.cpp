#include <bits/stdc++.h>
using namespace std;
void help(int input[],int startindex,int s,int output[],int m)
{
    //if all the elemts have been included 
    if(startindex==s)
    {
        //output array is filled we just need to print it's each element
        for(int i=0;i<m;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    int helpo[1000];
    int helps=0;
    help(input,startindex+1,s,output,m);
    int i;
    for( i=0;i<m;i++)
    {
        helpo[i]=output[i];
    }
    helpo[i]=input[startindex];
    help(input,startindex+1,s,helpo,m+1);
}
void printSubsetsOfArray(int input[], int size) {

    int output[1001];
    int m=0;
    help(input,0,size,output,m);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
