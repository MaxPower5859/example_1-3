#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    gpio_t gasDetector;
    gpio_init_in_ex(&gasDetector,D2,PullDown);
    

    gpio_t overTempDetector;
    gpio_init_in_ex(&overTempDetector,D3,PullDown);
    

    gpio_t alarmOffButton;
    gpio_init_in_ex(&alarmOffButton,BUTTON1,PullDown);
    

    gpio_t alarmLed;
    gpio_init_out(&alarmLed, LED1);

    gpio_write(&alarmLed, OFF);

    bool alarmState = OFF;

    while (true) {

        if ( gpio_read(&gasDetector) == ON || gpio_read(&overTempDetector) == ON ) {
            alarmState = ON;
        }

        gpio_write(&alarmLed, alarmState);

        if ( gpio_read(&alarmOffButton) == ON ) {
            alarmState = OFF;
        }
    }
}