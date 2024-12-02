#ifndef STATECONTROLLER_H
#define STATECONTROLLER_H
#include "State.h"
#include "Lockout.h"
#include "Idle.h"
#include "TriggerOnly.h"
#include "DriveForward.h"
#include "DriveReverse.h"
#include "Holdoff.h"

// StateController class

class StateController {
    public: 
        StateController() = default;
        ~StateController() = default;

        // Member Functions
        void Init();
        void Execute();
        void Update(char button_type);
        void TransitionTo();

    private:
        // Member variables
        State *currentState = nullptr;
        bool m_trigger_button_value = false;
        bool m_forward_button_value = false;
        bool m_reverse_button_value = false;
        bool m_forward_drive_valve_value = false;
        bool m_reverse_drive_valve_value = false;
};

#endif
