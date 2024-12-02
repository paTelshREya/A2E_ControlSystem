#ifndef IDLE_H
#define IDLE_H
#include "State.h"

// Idle class

class Idle : public State {
    public: 
        Idle();
        Idle(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        ~Idle() override;

        void enter() override;
        void execute() override;
        void update(char button_type) override;
        void exit() override;
};

#endif
