// Stat struct contains the metadata about a file. 
// dev_t st_dev - device on which the file resides. 
// ino_t sr_ino - inode number of the file,
// mode_t st-mode - protection
// nlink_t st_nlink - number of hard links,
// uid_t st_uid - userId of owner.
// gid_t st_gid - groupID of owner. 

//ino_t st_ino - inode number
//off_t st_size - total_size
//blkcnt_t st_blocks - blocksize for file system i/o.


//How to have inodes for all 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


#define NUM_BLOCKS 512
#define BLOCK_SIZE 1024

char file_data[NUM_BLOCKS][BLOCK_SIZE];


int findFreeBlock()
{
    //itwrate thorugh out file_data and see which one is empty . 
    return 0;

    
}

void printBlock()
{

    for(int i=0; i>NUM_BLOCKS;i++)
    {
        // file_data[i]=strdup("NULL");
        strcpy(file_data[i] , "NULL");
        printf("%s\n" , file_data[i]);
    }

    return;

}
int main(int argc , char *argv[])
{

    



    //declare variables
    int status;
    struct stat buf;

    // 3 args , program name , file to copy from , file to copy to, 

    if(argc!=3)
    {
        printf("Incorrect number of parameters\n");
        return -1;
    }

    status = stat(argv[1] , &buf);
    //fills in the bust struct with file parameters. 

    if (status !=-1)
    {
       //We get the paramwters of the file.
       //We read from the input file.
       FILE *ifp = fopen(argv[1] , "r");
       printf("Reading %d bytes from %s\n" , (int) buf.st_size , argv[1]);

       //Save the total size of the buf. 
       int copy_size = buf.st_size;

       //We want to copy and write in chunks of BLOCK_SIZE. 
       //So to do this , we are using fseek to move along out file stream in chunks of BLOCK_SIZE
       //we will copy our bytes , increment out file pointer by block_size and repear. 

       //We want to copy and write in chunks of BLOCK_SIZE . So to do this , we are going to use 
       //fseek to move along our file in chunks of Block_size . 
       //We will copy bytes , increment out file pointer by BLOCK_SIZE and repet.
       int offset = 0;
       
       //nlock_index will keep us pointin to the area that we will read from or write to
       int block_index=0;


       while(copy_size>0)
       {

        

        //Index into the input file by offset number of bytes . Initially offset is set to zeor , so we copy BLOCK_SIZE
        fseek(ifp , offset , SEEK_SET);

        //Read b.ock size number of bytes from input file and stroe them in out data array
        int bytes = fread(file_data[block_index] , BLOCK_SIZE , 1 , ifp);

        if(bytes==0 && !feof(ifp))
        {
            printf("An error occured reading from the input file\n");
            return -1;
        }

        //Clear the EOF file flag.
        copy_size -= BLOCK_SIZE;
        //nEXT TIME WE ARE usin fseek we are reading the next block size.
        offset+= BLOCK_SIZE;

        //INcrement the index into block array
        block_index++;

        


       }

       fclose(ifp);

       //The above function is the put command , reading from file and storing in you array

       //the function below is to open a new output file and write the same data to. 
       FILE *ofp;
       ofp = fopen(argv[2] , "w");

       if(ofp==NULL)
       {
        printf("Could not open the file: %s\n" , argv[2]);
        perror("Opening output file returned");
        return -1;
       }

       //Initialize our offsers and pointers , just like we did above when reading from the file. 
       block_index=0;
       copy_size=buf.st_size;
       offset=0;


        printf("Writing %d bytes to %s\n", (int) buf . st_size, argv[2] );


        //We are using copy_size as a count to determine when we have copied enough bytes to the outp\ut file. 
        //Each time through the loop , except the last time , we will copy BLOCK_SIZE number of bytes from our stored data 
        // to the file fp , then we will increment the offset into the file. 
        //on the last one , instead of copying BLOCK_SIZE number of bytes we just copy however is left . 

        while(copy_size>0)
        {
            int num_bytes;

            //if the remaining number of bytes we need to copy is less than BLOCK_SIZE then only copy the amount that remains. 
            //If we copied BLOCK_SIZE , number of bytes we'd end up with garbage. 


            if(copy_size<BLOCK_SIZE)
            {
                num_bytes=copy_size;

            }
            else
            {
                num_bytes=BLOCK_SIZE;
            }
            // num_bytes=BLOCK_SIZE;

            //we need to get the block_index value from the inode once we are looking for free blocks.
            

            fwrite(file_data[block_index] , num_bytes , 1 , ofp);

            copy_size-= BLOCK_SIZE;
            offset += BLOCK_SIZE;
            block_index++;


            fseek(ofp , offset , SEEK_SET);
        }


       



    }
    else
    {
        printf("Unable to open the file%s\n" , argv[1]);
        perror("Opening the input file");
        return -1;
    }


    //similar functionlaity to your put command. 

    return 0;


}

// 2-3 - free inode block and inode blocl
// 3-5 - blocks for the data
//5 -135 

//create , open , df first. 
