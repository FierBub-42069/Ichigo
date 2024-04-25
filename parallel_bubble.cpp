#include<omp.h>
#include<iostream>
#include<time.h>
using namespace std;

int main() {
  int n, var = 0;
  cout<<"Enter no. of elements:\t";
  cin>>n;
  int array[n] = {0};

  for(int i=0; i<n; i++) {
    int r = rand();
    array[i] = r%32;
  }

  cout<<"\nOriginal array:\t";
  for(int i=0; i<n; i++)
    cout<<array[i]<<" ";
  cout<<endl;

  clock_t start = clock();
  
  for(int i=0; i<n; i++) {
    #pragma omp parallel for
    for(int j=var; j<n-1; j+=2) {
      if(array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
    if(var == 0)
      var = 1;
    else
      var = 0;
  }

  clock_t stop = clock();

  cout<<"\nFinal array:\t";
  for(int i=0; i<n; i++)
    cout<<array[i]<<" ";
  cout<<endl;

  cout<<"\nTime Required:\t"<<(double)(stop-start)<<" ms\n";
  return 0;
}