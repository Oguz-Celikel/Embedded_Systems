
#include <avr/io.h>
int main(void) {

	DDRB = 0xFF; // All port-B pins are configured as an output
	DDRD = 0xFC; // Least two port-D pins are configured as an input
	PORTB = 0x01; // PINB0 pin is configured as a high

    while(1){
        if((PIND & _BV(PIND0)) == 0x00){  // It runs when SW0 is closed
            if((PIND & _BV(PIND1)) == 0x00){   // It runs when SW0 and SW1 are closed
                if(PORTB == 0x01){     // Check bit position
//                    PORTB = 0x01;
//                    PORTB = 0x01;
//                    PORTB = 0x01;
//                    PORTB = 0x01;
                    PORTB = 0x80;      // Reload for rotation
                }
                else{
                    PORTB = PORTB >> 1;   // Right-Shift operation for rotation
                }
            }
            else{
                if(PORTB == 0x80){      // Check bit position
//                    PORTB = 0x80;
//                    PORTB = 0x80;
//                    PORTB = 0x80;
                    PORTB = 0x01;       // Reload for rotation
                }
                else{
                    PORTB = PORTB << 1;   // Left-Shift operation for rotation
                }
            }
        }
        else{
            continue;
        }
    }
return 0;
}

