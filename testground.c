/* File: testground.c
 * Author: Josh Stephens
 * Purpose: While reading source code and starting with C i need a way to 
 * 	visually see how something works. This is my way of doing it.
 */
#include <sys/stat.h>
#include <stdio.h>
#include <err.h>
#include <string.h>


/* 
 * Test input: josh:my_very_short_password
 */

int main(int argc, char** argv) {
	char *line = NULL, *login = NULL, *tok;
	int loginlen=0, batch=0;
	size_t linesize = 0; /* linesize must be positive */
	ssize_t linelen; /* similar to size_t but a negative means error normally */

	printf("Status out: linelen = %d, linesize = %d, loginlen = %d, batch=%d\n",
			linelen, linesize, loginlen, batch);
	
	/* getline
	 * 	getline will take input from stdin and assign string to line
	 *	then it will return the length of string to linelen
	 *  linesize from what I can tell is the buffersize 
     *  but I don't understand why it is set to 0
     */
	if ((linelen = getline(&line, &linesize, stdin)) == -1)
		err(1, "cannot read login:password from stdin");
	
	printf("line is now %s", line);
    		
	printf("Status out: linelen = %d, linesize = %d, loginlen = %d, batch=%d\n",
			linelen, linesize, loginlen, batch);
	/* strstr
	 * char* strstr(const char *haystack, const char *needle)
	 * returns a pointer to the first index of a given needle. 
	 * return null if not present.
	 *
     * In this case if given josh:my_very_shortt_password then tok will start 
	 * at : and printed to screen would be :my_very_short_password
     */
	if ((tok = strstr(line, ":")) == NULL)
		err(1, "cannot find ':' in input");

	printf("tok = %s", tok);
	/* change ':' to be a null byte then move pointer forward one after 
	 * change 
	 */
	*tok++ = '\0';
	
	printf("Now tok = %s", tok);
	printf("Now line = %s\n", line);
	
	return 0;
}
