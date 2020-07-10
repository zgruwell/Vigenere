#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DEBUG 0

#define ENCODE 1 /* the macro ENCODE expands to the number 1 */
#define DECODE 0 /* DECODE expands to 0 */
#ifndef MODE 	 /* if the macro MODE wasn't defined during compilation... */
	#define MODE ENCODE	/* define it to be ENCODE */
#endif
	

int main(int argc, char *argv[]) {

	/* perform a simple caesear cipher
	 * -------------------------------
	 * accepts three arguments:
	 * 1. a shift value (integer)
	 * 2. a filename to draw input from
	 * 3. a filename to write output to
	 */

	int i = 0; /* iterator we'll reuse */

	if (DEBUG) {
		/* change DEBUG to 0 or remove this code */

		printf("This program is named '%s'\n", argv[0]);
		printf("There are %d arguments. They are:\n", argc);

		/* loop through, printing the name and value of each 
		 * argument string.
		 */

		for (i = 0; i <= argc; i++) {

			printf("\t%d --> %s\n", i, argv[i]);

		}
	}

	//	if (argc < 4) {
	//	printf("Missing arguments!\n\n");
	//	printf("Usage: caesar shift infile outfile\n\n");
	//	printf("Note: outfile will be overwritten.\n");
		//	return 1;
	//}

	/* get program arguments */

	/* caesar needs a shift value */
	/* The first argument, 'argv[1]' is a string, not a number.
	 * To use it as our shift value, we must first convert it to an integer. */

	/*int shift = atoi(argv[1]); /* atoi means "ASCII to integer" */
	//if (shift > 255 || shift < 0) {
	//	printf("Value of shift must be between 0-255.\n");
	//	exit(1);
	//}

	/* Note: vigenere instead takes a path to a key file rather than a shift
	 * value.  See the lab manual for instructions on how to read a file into a
	 * character array.
	 */

	unsigned char *keyfile = argv[1];
       	unsigned char *input = argv[2]; /* input file name */
       	unsigned char *output = argv[3]; /* output file name */
	unsigned int Data[128];
	unsigned int Position = 0;
	//	unsigned char *KEYFILE = argv[1];
	//	unsigned char *INPUT = argv[2];
	//	unsigned char *OUTPUT = argv[3];
	
	/* open the input or quit on error */
	FILE *KEYFILE;
	if ((KEYFILE = fopen(keyfile, "r")) == NULL) {
		printf("Problem opening keyfile file '%s'; errno: %d\n", keyfile, errno);
		return 1;
	}
	FILE *INPUT;
   	if ((INPUT = fopen(input, "r")) == NULL) {
		printf("Problem opening input file '%s'; errno: %d\n", input, errno);
		return 1;
	}
	
	/* open the output or quit on error */
	FILE *OUTPUT;
   	if ((OUTPUT = fopen(output, "w+")) == NULL) {
		printf("Problem opening output file '%s'; errno: %d\n", output, errno);
		return 1;
	}

	int symbol; /* we will read each input byte into 'symbol' */
	unsigned char cipher; /* we will encode each output byte in 'cipher' */
	
	while (Position < (128) && (symbol = fgetc(KEYFILE)) != EOF){
	  Data[Position] =(char) symbol;
	  Position++;
	}

	if(MODE == ENCODE){
	  int i = 0;
	  while((symbol = fgetc(INPUT)) != EOF){
	  if(i==Position)
	    i=0;
	  cipher = (unsigned char)(symbol + Data[i]%256);
	  printf("%c\n", Data[i]);
	  i++;
	  fprintf(OUTPUT, "%c", cipher);
	}

	} else {
   if(MODE == DECODE){
     while((symbol = fgetc(INPUT)) != EOF){
	  if(i==Position)
	    i=0;
	  cipher = (unsigned char)(symbol - Data[i]%256);
	  printf("%c\n", Data[i]);
	  i++;
	  fprintf(OUTPUT, "%c", cipher);
	}}

	/*If (MODE != ENCODE) {
		shift = 256 - shift;  mode is DECODE, so "unshift" the characters 
	}
	
	if (DEBUG) {
		printf("The shift value is %d\n", shift);
	}

	/***************************
	 * OK, LET'S GET ENCODING! *
	 ***************************/

	/* read individual characters from INPUT until we hit the EOF 
	while ((symbol = fgetc(INPUT)) != EOF) {

		 Do the Caesar Shift:
		 * 1. take the integer value of 'symbol'
		 * 2. add the shift value
		 * 4. cast to char and store into 'cipher' 
		 

		cipher = (char)(symbol + shift); /* char is 8-bits so wraps automatically 

		if (DEBUG) {
			 leaving this code turned on will make your program very slow! 
			printf("symbol is: %d == %02x became %02x\n", symbol, symbol, cipher);
		}

		 write the number 'cipher' as a character to OUTPUT 
		fprintf(OUTPUT, "%c", cipher);

		}*/

      	fclose(INPUT);
        fclose(OUTPUT); 
        fclose(KEYFILE);
	return 0;

	}}
