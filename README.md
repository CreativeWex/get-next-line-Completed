# get_next_line ♅

>Reading a line on a fd is way too tedious

Summary: The aim of this project is to make you code a function that returns a line,
read from a file descriptor.
<br>
<br>
<br>
<br>
**Static variables** have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope. 

## get_next_line(int fd)
- ``static char		*str;`` - string with the first occurrence of \n + some characters of the next string (further - garbage). The variable is static to store values between function calls;
- ``char			*buff;`` - final string, cleared of garbage, to be printed;
<br>
<br>
## char	*ft_trashed_readline(int fd, char *str)

1) In the loop it reads packs of characters by BUFFER_SIZE in a piece;
2) Sends the readed packs of characters to char *ft_symbols_pack_check(const char *str) until it confirms that there is '\n' among the readed packs;

3) Returns the string with the first occurrence of '\n'.
<br>
<br>

## char	*ft_completed_line(char *str)

function prepares str for printing
  1) move i to '\n';
  2) allocate memory for str, extra slots for '\n' and '\0';
 3) returns final string, cleared of garbage, to be printed.
 <br>
<br>
 ## char	*ft_cutting(char *str)
  1) move pointer to '\n'
  2) if there is no '\n' in file -> clean line. (Needed for null output)
  3) allocate memory for trash
  4) move i to first trash char entrance
  5) trash -> buff

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

 