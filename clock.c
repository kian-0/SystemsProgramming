#include <stdio.h>
#include <stdint.h>

#define TIMER_ADDRESS 0xFFFF // Last addressable memory word
#define LCD_DEVICE 64        // LCD is mapped to device 64

// Mock function to simulate writing to the LCD device
void write_to_lcd(char *str)
{
    while (*str)
    {
        putchar(*str); // Simulates sending a character to the LCD
        str++;
    }
}

// Function to format and display time
void display_clock(uint32_t timer)
{
    uint32_t seconds_since_midnight = timer & 0x7FFFFFFF; // Mask out the MSB
    int is_24_hour = (timer & 0x80000000) != 0;           // Check the MSB

    int hours = (seconds_since_midnight / 3600) % 24;
    int minutes = (seconds_since_midnight / 60) % 60;

    char output[6]; // HHMMT format (5 characters + null terminator)

    if (is_24_hour)
    {
        // Format for 24-hour time (HHMM)
        sprintf(output, "%02d%02d", hours, minutes);
    }
    else
    {
        // Format for 12-hour time (HHMMT)
        char period = (hours >= 12) ? 'P' : 'A';
        hours = hours % 12;
        if (hours == 0)
            hours = 12; // Handle midnight and noon
        sprintf(output, "%02d%02d%c", hours, minutes, period);
    }

    // Output to LCD
    write_to_lcd(output);
}

int main()
{
    // Simulate timer value for testing
    uint32_t timer = 0x80002710; // Example: 10,000 seconds since midnight in 24-hour format
    display_clock(timer);

    timer = 0x00002710; // Example: 10,000 seconds since midnight in 12-hour format
    display_clock(timer);

    return 0;
}