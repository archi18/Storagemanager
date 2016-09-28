**********************************************************************
PROGRAMMING ASSIGNMENT 1 - STORAGE MANAGER

TEAM MEMBERS :
1)AKSHAY SHANBHAG (A20357098)  (ashanbha@hawk.iit.edu) (Representative)
2)KARTHIK KRISHNAMURTHY (A20344464) (kkrish14@hawk.iit.edu)
3)ARJUN ASHOKKUMAR (A20354916) (aashokk1@hawk.iit.edu)

CONTENTS :
1)Instructions to run the code
2)Description of functions used
3)Memory Leak - Valgrind tool
4)Extra Test Cases
************************************************************************

1)Instructions to run the code
------------------------------

a)For executing create,Open,close and destroy test cases:

1) In the ubuntu terminal,navigate to the assignment directory.

2) Type: 
	make -f Makefile1


b) For executing additional test cases:

1) In the ubuntu terminal,navigate to the assignment directory.

2) Type: 
	make -f Makefile2


2) Description of functions used
---------------------------------

*******************************************************
Description of functions used for CREATE, OPEN, CLOSE, DESTROY File operations.
*******************************************************


	Function : CreatePageFile	
	-------------------------
		
1)Creating a new file, if already exist it is discarded and new empty file is created
2)If the file is created successfully, it is filled with null bytes else return error.

	Function : OpenPageFile
	------------------------
	
1) Checks if file exists with given name.
2) If yes, initializing file handle with all file related information
3) If not, returning appropriate file not found error message 
4) The file pointer is stored for book keeping(mgmtInfo) 

	Function : ClosePageFile
	-----------------------------
1) Close the file and return a success message upon success.
2) Upon failure, return appropriate error message.


	Function : DestroyPageFile
	------------------------------
	
1) Removes the file , if it is present.
2) If it is success, return a success message.
3) else, return a failure message.




*******************************************************
Description of functions used for READ File operations.
*******************************************************

	Function : readFirstBlock
	-------------------------

1)It checks if the file exist or not.
2)If the file dosent exist, it return appropriate error message.
3)If the file exist, initialize file pointer and assign page file information values. 
4)Pass the file handle and buffer(memPage) value to readCurrentBlock
5)Move the pointer to initial page block and read the file.

	Function : getBlockPos
	-------------------------
		
1) Returns current Block position.

	Function : readBlock
	---------------------
1)Check if the file exist. If it is not present return appropriate failure error message.
2)If it the file exist, initialize file pointer and assign page file information values. 
3)Move the pointer to initial page block and read the file.

	Function : readPreviousBlock
	----------------------------
1)Pass the previous file handle value and buffer(memPage) value to readCurrentBlock.
2)It checks if the file exist or not.
3)If the file does not exist, it return appropriate error message.
4)If the file exist, initialize file pointer and assign page file information values. 
5)Move the pointer to fild Handle location and read the file.

	Function : readCurrentBlock
	---------------------------
1)It checks if the file exist or not.
2)If the file does not exist, it return appropriate error.
3)If the file exist, initialize file pointer and assign page file information values. 
4)Move the pointer to file Handle location and read the file.


	Function : readNextBlock
	------------------------
1)Pass the next block value and memPage value to readCurrentBlock .
2)Checks the file exist or not.
3)If the file exist, the file handle location will be moved to next block and reads the file.
4)If the file does not exist, it returns appropriate error.


	Function : readLastBlock
	------------------------

1)Passes the last block location and buffer to readCurrentBlock.
2)Checks the file exist or not.
3)If the file exist, the file handle location will be moved to next block and reads the file.
4)If the file does not exist, it returns appropriate error.



********************************************************
Description of functions used for WRITE File operations.
********************************************************

	Function: writeBlock
	---------------------
	
1)Check if the file exist, if yes it poceeds to write.
2)Move pointer location to next available location.
3)If file does not exit return error message.


	Function : appendEmptyBlock
	-------------------------------
	
1)Check if the file exist, returns error message if it does not exist.
2)Otherwise adds 1 block to the current position.


	Function : ensureCapacity
	-----------------------------
	
1) Check if the file exist, if it exist then checks the size of the page block is less than the number of pages.
2) If yes,then the memory is allocated and size is increased.
3) Otherwise, print'NULL' for the remaining pages.



********************************************************************************************************************************************************


3) Memory Leak - Valgrind tool
------------------------------
We have used valgrind tool for memory leak check and we have found that there is memory leak in test_assign_1 because memory allocated has not been freed.


********************************************************************************************************************************************************

4) Extra Test Cases
--------------------------

We have included the following extra test cases for executing the following functions:

-Read File operations:
1.getBlockPos
2.readCurrentBlock
3.readPreviousBlock
4.readNextBlock
5.readLastBlock


-Write File operations:
1. writeCurrentBlock
2. EnsureCapacity
3. appendEmptyBlock


******************************************************END OF FILE **************************************************************************************


