///
/// \file 				StateMachine.h

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    ST_IDLE,
    ST_LED_ON,
    ST_LED_OFF
} state_t;

typedef struct {
    state_t currState;
} stateMachine_t;

/// \brief      All the possible events that can occur for this state machine.
/// \details    Unlike states_t, these do not need to be kept in a special order.
typedef enum {
    EV_ANY,
    EV_NONE,
    EV_BUTTON_PUSHED,
    EV_BUTTON_RELEASED,
    EV_TIME_OUT,
} event_t;

void StateMachine_Init(stateMachine_t * stateMachine);
void StateMachine_RunIteration(stateMachine_t *stateMachine, event_t event);
const char * StateMachine_GetStateName(state_t state);

#endif