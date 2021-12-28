#ifndef STURECORDS10_H
#define STURECORDS10_H

using namespace std;
//*****************************************************************
//stuRecords10.h includes all data for student records, including the
//structure Stu which is used to implement student records, arrays of
//test scores, all the Stu's that are created, and the avg function
//which is used to calculate grade average. I used this .h file to
//keep project10.cpp free of clutter.
//*****************************************************************
const int TESTNUM = 10;

struct Stu
{
    int id;  //Student identification number
    string name;  //Student name
    int* testPtr;
};

//modified Student records - just names
    string s1 = "John Smith";
    string s2 = "Jane Smith";
    string s3 = "James Smithers";
    string s4 = "Johnathan Smoth";
    string s5 = "Don Johnson";
    string s6 = "John Donson";
    string s7 = "Don Donnerson";
    string s8 = "Dane Danerson";
    string s9 = "Elvis Presley";
    string s10 = "Jennifer Aniston";
    string s11 = "Jorn Smith";
    string s12 = "Janet Smith";
    string s13 = "Jameson Smitherson";
    string s14 = "Johnathanathan Smothoth";
    string s15 = "Donny Johnnyson";
    string s16 = "Johnny Donnyson";
    string s17 = "Donathan Donathanerson";
    string s18 = "Danet Daneterson";
    string s19 = "Elvish President";
    string s20 = "Hennifer Maniston";
    string s21 = "Abe Jonson";
    string s22 = "Jeff Jonny";
    string s23 = "Johnny Abesmith";
    string s24 = "Johnathan Aemith";
    string s25 = "Jo Sith";
    string s26 = "Johb Emith";
    string s27 = "On Ramith";
    string s28 = "Jay Smaserth";
    string s29 = "Joasdfhn Smiasdfth";
    string s30 = "Dan Danson";
    string s31 = "George Georgeson";
    string s32 = "Jeff Jeffson";
    string s33 = "Joe Joeson";
    string s34 = "Arty Artson";
    string s35 = "Smitherton Smith";
    string s36 = "Jhayn Jayneson";
    string s37 = "Onad Ramithsmith";
    string s38 = "Jayerton Smaserthorn";
    string s39 = "Joasn Smifth";
    string s40 = "Jowerasdfhn Smasdfiasdfth";

    string stuNames[] = {s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12,s13,s14,s15,
            s16,s17,s18,s19,s20,s21,s22,s23,s24,s25,s26,s27,s28,s29,s30,s31,
            s32,s33,s34,s35,s36,s37,s38,s39,s40};

