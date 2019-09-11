#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

#define STRLENGTH 100
#define SERIALSTRINGLENGTH 120

int getlines(char s[], int lim, int * sum);
int openport(void);
int main(void) {
	int sum = 0;
	int length = 0;
	int n;
	char s[STRLENGTH];
	char unixs[SERIALSTRINGLENGTH];
	char terminalcharacters[] = " > /dev/ttyUSB1";
	int fd = openport();
	while((length = getlines(s, STRLENGTH, &sum)) > 2){
		printf("%s\n", s);
		n = write(fd, s, length);
		if (n < 0)
			fputs("Write operation failed.\n", stderr);
		sum = 0;
	}
	close(fd);
}

int getlines(char s[],int lim, int * sum)
 {
 	int c, i;
	s[0] = '\"';
 	for (i=1; i < lim-2 && (c=getchar())!=EOF; ++i){
 		s[i] = c;
		*sum += c;
	}
	s[i] = '\"';
	s[++i] = '\0'; 
 	return i;
 }

int openport(void)
{
  int fd; /* File descriptor for the port */


  fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */

    perror("open_port: Unable to open /dev/ttyUSB1 - ");
  }
  else
    fcntl(fd, F_SETFL, 0);

  return (fd);
}

