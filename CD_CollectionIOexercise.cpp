#include<iostream>
#include<string>
#include <fstream> 
using namespace std;

void saveCD(void);
void displayCDs(void);

main(){
int menuOption = 0;

do{ // begin the loop
 cout << " 1: Enter CD Information " <<endl;
 cout << " 2: Display CD Information " <<endl;
 cout << " 3: End the program " <<endl;
 cin >> menuOption;
 cin.ignore(1,'\n');
 cout << endl;
 //call appropriate Function or display error message ..

 if(menuOption == 1)
 saveCD();
 else if(menuOption ==2)
 displayCDs();

 cout <<endl; }while(menuOption !=3);
}

void saveCD(){
//writes records to a sequential access file
string cdName = "";
string artistName = "";
//create file object and open the file
ofstream outFile;
outFile.open("cds.txt", ios::app);
//determine whether the file was opened

if (outFile.is_open())
{
//get the CD name
cout << "CD name (-1 to stop): ";
getline(cin, cdName);
while (cdName != "-1")
{
//get the artist's name
cout << "Artist's name: ";
getline(cin, artistName);
//write the record
outFile << cdName << '#'
<< artistName << endl;
//get another CD name
cout << "CD name (-1 to stop): ";
getline(cin, cdName);
} //end while

//close the file
outFile.close();
}

else
cout << "File could not be opened." << endl;
//end if
} //end of saveCd function

void displayCDs(){
//displays the records stored in the cds.txt file
string cdName = "";
string artistName = "";
//create file object and open the file
ifstream inFile;
inFile.open("cds.txt", ios::in);

//determine whether the file was opened
if (inFile.is_open())
{
//read a record
getline(inFile, cdName, '#');
getline(inFile, artistName);

while (!inFile.eof())
{
//display the record
cout << cdName << ", " <<
artistName << endl;
//read another record
getline(inFile, cdName, '#');
getline(inFile, artistName);
} //end while
//close the file
inFile.close();
}

else
cout << "File could not be opened." << endl;
//end if

} //end of displayCds function