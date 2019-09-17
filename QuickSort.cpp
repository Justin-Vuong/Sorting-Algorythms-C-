#include <cstdlib>
#include <iostream>

using namespace std;

void quickSort (int*, int);
void quickSort (int*, int, int);

int main() {
  int numItems;
  int* test;
  cout << "Enter number of elements: ";
  cin >> numItems;
    /* populate array with random integers */
  test = new int[numItems];

  for (int i = 0; i < numItems; i++){
    test[i] = (int)(rand()%100);
  }
  cout << "Unsorted:";

  for(int g = 0; g < numItems; g++){
    cout << test[g] << " ";
  }
  
  quickSort(test, numItems);

  cout << endl << "Sorted:";

  for(int g = 0; g < numItems; g++){
    cout << test[g] << " ";
  }
  
}


void quickSort (int* list, int length) {
 quickSort(list, 0, length - 1);
}

void quickSort (int* list, int low, int high) {
 const int MOVING_LEFT = 0;
 const int MOVING_RIGHT = 1;

 if (low < high) {
  int left = low;
  int right = high;
  int currentDirection = MOVING_LEFT;
  int pivot = list[low];

 while (left < right) {
    if (currentDirection == MOVING_LEFT) {
     while ((list[right] >= pivot) && (left < right))
       right--;

     list[left] = list[right];
     currentDirection = MOVING_RIGHT;
    }
 
   if (currentDirection == MOVING_RIGHT) {
      while ((list[left] <= pivot) && (left < right))
      left++;
      list[right] = list[left];
      currentDirection = MOVING_LEFT;
    }
 }
 
 list[left] = pivot; // or list[right] = pivot, since left == right
 quickSort(list, low, left-1);
 quickSort(list, right+1, high);
 }
 }