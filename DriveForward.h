#ifndef FORWARD_H
#define FORWARD_H
#include "State.h"

// DriveForward class

class DriveForward : public State {
    public: 
        DriveForward();
        DriveForward(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        ~DriveForward() override;

        void enter() override;
        void execute() override;
        void update(char button_type) override;
        void exit() override;
};

#endif
