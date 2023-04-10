// C++ Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "main.h"

// multiple constructor definitions allows for overloading
Military::Military(int troops, int startMoney) {
    reserveCount = troops;
    mobalizingCount = 0;
    activeCount = 200;
    money = startMoney;
}

// the default constructor: use "::" to append/modify or access the 
// class/namespace instead of an instance. In this case i am appending
// a definition to the class for one of its funcions, which also happens
// to be a special funcion: the constuctor
Military::Military() {
    reserveCount = 500;
    mobalizingCount = 0;
    activeCount = 200;
    money = 5000;
}

// function defined in the cpp file, header file is only for declarations
void Military::Mobalize(int count) {
    //consider if we try to mobalize more troops than
    //we actually have in the reserve, then use as many as possible
    int change = count < reserveCount ? count : reserveCount;
    reserveCount -= change;
    mobalizingCount += change;
}

// constructor for the subclass, done by make a funcion with same name
// as the class itself. Constructors run when an instance is created
// this is like the Start() or Awake() funcion on Unity's gameobjects
ArmorDivision::ArmorDivision() {
    reserveCount = 50000;
    mobalizingCount = 0;
    activeCount = 200;
    money = 500;
}

//function that uses references for parameters
bool ArmorDivision::Attack(Military& attackedForce) {
    int forces = attackedForce.activeCount;
    int casualties = forces /= 2;

    attackedForce.activeCount -= casualties;
    std::cout << "Deaths: " << casualties << std::endl;

    return true;
}

// alt way to do the same thing with pointers as parameters
bool ArmorDivision::Attack(Military* attackedForce) {
    // use -> to automatically dereference pointer (get value at memory
    // address, not the address itself, which is the pointer)
    int forces = attackedForce->activeCount;
    int casualties = forces /= 2;

    // alternatively, we can manually dereference with the * and then we
    // can use the . like normal, but this is messier
    (*attackedForce).activeCount -= casualties;
    std::cout << "Deaths: " << casualties << std::endl;

    return true;
}

int main()
{
    Military usa(1'000'000, 26'000'000);

    ArmorDivision russia;
    std::cout << "USA troops: " << usa.GetTroopCount() << std::endl;
    std::cout << "Russia is attacking USA" << std::endl;

    //using references
    const bool worked = russia.Attack(usa);
    std::cout << "Post attack USA troops: " << usa.GetTroopCount() << std::endl;

    //using pointers to do the same thing
    Military* usaPtr = &usa;
    std::cout << "Russia is BOMBING USA" << std::endl;
    const bool workedAgain = russia.Attack(usaPtr);
    std::cout << "Post bombing USA troops: " << usa.GetTroopCount() << std::endl;
}

