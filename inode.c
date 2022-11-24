//Set some blocks as not free for testing.

// Blocks are the units of storage. 
// Files are made up of blocks of bytes.  The inodes maintain a list of which blocks make up a file.  One inode per file.

// We can have up to 125 files in our image so we need 125 inodes


//The directory maps from the filename to an inode number that holds that files information

//my group member and I created a struct for the 
// iNodeMap, BlockMap, and Directory and we understand what they are supposed to do but we are a bit confused about what the structs should hold?

//The maps just specify whether or not that inode or block is in use.  True or False. 0 or 1.

//The directories hold the filename and inode number.  If the first file in the image is a file named “main.c” 
//is in inode 0 then directory[0].name is “main.c” and directory[0].inode is 0.  And iNodeMap[0] == 1 for “in use”.

//And the inode[0].blocks[] contains all the blocks that make up the file. 
// inode[0].size holds the filesize, inode[0].date … etc

