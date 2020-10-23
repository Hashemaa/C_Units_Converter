#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Declares the functions.
double to_byte(double value, double unit_value);
double byte_to_type(double bytes, double unit_value);
double digit_length(double bytes);

//Creates a global integer variable for table spacing purposes.
int spacing = 0;


int main() {
	//Outputs Coder's information.
	printf("Units: Hashem Abou Ahmad - 0961218\n");

	//Prompts user to enter a value followed by a unit type.
	printf("Enter the value to convert followed by a unit type = ");

	//Creates a double type variable to hold the value.
	double value = 0.0;
	//Creates a character type variable to hold the unit type.
	char unit_type = '\0';

	//Scans the input and assigns it to the appropriate variable.
	scanf_s("%lf", &value);

	//Checks if input is a negative number.
	if (value < 0) {
		//Explains the issue.
		printf("\nInvalid entry, please try again by entering a positive number.\n");
		//Terminates with an exit code of 1 indicating unsuccessful operation.
		return 1;
	}//End of single-selection if statement.
	//Gets the first character and then converts it to a lower case.
	unit_type = toupper(getchar());
	//Checks if the first character is not a letter.
	while (!isalpha(unit_type)) {
		unit_type = toupper(getchar());
	}//End of while loop.

	//Creates a double type variable to hold the value of bytes.
	double bytes = 0;
	
	//Outputs the value.
	printf("\n%.3lf ", value);

	//Adds 'unsigned' to satisfy user, but flushes it since it does not have a valid application.
	if (unit_type == 'U') {
		while (unit_type = getchar() != ' ');
		printf("unsigned ");
		unit_type = toupper(getchar());
	}//End of single-selection if statement.

	//Creates a switch statement to find the unit type desired.
	switch (unit_type) {

	case 'B':
		bytes = value;
		printf("byte");
		break;

	case 'K':
		unit_type = toupper(getchar());
		if (unit_type == 'B') {
			bytes = to_byte(value, pow(10, 3));
			printf("kB");
		}
		else if (unit_type == 'I') {
			bytes = to_byte(value, pow(2, 10));
			printf("KiB");
		}
		else {
			printf("\nInvalid entry, please try again.\n");
			//Terminates with an exit code of 1 indicating unsuccessful operation.
			return 1;
		}//End of trailing-else.
		//Breaks out of the switch statement.
		break;

	case 'M':
		unit_type = toupper(getchar());
		if (unit_type == 'B') {
			bytes = to_byte(value, pow(10, 6));
			printf("MB");
		}
		else if (unit_type == 'I') {
			bytes = to_byte(value, pow(2, 20));
			printf("MiB");
		}
		else {
			printf("\nInvalid entry, please try again.\n");
			//Terminates with an exit code of 1 indicating unsuccessful operation.
			return 1;
		}//End of trailing-else.
		//Breaks out of the switch statement.
		break;

	case 'G':
		unit_type = toupper(getchar());
		if (unit_type == 'B') {
			bytes = to_byte(value, pow(10, 9));
			printf("GB");
		}
		else if (unit_type == 'I') {
			bytes = to_byte(value, pow(2, 30));
			printf("GiB");
		}
		else {
			printf("\nInvalid entry, please try again.\n");
			//Terminates with an exit code of 1 indicating unsuccessful operation.
			return 1;
		}//End of trailing-else.
		//Breaks out of the switch statement.
		break;

	case 'T':
		unit_type = toupper(getchar());
		if (unit_type == 'B') {
			bytes = to_byte(value, pow(10, 12));
			printf("TB");
		}
		else if (unit_type == 'I') {
			bytes = to_byte(value, pow(2, 40));
			printf("TiB");
		}
		else {
			printf("\nInvalid entry, please try again.\n");
			//Terminates with an exit code of 1 indicating unsuccessful operation.
			return 1;
		}//End of trailing-else.
		//Breaks out of the switch statement.
		break;

	case 'P':
		unit_type = toupper(getchar());
		if (unit_type == 'B') {
			bytes = to_byte(value, pow(10, 15));
			printf("PB");
		}
		else if (unit_type == 'I') {
			bytes = to_byte(value, pow(2, 50));
			printf("PiB");
		}
		else {
			printf("\nInvalid entry, please try again.\n");
			//Terminates with an exit code of 1 indicating unsuccessful operation.
			return 1;
		}//End of trailing-else.
		//Breaks out of the switch statement.
		break;

	case 'E':
		unit_type = toupper(getchar());
		if (unit_type == 'B') {
			bytes = to_byte(value, pow(10, 18));
			printf("EB");
		}
		else if (unit_type == 'I') {
			bytes = to_byte(value, pow(2, 60));
			printf("EiB");
		}
		else {
			printf("\nInvalid entry, please try again.\n");
			//Terminates with an exit code of 1 indicating unsuccessful operation.
			return 1;
		}//End of trailing-else.
		//Breaks out of the switch statement.
		break;

	case 'C':
		bytes = value;
		printf("char");
		//Breaks out of the switch statement.
		break;

	case 'S':
		bytes = 2 * value;
		printf("short");
		//Breaks out of the switch statement.
		break;

	case 'I':
		bytes = 4 * value;
		printf("int");
		//Breaks out of the switch statement.
		break;

	case 'L':
		bytes = 4 * value;
		printf("long");
		while ((unit_type = toupper(getchar())) != EOF && unit_type != '\n') {
			if (unit_type == 'L') {
				bytes *= 2;
				printf(" long");
			}//End of single-selection if statement.
		}//End of while loop.
		//Breaks out of the switch statement.
		break;

	case 'F':
		bytes = 4 * value;
		printf("float");
		//Breaks out of the switch statement.
		break;

	case 'D':
		bytes = 8 * value;
		printf("double");
		//Breaks out of the switch statement.
		break;

	default:
		//Explains issue.
		printf("\nInvalid entry, please check your input and try again.\n");
		//Terminates with an exit code of 1 indicating unsuccessful operation.
		return 1;
	}//End of switch statement.

	//Assigns the length of the digits in bytes desired for spacing.
	spacing = (int)digit_length(bytes) + 1;

	//Outputs results.
	printf(" is %.0lf bytes\n\n", bytes);
	printf("%*s     %*s", spacing, "  Metric", spacing, "IEC\n");
	printf("%*s     %*s", spacing, "  ======", spacing, "===\n");
	printf("%*.3lf kB %*.3lf KiB\n", spacing, byte_to_type(bytes, pow(10, 3)), spacing, byte_to_type(bytes, pow(2, 10)));
	printf("%*.3lf MB %*.3lf MiB\n", spacing, byte_to_type(bytes, pow(10, 6)), spacing, byte_to_type(bytes, pow(2, 20)));
	printf("%*.3lf GB %*.3lf GiB\n", spacing, byte_to_type(bytes, pow(10, 9)), spacing, byte_to_type(bytes, pow(2, 30)));
	printf("%*.3lf TB %*.3lf TiB\n", spacing, byte_to_type(bytes, pow(10, 12)), spacing, byte_to_type(bytes, pow(2, 40)));
	printf("%*.3lf PB %*.3lf PiB\n", spacing, byte_to_type(bytes, pow(10, 15)), spacing, byte_to_type(bytes, pow(2, 50)));
	printf("%*.3lf EB %*.3lf EiB\n", spacing, byte_to_type(bytes, pow(10, 18)), spacing, byte_to_type(bytes, pow(2, 60)));

	//Returns 0 indicating success.
	return 0;

}//End main() method.

//Functions:

//Returns a double after calculating the byte value.
double to_byte(double value, double unit_value) {
	//Returns the calculated bytes.
	return value * unit_value;
}//End of to_byte() function.

//Returns a double after converting from bytes to the unit type desired.
double byte_to_type(double bytes, double unit_value) {
	//Returns the calculated value from bytes to the unit type.
	return bytes / unit_value;
}//End of byte_to_type() function.

//Returns a double after calculating the digit length.
double digit_length(double bytes){
	//Declares and initializes an integer type variable to hold the length.
	int length = 1;
	//Creates a while loop to check the length of the digits received/
	while (bytes >= 10){
		//Increments the length.
		length++;
		bytes /= 10;
	}//End of while loop.
	//Returns the length.
	return length;
}