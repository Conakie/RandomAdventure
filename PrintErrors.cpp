
#include <iostream>
#include <string_view>
#include "PrintErrors.h"



void Print::Errors::pleaseReport()
{
    std::cout << "Nekoto: \"If you could report this to Nanre, you would do us a favour.\n"
        << "And if you can add a sceenshot, even better!\n"
        << "Thank you for any help and for playing.\"\n";
}

void Print::Errors::genericError()
{
    std::cout << "\nError 000: An error occurred. Unknown reason.\n";
    pleaseReport();
}

void Print::Errors::genericError(std::string_view extraDetails)
{
    std::cout << "\nError 000: An error occurred. Below are info about the error:\n"
        << extraDetails << "\n";
    pleaseReport();
}

void Print::Errors::notFound()
{
    std::cout << "\nError 001: Not found!\n";
    pleaseReport();
}

void Print::Errors::actionNotfound()
{
    std::cout << "Error 002: Action not found!\n";
    pleaseReport();
}

void Print::Errors::noMatchCase(auto num, std::string_view location)
{
    std::cout << "Error 003: No case matched with value: " << num << ".\n"
        << "Location: \"" << location << "\"";
    pleaseReport();
}

void Print::Errors::wrongRandNum(int num)
{
    std::cout << "Error 004: RNG set with wrong max/min value! (Result: " << num << ")\n";
    pleaseReport();
}

void Print::Errors::wrongNum(int num)
{
    std::cout << "Error 005: Wrong number! (Number: " << num << ")\n";
    pleaseReport();
}

void Print::Errors::noTargetSet()
{
    std::cout << "Error 006: No target set!\n";
    pleaseReport();
}

void Print::Errors::cannotCreateObject()
{
    std::cout << "Erorr 007: The OS refused to give the program the ram for an object.\n";
    pleaseReport();
}

void Print::Errors::noEncounterPresent()
{
    std::cout << "Error 008: No encounter present in the room when there should be one!\n";
    pleaseReport();
}
