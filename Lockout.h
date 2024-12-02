#ifndef LOCK_H
#define LOCK_H
#include "State.h"

// Lockout class

class Lockout : public State {
    public: 
        Lockout();
        Lockout(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        ~Lockout() override;

        void enter() override;
        void execute() override;
        void update(char button_type) override;
        void exit() override;
};

#endif
