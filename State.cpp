#include "State.h"

State::State(bool trigger_button_value, 
                bool forward_button_value,
                bool reverse_button_value,
                bool forward_drive_valve_value,
                bool reverse_drive_valve_value)
                : m_trigger_button_value(trigger_button_value),
                    m_forward_button_value(forward_button_value),
                    m_reverse_button_value(reverse_button_value),
                    m_forward_drive_valve_value(forward_drive_valve_value),
                    m_reverse_drive_valve_value(reverse_drive_valve_value) {

}

bool State::get_trigger_button_value() {
    return m_trigger_button_value;
}

bool State::get_forward_button_value() {
    return m_forward_button_value;
}

bool State::get_reverse_button_value() {
    return m_reverse_button_value;
}

bool State::get_forward_drive_valve_value() {
    return m_forward_drive_valve_value;
}

bool State::get_reverse_drive_valve_value() {
    return m_reverse_drive_valve_value;
}

void State::set_trigger_button_value(bool button_value) {
    m_trigger_button_value = button_value;
}

void State::set_forward_button_value(bool button_value) {
    m_forward_button_value = button_value;
}

void State::set_reverse_button_value(bool button_value) {
    m_reverse_button_value = button_value;
}

void State::set_forward_drive_valve_value(bool button_value) {
    m_forward_drive_valve_value = button_value;
}

void State::set_reverse_drive_valve_value(bool button_value) {
    m_reverse_drive_valve_value = button_value;
}
