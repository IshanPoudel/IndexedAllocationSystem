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
#include <time.h>



#define WHITESPACE " \t\n"      // We want to split our command line up into tokens
                                // so we need to define what delimits our tokens.
                                // In this case  white space
                                // will separate the tokens on our command line

#define MAX_COMMAND_SIZE 255    // The maximum command-line size

#define MAX_NUM_ARGUMENTS 5     // Mav shell only supports five arguments



#define NUM_BLOCKS 4226
#define BLOCK_SIZE 8192
#define MAX_NUM_OF_BLOCKS_PER_FILE 32
#define MAX_NUM_OF_FILES 125

//contains file name and their inode number
struct directory_entry
{
  char * name;
  int in_use;
  int inode_index;
  int size;
  int valid;
  int hidden;  //if hidden = 1, it is hidden
  int read_only; //if read_only=1 , it is read only.
  time_t time;
};


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


int open = 0;
char * currentFileSystem;
FILE* open_file;


void initialize()
{
  //Initalize the directory 
  for(int i=0; i<NUM_BLOCKS;i++)
  {
    strcpy(file_data[i] , "");
  }

// //Set some blocks as not free for testing.
//   strcpy(file_data[5] , "TEST");
//   strcpy(file_data[10] , "TEST");
//   strcpy(file_data[7] , "TEST");


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

//When you save and open , initialize the directory_entry_array with the output. 
//When you save and open, initialize the inode_array_ptr with the data file.


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
            return i;
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

  printf("\n\nThe following block indexes are occupied.\n\n");
    

    

    for(int i=0; i<NUM_BLOCKS;i++)
    {
      if (strcmp(file_data[i] , "")!=0)
      {
        printf(" %d " , i);

      }
       
       
    }

    printf("\n");

    return;

}

void printInodeBlock()
{

  printf("\n\nContents of the  Inode Block\n\n");
    

    

    for(int i=0; i<MAX_NUM_OF_FILES;i++)
    {
      if (inode_array_ptr[i].in_use==1)
      {
        printf("\nFor inode at index %d \n" , i);
        //Get size of array
        int size = sizeof(inode_array_ptr[i].blocks)/sizeof(inode_array_ptr[i].blocks[0]);
        for (int j=0; j<size;j++)
        {
          printf(" %d " , inode_array_ptr[i].blocks[j]);
        }

      }
       
        
    }
    printf("\n");

    return;

}

void printInode(int index)
{
  
  printf("\nFor inode at index %d \n" , index);
  
  int size = sizeof(inode_array_ptr[index].blocks)/sizeof(inode_array_ptr[index].blocks[0]);
  for (int j=0; j<MAX_NUM_OF_BLOCKS_PER_FILE;j++)
  {
    printf(" %d " , inode_array_ptr[index].blocks[j]);
  }
  printf("\n\n");

}

void printDirectory()
{
  printf("\n\nContents of the directory block\n\n");

  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (directory_entry_array[i].valid==1)
    {
      printf("Deleted , but the file is still not overwritten\n");
      printf("Name :%s , Inode Number: %d \n" , directory_entry_array[i].name , directory_entry_array[i].inode_index);   
      printInode(directory_entry_array[i].inode_index); 
    }
    else if (directory_entry_array[i].in_use==1)
    {
      
      printf("Name :%s , Inode Number: %d \n" , directory_entry_array[i].name , directory_entry_array[i].inode_index);       
      printInode(directory_entry_array[i].inode_index);
    }
    else{

    }
  }
  printf("\n");
}

