#include "Lockout.h"

Lockout::Lockout() {
    std::cout << "Creating an object of Lockout State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

Lockout::Lockout(bool trigger_button_value, 
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
    std::cout << "Creating an object of Lockout State using Custom Constructors." << std::endl;
}

Lockout::~Lockout() {
    exit();
    std::cout << "Removing an object of Lockout State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void Lockout::enter() {
    std::cout << "Entering into the Lockout State." << std::endl;
}

void Lockout::execute() {
    std::cout << "Executing the Lockout State." << std::endl;
    if(get_trigger_button_value() || get_forward_button_value() || get_reverse_button_value()) {
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

void Lockout::update(char button_type) {
    std::cout << "Updateing the value in Lockout State." << std::endl;
    set_trigger_button_value(0);
    set_forward_button_value(0);
    set_reverse_button_value(0);
}

void Lockout::exit() {
    std::cout << "Exiting the Lockout State." << std::endl;
}
