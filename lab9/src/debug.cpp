#include <iostream>
#include <iomanip>

using namespace std;

void output_header(){

    // Table Headers
    cout << setw(20) << right << "Class";
    cout << setw(20) << right << "ZIP City";
    cout << setw(20) << right << "ZIP Code"; 
    cout << setw(20) << right << "Value "; 
    cout << endl;
    
    // Dashes 
    for(int i = 0; i < 80; ++i){
        cout << "-";
    }
    cout << endl;
}

void populate_array(int *arrayPtr){

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            *(arrayPtr + i*j) = i*j;
        }
    }
}

void print_Array(int* arrayPtr){

    for (int i = 0; i < 4; ++i){
        cout << "[";
        for (int j = 0; j < 4; ++j){
            if (j != 3){
                cout << *(arrayPtr + i*j) << ",";
            } else {
                cout << *(arrayPtr + i*j);
            }
        }
        cout << "]" << endl;
    }
}

int main(){

    int myArray[4][4];

    populate_array(&myArray[0][0]);

    print_Array(&myArray[0][0]);

    return(0);
}