void put(char* input )
{
  

  char *output = input;
  printf("\n I am trying to put the contents of %s into %s \n" , input , output);



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
    directory_entry_array[dir_index].size = (int) buf.st_size;

    //set read_only and hidden to false by default.
    directory_entry_array[dir_index].hidden=0;
    directory_entry_array[dir_index].read_only=0;

    //Once you find a free directory block, check if it;s index node has not been freed yet.
    //Use a valid flag. Set it to 1 if it has been deleted. 
    // If you use it , set valid to zero such that it's files are still in use
    if (directory_entry_array[dir_index].valid==1)
    {
      int inode_to_del = directory_entry_array[dir_index].inode_index;
      // you are using a directory which has been removed once.
      //first remove the block from it's corresponding inode.
      //Then do your stuff.
      for (int j=0; j<MAX_NUM_OF_BLOCKS_PER_FILE;j++)
      {
        //Get the index of the block. If not zero , then it is a block_number which we must delete.
        //It contains a block we must free
        // [2 ,3 ,  4, 5 , 8 , 0 , 0 , 0 , 0 ]
        if(inode_array_ptr[inode_to_del].blocks[j]!=0)
        {
          //remove the files.
          strcpy(file_data[inode_array_ptr[inode_to_del].blocks[j]] ,"" );

          //set the block to zero for further use.
          inode_array_ptr[inode_to_del].blocks[j]=0;
          //[0 , 3 , 4 , 5 , 8 , 0 , 0 , 0 ,0]

        }
      }

      //reset the valid.
      directory_entry_array[dir_index].valid=0;
      

    }
    
   

    //Find free inode block

    int inode_index = findFreeInodeBlock();
    //Link the directory with the inode struct.
    directory_entry_array[dir_index].inode_index=inode_index;
    printf("I made the index at %d in the inode_array_ptr in use\n" , inode_index);
    inode_array_ptr[inode_index].in_use = 1;

    FILE *ifp = fopen(input , "r");
    printf("Reading %d bytes from %s\n" , (int) buf.st_size , input);

    int copy_size = buf.st_size;

    int offset = 0;
    int block_index = findFreeBlock();

    //nEED TO COPY TO DIFFERENT FILE FORMATS. 

    int inode_block_counter = 0;
    //To increment struct inode's block array when a new block is read.

    while (copy_size>0)
    {
       fseek( ifp, offset, SEEK_SET );

       //Read block_size and put it in the file
       int bytes  = fread( file_data[block_index], BLOCK_SIZE, 1, ifp );

       if(bytes==0 && !feof (ifp))
       {
        printf("An error occured reading from the input file.\n");
        return;
       }

       //At this point , add the block index to the inode.
       //Need a pointer to know how many blocks are needed.
       //Make sure that the block_index is free. 
      //  printf("i read from the file and added the block index %d at the struct.array ar position %d\n" , block_index , inode_block_counter);
       inode_array_ptr[inode_index].blocks[inode_block_counter]=block_index;
       inode_block_counter++;


       //clear the eof flag.
       clearerr(ifp);

       //Reduce block_copy size.
       copy_size-=BLOCK_SIZE;

       offset += BLOCK_SIZE;

       block_index=findFreeBlock();



    }

    fclose(ifp);

    printf("\nCurrent state:\n");
    printDirectory();

    

    
    

  }

  else
  {
    printf("ERORR\n");
  }

 




}

void get(char** token , int token_count)

{
  
  //See number of args , before doing stuff.
  printf("%d\n" , token_count);
  //Need to check if string not empty
  char *input_file = token[1];
  char *output_file;
  if (token[2]==NULL)
  {   
    output_file = token[1];
    printf("Only two args\n");
  }
  else
  {
    output_file = token[2];
  }

  //Now do your thing.
  //Read the file from the inode.

  //Get the inode. 
  int inode_index=-1;
  int file_size=0;
  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (strcmp(directory_entry_array[i].name , input_file)==0)
    {
      inode_index=directory_entry_array[i].inode_index;
      file_size = directory_entry_array[i].size;
      break;

    }
  }

  if (inode_index==-1)
  {
    printf("File not in disk");
    return;
  }

  //Read the blocks from the inode. 
  // int  block[MAX_NUM_OF_BLOCKS_PER_FILE ] = inode_array_ptr[inode_index].blocks;
  // to read the block
  int block_counter = 0;

  //Open the second file. 
  FILE *ofp;
  ofp = fopen(output_file , "w");

  if(ofp==NULL)
  {
  printf("Could not open the file: %s\n" , output_file);
  perror("Opening output file returned");
  return;
  }

  int block_index=inode_array_ptr[inode_index].blocks[block_counter++];
  int copy_size = file_size;
  
  int offset = 0;

  printf("Writing %d bytes to %s\n", file_size, output_file);

  while (copy_size>0)

  {
    int num_bytes;
    
    //To check when the thing we want to copy is less than BLOCK_SIZE
    if( copy_size < BLOCK_SIZE )
    {
      num_bytes = copy_size;
    }
    else 
    {
      num_bytes = BLOCK_SIZE;
    }

    fwrite( file_data[block_index], num_bytes, 1, ofp ); 
    copy_size -= BLOCK_SIZE;
    offset    += BLOCK_SIZE;

    block_index = inode_array_ptr[inode_index].blocks[block_counter++];
    fseek( ofp, offset, SEEK_SET );


  }

  fclose(ofp);
  return;
}

