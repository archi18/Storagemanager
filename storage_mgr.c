/*
@author {
	Reona Cerajo
	Jeevika Sundarrajam
	Li
	Archi Dsouza 
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage_mgr.h"
#include "dberror.h"

void updateSmFileHandle(int , int ,SM_FileHandle *);
void countPageNum(FILE);

FILE *sm_file;
SM_FileHandle *sm_fileHandle;
typedef char* SM_PageHandle;

void main(void){

	printf("\n hello world");
}

void initStorageManager (void){
	printf("\n Initialize storage manager");
}

RC createPageFile (char *fileName){
	sm_file = fopen(fileName,"w+");
	if (!sm_file){
		return RC_FILE_NOT_FOUND;
	}
	for(int i=0; i<PAGE_SIZE;i++)
		putc('\0',sm_file);
	sm_fileHandle->fileName = fileName;
	updateSmFileHandle(1,1,sm_fileHandle);
	return RC_OK;
}


RC openPageFile (char *fileName, SM_FileHandle *fHandle){
	sm_file = fopen(fileName,"r");
	if (!sm_file){
		return RC_FILE_NOT_FOUND;
	}
	
	int sz = ftell(sm_file);
	int totalNumPages = (int) sz / PAGE_SIZE;
	updateSmFileHandle(totalNumPages,1,fHandle);

}

/*
This method will update information in SM_FileHandle
@param totalNumPages : total no pages in file
		curPagePos : current page position
		SM_FileHandle : represents an open page fil        
*/
void updateSmFileHandle(int totalNumPages, int curPagePos,SM_FileHandle *sm_fileHandle){
	sm_fileHandle->totalNumPages = totalNumPages;
	sm_fileHandle->curPagePos = curPagePos;
}



