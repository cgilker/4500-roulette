//Drew Johnson & Colin Gilker
//4500 HW2 - Roulette
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


//returns true on win
bool roll(int slots, int zeroSlots)
{
    srand(time(NULL));
    int result = rand() % slots+1;
    std::cout << result<<"\n";   
    //odd #s are a loss, plus 2 4 and 6 depending on zero slots
    //in the case of one slot, 2 is a loss
    //in the case of two slots, 4 is now a loss as well
    //three slots includes 6 as well
    if ((result % 2 != 0) || (result <= 2*zeroSlots)){
        return false;
    }
    //evens win
    else{
        return true;
    }
}


//wallet starts as however much money I have brought on this trip and changes as i win/lose depedning on bet value  

//the 2nd parameter determines the strat used (1 martingate, 2 random, 3 fixed)
int betting(int wallet, int strat, int slots, int zeroSlots, int fixedBet){
    //store values prior to bet
    //one loop is one bet plus a check to stop
    
    int i = 0;
    while(1){ //retrn is used to exit while loop and function
        //determine bet value
        int bet = 0;
        //martingate
        if(strat==1){
            bet = 1 * 2^i;
        }
        //random
        else if (strat==2){
            bet = rand() % wallet + 1;  //between 1 and current wallet value
        }
        //fixeds
        else if (strat==3){
            bet = fixedBet;
        }
        
        //now that we have set a bet, roll the wheel and adjust our wallet
        //win case
        bool roundWon = false;
        if (roll(slots, zeroSlots)){ //roll with values from user at the start
            wallet = wallet + bet;
            roundWon = true;
        }
        //lose case
        else{
            wallet = wallet - bet;
        }
        
        //store the values for later
        
        //check
        if (wallet <= 0){
            wallet==0; //lets just say we cant go into debt :)
            return 0;
        }
        //martingate case
        if ((strat==1)&&(roundWon)){
            return 1;
        }
        
        //random case and fixed case
        if ((i==50)&&(strat!=1)){
            return 1;
        }
        i = i + 1;
    }
}

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

//Main method that handles input and calls to betting() methid using user input
int main()
{
    int totalSlots = 0;
    while (totalSlots < 2 || totalSlots > 200) {
    cout << "How many total slots (red, black and green) would you like to have? (acceptable: 2-200)\n";
    cin >> totalSlots;
    if (totalSlots < 2 || totalSlots > 200)
        cout << "You entered " << totalSlots << " . Value must be an integer between 2 and 200.\n";
    }
    int zeroSlots = -1;
    while (zeroSlots < 0 || zeroSlots > 2) {
    cout << "How many slots would you like marked as 0 or 00? (acceptable: 0-2)\n";
    cin >> zeroSlots;
    if (zeroSlots < 0 || zeroSlots > 2)
        cout << "You entered " << zeroSlots << " . Value must be an integer between 0 and 2.\n";
    }
    int visits = 0;
    while (visits < 1 || visits > 100000) {
    cout << "How many times would you like to visit the casino? (acceptable: 1-100,000)\n";
    cin >> visits;
    if (visits < 1 || totalSlots > 100000)
        cout << "You entered " << visits << " . Value must be an integer between 1 and 100,000.\n";
    }
    int money = 0;
    while (money < 1  || money > 1000000) {
    cout << "How much money are you willing to gamble? (acceptable: 1-1,000,000)\n";
    cin >> money;
    if (money < 1 || money > 1000000)
        cout << "You entered " << money << " . Value must be an integer between 1 and 1,000,000.\n";
    }
    int strategy = 0;
    while (strategy < 1 || strategy > 3) {
    cout << "What betting strategy would you like to use? \n1. \n2. \n3. ";
    cin >> strategy;
    if (strategy < 1 || strategy > 3)
        cout << "You entered " << strategy << " . Value must be menu option 1, 2, or 3. \n";
    }
    
    return 0;
}