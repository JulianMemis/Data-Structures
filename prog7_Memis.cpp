/************************************************************/
/* Author: Julian Memis */
/* Major: Computer Science */
/* Creation Date: December 4th, 2023 */
/* Due Date: December 8th, 2023 */
/* Course: CS100-01 */
/* Professor Name: Professor Shimkanon */
/* Assignment: #7 Data Structures */
/* Filename: prog7_Memis.cpp */
/* Purpose: This program demonstrates various data structures (Vector/Stack/Queue/Array) */
/* by taking in integers from a file, adding them to the data structure, and then printing */
/* the integers to the console. */
/************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	//Variables:
	ifstream inData("stackNums.txt"); //Input Data
	int number; //Number from file
	int length; //Length of text file
	int index = 0; //Index for array position
	int count = 1; //Amount of numbers in file (length of array)
	string line; //Used for length of file
	//Data Structures:
	vector<int> vector; //Vector
	stack<int> stack; //Stack
	queue<int> queue; //Queue
	
	//Read in from file:
	getline(inData, line);
	length = line.length(); //How many char in file
	inData.close(); //Close file to reset
	inData.open("stackNums.txt"); //Open back up
	
	//Get amount of numbers in file:
	for(int i = 0; i < length; i++)
	{
		if(line[i] == ' ')
		{
			count ++; //Numbers in file
		}
		
		else if(!isdigit(line[i])) //Error Check
		{
			cout << "File contains float or string data. Program exit";
			inData.close(); //Close File
			return 0; //Exit
		}
	}
	
	//Create Array:
	int array[count]; //Array

	//Read data into array:	
	cout << "READING FROM FILE INTO ARRAY:\n";
	while (inData >> number && index < count) 
	{
        array[index++] = number;
    }
	
	//Print Array:
 	for (int i = 0; i < count; ++i) 
	{
    	cout << array[i] << " ";
    }
        
        
    //Read array into stack:
    cout << "\n\nREADING ARRAY INTO STACK..." << endl;
    for(int i = 0; i < count; i++)
    {
    	stack.push(array[i]);
	}
	
	//Pop Stack and add to vector:
	cout << "\nCLEARING STACK:" << endl;
	for (int i = 0; i < count; i++) 
	{
    	int temp = stack.top();
        vector.push_back(temp);
        stack.pop();
    }
    
    //Output Popped Stack (Vector):
    for (int i = vector.size() - 1; i >= 0; i--) 
	{
    	cout << vector[i] << " "; //Use vector to print popped nums
    }

    vector.clear(); //Clear vector for new use	
	inData.close(); //Close File

	
	
	//Open 2nd File:
	inData.open("queueNums.txt"); //Queue Input Data

	//Vector Output:
	cout << "\n\nREADING IN VECTOR:\n";
	
	//Error Check:
	getline(inData, line);
	length = line.length(); //How many char in file
	for(int i = 0; i < length; i++)
	{
		if(line[i] == ' ')
		{
			count ++; //Numbers in file
		}
		
		else if(!isdigit(line[i])) //Error Check
		{
			cout << "File contains float or string data. Program exit";
			inData.close(); //Close File
			return 0; //Exit
		}
	}
	inData.close(); //Close file to reset
	inData.open("queueNums.txt"); //Open back up
	
	//Read in data from file to vector:	
	while (inData >> number) 
	{		
		vector.push_back(number);
    }
    
    //Print numbers in vector:
    for (int i = 0; i < vector.size(); i++) 
    {
    	cout << vector[i] << " ";
	}	

	//Queue Output:
	cout << "\n\nREADING VECTOR INTO QUEUE...";
		
	//Read vector into queue:
	for(int i = 0; i < vector.size(); i++)
	{
		queue.push(vector[i]);
	}
	vector.clear(); //Clear Vector

	//Pop Queue and add to vector:
	cout << "\n\nCLEARING QUEUE:" << endl;
	while (!queue.empty()) 
	{
        vector.push_back(queue.front()); // Add num to vector
        queue.pop();// Pop num from queue
    }	
		
	//Output Popped Queue (Vector):
    for (int i = 0; i < vector.size(); i++) 
	{
    	cout << vector[i] << " "; //Use vector to print popped nums
    }	

	//Close Files:
	inData.close();
	
	return 0;
}
