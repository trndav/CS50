#include <stdio.h>
#include <time.h>

int main(void) {
    // Get current time
    time_t now;
    time(&now);

    // Get current year and next year
    struct tm *local = localtime(&now);
    int currentYear = local->tm_year + 1900;
    int nextYear = currentYear + 1;

    // Set next New Year's Day date and time
    struct tm newYearDate = {0};
    newYearDate.tm_year = nextYear - 1900; // Year is represented as years since 1900
    newYearDate.tm_mon = 0; // January (month 0)
    newYearDate.tm_mday = 1; // 1st day
    newYearDate.tm_hour = 0; // 00:00:00 (midnight)
    newYearDate.tm_min = 0;
    newYearDate.tm_sec = 0;

    // Convert dates to time_t
    time_t newYearTime = mktime(&newYearDate);
    time_t currentTime;

    while (1) {
        time(&currentTime); // Update current time within the loop
        double secondsRemaining = difftime(newYearTime, currentTime);

        if (secondsRemaining <= 0) {
            printf("Happy New Year!\n");
            break; // Exit the loop when New Year's Day arrives
        }

        printf("Time remaining until New Year's 223Day: %.0f seconds\n", secondsRemaining);
        
        // Check if user wants to break the countdown
        printf("Press 'q' to quit: ");
        char input;
        scanf(" %c", &input);

        if (input == 'q') {
            printf("Countdown terminated by user.\n");
            break; // Exit the loop if the user enters 'q'
        }
    }

    return 0;
}