void del(char *filename)
{
  //You get the name of the file 

  int inode_to_del = -1;
  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (directory_entry_array[i].in_use == 1)
    {
      if (strcmp(directory_entry_array[i].name , filename)==0)
      {
        //check if read_only
        if (directory_entry_array[i].read_only==1)
        {
          printf("Cannot delete file . It is read only\n");
          return;
        }
        //If you find a match , get the inode_number so we can delete it from the inode struct array
        inode_to_del=directory_entry_array[i].inode_index;
        //Set the direcotry to be usable again.
        directory_entry_array[i].in_use=0;
        break;
        
      }
    }
  }

  //if traversed through the file , and the file not found
  if (inode_to_del==-1)
  {
    printf("File not found\n");
    return;
  }

  

  //Get the inode number.
  //Make sure to set it in use.
  inode_array_ptr[inode_to_del].in_use=0;

  directory_entry_array[inode_to_del].valid = 1;
  //Aka it still can be used because the only thing that has been done is change in_use to 0.


  //Traverse the directory block .
  //Set all the block to zero or ""

  

  // //Reset all the blocks to zero.
  // for (int j=0; j<MAX_NUM_OF_BLOCKS_PER_FILE;j++)
  // {
  //   //Get the index of the block. If not zero , then it is a block_number which we must delete.
  //   //It contains a block we must free
  //   // [2 ,3 ,  4, 5 , 8 , 0 , 0 , 0 , 0 ]
  //   if(inode_array_ptr[inode_to_del].blocks[j]!=0)
  //   {

  //     strcpy(file_data[inode_array_ptr[inode_to_del].blocks[j]] ,"" );

  //     //set the block to zero for further use.
  //     inode_array_ptr[inode_to_del].blocks[j]=0;
  //     //[0 , 3 , 4 , 5 , 8 , 0 , 0 , 0 ,0]

  //   }
  // }
  
  // instead reset all the blocks to zero before you are adding it to the inode. 

  printf("\n\n After deleting\n\n");
  printDirectory();
  

 
}

void undel(char *filename)
{

  

  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (( (directory_entry_array[i].valid==1) && strcmp(directory_entry_array[i].name , filename) == 0 )   && (directory_entry_array[i].in_use!=1))
    {
      //File can be restored.
      printf("I found the file %s\n" , filename);

      directory_entry_array[i].in_use=1;
      //change the valid sign to anything else than a 1.
      directory_entry_array[i].valid=0;
      //make the inode also in use
      int inode = directory_entry_array[i].inode_index;
      inode_array_ptr[inode].in_use=1;
      printf("%s has been restored\n" , filename);
      return;
    }
  }

  printf("File not found for deletetion\n");
  return;
}


void printdf()
{
  //print total free memory. 
  int total = NUM_BLOCKS* BLOCK_SIZE;

  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (directory_entry_array[i].in_use==1)
    {
      total = total - directory_entry_array[i].size;
    }
  }

  printf("%d bytes free\n" , total);
}

void list ()
{
  //List all the files. 
  int empty=0;

  for (int i=0; i<MAX_NUM_OF_FILES ; i++)
  {
    if (directory_entry_array[i].in_use==1 && directory_entry_array[i].hidden!=1)
    {
      empty=1;
      printf("%d  %s \n" , directory_entry_array[i].size , directory_entry_array[i].name);
    }
  }

  if (empty==1)
  {
    printf("No files found\n");
  }
}

void setAttribute(char* flag , char *filename)
{

  //find the filename and change it in the directory
  
  for (int i=0; i<MAX_NUM_OF_FILES;i++)
  {
    if (directory_entry_array[i].in_use==1 && strcmp(directory_entry_array[i].name , filename)==0)
    {
      if (strcmp(flag , "+h")==0)
      {
        
        directory_entry_array[i].hidden=1;
        printf("Set %s to be hidden\n" , filename);

      }
      else if (strcmp(flag , "-h")==0)
      {
        directory_entry_array[i].hidden=0;
        printf("Set %s to be un-hidden\n" , filename);

      }
      else if(strcmp(flag , "+r")==0)
      {
        directory_entry_array[i].read_only=1;
        printf("Set %s to be read only\n" , filename);
      }
      else
      {
        directory_entry_array[i].read_only=0;
        printf("Set %s to be not just read only\n" , filename);

      }

      return;
    }
    
  }

  printf("attrib: File not found\n");




}

