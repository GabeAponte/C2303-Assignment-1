# C2303-Assignment-1
Gabriel Aponte
CS2303 PA1 README

Description:
My program begins by prompting the user to input a year they want a calendar to be generated for.
The program checks to see if the inputted year is positive. If the year is not positive, an error is shown and the program
asks the user to input a valid year. When the year inputted is valid the program then continues by running the given year through then
printCalendar function. printCalendar takes in the inputted year as well as the starting day for that year. The starting day is
calculated through the findYearStartDate function. This function uses a form of Tomohiko Sakamoto's algorithm to calculate the correct
day for January 1st for the inputted year. This algorithm was created to calculate the day of the week for any month in a year, I
modified it by plugging in 1 for the month and day variables since the calendar program only needs the day for January 1st.

  Sakamoto's method Original Code
  int dayOfWeek (int y, int m, int d) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
      return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    }
  Citation: “Determination of the Day of the Week.” Wikipedia, Wikimedia Foundation
                en.wikipedia.org/wiki/Determination_of_the_day_of_the_week.

The printCalendar function then continues to run by looping through the printMonth function. printMonth assigns the days of the week
(Sun-Sat) to each day in the Month. In order to know how many days are in each month, printMonth calls printMonthName. printMonthName returns
the total amount of days in each month. When printMonthName gets to February it calls the isLeapYear function to determine how
many days are in February. isLeapYear checks if the inputted year is If the year is divisible by 4 (and it isn't the start of a century or
it is one every forth century). If it is a leap year then February has 29 days. If not then it has 28 days. Once printMonth finishes
printing out a month, it saves the last day so that it can continue onto the next month without needing a new start day. This process
continues until all 12 months are printed out.

Loop Invariants:
  printMonth loop invariant #1
    The day variable will always be greater than zero and less than seven, and will execute seven times.
    This is because a day will always be assigned an integer of 0-6 since 0-6 represents Sun-Sat.

  printMonth loop invariant #2
    The day variable will always be less than the sum of total days in a month and the start day of that month.
    It will also always be greater than or equal to zero and the loop will not finish until the day is equal to the number of days in
    the month added to the start day.

  printCalendar loop invariant #1
    The month will always be greater than or equal to zero and less than twelve, and it will execute as long as that range is met.
    This is because a month will always be assigned an integer of 0-11 since 0-11 represents Jan-December.

 How to execute the program:
  Navigate in the directory to where the file is stored and compile it in the command shell by typing "gcc -Wall -o PA1 PA1.c."
  Then type is ./PA1. You will be prompted to enter a year. Do that and watch the magic happen.
