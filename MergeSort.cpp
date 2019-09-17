#include <iostream>
#include <cstdlib>

using namespace std;

void merge  (int*, int, int, int);
void mergesort (int*, int,int);

int main() {
  srand((unsigned)time(0));
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

  mergesort(test,0,numItems-1);
  cout << endl << "Sorted:";

  for(int g = 0; g < numItems; g++){
    cout << test[g] << " ";
  }
  
}

 void merge(int* items, int start, int mid, int end) {
  int* temp = new int[sizeof(items)/sizeof(items[0])];
  int pos1 = start;
  int pos2 = mid + 1;
  int spot = start;

  while (!(pos1 > mid && pos2 > end)) {
    if ((pos1 > mid) || ((pos2 <= end) && (items[pos2] < items[pos1]))) {
    temp[spot] = items[pos2];
    pos2 += 1;
  } else {
    temp[spot] = items[pos1];
    pos1 += 1;
  }
    spot += 1;
  }
/* copy values from temp back to items */
  for (int i = start; i <= end; i++) {
    items[i] = temp[i];
  }
}


void mergesort(int* items, int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergesort(items, start, mid);
    mergesort(items, mid + 1, end);
    merge(items, start, mid, end);
  }
}