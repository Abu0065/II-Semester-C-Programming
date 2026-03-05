//Kalnirnay: Conversion from Gregorian to Hindi calendar.
#include <stdio.h>
#include <stdlib.h>
void convertToHindiCalendar(int day, int month, int year) {
    const char* hindiMonths[] = {"Chaitra", "Vaishakh", "Jyeshtha", "Ashadha", "Shravana", "Bhadrapada", "Ashwin", "Kartika", "Margashirsha", "Pausha", "Magha", "Phalguna"};
    const char* hindiDays[] = {"Pratipada", "Dwitiya", "Tritiya", "Chaturthi", "Panchami", "Shashthi", "Saptami", "Ashtami", "Navami", "Dashami", "Ekadashi", "Dvadashi", "Trayodashi", "Chaturdashi", "Purnima"};

    int hindiMonthIndex = (month - 1) % 12; 
    int hindiDayIndex = (day - 1) % 15; 

    printf("Gregorian Date: %d/%d/%d\n", day, month, year);
    printf("Hindi Calendar Date: %s %s\n", hindiDays[hindiDayIndex], hindiMonths[hindiMonthIndex]);
}
int main() {
    int day, month, year;
    printf("Enter Gregorian date (day month year): ");
    scanf("%d %d %d", &day, &month, &year);
    convertToHindiCalendar(day, month, year);
    return 0;
}
