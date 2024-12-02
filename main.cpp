#include "StateController.h"

int main(){

    std::cout << std::endl;
    std::cout << "*-*-*-* Control System Implementation *-*-*-*" << std::endl;
    std::cout << "* At a time only one button can be pressed. *" << std::endl;
    std::cout << "Enter 'T' for press or release Trigger Button" << std::endl;
    std::cout << "Enter 'F' for press or release Forward Button" << std::endl;
    std::cout << "Enter 'R' for press or release Reverse Button" << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;

    StateController stateController;
    stateController.Init();

    char button_type;

    while (button_type != 'Q')
    {   
        stateController.Execute();
        std::cout << ">>>>> Please press or release the button! >>>>>" << std::endl;
        std::cin >> button_type;

        if (button_type == 'T' || button_type == 'F' || button_type == 'R')
        {
            stateController.Update(button_type);
        } else if(button_type == 'Q') {
            return 0;
        }
        else {
            std::cout << "Please enter correct button value." << std::endl;
            std::cout << std::endl;
        }
        stateController.TransitionTo();
    }

    return 0;
}
