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

- Line 51 creates a character array called hash with the size of password len and pass set to 1024 and pass2 set to 1024

- Lines 52 sets up a few string variables
- Line 53 sets up a few int variables

- Line 54 sets up a in file and out file to hold the input file location and the output file location

- Line 55 creates a variable string called file

## After Main
function nag 
- takes a string variable with the name of line
- breaks string 1st param with a delemiter 2nd arg
- if tok doesn't contain $2a$ or $2b$ then update nagcount and if nagcount then complain to user 5 times then stop complaining to them to not use bcrypt

## Side quests 
strtok - breaks strings into sequence of >= 0 non empty tokens. First call is string to be parsed. Subsquent calls must be NULL. Each call returns a pointer to a null-terminated string. Returns NULL 
when all tokens have been found

strncmp - compares the first n bytes between two strings. str1 is the first string, str2 is the second string, n is the max number of characters. <0 if s1 less than s2, > 0 if s1 is greater than s2 and 0 if they are equal
