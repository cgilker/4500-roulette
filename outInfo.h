//Drew Johnson
//4500 HW2 - Roulette
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


//outInfo() function takes in an int array and 4 ints, it has no return value but prints to the user various statistics of import.
void outInfo( int walletArr[], int visits, int slots, int zeroSlots, int startMoney) 
{
    //print out all starting values to the user
    cout << "\nHere are your results for given input: \n";
    cout << "\tTotal number of slots: " << slots << ".\n";
    cout << "\tNumber of 00 or 0 slots: " << zeroSlots << ".\n";
    cout << "\tNumber of visits to the casino: " << visits << ".\n";
    cout << "\tStarting money before each visit: " << startMoney << ".\n";
    
    //print out total risked money
    int risked = startMoney*visits;
    cout << "\nTotal money risked throughout entire simulation: " << risked << ".\n";
    
    //print out total walked away with, and as a percentage of risked
    int walkingMoney = 0;
    for (int i=0;i<visits;i++) 
    {
        walkingMoney = walkingMoney + walletArr[i];
    }
    cout << "Total amount of money walked away with, for " << visits << " visits: " << walkingMoney << ".\n";
    double percentChange = (static_cast<double>(walkingMoney)/static_cast<double>(risked))*100;
    if (percentChange >= 100)
        cout << "Percentage gain of money walked away with to risked money: +" << percentChange << ".\n";
    else
        cout << "Percentage loss of money walked away with to risked money: -" << 100 - percentChange << ".\n";
    
    //print out the highest winnings for a visit
    int bigGain = 0;
    for(int i=0;i<visits;i++)
    {
        if (walletArr[i] > bigGain)
            bigGain = walletArr[i];
    }
    if (bigGain == 0)
        cout << "There were no winnings in all " << visits << " visits.\n";
    else
        cout << "The largest winnings out of all visits were $" << bigGain - startMoney << ".\n";
    
    //print out number of times finished with no money
    int broke = 0;
    for(int i=0;i<visits;i++)
    {
        if (walletArr[i] == 0)
            broke++;
    }
    if (broke == 0)
        cout << "No visits ended with $0.\n";
    else    
        cout << "The number of visits that ended with $0 is " << broke << ".\n";
    
    //print the average change over all visits
    double accChange = 0;
    double avgChange;
    for(int i=0;i<visits;i++)
    {
        accChange = accChange + (static_cast<double>(walletArr[i] - startMoney));
    }
    avgChange = accChange/visits;
    cout << "The average change for each visit is " << avgChange << ".\n";
    
    //print number of times user gained money, lost money, and went even
    int pos = 0;
    int neg = 0;
    int even = 0;
    for(int i=0;i<visits;i++)
    {
        if(walletArr[i] > startMoney)
            pos++;
        if(walletArr[i] < startMoney)
            neg++;
        if(walletArr[i] == startMoney)
            even++;
    }
    cout << "The gambler left with more money than they started with " << pos << " times.\n";
    cout << "The gambler left with less money than they started with " << neg << " times.\n";
    cout << "The gambler went even " << even << " times. \n";
    
}

int main()
{
    int slots = 150;
    int zeroSlots = 1;
    int visits = 15;
    int money = 105;
    int gain[] = {1,25,69,72,45,10,67,142,100,100,10,5,18,70,1};
    outInfo(gain, visits, slots, zeroSlots, money);
    return 0;
}





