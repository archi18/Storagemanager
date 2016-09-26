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
	fseek(sm_file,0,SEEK_END);
	int last_byte_loc = ftell(sm_file);
	int totalNumPages = (int) last_byte_loc / PAGE_SIZE;
	updateSmFileHandle(totalNumPages,1,fHandle);
	printf("total No of pages in file %d ", totalNumPages);
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

RC closePageFile (SM_FileHandle *fHandle){
	fclose(sm_file);
	free(fHandle);
}
RC destroyPageFile (char *fileName){
	fclose(sm_file);
	if(remove(fileName)!=0)
		return RC_FILE_NOT_FOUND;
	else
		return RC_OK;
}

RC readBlock (int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage){
	if(pageNum > fHandle->totalNumPages)
		return RC_READ_NON_EXISTING_PAGE;
	memPage = (char*) malloc(sizeof(char)*PAGE_SIZE);
	fseek(sm_file,PAGE_SIZE * (pageNum-1), SEEK_SET);
	size_t ret_Read = fread(memPage, 1, PAGE_SIZE,sm_file);
	if(ret_Read != 0)
		return RC_READ_NON_EXISTING_PAGE;
	else
		return RC_OK;
}



