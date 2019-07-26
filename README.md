# GNL (get next line)
GNL is a [42] project aimed to develop a function to read a file line by line.
A line is a set of characters ended by a newline `\n` or by an `EOF` (end of file).

###### Keywords: *`read` `file descriptor` `static variable`*


### First version ([v1.0])
As part of the subject of the project, the function should have the following prototype :
```c
int    get_next_line(const inf fd, char **line);
```
It should read on the provided `file descriptor` and store the extracted data in the `line` variable.

##### Return value
* `1`  : a line has been read
* `0`  : `EOF` has been reached
* `-1` : an error occurred

This first version of `GNL` handles reading on multiple `fd` alternatively

#### Caveats
This first version was enough to validate the project. However the functions used were assuming that the sequence of characters
was made of ASCII chars only and that a `\0` was only used to define an end of string. It become then clear that it would be
impossible to faithfully read binary data.
In order to possess a reusable and trustworthy `GNL` in futur projects, I decided to solve rewrite it completely.

### Second version ([v2.0])
In this version, I used functions to directly work on the memory. For performance issue, and because I did not feel that the
next projects will require it, I decided to remove the ability to handle mutliple `fd` alternatively. I also change the
prototype of the function to meet new needs :
```c
ssize_t    get_next_line(const int fd, char **line, int *eol_had_newline);
```
It still takes a `fd` and stores the data in the `line` variable. Additionally, the last parameter `int *eol_had_newline` allows to
store a `boolean` value to know if the line was terminated with a newline (`\n`).

##### Return value
Here the return value has a different type. The `ssize_t` (*signed size_t*) is used to store the length of the extracted line.
It become clear that here `0` can not be used to indicate the `EOF`. Therefore to indicate the `EOF` a negative value is used.
* `>=0` : length of the line
* `-1`  : `EOF` has been reached
* `-2`  : an error occurred
Those return values are stored as `define` in the `get_next_line.h` header.


[42]: https://www.42.fr/
[v1.0]: https://github.com/apft/get_next_line/releases/tag/v1.0
[v2.0]: https://github.com/apft/get_next_line/releases/tag/v2.0
