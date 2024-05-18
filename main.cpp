#include "mbed.h"
#include <cstdio>

/*  Couldnt find p13, p16, p23 or p25 on the board. While PC_13 is the button
    I couldnt make sense of using that button when the rest of the instruction
    seemed not to correspond. I took a general approach that relates to external
    buttons and outputs
*/

// Initialise digital ins/outs to corresponding digital pins.
DigitalIn p13(D3);
DigitalIn p16(D4);

DigitalOut p23(D5);
DigitalOut p25(D6);

// main() runs in its own thread in the OS
int main()
{
    while (true) {
        if(p13 == true && p16 == false){ //true indicates a boolian 1 which means the button is pressed

            p23.write(1);// send required output to digital out pins
            p25.write(0);

        }
        else if(p16 == true && p13 == false){

            p23.write(0);
            p25.write(1);
/*Code compiles but for some reason on line above the following message appears before p25.write(1)
"Expected ';' after expression (fix available)clang(expected_semi_after_expr)"
All semicolons seem to be where needed however the red squiggle wont go away.*/
        }
        else if(p16 == true && p13 == true){ // Condition for possibility not described in flowchart

            p25.write(1);
            p23.write(1);

        }
        else{
            // in case of no button press, turn off the devices connected to outputs
            p23.write(0);
            p25.write(0);

        }
    }
}

