//  main.cpp
//  streams

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream myFile;
    
    myFile.open("test.txt", ios::out);
    if (myFile.is_open())
    {
        cout << "file open for writing = sucess." << endl;
    }
    else
    {
        cout << "file open for writing = failure." << endl;
    }
    
    //loop to write 100 lines:
    for (int i = 1; i <= 100; i++)
    {
        myFile << "this is line " << i << endl;
    }
    myFile.close(); //remember to close files after usage.
    
    //prep file for reading:
    myFile.open("test.txt", ios::in);
    cout << myFile.is_open() << endl; //is._open is a boolean: 1 = true.
    if (myFile.is_open())
    {
        cout << "file open for reading = sucess." << endl;
    }
    else
    {
        cout << "file open for reading = failure." << endl;
    }
    
    //read only the first line from file:
    string line;
    getline(myFile, line);
    cout << line << endl;
    
    //read all lines from file using while loop:
    cout << "starting below this line, using while loop to read data." 
    << endl;
    
    string allLines;
    while (getline(myFile, allLines))
    {
        cout << allLines << endl;
    }
    myFile.close(); //remember to close files after usage.
    return 0;
} //closes main function.


//notes:
//1) no need for #include <string> to read data like some documentation states.
//might be just for xcode on mac os?
//2) was having trouble with files until changed edit scheme option to custom directory on c++ (root directory of project).
//product >> scheme >> edit scheme >> options >> use custom working directory.
