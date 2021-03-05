#include <stdio.h>
#include <unistd.h> 

/*exercises the read() system call to read a single byte, at a time, from stdin
validate that the read byte is appropriate for conversion, e.g., it must be either an ASCII '0' or '1'
converts each byte into an integer value via a mathematical expression
uses the resulting integer as part of the calcuation to determine the final number
identifies the end of a input string by either end of file or by a new line
End of file is detected when read() returns the value '0'
A new line is identified in the ASCII table as either: newline, nl, LF, or \n'
prints this final unsigned number on stdout
returns a value of 0 upon success and 1 otherwise
*/

int main()
{
    int offset = 48;  // sets values for offset, number, and sets a character variable
    int number = 0;   // called ascii_value
    char ascii_value;

    int retval = read(0, &ascii_value, 1);

    while ((retval == 1) && (ascii_value != '\n')) {
        int digit = ascii_value - offset;
        
        if ((digit == 1) || (digit == 0)){
            number = (number << 1) + digit;
            retval = read(0, &ascii_value, 1); 
            }
    else {
    return 1;
    }
    }
    printf("%u\n", number);  // prints value

    return 0; //at the end of the code return value 0 

}
