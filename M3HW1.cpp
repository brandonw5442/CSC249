#include <iostream>
#include <string>
using namespace std;

string ArrayToString(int* array, int arraySize) {
   // Special case for empty array
   if (0 == arraySize) {
      return string("[]");
   }
   
   // Start the string with the opening '[' and element 0
   string result = "[" + to_string(array[0]);
   
   // For each remaining element, append comma, space, and element
   for (int i = 1; i < arraySize; i++) {
      result += ", ";
      result += to_string(array[i]);
   }
   
   // Add closing ']' and return result
   result += "]";
   return result;
}

int InsertionSortInterleaved(int* numbers, int numbersSize, int startIndex, int gap) {
   int swaps = 0;
   for (int i = startIndex + gap; i < numbersSize; i += gap) {
      int j = i;
      while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
         swaps++;
         // Swap numbers[j] and numbers [j - 1]
         int temp = numbers[j];
         numbers[j] = numbers[j - gap];
         numbers[j - gap] = temp;
         j -= gap;
      }
   }
   return swaps;
}
   
int ShellSort(int* numbers, int numbersSize, int* gapValues, int gapValuesSize) {
   int totalSwaps = 0;
   for (int g = 0; g < gapValuesSize; g++) {
      int swapsForGap = 0;
      for (int i = 0; i < gapValues[g]; i++) {
         swapsForGap += InsertionSortInterleaved(numbers, numbersSize, i, gapValues[g]);
      }
      cout << ArrayToString(numbers, numbersSize) << " (after " << swapsForGap;
      cout << " swap" << (swapsForGap == 1 ? "" : "s") << " with gap=";
      cout << gapValues[g] << ")" << endl;
      totalSwaps += swapsForGap;
   }
   return totalSwaps;
}
void Merge(int* numbers, int leftFirst, int leftLast, int rightLast) {
   int mergedSize = rightLast - leftFirst + 1;       // Size of merged partition
   int* mergedNumbers = new int[mergedSize];   // Dynamically allocates temporary
                                              // array for merged numbers
   int mergePos = 0;                         // Position to insert merged number
   int leftPos = leftFirst;                  // Initialize left partition position
   int rightPos = leftLast + 1;              // Initialize right partition position
      
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= leftLast && rightPos <= rightLast) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         leftPos++;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         rightPos++;
      }
      mergePos++;
   }
      
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= leftLast) {
      mergedNumbers[mergePos] = numbers[leftPos];
      leftPos++;
      mergePos++;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= rightLast) {
      mergedNumbers[mergePos] = numbers[rightPos];
      rightPos++;
      mergePos++;
   }
   
   // Copy merged numbers back to numbers
   for (mergePos = 0; mergePos < mergedSize; mergePos++) {
      numbers[leftFirst + mergePos] = mergedNumbers[mergePos];
   }
   
   // Free temporary array
   delete[] mergedNumbers;
}
   
void MergeSort(int* numbers, int startIndex, int endIndex) {
   
   if (startIndex < endIndex) {
      // Find the midpoint in the partition
      int mid = (startIndex + endIndex) / 2;

      // Recursively sort left and right partitions
      MergeSort(numbers, startIndex, mid);
      MergeSort(numbers, mid + 1, endIndex);
            
      // Merge left and right partition in sorted order
      Merge(numbers, startIndex, mid, endIndex);
   }
}

int main() {
   // Create an array of numbers to sort
   int numberSize = 0; 
   cout << "How many numbers would you like to enter " << endl; 
   cin >> numberSize; 
   int numbers[numberSize];
  int numbersCopy[numberSize];
   for (int i = 0; i < numberSize; ++i) {
     cout << "Input number " << (i + 1) << ": "; 
     cin >> numbers[i];
     cout << endl; 
   }
  for (int i = 0; i < numberSize; ++i) {
     numbersCopy[i] = numbers[i]; 
     cout << endl; 
   }
   int numbersSize = sizeof(numbers) / sizeof(numbers[0]);

  int input; 
  
  cout << "What type of sort would you like to use?" << endl; 
  cout << "1) Shell sort" << endl; 
  cout << "2) Merge sort" << endl; 
  cin >> input; 

    if (input == 1) {
     // Display the contents of the array
     cout << "---- Shell sort ----" << endl;
     cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;
        
     // Call the ShellSort function
     int gapValues[] = { 4, 2, 1 };
     int gapValuesSize = sizeof(gapValues) / sizeof(gapValues[0]);
     int totalSwaps = ShellSort(numbers, numbersSize, gapValues, gapValuesSize);
  
     // Display sorted array and the total number of swaps
     cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
     cout << "Total swaps: " << totalSwaps << endl;
        
     // Sort the same array with insertion sort
     cout << endl << "---- Regular insertion sort ----" << endl;
     cout << "UNSORTED: " << ArrayToString(numbersCopy, numbersSize) << endl;
     totalSwaps = InsertionSortInterleaved(numbersCopy, numbersSize, 0, 1);
     cout << "SORTED:   " << ArrayToString(numbersCopy, numbersSize) << endl;
     cout << "Total swaps: " << totalSwaps << endl;
    }
    else if (input == 2) {
      // Display the contents of the array
     cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;
        
     // Call the MergeSort function
     MergeSort(numbers, 0, numbersSize - 1);
        
     // Display the sorted contents of the array
     cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
  }
  else if (input == 3) {
    // Display the contents of the array
     cout << "---- Shell sort ----" << endl;
     cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;
        
     // Call the ShellSort function
     int gapValues[] = { 4, 2, 1 };
     int gapValuesSize = sizeof(gapValues) / sizeof(gapValues[0]);
     int totalSwaps = ShellSort(numbers, numbersSize, gapValues, gapValuesSize);
  
     // Display sorted array and the total number of swaps
     cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
     cout << "Total swaps: " << totalSwaps << endl;
        
     // Sort the same array with insertion sort
     cout << endl << "---- Regular insertion sort ----" << endl;
     cout << "UNSORTED: " << ArrayToString(numbersCopy, numbersSize) << endl;
     totalSwaps = InsertionSortInterleaved(numbersCopy, numbersSize, 0, 1);
     cout << "SORTED:   " << ArrayToString(numbersCopy, numbersSize) << endl;
     cout << "Total swaps: " << totalSwaps << endl;

     
    
  }
    
}
    

