
#include <iostream>
#include <string_view>
#include "PrintErrors.h"



void Print::Errors::pleaseReport()
{
    std::cout << "Please, report this to Nanre.\n"
        << "If possible add a screenshot and error number and info.\n"
        << "Thanks, this can make OUR game better.\n";
}

void Print::Errors::generalError()
{
    std::cout << "\nError 000: An error occurred. Unknown reason.\n";
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
