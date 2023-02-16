/**
* Ethan Baker
* project3_Baker_ezb0061.cpp
* compile using g++ project3_Baker_ezb0061.cpp
* run using ./a.out
* Learned how to read and write to files using Dr.Li's guide and StackOverflow.
* Learned how to use sort from GeeksforGeeks.
* Learned how to merge arrays from GeeksforGeeks.
*/

#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 100;

//DECLARING USER DEFINED METHODS

//Used to read an input file, append its data into an array, and return the length of that array.
int readFile(int Array[], ifstream& instream);


//Used to create the ofstream, and then append the data to output txt file.
void writeFile(int outputArray[], int outputArray_size, char* outputFile);


//Merges data from two input arrays, sort output array, and return length of output array.
int mergeSort(int Array1[], int Array1_size, int Array2[], int Array2_size, int outputArray[]);

//Main
int main() {

   //Initialize variables for the Files
   char file1[50];
   char file2[50];

   //Initialize arrays that stores the values
   int Array1[MAX_SIZE];
   int Array2[MAX_SIZE];

   //Initialize output array
   int outputArray[2*MAX_SIZE];

   cout<<"*** Welcome to Ethan's sorting program ***"
      <<"\nEnter the first input file name: ";
   cin>>file1;

   //Open the file
   ifstream currentFile;
   currentFile.open(file1);

   //Error message for when file is not opened or does not exist
   if(currentFile.fail()) {
      cout << "Input file opening failed!" << endl;
      exit(1);
   }

   //Reads the file and then close it.
   int input1_size = readFile(Array1,currentFile);
   currentFile.close();

   cout<<"The list of "<<input1_size<<" numbers in file "<<file1<<" is: \n"; //Displays # of inputs in file

   for(int i = 0;i < input1_size;i++) {
      cout<<Array1[i]<<endl;
   }

   //Repeat the process for file2
   cout<<"\nEnter the second input file name: ";
   cin>>file2;

   currentFile.open(file2);

   //Check for error again.
   if(currentFile.fail()) {
      cout << "Input file opening failed!" << endl;
      exit(1);
   }

   int input2_size = readFile(Array2,currentFile);
   currentFile.close();

   cout<<"The list of "<<input2_size<<" numbers in file "<<file2<<" is: \n"; //Displays # of inputs in file

   for(int i = 0;i < input2_size;i++) {
      cout<<Array2[i]<<endl;
   }

   //Prepares the output array.

   int output_size = mergeSort(Array1, input1_size, Array2, input2_size, outputArray);

   cout<<"\nThe sorted list of 11 numbers is: ";

   for(int i=0;i<output_size;i++) {
      cout<<outputArray[i]<<" ";
   }
   cout<<std::endl;

   //Creates the new output file.

   cout<<"Enter the output file name: ";

   char outputFile[50]; 
   cin>> outputFile;
   writeFile(outputArray,output_size,outputFile);
   cout<<"*** Please check the new file - "<<outputFile<<" ***"
      <<"\n*** Goodbye. ***";

}

//reads file name
int readFile(int Array[], ifstream& instream) {
   int i = 0;
   instream >> Array[i];
   while(!instream.eof()) {
      i++;
      instream >> Array[i];
   }
   return i;
}

//writes the output file
void writeFile(int outputArray[], int outputArray_size, char* outputFile) {
   std::ofstream ofs(outputFile);

   //Check if output file is opened
   if(ofs.fail())
   {
      cout<< "Failed to open file for writing" <<endl;
      exit(1);
   }

   //Write to output file
   for(int i = 0; i < outputArray_size; i++)
   {
      ofs << outputArray[i] << std::endl;
   }
}


//merges both arrays from 2 input files
int mergeSort(int Array1[], int Array1_size, int Array2[], int Array2_size, int outputArray[]) {
   int a=0;
   int b=0;
   int c=0;

   //Filling Array with Input1
   while(a < Array1_size) {
      outputArray[c] = Array1[a];
      a += 1;
      c += 1;
   }

   //Filling Array with Input2
   while(b < Array2_size) {
      outputArray[c] = Array2[b];
      b += 1;
      c += 1;
   }
   return 0;
}