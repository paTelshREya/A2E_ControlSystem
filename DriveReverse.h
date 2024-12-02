#ifndef REVERSE_H
#define REVERSE_H
#include "State.h"

// DriveReverse class

class DriveReverse : public State {
    public: 
        DriveReverse();
        DriveReverse(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        ~DriveReverse() override;

        void enter() override;
        void execute() override;
        void update(char button_type) override;
        void exit() override;
};

#endif
