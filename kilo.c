#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>


struct termios orig_termios;
void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;

  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);    // input flags
	raw.c_oflag &= ~(OPOST);     // output flags 
  raw.c_cflag |= (CS8);        // control flags
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);    // local/misc. flags
  // control characters
  raw.c_cc[VMIN] = 0;   // VMIN: sets the min no. of bytes of 
                        // input needed before read() can return
  raw.c_cc[VTIME] = 1;   // VTIME: sets the max amt of time to 
                        // wait before read() returns
  
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main() {
  enableRawMode();
  while (1) {
    char c = '\0';
    read(STDIN_FILENO, &c, 1);
    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d ('%c')\r\n", c, c);
    }
  }
  return 0;
}