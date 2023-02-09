#include <iostream>
#include <string>
using namespace std;

void InsertionSort(int* numbers, int numbersSize) {
   for (int i = 0; i < numbersSize; i++) {
      int j = i;
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         // Swap numbers[j] and numbers [j - 1]
         cout << "smallest: " << numbers[j] << " @ " << j << endl; 
         cout << "Current sort [" << numbers[0]; 
        for (int i = 1; i < numbersSize; i++) {
          cout << ", " << numbers[i]; 
        }
        cout << "]" << endl; 
         int temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         j--;
      }
   }
}

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
int main() {
  // Create an array of numbers to sort
   int i; 
   // Create an array of numbers to sort
   int numbersSize = 0;
   cout << "How many numbers would you like to enter " << endl; 
   cin >> numbersSize; 
  int numbers[numbersSize];
   for (i = 0; i < numbersSize; ++i) {
     cout << "Input number " << (i + 1) << ": "; 
     cin >> numbers[i];
     cout << endl; 
   }
      
   // Display the contents of the array
   cout << "UNSORTED: " << ArrayToString(numbers, numbersSize) << endl;
      
   // Call the InsertionSort function
   InsertionSort(numbers, numbersSize);
      
   // Display the sorted contents of the array
   cout << "SORTED:   " << ArrayToString(numbers, numbersSize) << endl;
  
}