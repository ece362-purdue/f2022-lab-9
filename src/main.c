/**
  ******************************************************************************
  * @file    main.c
  * @author  Weili An
  * @version V1.0
  * @date    Nov 4, 2022
  * @brief   ECE 362 Lab 9 Student template
  ******************************************************************************
*/

#include "stm32f0xx.h"
#include <math.h>   // for M_PI

void nano_wait(int);

// 16-bits per digit.
// The most significant 8 bits are the digit number.
// The least significant 8 bits are the segments to illuminate.
uint16_t msg[8] = { 0x0000,0x0100,0x0200,0x0300,0x0400,0x0500,0x0600,0x0700 };
extern const char font[];
// Print an 8-character string on the 8 digits
void print(const char str[]);
// Print a floating-point value.
void printfloat(float f);


//============================================================================
// Lab 9 Functions
//============================================================================
void setup_tim3(void) {
    // TODO: Enable GPIO C

    // TODO: Configure the PC6-9 to be the outputs of TIM3 Ch 1-4
    // TODO: First we clear their MODER bits
    // TODO: Then we set them to AF mode
    // TODO: Set PC6-9 to use AF0 since this corresponds to the TIM3 Ch1-4
    // AFR[0] -> AFRL
    // AFR[1] -> AFRH

    // TODO: Enable TIM3 with 1 Hz timer

    // TODO: Set to PWM mode 1 for all channels
    // Can use the following code to set a channel to PWM mode 1 (110)
    // This line set Timer x's channel 1 to be PWM mode 1 (OC1M bits with 110)
    // TIMx->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;

    // TODO: Enable all 4 channel outputs in `TIM3_CCER` using `CC1E` bit

    // TODO: Enable TIM3 counter

    // TODO: Set CCR values
}

void setup_tim1(void) {
    // Generally the steps are similar to those in setup_tim3
    // However, we will need to set the MOE bit in BDTR
    // Enable MOE bit in BDTR
    // TIM1->BDTR |= TIM_BDTR_MOE;
}

int getrgb(void);

// Helper function for you
// Accept a byte in BCD format and convert it to decimal
uint8_t bcd2dec(uint8_t bcd) {
    // Lower digit
    uint8_t dec = bcd & 0xF;

    // Higher digit
    dec += 10 * (bcd >> 4);
    return dec;
}

void setrgb(int rgb) {
    uint8_t b = bcd2dec(rgb & 0xFF);
    uint8_t g = bcd2dec((rgb >> 8) & 0xFF);
    uint8_t r = bcd2dec((rgb >> 16) & 0xFF);

    // TODO: Assign values to TIM1->CCRx registers
    // Remember these are all percentage
    // Also LEDs are on when the corresponding PWM output is low
    // so you might want to invert some numbers
}

//============================================================================
// Lab 9 Functions end, rest are just copying your previous lab code
//============================================================================


//============================================================================
// enable_ports()
//============================================================================
void enable_ports(void) {

}

//============================================================================
// setup_dma()
//============================================================================
void setup_dma(void) {

}

//============================================================================
// enable_dma()
//============================================================================
void enable_dma(void) {

}

//============================================================================
// init_tim15()
//============================================================================
void init_tim15(void) {

}

uint8_t col; // the column being scanned

void drive_column(int);   // energize one of the column outputs
int  read_rows();         // read the four row inputs
void update_history(int col, int rows); // record the buttons of the driven column
char get_key_event(void); // wait for a button event (press or release)
char get_keypress(void);  // wait for only a button press event.
float getfloat(void);     // read a floating-point number from keypad
void show_keys(void);     // demonstrate get_key_event()

//============================================================================
// The Timer 7 ISR
//============================================================================
// TODO To be copied


//============================================================================
// init_tim7()
//============================================================================
void init_tim7(void) {

}

//=============================================================================
// Part 3: Analog-to-digital conversion for a volume level.
//=============================================================================
uint32_t volume = 2400;

//============================================================================
// setup_adc()
//============================================================================
void setup_adc(void) {

}

//============================================================================
// Varables for boxcar averaging.
//============================================================================
#define BCSIZE 32
int bcsum = 0;
int boxcar[BCSIZE];
int bcn = 0;

//============================================================================
// Timer 2 ISR
//============================================================================
// TODO To be copied


//============================================================================
// init_tim2()
//============================================================================
void init_tim2(void) {

}


//===========================================================================
// Part 4: Create an analog sine wave of a specified frequency
//===========================================================================
void dialer(void);

// Parameters for the wavetable size and expected synthesis rate.
#define N 1000
#define RATE 20000
short int wavetable[N];
int step0 = 0;
int offset0 = 0;
int step1 = 0;
int offset1 = 0;

//===========================================================================
// init_wavetable()
// Write the pattern for a complete cycle of a sine wave into the
// wavetable[] array.
//===========================================================================
void init_wavetable(void) {
    for(int i=0; i < N; i++)
        wavetable[i] = 32767 * sin(2 * M_PI * i / N);
}

//============================================================================
// set_freq()
//============================================================================
void set_freq(int chan, float f) {
    if (chan == 0) {
        if (f == 0.0) {
            step0 = 0;
            offset0 = 0;
        } else
            step0 = (f * N / RATE) * (1<<16);
    }
    if (chan == 1) {
        if (f == 0.0) {
            step1 = 0;
            offset1 = 0;
        } else
            step1 = (f * N / RATE) * (1<<16);
    }
}

//============================================================================
// setup_dac()
//============================================================================
void setup_dac(void) {

}

//============================================================================
// Timer 6 ISR
//============================================================================
// TODO To be copied


//============================================================================
// init_tim6()
//============================================================================
void init_tim6(void) {

}

//============================================================================
// All the things you need to test your subroutines.
//============================================================================
int main(void) {

    // Demonstrate part 1
#define TEST_TIMER3
#ifdef TEST_TIMER3
    setup_tim3();
    for(;;) { }
#endif

    // Initialize the display to something interesting to get started.
    msg[0] |= font['E'];
    msg[1] |= font['C'];
    msg[2] |= font['E'];
    msg[3] |= font[' '];
    msg[4] |= font['3'];
    msg[5] |= font['6'];
    msg[6] |= font['2'];
    msg[7] |= font[' '];

    enable_ports();
    setup_dma();
    enable_dma();
    init_tim15();
    init_tim7();
    setup_adc();
    init_tim2();
    init_wavetable();
    init_tim6();

    setup_tim1();

    // demonstrate part 2
//#define TEST_TIM1
#ifdef TEST_TIM1
    for(;;) {
        for(float x=10; x<2400; x *= 1.1) {
            TIM1->CCR1 = TIM1->CCR2 = TIM1->CCR3 = 2400-x;
            nano_wait(100000000);
        }
    }
#endif

    // demonstrate part 3
//#define MIX_TONES
#ifdef MIX_TONES
    set_freq(0, 1000);
    for(;;) {
        char key = get_keypress();
        if (key == 'A')
            set_freq(0,getfloat());
        if (key == 'B')
            set_freq(1,getfloat());
    }
#endif

    // demonstrate part 4
//#define TEST_SETRGB
#ifdef TEST_SETRGB
    for(;;) {
        char key = get_keypress();
        if (key == 'A')
            set_freq(0,getfloat());
        if (key == 'B')
            set_freq(1,getfloat());
        if (key == 'D')
            setrgb(getrgb());
    }
#endif

    // Have fun.
    dialer();
}
