#include <iostream>
#include <fstream>
using namespace std;

// Here I've left the code as I found it, to show you
// a contrasting (and in my opinion, nowhere near as clear)
// style.  Many C++ coders have this style.


// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode
//
long mode (long *arr, int n) {
  	// TO DO:: Fill in this function.
	long mcount = 0.0;  // Initializing max count to 0.0.
	int index = 0;   // Set index to 0.
	for (int i=0; i<n; i++){
		long count = 0.0;    // Initializing element count to 0.
		for (int j = 0; j<n; j++){
			if(arr[i] == arr[j]){   // Search each element, if the previous one is the same as the next one, then count + 1.
				count++;
			}
		}
		// Find the max count element in the array.
		if (count > mcount){ 
			mcount = count;  // Update max count if count larger than max count.
			index = i; // Update max repeated element's index.
		}
	}
	return arr[index];  // Return the mode of the array.
}


// Input is the number of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.
int main (int argc,  char* argv[]) {

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
	int n;
	long *arr;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a number:" << endl;
		cin >> arr[i];
	}

	long m = mode(arr,n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}