void createfs(char *fileSystemName)
{

  initialize();
  open=1;
  currentFileSystem= fileSystemName;
  

}

void savefs()
{
  //Save the data. 
  // //Need to make the file block[0] equal to dir entry array
  // //Store as json. 
  // char dir_entry_text[BLOCK_SIZE];
  // for (int i=0; i<directory_entry_array;i++)
  // {
    


  // }


  //Need to make file block[2] and [3] equal to dir entry.

  //Open the data.
  //Save the data.
  // FILE *fp = fopen()
  // fwrite( &file_data[0], 8192, 4226, fp );
  FILE *fp = fopen(currentFileSystem , "w");
  printf("I opened the file %s \n" , currentFileSystem);
  fwrite( &file_data[0], BLOCK_SIZE, NUM_BLOCKS, fp );
  printf("i saved the file %s\n" , currentFileSystem);
  fclose(fp);
  return;
}

void openFileSystem(char *fileName)
{
  //Load the file name .
  //Initilaize the data file.
  FILE *fp = fopen(fileName , "r");
  fread( &file_data[0], BLOCK_SIZE, NUM_BLOCKS, fp );
  open_file=fp;
  printf("I read the file: %s\n" , fileName);
  currentFileSystem=fileName;

  //Initializae the inode and the direcotry entry array.
  open=1;
  printBlock();
  return;

}

void closeFileSystem()
{
  fclose(open_file);
  open=0;
  open_file=NULL;
  currentFileSystem=NULL;
  initialize();


}


int main()
{
  printf ("Full Directory_entry_array: %d\n" , (int)sizeof(directory_entry_array));
  printf("Single directory_entry_array value: %d\n" , (int)sizeof(directory_entry_array[0]));
  printf("Full inode_array: %d \n" , (int)sizeof(inode_array_ptr));
  printf("Single inode_array  value: %d \n" , (int)sizeof(inode_array_ptr[0]));
  printf("File data: %d\n" , (int)sizeof(file_data));
  printf("Single block in file_data: %d\n" , (int)sizeof(file_data[0]));




  char * cmd_str = (char*) malloc( MAX_COMMAND_SIZE );

  

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
      // printf("token[%d] = %s\n", token_index, token[token_index] );  
     

      
    }

    if (strcmp(token[0] , "createfs")==0)
    {
      
      if (token[1] == NULL )
      {
        printf("Need two arguments.\n");
      }
      else
      {
        createfs(token[1]);

      }
      
       
    }
    else if(strcmp(token[0] , "openfs")==0)
    {
      if (token[1] == NULL )
      {
        printf("Need two arguments.\n");
      }
      else
      {
        openFileSystem(token[1]);

      }
      
    }

    else if (open==0)
    {
      printf("No file system selected\n");
      
    }
    else if (strcmp(token[0] , "savefs")==0)
    {
      savefs();
    }
    else if (strcmp(token[0] , "closefs")==0)
    {
      closeFileSystem();
    }

    else if (strcmp(token[0] , "put")==0)
    {
      put( token[1] );
    }

    else if (strcmp(token[0] , "del")==0)
    {
      del(token[1]);
    }

    else if (strcmp(token[0] , "get")==0)
    {
      get(token , token_count);
    }
    else if (strcmp(token[0] , "list")==0)
    {
      list();
    }
    else if (strcmp(token[0] , "undel")==0)
    {
      undel(token[1]);
    }
    else if (strcmp(token[0] , "print")==0)
    {
      printDirectory();
    }
    else if (strcmp(token[0] , "df")==0)
    {
      printdf();
    }
    else if (strcmp(token[0] , "attrib")==0)
    {
      
      if ((strcmp(token[1] , "+h")==0 ) || (strcmp(token[1] , "+r")==0) || (strcmp(token[1] , "-h")==0 ) || (strcmp(token[1] , "-r")==0) )
      {
        setAttribute(token[1] , token[2]  );

      }
    
      else
      {
        printf("Wrong attribute\n");
      }
    }

    free( working_root );

  }
  return 0;
}

//Del a file , undel it and then put it .