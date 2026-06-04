
#ifndef KIIYUO_RATABS_PRINT_ERRORS_H
#define KIIYUO_RATABS_PRINT_ERRORS_H

#include <string_view>
#include <print>
#include <ostream>

namespace Print
{
    namespace Errors
    {
        void pleaseReport();
        void genericError();
        void genericError(std::string_view extraDetails);
        void notFound();
        void actionNotfound();
        void noMatchCase(auto num, std::string_view location)
        {
            std::print("Error 003: No case matched with value: {}", num);
            std::print("Location: \"{}\"\n", location);
            pleaseReport();
        }
        void wrongRandNum(int num);
        void wrongNum(int num);
        void noTargetSet();
        void cannotCreateObject();
        void noEncounterPresent();
        void somethingWentWrong(std::string_view what, std::string_view where);
    }
}

#endif // !KIIYUO_RATABS_PRINT_ERRORS_H