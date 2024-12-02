#ifndef TRIGGER_H
#define TRIGGER_H
#include "State.h"

// TriggerOnly class

class TriggerOnly : public State {
    public: 
        TriggerOnly();
        TriggerOnly(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        ~TriggerOnly() override;

        void enter() override;
        void execute() override;
        void update(char button_type) override;
        void exit() override;
};

#endif
