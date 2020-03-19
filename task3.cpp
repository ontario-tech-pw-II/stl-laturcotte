//Liam Turcotte
#include <iostream>
#include <fstream>
#include <string> 
#include <map> 

using namespace std;

int main() {

    string filename = "task2infile.txt"; 

    ifstream infile(filename); 

    string currentName; 
    int currentGrade; 

    map<string, int> c; 

    //pair<string, int> studentpair; 

    while (infile >> currentName) {
        infile >> currentGrade; 

        //put the name in map if it's not already there 
        if (c.find(currentName) == c.end()) {
            c[currentName] = 0; 
        } 
        if (currentGrade < 50) {
            c[currentName]++; 
        }
        
    }

    infile.close(); 

    ofstream outfile("task3outfile.txt"); 

    map<string, int>::iterator p; 

    for (p = c.begin(); p != c.end(); p++) {
        outfile << p->first << " " << p->second << endl; 
    } 

    outfile.close(); 
    
    return 0; 
}