#include "Idle.h"

Idle::Idle() {
    std::cout << "Creating an object of Idle State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

Idle::Idle(bool trigger_button_value, 
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
    std::cout << "Creating an object of Idle State using Custom Constructors." << std::endl;
}

Idle::~Idle() {
    exit();
    std::cout << "Removing an object of Idle State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void Idle::enter() {
    std::cout << "Entering into the Idle State." << std::endl;
}

void Idle::execute() {
    std::cout << "Executing the Idle State." << std::endl;

    if (get_trigger_button_value() && get_forward_button_value() && get_reverse_button_value()) {
        std::cout << "Please release all buttons!" << std::endl;
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

void Idle::update(char button_type) {
    std::cout << "Updateing the value in Idle State." << std::endl;
    switch (button_type)
    {
        case 'T':
            set_trigger_button_value(1);
            break;
        case 'F':
            std::cout << "Please press the Trigger button first!" << std::endl;
            break;
        case 'R':
            std::cout << "Please press the Trigger button first!" << std::endl;
            break;
        default:
            std::cout << "Please enter correct button value." << std::endl;
            break;
    }
}

void Idle::exit() {
    std::cout << "Exiting the Idle State." << std::endl;
}
