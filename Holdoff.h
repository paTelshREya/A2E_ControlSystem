#ifndef HOLD_H
#define HOLD_H
#include "State.h"

// Holdoff class

class Holdoff : public State {
    public: 
        Holdoff();
        Holdoff(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        ~Holdoff() override;

        void enter() override;
        void execute() override;
        void update(char button_type) override;
        void exit() override;
};

#endif
