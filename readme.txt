PROGRAMMING ASSIGNMENT 1 - STORAGE MANAGER

Archi Dsouza (A20375329, adsouza8@hawk.iit.edu, Representative)
Jeevika Sundarrajan (A20379071, jsundarrajan@hawk.iit.edu)
Zhizheng Li (A20351352, zli157@hawk.iit.edu)
Reona Cerejo (A20375246, rcerejo@hawk.iit.edu)


INSTALLATION INSTRUCTION:

a. For executing existing test cases:
    Browse to the assignment directory in the Ubuntu Terminal

	make -f makefile1

b. For additional test cases:
    Browse to the assignment directory in the Ubuntu Terminal

	make -f makefile2


FUNCTION DESCRIPTION:

1. Manipulating page files (CREATE, OPEN, CLOSE, DESTROY)
a) createPageFile:
	- Creates a new page file of 1 page.
	- The file created contains \0 bytes

b) openPageFile:
	- Checks if the file mentioned in input exists
	- If the file exists then it opens the existing file
	- If the file does not exists then it throws an error "file not found".
 
c) closePageFile:
	- The function is used to close a file and returns OK message if successful
	- If not uccessful, it throws an error

d) destroyPageFile:
	- The function destroy a file
	- If successful, returns OK message
	- If not uccessful, it throws an error

2. Reading blocks from disc:
a) readFirstBlock:
	- Checks if the entered file exists else throws an error
	- If the file exists then it initializes the pointer to first page
	- fread is used to read file.

b) getBlockPos:
	-  This function returs the current position of block.

c) readBlock:
	- Checks if the entered file exists else throws an error
	- If the file exists, file pointer is initialized to the position specified.
	- It reads the file from the specified position

d) readPreviousBlock:
	- Checks if the entered file exists else throws an error
	- If the file exists, it checks if the current page position is not a first page else throws an error
	- If there is a previous page then the current page pointer is moved to the previous page and it reads the previous page.

e) readCurrentBlock:
	- Checks if the entered file exists else throws an error
	- If the file exists, it sets the pointer to current page position.
	- Reads the current page

f) readNextBlock:
	- Checks if the entered file exists else throws an error
	- If the file exists, it checks if the current page position is not the last page else throws an error
	- If there is a next page then the current page pointer is moved to the next page and it reads the next page.

g) readLastBlock:
	- Checks if the entered file exists else throws an error
	- If the file exists, the current page position is moved to the last page.
	- Reads the contents of last page

3. Writing blocks to a page file:
a)  writeBlock:
	- This function writes a page to disk if the file exists.
	- It takes the page number and writes the block from that page number.
	- The contents from the page number specified are moved ahead by number of blocks to be written.
	- If the file does not exists then it throws an error.

b) writeCurrentBlock:
	-This function writes a page to disk if the file exists.
	- The blocks are written from the current position of the pointer.
	- If the file does not exists then it throws an error.

c) appendEmptyBlock:
	- It checks if the file exists else throws an error.
	- If the file exists then it appends a block filled with NULL bytes.


d) ensureCapacity:
	- It checks the number of pages in last block of the file
	- If the number of pages in less then the specified pages in a block then it increases the number of pages to specified number.

ADDITIONAL TEST CASES:

We have added the following additional test cases to execute the code:

Read File:
a. readFirstBlock
b. readNextBlock
c. readLastBlock
d. readPreviousBlock
e. readBlock
f. readcurrentblock

Write File:
a. writeBlock