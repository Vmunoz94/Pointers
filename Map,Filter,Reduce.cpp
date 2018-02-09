#include <iostream>
#include <vector>
using namespace std;

vector<int> * map ( int (*fxn) (int), vector<int>  * vec );
vector<int> * filter ( bool (*fxn) (int), vector<int> * vec );
int reduce ( int (*fxn) (int, int), vector<int> * vec );

int square (int);       // For use with map
bool isEven (int);      // For use with filter
int product (int,int);  // For use with reduce

bool testPassed();

// The map function takes as arguments a function pointer and a integer vector pointer.
// It applies the function to every element in the vector, storing the results in-order in a new vector.
// It then returns a pointer to a new vector.
vector<int> * map ( int (*fxn) (int), vector<int>  * vec ){

     int vecSize = vec->size();
     vector <int>* tempMapVector_p = new vector <int>();

     tempMapVector_p->resize(vecSize);
          //initializing my new Map Vector_p with the variables in my original Vector squared
          for (unsigned int i = 0; i < vecSize; i++){
               //my new tempMapVector_p at any index = my original vector squared
               tempMapVector_p->at(i) = fxn(vec->at(i));
          }

     return tempMapVector_p;
     }

// The filter function takes as arguments a function pointer and a integer vector pointer.
// It tests every element in the vector against the function,
//storing in a new vector those elements for which the function returns true.
// It then returns a pointer to the new vector.
vector<int> * filter ( bool (*fxn) (int), vector<int> * vec ){

     int vecSize = vec->size();
     vector <int>* tempFilterVector_p = new vector <int>();


     //if the vec->at(i) is even, pass it to the back of tempFilterVector_p
     for (unsigned int i = 0; i < vecSize; i++){

      if(fxn(vec -> at(i)) == true){

         tempFilterVector_p->push_back(vec->at(i));

         }
     }

   //returning my tempFilterVector_p pointer
   return tempFilterVector_p;
   }

//The reduce function takes as arguments a function pointer and a integer vector pointer.
//The reduce function reduces a vector down to a single value by passing a running total and next vector element to the function,
//then storing the results as the new total.
//It does this for every element of the vector.
int reduce ( int (*fxn) (int, int), vector<int> * vec ){
     //declaring and initializing the total to the contents of the first location of the vector
	int total = vec -> at(0);

	for (unsigned int i = 1; i < vec->size(); i++){

	   total = fxn(total, vec -> at(i));

	}

	return total;
}

//Takes an integer and returns its square
int square (int x){

   return (x * x);

   }

//Takes an integer and returns true if even, otherwise false
bool isEven (int x){

     return (x % 2 == 0);

   }

//Takes two integers and returns their product
int product (int x, int y){

   return (x * y);

   }


int main ( ) {
	/* Use the main method for your own testing, debugging, etc */

   //declaring the size of the vector
   int vectorSize;
   int sum;
   //declaring my vectors
   vector<int> myOriginalVector;
   vector<int>* myOriginalVector_p = &myOriginalVector;
   vector <int>* mapVector_p;
   vector <int>* filterVector_p;
   //declaring my function pointers
   int (*fxnSquare) (int) = &square;
   bool (*fxnisEven) (int) = &isEven;
   int (*fxnProduct) (int, int) = &product;


   //initializing my vector
   cout << "How many variables should the vector contain?" << endl;
   cin >> vectorSize;
   myOriginalVector.resize(vectorSize);
   cout << "Input vector variables" << endl;

      for (int i = 0; i < vectorSize; i++){

         cin >> myOriginalVector.at(i);

     }

   //calling functions
   mapVector_p = map(*fxnSquare, myOriginalVector_p);
   filterVector_p = filter(*fxnisEven, myOriginalVector_p);
   sum = reduce(*fxnProduct, myOriginalVector_p);

   cout << endl;
   //printing out statements
   //original vector
   cout << "My original vector : " << "\t" << "{ ";
   for (int i = 0; i < vectorSize; i++){

         if ( i < vectorSize - 1){

            cout << myOriginalVector_p->at(i) << ", ";

         }
         else{

            cout << myOriginalVector_p->at(i) << " }" << endl;

          }
     }

	//mapVector
     cout << "My map function    : " << "\t" << "{ ";
     for (unsigned int i = 0; i < vectorSize; i++){

         if ( i < vectorSize - 1){

            cout <<  mapVector_p->at(i) << ", ";

          }
         else{

            cout <<  mapVector_p->at(i) << " }" << endl;

          }
     }
	//filterVector
     cout << "My filter function : " << "\t" << "{ ";
     int filterVectorSize = filterVector_p->size();
	for (unsigned int i = 0; i < filterVectorSize; i++){

		if ( i < filterVectorSize - 1){

			cout <<  filterVector_p->at(i) << ", ";

	     }
		else{

			cout <<  filterVector_p->at(i) ;

		}
	}
     cout << " }" << endl;

	cout << "My reduce function : " << "\t" << "{ " << sum << " }" << endl;

	//original vector
     cout << "My original vector : " << "\t" << "{ ";
     for (int i = 0; i < vectorSize; i++){

          if ( i < vectorSize - 1){

              cout << myOriginalVector_p->at(i) << ", ";

          }
          else{

              cout << myOriginalVector_p->at(i) << " }" << endl;

          }
     }

	return 0;
}
