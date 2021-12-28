// File Name: project10.cpp
//
// Author: (David Hackenbracht)
// Date: 11/21/2020
// Assignment Number: 10
// CS 3358 Fall 2020
// Instructor: Dr. C Jinshong Hwang
//
// (This program creates two binary search trees that organize student records)

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "stuRecords10.h"
#include "StuBinaryTree.h"

using namespace std;

const int STUNUM = 40;
const int HALFSTU = 20;
const int NUMTESTS = 10;

/**************************************************
 **Function: stuIdGen
 **Description: Generates pseudorandom numbers and inserts them into an int
 array. This version of stuIdGen guarantees each random number has not been used
 before.
 **Parameters: stuIds[] is the array of numbers.
 **Other: test is a "randomly" generated integer guaranteed to be 4 digits long,
 with a range from 1000 to 1999.
**************************************************/
void stuIdGen(int stuIds[])
{
    srand(time(NULL));
    //Generates "random" 4 digit numbers.
    for(int i = 0; i < STUNUM; i++)
    {
BR1:    int test = (rand() %1000) + 1000;
        //Verify this number is not a repeat.
        //Initial case: no possible repeat.
        if(i == 0)
        {
            stuIds[i] = test;
        }
        //All other cases, if int test is a number already in the array,
        //jump back to BR1 and try to create a new random number.
        else
        {
            for(int j = 0; j < i; ++j)
            {
                if(test == stuIds[j])
                    goto BR1;  //Learned this trick in Assembly Language class
            }
            stuIds[i] = test;
        }
    }
}

/**************************************************
 **Function: dispStus
 **Description: displays formatted student records from an array of Stu data
 **Parameters: stus[] is the array of student records.
**************************************************/
void dispStus(Stu stus[])
{
    for(int i = 0; i < HALFSTU; ++i)
    {
        cout << left << setw(8) << stus[i].id << " " << setw(25) << stus[i].name;
        //display test scores as dereferenced pointers
        for(int j = 0; j < NUMTESTS; ++j)
        {
            cout << " " << setw(3) << *(stus[i].testPtr + j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    //create array of integers, size STUNUM
    int stuIds[STUNUM];

    //fill array with randomly generated 4 digit numbers
    stuIdGen(stuIds);

    //create array of struct Stu's, with rand generated IDs, preset names,
    //and pointers to test scores
    Stu students1[HALFSTU];
    for(int i = 0; i < HALFSTU; ++i)
    {
        students1[i].id = stuIds[i];
        students1[i].name = stuNames[i];
        students1[i].testPtr = testPtrs[i];
    }
    cout << "\nDisplaying First Unsorted Array of Students: \n";
    dispStus(students1);

    StuBinaryTree tree1;
    //Insert Stus into binary search tree
    for(int i = 0; i < HALFSTU; ++i)
    {
        tree1.insertNode(students1[i]);
    }
    cout << "\nDisplaying Student Records Using InOrder Traversal\n";
    tree1.displayInOrder();

    int sID1, sID2 = 0;
    cout << "Please enter first Student ID to search for: ";
    cin >> sID1;
    tree1.searchNodeById(sID1);

    cout << "Please enter second Student ID to search for: ";
    cin >> sID2;
    tree1.searchNodeById(sID2);

    int dID1, dID2 = 0;
    cout << "Please enter first Student ID to delete: ";
    cin >> dID1;
    tree1.removeById(dID1);
    cout << "\nRecord Deleted.\n";

    cout << "Please enter second Student ID to delete: ";
    cin >> dID2;
    tree1.removeById(dID2);
    cout << "\nRecord Deleted.\n";

    cout << "\nDisplaying tree after deletions\n";
    tree1.displayInOrder();

    /********************SECOND SET OF DATA***************************/

    Stu students2[HALFSTU];
    for(int i = HALFSTU, j = 0; i < STUNUM; ++i, ++j)
    {
        students2[j].id = stuIds[i];
        students2[j].name = stuNames[i];
        students2[j].testPtr = testPtrs[i];
    }

    cout << "\nDisplaying Second Unsorted Array of Students: \n";
    dispStus(students2);

    StuBinaryTree tree2;
    //Insert Stus into binary search tree
    for(int i = 0; i < HALFSTU; ++i)
    {
        tree2.insertNode(students2[i]);
    }
    cout << "\nDisplaying Student Records Using InOrder Traversal\n";
    tree2.displayInOrder();

    int s2ID1, s2ID2 = 0;
    cout << "Please enter first Student ID to search for: ";
    cin >> s2ID1;
    tree2.searchNodeById(s2ID1);

    cout << "Please enter second Student ID to search for: ";
    cin >> s2ID2;
    tree2.searchNodeById(s2ID2);

    int d2ID1, d2ID2 = 0;
    cout << "Please enter first Student ID to delete: ";
    cin >> d2ID1;
    tree2.removeById(d2ID1);
    cout << "\nRecord Deleted.\n";

    cout << "Please enter second Student ID to delete: ";
    cin >> d2ID2;
    tree2.removeById(d2ID2);
    cout << "\nRecord Deleted.\n";

    cout << "\nDisplaying tree after deletions\n";
    tree2.displayInOrder();



    return 0;
}
