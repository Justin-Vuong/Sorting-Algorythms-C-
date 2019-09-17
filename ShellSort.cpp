#include <iostream>
#include <math.h>
#include <cstdlib>
#include <sys/timeb.h>
using namespace std;

void kSortSublist(int*, int, int, int);
void shellSort(int*, int);
int getMilliCount();
int getMilliSpan(int);

int main() {
  /*
5 SORTED
  19             26            47      
     18             37            61   
        21             26            72   
           22             41            55 
              29             63  
  
  Therefore: 19 18 21 22 29 26 37 26 41 63 47 61 72 55
  
4 SORTED
  22          26          55          63  
     19          22          29          37 
        21          47          61     
           18          41          72  

Therefore : 22 19 21 18 26 22 47 41 55 29 61 72 63 37
  */
  
  bool isDone = false;
    int n = 0;
  do{
    cout << "What is your value of n? (Must be positive integer) ";

  cin >> n;
  
  if(n > 0){
    isDone = true;
  } else {
    cout << "Invalid input please try again" << endl;
  }
  
  } while(isDone == false);
  int k = (pow(3,(ceil(log(2*n+1)/log(3.0))-1)) - 1)/2;
  cout << "\nThe value of k for an array of size " << n << " is: " << k;
  
  isDone = false;
  do{
  cout << "\n\nWhat is your value of k? (Must be integer greater than 0) ";
  n = 0;
  cin >> n;
  
  if(n > 0){
    isDone = true;
  } else {
    cout << "Invalid input please try again" << endl;
  }
  
  } while(isDone == false);
  
  
  cout << "If the value of k is " << n << ", then the previous value of k is " << (n-1)/3 << endl;

  srand((unsigned)time(0));
  int* sort = new int[500];
  
  
  for(int x = 0; x < 500; x++){
    sort[x] = rand()%1000;
    if (x%10 == 9)
      cout << sort[x] << endl;
    else
      cout << sort[x] << " ";
  }
  
  int begin = getMilliCount();
  cout << endl << "Sorted array is " << endl;

shellSort(sort,500);
int elapsed = getMilliSpan(begin);
  
  for(int x = 0; x < 500; x++){
    if (x%10 == 9)
      cout << sort[x] << endl;
    else
      cout << sort[x] << " ";
  }

cout << "That took " << elapsed << "milliseconds" << endl;

int inputK = 0, inputStep = 0, sizeArr = 0;
bool validInput = false;
while(validInput == false){
  
  cout << "\nHow many values in your array (must be an integer greater then 0): ";
cin >> sizeArr;
  
cout << "\nNow enter a value for k (Must be an integer greater than 0): ";
cin >> inputK;

cout << "Now enter a step for k (must be an integer greater then 0): ";
cin >> inputStep;

if(inputStep <= 0 || inputK <= 0 || sizeArr < 0){
  cout << "invalid input, please try again." << endl;
} else{
  validInput = true;
}
}

cout << "Here is your array: " << endl;
for(int x = 0; x < sizeArr; x++){
    sort[x] = rand()%1000;
    if (x%10 == 9)
      cout << sort[x] << endl;
    else
      cout << sort[x] << " ";
  }

begin = getMilliCount();

inputK += inputStep;

do{
  inputK-= inputStep;
  
  if(inputK <= 0){
    inputK = 1;
  }
  
  for(int j = 0; j < k; j++){
 kSortSublist(sort,inputK,j, sizeArr); 
 }
  
  
} while (inputK>1);
elapsed = getMilliSpan(begin);

cout << "\nHere is your sorted array" <<endl;
for(int x = 0; x < sizeArr; x++){
    if (x%10 == 9)
      cout << sort[x] << endl;
    else
      cout << sort[x] << " ";
  }

cout << "\nThat took "<< elapsed << " milliseconds!";
}

void shellSort(int *arr, int length){

  int kSort = (pow(3,(ceil(log(2*(500+1))/log(3.0))-1)) - 1)/2;

  
  for (int k = kSort; k >=1; k = (k-1)/3){
   for(int a = 0; a < k; a++){
     kSortSublist(arr,k,a,length);
  }
    
  }
  
}

void kSortSublist(int *arr, int k, int start, int length){
  for (int top = start + k; top < length; top = top + k){
    int item = arr[top]; //temporary store for current item
    int i = top;
    while (i > start && item < arr[i-k]){
      // shift larger items to the right by k
      arr[i] = arr[i-k];
      // prepare to check the next item, k spaces left
      i = i - k;
    }
    arr[i] = item; // put sorted item in open location
  }
}


int getMilliCount(){
  timeb tb;
  ftime(&tb);
 int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
 return nCount;
}

int getMilliSpan(int nTimeStart){
 int nSpan = getMilliCount() - nTimeStart;
 if(nSpan < 0)
    nSpan += 0x100000 * 1000;
 return nSpan;
}
