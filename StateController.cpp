#include "StateController.h"

void StateController::Init() {
    currentState = new Lockout();
}

void StateController::Execute() {
    currentState->enter();
    currentState->execute();
}

void StateController::Update(char button_type) {
    currentState->update(button_type); 
}

void StateController::TransitionTo() {
    m_trigger_button_value = currentState->get_trigger_button_value();
    m_forward_button_value = currentState->get_forward_button_value();
    m_reverse_button_value = currentState->get_reverse_button_value();
    m_forward_drive_valve_value = currentState->get_forward_drive_valve_value();
    m_reverse_drive_valve_value = currentState->get_reverse_drive_valve_value();
    
    delete currentState;

    if((m_trigger_button_value == 0) && (m_forward_button_value == 0) && (m_reverse_button_value == 0)) {
        currentState = new Idle(m_trigger_button_value, 
                                    m_forward_button_value, 
                                    m_reverse_button_value,
                                    m_forward_drive_valve_value,
                                    m_reverse_drive_valve_value);
    } else if((m_trigger_button_value == 0) && ((m_forward_button_value == 1) || (m_reverse_button_value == 1))) {
        currentState = new Idle(m_trigger_button_value, 
                                    m_forward_button_value, 
                                    m_reverse_button_value,
                                    m_forward_drive_valve_value,
                                    m_reverse_drive_valve_value);
    } else if((m_trigger_button_value == 1) && (m_forward_button_value == 0) && (m_reverse_button_value == 0) 
                && (m_forward_drive_valve_value == 0) && (m_reverse_drive_valve_value == 0)) {
        currentState = new TriggerOnly(m_trigger_button_value, 
                                    m_forward_button_value, 
                                    m_reverse_button_value,
                                    m_forward_drive_valve_value,
                                    m_reverse_drive_valve_value);
    } else if((m_trigger_button_value == 1) && (m_forward_button_value == 1) && (m_reverse_button_value == 0)) {
        currentState = new DriveForward(m_trigger_button_value, 
                                    m_forward_button_value, 
                                    m_reverse_button_value,
                                    m_forward_drive_valve_value,
                                    m_reverse_drive_valve_value);
    } else if((m_trigger_button_value == 1) && (m_forward_button_value == 0) && (m_reverse_button_value == 1)) {
        currentState = new DriveReverse(m_trigger_button_value, 
                                    m_forward_button_value, 
                                    m_reverse_button_value,
                                    m_forward_drive_valve_value,
                                    m_reverse_drive_valve_value);
    } else if((m_trigger_button_value == 1) && (m_forward_button_value == 0) && (m_reverse_button_value == 0) 
                && ((m_forward_drive_valve_value == 1) || (m_reverse_drive_valve_value == 1))) {
        currentState = new Holdoff(m_trigger_button_value, 
                                    m_forward_button_value, 
                                    m_reverse_button_value,
                                    m_forward_drive_valve_value,
                                    m_reverse_drive_valve_value);
    } else {
        std::cout << "Please release all buttons" << std::endl;
    }
}
