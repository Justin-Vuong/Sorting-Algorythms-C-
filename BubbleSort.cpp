#include <iostream>
using namespace std;

void shakerSort(int[], int);

int main() {
  int arr[7] = {2,9,4,6,1,7,4};
  shakerSort(arr, 7);
  
}

void shakerSort(int arr[], int length) {
 int upper = length-1, lower = 0, pass = 0;
 bool sorted = false;
 
 while (upper != lower){
 if(pass % 2 == 0){
  cout << "Even Pass " << endl;
 for (int j = 0; j < upper; j++) {
  if (arr[j] > arr[j+1]) {
 int temp = arr[j];
 arr[j] = arr[j+1];
 arr[j+1] = temp;
 }
 for (int y = 0; y < length; y++)
  cout << arr[y] << " ";
  cout << endl;
 }
 
 pass++;
 upper--;
 cout << endl;
 
 } else {
   cout << "Odd Pass" << endl;
  for (int j = upper; j > lower; j--) {
  //cout << arr[j] << " < " << arr[j-1] << " " << (arr[j] < arr[j-1]);
  if (arr[j] < arr[j-1]) {
 int temp = arr[j];
 arr[j] = arr[j-1];
 arr[j-1] = temp;
 }
 for (int y = 0; y < length; y++)
  cout << arr[y] << " ";
  cout << endl;
 }
 
 pass++;
 lower++;
 cout << endl;
   
 }
}
}