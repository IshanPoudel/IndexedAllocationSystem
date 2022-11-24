// The MIT License (MIT)
// 
// Copyright (c) 2016, 2017 Trevor Bakker 
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>


#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 5     // Mav shell only supports five arguments


#define NUM_BLOCKS 512
#define BLOCK_SIZE 1024
#define MAX_NUM_OF_BLOCKS_PER_FILE 20
#define MAX_NUM_OF_FILES 125



//contains file name and their inode number
struct directory_entry
{
  char * name;
  int in_use;
  int inode_index;
};

//Manually increase the size of the directory . 
struct directory_entry directory_entry_array[MAX_NUM_OF_FILES];

//contains the inode number and the number of blocks that it is using.
struct Node 
{
    
    int blocks[MAX_NUM_OF_BLOCKS_PER_FILE];
    int in_use;

};

//decalre an array to store inodes
struct Node inode_array_ptr[MAX_NUM_OF_FILES];

//declare a directory to store the blocks.

char file_data[NUM_BLOCKS][BLOCK_SIZE];


void initialize()
{
  //Initalize the directory 
  for(int i=0; i<NUM_BLOCKS;i++)
  {
    strcpy(file_data[i] , "");
  }

//Set some blocks as not free for testing.
  strcpy(file_data[5] , "TEST");
  strcpy(file_data[10] , "TEST");
  strcpy(file_data[7] , "TEST");


  //Initialize the inode_array_ptr
  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    inode_array_ptr[i].in_use=0;
  }

  //Initialize the directory_entry

  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {

    directory_entry_array[i].in_use=0;
  }
}




int findFreeBlock()
{
    //itwrate thorugh out file_data and see which one is empty . 

    for(int i=5; i<NUM_BLOCKS;i++)
    {
        if ( strcmp(file_data[i] , "") ==0)
        {
            printf("I found a free block at %dth index\n" , i);
            return i;

        }
        
    }
    return -1;

    
}

int findFreeInodeBlock()
{
    for (int i=0; i<MAX_NUM_OF_FILES;i++)
    {
        if (inode_array_ptr[i].in_use==0)
        {
            printf("I found a free inode block at %dth index to put my file name and array\n" , i);
            return 1;
        }

    }
    return -1;
}

int findFreeDirectoryBlock()
{

  for (int i=0 ; i<MAX_NUM_OF_FILES;i++)
  {
    if (directory_entry_array[i].in_use==0)
    {
      printf("I found a free directory entry at %dth index to put my file and inode number\n" , i);
      return i;
    }

    
  }

  return -1;
}

void printBlock()
{

  printf("\n\nContents of the Block\n\n");
    

    

    for(int i=0; i<NUM_BLOCKS;i++)
    {
       
        printf("%s\n" , file_data[i]);
    }

    return;

}

void printInodeBlock()
{

  printf("\n\nContents of the  Inode Block\n\n");
    

    

    // for(int i=0; i<MAX_NUM_OF_FILES;i++)
    // {
    //   if (inode_array_ptr[i].in_use==1)
    //   {
    //     printf("%s\n" , inode_array_ptr[i].name);

    //   }
       
        
    // }

    return;

}

void printDirectory()
{
  printf("\n\nContents of the directory block\n\n");

  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (directory_entry_array[i].in_use==1)
    {
      printf("%s\n" , directory_entry_array[i].name);
    }
  }
}

void put(char* input , char* output)
{
  printf("\nI am trying to put the contents of %s into %s \n" , input , output);

  //declare variables
  int status;
  struct stat buf;

  status = stat(input , &buf);

  if (status!=-1)
  {
    //Find free directory_block
    int dir_index = findFreeDirectoryBlock();
    directory_entry_array[dir_index].in_use=1;
    directory_entry_array[dir_index].name=strdup(output);
    printDirectory();

    //Find free inode block

    int inode_index = findFreeInodeBlock();
    //Link the directory with the inode struct.
    directory_entry_array[dir_index].inode_index=inode_index;
    inode_array_ptr[inode_index].in_use=1;

    FILE *ifp = fopen(input , "r");
    printf("Reading %d bytes from %s\n" , (int) buf.st_size , input);

    int copy_size = buf.st_size;

    int offset = 0;
    int block_index = findFreeBlock();
    

  }

 




}

int main()
{

  char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );

  initialize();

  while( 1 )
  {
    // Print out the mfs prompt
    printf ("mfs> ");

    // Read the command from the commandline.  The
    // maximum command that will be read is MAX_COMMAND_SIZE
    // This while command will wait here until the user
    // inputs something since fgets returns NULL when there
    // is no input
    while( !fgets (cmd_str, MAX_COMMAND_SIZE, stdin) );

    /* Parse input */
    char *token[MAX_NUM_ARGUMENTS];

    int   token_count = 0;                                 
                                                           
    // Pointer to point to the token
    // parsed by strsep
    char *arg_ptr;                                         
                                                           
    char *working_str  = strdup( cmd_str );                

    // we are going to move the working_str pointer so
    // keep track of its original value so we can deallocate
    // the correct amount at the end
    char *working_root = working_str;

    // Tokenize the input stringswith whitespace used as the delimiter
    while ( ( (arg_ptr = strsep(&working_str, WHITESPACE ) ) != NULL) && 
              (token_count<MAX_NUM_ARGUMENTS))
    {
      token[token_count] = strndup( arg_ptr, MAX_COMMAND_SIZE );
      if( strlen( token[token_count] ) == 0 )
      {
        token[token_count] = NULL;
      }
        token_count++;
    }

    // Now print the tokenized input as a debug check
    // \TODO Remove this code and replace with your shell functionality

    int token_index  = 0;
    for( token_index = 0; token_index < token_count; token_index ++ ) 
    {
      printf("token[%d] = %s\n", token_index, token[token_index] );  
     

      
    }

    if (strcmp(token[0] , "put")==0)
    {
      put( token[1] , token[2]);
    }

    free( working_root );

  }
  return 0;
}
