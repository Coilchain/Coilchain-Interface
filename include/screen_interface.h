
#ifndef __SCREEN_INTERFACE_H__
#define __SCREEN_INTERFACE_H__

#endif

struct Ui_data {
    int bike_speed;
    int assistance_level;
    int generated_power;
    int cadence;
};

struct Ui_data * screen_interface_init();

// Read the data that is being sent be the motor controller
void read_controller_data();

// Updates the information that is shown on the screen
void update_ui_data();