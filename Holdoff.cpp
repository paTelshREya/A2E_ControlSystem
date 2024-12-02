#include "Holdoff.h"

Holdoff::Holdoff() {
    std::cout << "Creating an object of Holdoff State." << std::endl;
}

Holdoff::Holdoff(bool trigger_button_value, 
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value)
                : State(trigger_button_value,
                    forward_button_value,
                    reverse_button_value,
                    forward_drive_valve_value, 
                    reverse_drive_valve_value) {
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    std::cout << "Creating an object of Holdoff State using Custom Constructors." << std::endl;
}

Holdoff::~Holdoff() {
    std::cout << "Removing an object of Holdoff State." << std::endl; 
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;   
}

void Holdoff::enter() {
    std::cout << "Entering into the Holdoff State." << std::endl;
}

void Holdoff::execute() {
    std::cout << "Executing the Holdoff State." << std::endl;
    if(!(get_trigger_button_value() == 1) && (get_forward_button_value() == 0) && (get_reverse_button_value() == 0)) {
        std::cout << "Only Trigger button should be pressed!" << std::endl;
    } else {
        std::cout << "All good." << std::endl;
        set_forward_drive_valve_value(0);
        set_reverse_drive_valve_value(0);
    }
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    std::cout << "[Trigger Button: " << get_trigger_button_value() << 
                ", Forward Button: " << get_forward_button_value() <<
                ", Reverse Button: " << get_reverse_button_value() <<
                ", Forward Drive Valve: " << get_forward_drive_valve_value() <<
                ", Reverse Drive Valve: " << get_reverse_drive_valve_value() << "]" << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void Holdoff::update(char button_type) {
    std::cout << "Updateing the value in Holdoff State." << std::endl;
    switch (button_type)
    {
        case 'T':
            set_trigger_button_value(0);
            break;
        case 'F':
            std::cout << "Forward button is already released!" << std::endl;
            break;
        case 'R':
            std::cout << "Reverse button is already released!" << std::endl;
            break;
        default:
            std::cout << "Please enter correct button value." << std::endl;
            break;
    }
}

void Holdoff::exit() {
    std::cout << "Exiting the Holdoff State." << std::endl;
}
