# htpasswd.c
- File: htpasswd.md
- Author: Josh Stephens
- email: bsdtux@Gmail.com
- Purpose: describe how the htpasswd.c file works

## Before Main
- Lines 18 - 29 Include of standard library header files
- Line 31 function prototype for usage (prints out the programs usaga)
- Line 32 function prototype for nag
- Line 34 char string for program name. 
- Line 36 - 42 contains usage function definition
- Line 44 defines max number of nags to about using bcrypt

## Main
- Line 48 Starts the main function
- Line 50 creates a character array called salt with a size of password len and creates a tmpl character array the size of the string "/tmp/htpasswd-XXXXXXXXXX"

- Line 51 : 58 variable declerations
- Line 60 : uses pledge to force in a restricted mode or errors on bad path 
- Line 63 : parses any options and will display usage if anything other than I is used
    - If I is used set htpasswd to use batch mode

- Line 75 reduces the number of args by the next index
- Line 76 updates argv with the index of the next 

- Line 78 - starts the batch section 
- Line 79 checks that there is only one argument left and if so set file variable to that argument value
- Line 80 displays the usage and usage exits with a value of 1
- Line 83 Still trying to understand pledge from the man page.

- Line 86 Attempts to get the lenght of the line (If can't read line error) and read input into line
- Line 87 adds null terminator to end of line

- Line 90-91 attempts to search for ":" in haystack and error out if can't find colon

- Line 92 set null  byte to tok's next index

- Line 94 prints input string into login and gets the loginlen

- Line 97 writes tok into pass variable and checks that the size is not greater than 1024 bytes

## After Main
function nag 
- takes a string variable with the name of line
- breaks string 1st param with a delemiter 2nd arg
- if tok doesn't contain $2a$ or $2b$ 
    - update nagcount 
    - If MAXNAG Count not reached complain to user to upgrade file

## Side quests 
- strtok - breaks strings into sequence of >= 0 non empty tokens. First call is string to be parsed. Subsquent calls must be NULL. Each call returns a pointer to a null-terminated string. Returns NULL 
when all tokens have been found

- strncmp - compares the first n bytes between two strings. str1 is the first string, str2 is the second string, n is the max number of characters. <0 if s1 less than s2, > 0 if s1 is greater than s2 and 0 if they are equal

- wrote argtest while learning about optind. Found info from [http://man.openbsd.org/man3/getopt.3](http://man.openbsd.org/man3/getopt.3)
    - requires the unistd.h library
