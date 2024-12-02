#include "DriveForward.h"

DriveForward::DriveForward() {
    std::cout << "Creating an object of DriveForward State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

DriveForward::DriveForward(bool trigger_button_value, 
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
    std::cout << "Creating an object of DriveForward State using Custom Constructors." << std::endl;
}

DriveForward::~DriveForward() {
    exit();
    std::cout << "Removing an object of DriveForward State." << std::endl;
    std::cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

void DriveForward::enter() {
    std::cout << "Entering into the DriveForward State." << std::endl;
}

void DriveForward::execute() {
    std::cout << "Executing the DriveForward State." << std::endl;
    if(!(get_trigger_button_value() == 1) && (get_forward_button_value() == 1) && (get_reverse_button_value() == 0)) {
        std::cout << "Only Trigger button and Forward button should be pressed!" << std::endl;
    } else {
        std::cout << "All good." << std::endl;
        set_forward_drive_valve_value(1);
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

void DriveForward::update(char button_type) {
    std::cout << "Updateing the value in DriveForward State." << std::endl;
    switch (button_type)
    {
        case 'T':
            set_trigger_button_value(0);
            set_forward_button_value(0);
            set_reverse_button_value(0);
            break;
        case 'F':
            set_forward_button_value(0);
            break;
        case 'R':
            std::cout << "Please release the Forward button first!" << std::endl;
            break;
        default:
            std::cout << "Please enter correct button value." << std::endl;
            break;
    }
}

void DriveForward::exit() {
    std::cout << "Exiting the DriveForward State." << std::endl;
}