//ARRAYS OF TEST SCORES AND POINTERS TO ARRAYS OF TEST SCORES
    int t1[TESTNUM] = {44, 51, 90, 11, 64, 69, 97, 49, 78, 12};
    int* t1P = t1;
    int t2[TESTNUM] = {44, 68, 93, 86, 92, 8, 63, 52, 36, 92};
    int* t2P = t2;
    int t3[TESTNUM] = {43, 58, 93, 86, 92, 81, 73, 52, 100, 92};
    int* t3P = t3;
    int t4[TESTNUM] = {47, 68, 73, 76, 92, 38, 63, 52, 66, 92};
    int* t4P = t4;
    int t5[TESTNUM] = {49, 68, 93, 86, 92, 8, 63, 52, 36, 92};
    int* t5P = t5;
    int t6[TESTNUM] = {100, 68, 93, 86, 92, 8, 63, 52, 36, 82};
    int* t6P = t6;
    int t7[TESTNUM] = {84, 68, 73, 86, 92, 8, 63, 52, 36, 92};
    int* t7P = t7;
    int t8[TESTNUM] = {54, 68, 93, 86, 92, 91, 53, 52, 39, 91};
    int* t8P = t8;
    int t9[TESTNUM] = {84, 68, 93, 86, 92, 82, 63, 72, 36, 92};
    int* t9P = t9;
    int t10[TESTNUM] = {44, 68, 93, 86, 92, 18, 63, 52, 36, 92};
    int* t10P = t10;
    int t11[TESTNUM] = {13, 76, 25, 16, 94, 37, 12, 89, 7, 89};
    int* t11P = t11;
    int t12[TESTNUM] = {17, 48, 19, 84, 23, 29, 93, 87, 76, 38};
    int* t12P = t12;
    int t13[TESTNUM] = {11, 50, 56, 44, 9, 66, 4, 15, 79, 29};
    int* t13P = t13;
    int t14[TESTNUM] = {95, 25, 95, 82, 12, 12, 85, 71, 2, 63};
    int* t14P = t14;
    int t15[TESTNUM] = {56, 89, 79, 11, 100, 11, 39, 42, 55, 71};
    int* t15P = t15;
    int t16[TESTNUM] = {41, 92, 29, 6, 91, 48, 35, 53, 11, 37};
    int* t16P = t16;
    int t17[TESTNUM] = {41, 7, 8, 22, 8, 73, 50, 35, 4, 76};
    int* t17P = t17;
    int t18[TESTNUM] = {21, 33, 90, 49, 52, 47, 75, 79, 81, 54};
    int* t18P = t18;
    int t19[TESTNUM] = {61, 76, 11, 66, 100, 9, 24, 54, 91, 79};
    int* t19P = t19;
    int t20[TESTNUM] = {84, 77, 57, 94, 9, 42, 85, 70, 97, 74};
    int* t20P = t20;
    int t21[TESTNUM] = {17, 28, 83, 47, 26, 66, 11, 49, 7, 86};
    int* t21P = t21;
    int t22[TESTNUM] = {88, 76, 41, 14, 66, 38, 17, 6, 79, 5};
    int* t22P = t22;
    int t23[TESTNUM] = {26, 33, 60, 72, 9, 12, 64, 88, 60, 39};
    int* t23P = t23;
    int t24[TESTNUM] = {10, 96, 46, 69, 64, 19, 19, 59, 45, 21};
    int* t24P = t24;
    int t25[TESTNUM] = {8, 22, 86, 40, 70, 41, 21, 8, 36, 33};
    int* t25P = t25;
    int t26[TESTNUM] = {89, 30, 34, 63, 98, 89, 36, 9, 80, 61};
    int* t26P = t26;
    int t27[TESTNUM] = {73, 5, 26, 39, 64, 38, 65, 85, 52, 53};
    int* t27P = t27;
    int t28[TESTNUM] = {41, 28, 7, 71, 47, 80, 74, 55, 71, 47};
    int* t28P = t28;
    int t29[TESTNUM] = {35, 15, 32, 96, 99, 58, 66, 49, 37, 76};
    int* t29P = t29;
    int t30[TESTNUM] = {79, 58, 82, 17, 57, 40, 94, 79, 43, 38};
    int* t30P = t30;
    int t31[TESTNUM] = {3, 75, 84, 47, 91, 65, 18, 76, 24, 45};
    int* t31P = t31;
    int t32[TESTNUM] = {69, 2, 19, 60, 45, 6, 16, 15, 81, 50};
    int* t32P = t32;
    int t33[TESTNUM] = {87, 79, 27, 16, 66, 12, 60, 90, 82, 84};
    int* t33P = t33;
    int t34[TESTNUM] = {3, 32, 13, 18, 69, 62, 79, 77, 13, 2};
    int* t34P = t34;
    int t35[TESTNUM] = {80, 35, 9, 84, 60, 22, 49, 88, 24, 77};
    int* t35P = t35;
    int t36[TESTNUM] = {70, 4, 4, 90, 70, 39, 65, 95, 9, 89};
    int* t36P = t36;
    int t37[TESTNUM] = {73, 38, 15, 36, 17, 13, 33, 70, 19, 46};
    int* t37P = t37;
    int t38[TESTNUM] = {72, 32, 15, 96, 58, 58, 27, 90, 18, 52};
    int* t38P = t38;
    int t39[TESTNUM] = {73, 63, 86, 81, 52, 66, 15, 21, 31, 23};
    int* t39P = t39;
    int t40[TESTNUM] = {67, 24, 85, 26, 39, 93, 38, 12, 18, 57};
    int* t40P = t40;

    int* testPtrs[40] = {t1P, t2P, t3P, t4P, t5P, t6P, t7P, t8P, t9P, t10P,
        t11P, t12P, t13P, t14P, t15P, t16P, t17P, t18P, t19P, t20P, t21P, t22P,
        t23P, t24P, t25P, t26P, t27P, t28P, t29P, t30P, t31P, t32P, t33P, t34P,
        t35P, t36P, t37P, t38P, t39P, t40P};


#endif // STURECORDS10_H
