*This project has been created as part of the 42 curriculum by abaklout.*

# Get Next Line

## Description

**get_next_line** is a C function that reads a file descriptor line by line.  
Each call to the function returns the next line from the file until the end is reached.

The goal of this project is to:
- Understand and correctly use **static variables**
- Manage **memory allocation and deallocation**
- Handle **file descriptors**
- Write robust and norm-compliant C code

The returned line includes the newline character (`\n`), except when the end of file is reached and no newline exists.


---

## Instructions

### Compilation

The project must be compiled with the following flags:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```



Mandatory files:

- get_next_line.c

- get_next_line_utils.c

- get_next_line.h

# main usage example

```bash
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

```


Algorithm Explanation

The implementation is based on a static buffer that stores unread data between function
calls.

Step-by-step logic

Read from the file descriptor

Data is read using read() with a buffer size defined by BUFFER_SIZE

The read data is appended to a static storage variable

Search for a newline

If a newline character (\n) is found, a full line can be extracted

Extract and return the line

Memory is allocated for the line to return

The extracted line includes the newline character if present

Preserve remaining data

Any leftover data after the newline is kept in the static buffer for the next call

End of file handling

If read() returns 0 and no data remains, the function returns NULL

This approach ensures minimal reading, correct memory management, and compliance with
the project constraints.


Resources

man read

man malloc

man free

https://en.wikipedia.org/wiki/Static_variable

42 documentation and peer discussions

AI Usage

AI tools were used strictly as a learning aid to:

Clarify project requirements

Understand static variables and memory handling

Improve documentation quality

No source code was copied or generated directly for this project.
