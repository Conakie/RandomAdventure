
#ifndef EVERYUSEDFUNC_RA
#define EVERYUSEDFUNC_RA

// called in main for setting up seeds and some useless stuff
void setup();

// ignore this unless you're working on the input func
void ignoreLine();

// print a list with all actions the player can do
void listAzioni();

// print a list with all actions the player can do
void actionsList();

// print all stats of the player
void printPlayerStats();

// notify the user that the input is not possible at the moment
void printNotPossible();

// hold a int value, if edit is false, value won't be used
int intValuekeeper(int value = 0, bool edit = false);

// hold a double value, if edit is false, value won't be used
double doubleValueKeeper(double value = 0, bool edit = false);

//hold a bool value, if edit is false, value won't be used
bool boolValueKeeper(bool value = 0, bool edit = false);

// loop until the first valid input with 'w', then exit the function
void waitForAnyKey();

// loop until the first valid input with 'w', then exit the function
void aspettaPerW();

// returns @number as a char.
// Example -> convertToChar(9) returns '9'
char convertToChar(int number);

// wait @seconds before doing stuff again
void delay(int seconds);
#endif // !EVERYUSEDFUNC_RA
