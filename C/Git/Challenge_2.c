#include <stdio.h>

typedef enum {
    RETRACTED,
    RETRACTING,
    EXTENDED,
    EXTENDING
} LandingGearState;

void retract(LandingGearState* state) {
    if (*state == RETRACTED) {
        printf("Landing gear is already retracted.\n");
    } else if (*state == EXTENDED) {
        printf("Retracting landing gear.\n");
        *state = RETRACTING;
    }
}

void extend(LandingGearState* state) {
    if (*state == RETRACTED) {
        printf("Extending landing gear.\n");
        *state = EXTENDING;
    } else if (*state == EXTENDED) {
        printf("Landing gear is already extended.\n");
    }
}

void update(LandingGearState* state) {
    if (*state == RETRACTING) {
        printf("Landing gear is currently retracting...\n");
        // Perform retracting logic here
        *state = RETRACTED;
        printf("Landing gear has been retracted.\n");
    } else if (*state == EXTENDING) {
        printf("Landing gear is currently extending...\n");
        // Perform extending logic here
        *state = EXTENDED;
        printf("Landing gear has been extended.\n");
    }
}

int main() {
    LandingGearState state = RETRACTED;

    // Test the landing gear FSM
    extend(&state);
    update(&state);
    retract(&state);
    update(&state);

    return 0;
}
