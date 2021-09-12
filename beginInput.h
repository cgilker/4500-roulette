/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


int main()
{
    int totalSlots = 0;
    while (totalSlots < 2 || totalSlots > 200) {
    cout << "How many total slots (red, black and green) would you like to have? (acceptable: 2-200)\n";
    cin >> totalSlots;
    }
    int zeroSlots = -1;
    while (zeroSlots < 0 || zeroSlots > 2) {
    cout << "How many slots would you like marked as 0 or 00? (acceptable: 0-2)\n";
    cin >> zeroSlots;
    }
    int visits = -1;
    while (visits < 0 || visits > 100000) {
    cout << "How many times would you like to visit the casino? (acceptable: 1-100,000)\n";
    cin >> visits;
    }
    int money = -1;
    while (money < 0  || money > 1000000) {
    cout << "How much money are you willing to gamble? (acceptable: 1-1,000,000)\n";
    cin >> money;
    }
    
    return 0;
}



