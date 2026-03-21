
#ifndef KIIYUO_RATABS_PRINT_ERRORS_H
#define KIIYUO_RATABS_PRINT_ERRORS_H

#include <string_view>

namespace Print
{
    namespace Errors
    {
        void pleaseReport();
        void genericError();
        void genericError(std::string_view extraDetails);
        void notFound();
        void actionNotfound();
        void noMatchCase(auto num, std::string_view location);
        void wrongRandNum(int num);
        void wrongNum(int num);
        void noTargetSet();
        void cannotCreateObject();
        void noEncounterPresent();
    }
}

#endif // !KIIYUO_RATABS_PRINT_ERRORS_H