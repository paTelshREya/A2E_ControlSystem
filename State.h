#ifndef STATE_H
#define STATE_H
#include <iostream>

// State class is an abstarct class 
// and used as a base class for all posible states of the Control System

class State {
    public: 
        State() = default;
        State(bool trigger_button_value,
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value);
        virtual ~State() = default;

        // Member Functions
        virtual void enter() = 0;
        virtual void execute() = 0;
        virtual void update(char button_type) = 0;
        virtual void exit() = 0;

        // Getter and Setter Methods
        bool get_trigger_button_value();
        bool get_forward_button_value();
        bool get_reverse_button_value();
        bool get_forward_drive_valve_value();
        bool get_reverse_drive_valve_value();
        
        void set_trigger_button_value(bool button_value);
        void set_forward_button_value(bool button_value);
        void set_reverse_button_value(bool button_value);
        void set_forward_drive_valve_value(bool button_value);
        void set_reverse_drive_valve_value(bool button_value);
    
    private:
        // Member variables
        bool m_trigger_button_value = false;
        bool m_forward_button_value = false;
        bool m_reverse_button_value = false;
        bool m_forward_drive_valve_value = false;
        bool m_reverse_drive_valve_value = false;
};

#endif
