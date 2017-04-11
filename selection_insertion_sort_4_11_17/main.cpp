/*
    Daniel Erhabor
    @02778845
    selection_insertion sort lab 4_11_17
*/
#include <iostream>
#include <vector>
#include <ctime>        //Libraries needed
#include <cstdlib>
#include <stdlib.h>


using namespace std;
void insertion_sort(vector<int>& someVect);     // This function was not used.
void selection_sort (vector<int>& someVect);
void printVec(vector<int> someVec);                             // Function declarations
int BinarySearch(vector<int> someVec, int key);
string checkList(vector<int> someVec, int aKey);
void genRandVec(vector<int>& someVec, int numTimesGen);
void HintLowHigh(vector<int> someVec, int someCheck);
void HintHighLow(vector<int> someVec, int someCheck);
/*
    Some functions were commented out for testing the low level implementation for the searching and sorting
*/
int main()
{
    //srand(time(0));
    int numOfRand = 0;
    vector<int> aVec;                                               // Vector
    cout << "Enter amount of numbers to generate: " << endl;
    cin >> numOfRand;                                           // Get user input for number of random numbers to generate

    //aVec.push_back(5);
    //aVec.push_back(2);
    //aVec.push_back(6);
    //aVec.push_back(1);

    //int someKey = 98;
    genRandVec(aVec, numOfRand);            // Populate vector with number of random numbers

    //printVec(aVec);
    //insertion_sort(aVec);
    selection_sort(aVec);                       // Sort the vectors in ascending order using selection sort
    //printVec(aVec);
    //checkList(aVec, someKey)
    //BinarySearch(aVec, someKey)
    //cout << someKey << " found at index: ";
    //checkList(aVec, someKey);
    int numTries = 5;
    int numToCheck = 0;
    while (numTries > 0){
        cout << "Enter a number between 1 and 100: ";
        cin >> numToCheck;
        if (checkList(aVec,numToCheck)=="False"){
            --numTries;
            cout << "Wrong! Try Again. " << numTries << " tries left. ";
            //HintLowHigh(aVec, numToCheck);
            HintHighLow(aVec, numToCheck);
            cout << endl;
        }                                                                                           // Main program to get stuff from user
        else if (checkList(aVec,numToCheck)=="True"){
            --numTries;
            cout << "Correct!" << endl;
            printVec(aVec);
            break;
        }
    }
    if (numTries==0&&checkList(aVec,numToCheck)=="False"){
        cout << "Haha! You suck at this game." << endl;
        printVec(aVec);
    }


    return 0;
}
void insertion_sort(vector<int>& someVect){
    for (unsigned int i = 1; i < someVect.size(); ++i){             // Insertion sort function definition

        int j = i;
        while (j > 0 && someVect.at(j)< someVect.at(j-1)){
            int temp = someVect.at(j);
            someVect.at(j) = someVect.at(j-1);
            someVect.at(j-1) = temp;
            --j;
        }
    }
    return;
}
void selection_sort (vector<int>& someVect){
    for (unsigned int i = 0; i < someVect.size(); ++i){         // selection sort function definition
        int smi = i;
        for(unsigned int j = i+1; j < someVect.size(); ++j){
            if (someVect.at(j) < someVect.at(smi)){
                smi = j;
            }
        }
        int temp = someVect.at(i);
        someVect.at(i) = someVect.at(smi);
        someVect.at(smi) = temp;
    }
    return;
}
void printVec(vector<int> someVec){
    for (unsigned int i = 0; i < someVec.size(); ++i){      // Print the list
        cout << someVec.at(i) << " ";

    }
    cout << endl;

}

int BinarySearch(vector<int> someVec, int key) {
   int mid = 0;                                         // Binary search function definition for vectors
   int low = 0;
   int high = 0;

   high = someVec.size() - 1;

   while (high >= low) {
      mid = (high + low) / 2;
      if (key > someVec.at(mid)) {
         low = mid + 1;
      }
      else if (key < someVec.at(mid)) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }

   return -1; // not found
}

string checkList(vector<int> someVec, int aKey){
    int anIndex = BinarySearch(someVec, aKey);
    if (anIndex==-1){
        return "False";                                     // Check the list if element is there; this calls binarySearch function
    }
    else if (someVec.at(anIndex)==aKey){
        return "True";
    }
    return "Error";
}

void genRandVec(vector<int>& someVec, int numTimesGen){
    srand(time(0));
    for (int i = 0; i < numTimesGen; ++i){              // populate vector with random numbers using srand initialized to the time, hence gives randomness
        int aRand = rand() % 100 + 1;
        someVec.push_back(aRand);
    }

}

void HintLowHigh(vector<int> someVec, int someCheck){
    int lowDiff = abs(someVec.at(0) - someCheck);
    int highDiff = abs(someVec.at(someVec.size() - 1) - someCheck);
    if (someCheck < someVec.at(0)){
        cout << "Hint: Go higher";                                  // Function to know if to go higher or lower
    }                                                               // Only for edges of the list unless item is less than smallest element in the list then
    else{                                                           // go higher
        if (lowDiff < highDiff){
            cout << "Hint: Go lower";
        }
        else if (lowDiff > highDiff){
            cout << "Hint: Go higher";
        }
        else if (lowDiff==highDiff){
            cout << "Hint: Go higher";
        }
    }
    return;

}


void HintHighLow(vector<int> someVec, int someCheck){
    int closestCheck = abs(someCheck - someVec.at(0));
    int cCheckIndex = 0;
    if (someCheck < someVec.at(0)){                             // More optimized function
        cout << "Hint: Go higher";                              // for the hints
    }
    else{
        for (unsigned int i = 0; i < someVec.size(); ++i){
            if (abs(someCheck - someVec.at(i)) < closestCheck){
                closestCheck = abs(someCheck - someVec.at(i));
                cCheckIndex = i;
            }

        }
        if (someCheck > someVec.at(cCheckIndex)){
            cout << "Hint: Go lower";
        }
        else if (someCheck < someVec.at(cCheckIndex)){
            cout << "Hint: Go higher";
        }
    }

}

