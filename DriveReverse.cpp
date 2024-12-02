#include "DriveReverse.h"

DriveReverse::DriveReverse() {
    std::cout << "Creating an object of DriveReverse State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

DriveReverse::DriveReverse(bool trigger_button_value, 
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
    std::cout << "Creating an object of DriveReverse State using Custom Constructors." << std::endl;
}

DriveReverse::~DriveReverse() {
    exit();
    std::cout << "Removing an object of DriveReverse State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void DriveReverse::enter() {
    std::cout << "Entering into the DriveReverse State." << std::endl;
}

void DriveReverse::execute() {
    std::cout << "Executing the DriveReverse State." << std::endl;
    if(!(get_trigger_button_value() == 1) && (get_forward_button_value() == 0) && (get_reverse_button_value() == 1)) {
        std::cout << "Only Trigger button and Reverse button should be pressed!" << std::endl;
    } else {
        std::cout << "All good." << std::endl;
        set_forward_drive_valve_value(0);
        set_reverse_drive_valve_value(1);
    }
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    std::cout << "[Trigger Button: " << get_trigger_button_value() << 
                ", Forward Button: " << get_forward_button_value() <<
                ", Reverse Button: " << get_reverse_button_value() <<
                ", Forward Drive Valve: " << get_forward_drive_valve_value() <<
                ", Reverse Drive Valve: " << get_reverse_drive_valve_value() << "]" << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void DriveReverse::update(char button_type) {
    std::cout << "Updateing the value in DriveReverse State." << std::endl;
    switch (button_type)
    {
        case 'T':
            set_trigger_button_value(0);
            set_forward_button_value(0);
            set_reverse_button_value(0);
            break;
        case 'F':
            std::cout << "Please release the Reverse button first!" << std::endl;
            break;
        case 'R':
            set_reverse_button_value(0);
            break;
        default:
            std::cout << "Please enter correct button value." << std::endl;
            break;
    }
}

void DriveReverse::exit() {
    std::cout << "Exiting the DriveReverse State." << std::endl;
}
