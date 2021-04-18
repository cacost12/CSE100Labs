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

int main(){

    output_header();

    return(0);
}
