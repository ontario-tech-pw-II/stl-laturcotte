//Liam Turcotte
#include <iostream>
#include <fstream>
#include <string> 
#include <set> 

using namespace std;

int main() {

    string filename = "task2infile.txt"; 

    ifstream infile(filename); 

    string currentName; 
    float currentGrade; 

    set<string> student_names; 

    while (infile >> currentName) {
        infile >> currentGrade; 

        if (currentGrade < 50) {
            //only insert if name isn't already in the set 
            if (student_names.find(currentName) == student_names.end()) {
                student_names.insert(currentName); 
            }
        }
    }

    infile.close(); 

    ofstream outfile("task2outfile.txt"); 

    set<string>::iterator p; 

    for (p = student_names.begin(); p != student_names.end(); p++) {
        outfile << *p << endl; 
    } 

    outfile.close(); 
    
    return 0; 
}