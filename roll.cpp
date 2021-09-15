//Colin Gilker
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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
int betting(int wallet, int strat, int slots, int zeroSlots){
    //store values prior to bet
    //one loop is one bet plus a check to stop
    int fixedBet = 0;
    if(strat==3){
        std::cout << "Please enter fixed bet number"; // no flush needed
        std::cin >> fixedBet;
    }
    
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



//every c progrms needs a main method
int main(){
    std::cout << roll(2, 0);
    return 0;
}


