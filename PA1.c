/* PA1.c -- Gabriel Aponte, gaaponte*/
#include <stdio.h>

/** isLeapYear checks to see if the given year is a leap year or not
* @peram year   the year inputed into the program by the user for the calender they want to print
* @return       an integer that represents the boolean value
*/

int isLeapYear(int year){
	//If the year is divisible by 4 (and it isn't the start of a century or it is one every forth century) then it is a leap year.
	if(year%4 == 0 && (year%100 != 0 || year%400 == 0)){
		return 1; //True, it is a leap year
	}else{
		return 0; //False, it is not a leap year
	}
}

/** printMonthName prints the month name and returns the total number of days in the month.
* @param  year   the year we want the calendar to print out.
* @param  month  the month we want the calendar to print out and get the total number of days for.
* @return        an integer representing the total number of days in that month.
*/

int printMonthName(int year, int month){
	int daysTotal = 0; // Saves the total number of days in each month month.

	switch(month){
		case 0:
		printf("January %d", year);
		daysTotal = 31;
		break;

		case 1:
		printf("February %d", year);
		//checks if February is a leap year to adjust its daysTotal accordingly
		if(isLeapYear(year)){
			daysTotal = 29; //February has 29 days if it is a leap year
		}else{
			daysTotal = 28; //February has 28 days if it is not a leap year
		}
		break;

		case 2:
		printf("March %d", year);
		daysTotal = 31;
		break;

		case 3:
		printf("April %d", year);
		daysTotal = 30;
		break;

		case 4:
		printf("May %d", year);
		daysTotal = 31;
		break;

		case 5:
		printf("June %d", year);
		daysTotal = 30;
		break;

		case 6:
		printf("July %d", year);
		daysTotal = 31;
		break;

		case 7:
		printf("August %d", year);
		daysTotal = 31;
		break;

		case 8:
		printf("September %d", year);
		daysTotal = 30;
		break;

		case 9:
		printf("October %d", year);
		daysTotal = 31;
		break;

		case 10:
		printf("November %d", year);
		daysTotal = 30;
		break;

		case 11:
		printf("December %d", year);
		daysTotal = 31;
		break;
	}

	printf("\n\n");

	return daysTotal;
}

/** findYearStartDate gets the day of January 1st for the inputed year.
* @param  year  the year that is inputed to determine the first day.
* @return       an integer representing the day of January 1st of the year, where 0 == Sunday and 6 == Saturday.
*/

//Uses Sakamoto's Method to determine the starting day of the year
int findYearStartDate (int year){
	return ((year-1) + (year-1)/4 - (year-1)/100 + (year-1)/400 + 1) %7;
}

/** printMonth prints the month's calendar and returns the first day of the next month.
* @param  year   the year we want the calendar to print out.
* @param  month  the month we want the calendar to print out.
* @param  startDay  the day that the first of the month falls on, where 0 == Sunday and 6 == Saturday.
* @return      an integer representing the first day of the next month, where 0 == Sunday and 6 == Saturday.
*/

int printMonth(int year, int month, int startDay){
	int daysTotal = printMonthName(year, month); //Prints out the month title and gets the total number of days for that month.

	//INVARIANT: day variable will always be greater than or equal to zero and less than seven, and will execute seven times.
	for(int day = 0; day < 7; day++){ //assigns a label for each day of the week. i.e Sunday == 0, Saturday == 6
		switch(day){
			case 0:
			printf("Sun  ");
			break;

			case 1:
			printf("Mon  ");
			break;

			case 2:
			printf("Tue  ");
			break;

			case 3:
			printf("Wed  ");
			break;

			case 4:
			printf("Thu  ");
			break;

			case 5:
			printf("Fri  ");
			break;

			case 6:
			printf("Sat");
			break;
		}
	}
	printf("\n");

	int weekDayNum = 0; //Stores the day of the week as the program goes through the calendar; 0 == Sunday, 6 == Saturday
	int monthDayNum = 1; //Stores the day label for each month since not all months start on the same day.

	//INVARIANT: day variable  will always be less than the sum of total number of days in a month and the start day of that month.
	//int day will always be greater than or equal to zero and the loop will not finish until the day is equal to the number of days in the month added to the start day.
	for(int day = 0; day < daysTotal + startDay; day++){ //Loop through the days and the empty spaces
		weekDayNum++;

		// Checks to see if the current day is not the starting day of the month
		if(day < startDay){
			printf("     "); //Prints out an empty space if the month hasn't started
		}else{
			// Checks if the monthDayNum is less that ten so that it can assign correct spacing for the outputed calendar
			if(monthDayNum < 10){
				printf("  %d  ", monthDayNum); //Uses two spaces to align correctly.
			}else{
				//One space needed
				printf(" %d  ", monthDayNum); //Uses one space for correct alignment.
			}

			monthDayNum++;

			//Checks if the day is out of the range 0 <= day <= 6
			if(weekDayNum%7 == 0){
				weekDayNum = 0; //Sets the day back to Sunday

				//Checks if the calendar is not at the last day of the month
				if(day != daysTotal+startDay-1){
					printf("\n"); //Moves to the next line of the calendar.
				}
			}
		}
	}
	return weekDayNum;
}

/** printCalendar prints the month's calendar.
* @param  year  the year we want the calendar to print out.
* @param  startDay  the day January 1st falls on.
*/

void printCalendar(int year, int startDay){
	printf("\n\n  ***    CALENDAR for %d   ***\n\n", year);

	//INVARIANT: month variable will always be greater than or equal to zero and less than twelve, and it will execute as long as that range is met
	for(int month = 0; month<12; month++){ //Loops through all months in the year
		startDay = printMonth(year, month, startDay); //Prints out each month and storse the final day inorder to calculate the next month.
		printf("\n\n");
	}
}

/** main runs the calendar program. It asks the user to input a year for the calendar
* and runs the function printCalendar if the inputed year is positive
* @return     if the program ran successfully it is given the integer 0. if the program runs into errors, a non-zero integer is given
*/

int main(void){
	int year = 2000; //Initializes the year variable, can be any positive integer
	printf("Please enter year for this calendar:- ");
	scanf("%d", &year); //sets the calendar to the year that the user inputs
	//Checks if the year is postive, because a year can not be negative
	if(year > 0){
		printCalendar(year, findYearStartDate(year)); //Prints the calendar when year is postive
	}else{
		printf("Error: Please enter an actual year.\n\n"); //Gives an error when inputed year is negative
		main();
	}

}
