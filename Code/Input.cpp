
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include "Everywhere Used Func.h"
#include "Input.h"
#include "PlayerActions.h"



void ignoreLine() // Remove extra characters from input
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

namespace Input
{
    int integer()
    {

        int input{ 0 };

        while (true)
        {

            std::cout << std::endl;

            std::cin >> input;

            if (!std::cin) // has a previous extraction failed or overflowed?
            {

                if (std::cin.eof()) // if the stream was closed
                {

                    exit(0); // shut down the program

                }
                else // the strem is not closed so nothing happens here
                {

                }

                std::cin.clear(); // put cin in 'normal' operation mode

            }
            else // the extraction didn't fail nor it overflowed
            {

            }

            ignoreLine();

            std::cout << std::endl;

            return input;

        }

    }

    double real()
    {

        double input{ 0 };

        while (true)
        {

            std::cout << std::endl;

            std::cin >> input;

            if (!std::cin) // has a previous extraction failed or overflowed?
            {

                if (std::cin.eof()) // if the stream was closed
                {

                    exit(0); // shut down the program

                }
                else // the strem is not closed so nothing happens here
                {

                }

                std::cin.clear(); // put cin in 'normal' operation mode

            }
            else // the extraction didn't fail nor it overflowed
            {

            }

            ignoreLine();

            std::cout << std::endl;

            return input;

        }

    }

    char character()
    {

        char input{ '0' };

        while (true)
        {

            std::cout << std::endl;

            std::cin >> input;

            if (!std::cin) // has a previous extraction failed or overflowed?
            {

                if (std::cin.eof()) // if the stream was closed
                {

                    exit(0); // shut down the program

                }
                else // the strem is not closed so nothing happens here
                {

                }

                std::cin.clear(); // put cin in 'normal' operation mode

            }
            else // the extraction didn't fail nor it overflowed
            {

            }

            ignoreLine();

            std::cout << std::endl;

            return input;
        }

    }

    std::string string()
    {
        std::string input{ };

        while (true)
        {

            std::cout << std::endl;

            std::getline(std::cin >> std::ws, input);

            if (!std::cin) // has a previous extraction failed or overflowed?
            {

                if (std::cin.eof()) // if the stream was closed
                {

                    exit(0); // shut down the program

                }
                else // the strem is not closed so nothing happens here
                {

                }

                std::cin.clear(); // put cin in 'normal' operation mode

            }
            else // the extraction didn't fail nor it overflowed
            {

            }

            ignoreLine();

            std::cout << std::endl;

            return input;

        }

    }

    PlayerActions playerAction()
    {
        PlayerActions input{ '0' };

        while (true)
        {
            std::cout << std::endl;

            std::cin >> input;

            if (!std::cin) // has a previous extraction failed or overflowed?
            {
                if (std::cin.eof()) // if the stream was closed
                {
                    exit(0); // shut down the program
                }
                else // the stream is not closed so nothing happens here
                {
                }

                std::cin.clear(); // put cin in 'normal' operation mode
            }
            else // the extraction didn't fail nor it overflowed
            {
            }

            ignoreLine();

            std::cout << std::endl;
            if (input == PlayerActions::seeActions)
            {
                actionsList();
            }
            else
            {
                return input;
            }

        }

    }
}
