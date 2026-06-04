
#include <iostream>
#include <string_view>
#include <print>
#include "PrintErrors.h"



void Print::Errors::pleaseReport()
{
    std::print("Nekoto: \"If you could report this to Nanre, you would do us a favour.\n");
    std::print("If you can, could you include a screenshot of the game when it happened?\n");
    std::print("Thank you for any help and for playing this game.\"\n");
}

void Print::Errors::genericError()
{
    std::print("\nError 000: An error occurred. Unknown reason.\n");
    pleaseReport();
}

void Print::Errors::genericError(std::string_view extraDetails)
{
    std::print("\nError 000: An error occurred. Below are info about the error:\n{}.\n",
        extraDetails);
    pleaseReport();
}

void Print::Errors::notFound()
{
    std::print("\nError 001: Not found!\n");
    pleaseReport();
}

void Print::Errors::actionNotfound()
{
    std::print("Error 002: Action not found!\n");
    pleaseReport();
}

void Print::Errors::wrongRandNum(int num)
{
    std::print("Error 004: RNG set with wrong max/min value! (Number: {})\n", num);
    pleaseReport();
}

void Print::Errors::wrongNum(int num)
{
    std::print("Error 005: Wrong number! (Number: {})\n", num);
    pleaseReport();
}

void Print::Errors::noTargetSet()
{
    std::print("Error 006: No target set!\n");
    pleaseReport();
}

void Print::Errors::cannotCreateObject()
{
    std::print("Erorr 007: The OS refused to give the program the ram for an object.\n");
    pleaseReport();
}

void Print::Errors::noEncounterPresent()
{
    std::print("Error 008: No encounter present in the room when there should be one!\n");
    pleaseReport();
}

void Print::Errors::somethingWentWrong(std::string_view what, std::string_view where)
{
    std::print("Error 009: Something went wrong in the code.\n");
    if (!what.empty())
        std::print("Details: {}.\n", what);
    if (!where.empty())
        std::print("At: {}.\n", where);
    pleaseReport();
}