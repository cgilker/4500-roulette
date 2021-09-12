/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
    

    return 0;
}

int main(){
    std::cout << roll(2, 0);
    return 0;
}
