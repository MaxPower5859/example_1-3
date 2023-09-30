#include "mbed.h"
#include "arm_book_lib.h"

int main(){
    /* 
    Usando la clase gpio_t puedo definir mis objetos y luego utilizarlos
    basicamnete es el mismo codigo que antes pero ahora solo uso librerias de C
    y estoy a mas bajo nivel, ya que controlo directamente los puertos del micro
    y no es que me abstraigo como con las clases DitalInOut
    */

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