// fs.cpp: File System

#include "sfs/fs.h"

#include <algorithm>

#include <assert.h>
#include <stdio.h>
#include <string.h>

// Debug file system -----------------------------------------------------------

void FileSystem::debug(Disk *disk) {
    Block block;

    // Read Superblock
    disk->read(0, block.Data);

    printf("SuperBlock:\n");
    printf("    %u blocks\n"         , block.Super.Blocks);
    printf("    %u inode blocks\n"   , block.Super.InodeBlocks);
    printf("    %u inodes\n"         , block.Super.Inodes);

    Block BlockInode;
    disk->read(1,BlockInode.Data);
    /*
    for(int i=0;i<FileSystem::INODES_PER_BLOCK;i++){
        printf("\tsize: %u\n",BlockInode.Inodes[i].Data);
    */

    // Read Inode blocks
    for(unsigned int i=0;i<block.Super.InodeBlocks;i++){
        printf("Inode %d\n",i+1);
        printf("\tsize: %u\n",block.Inodes[i].Size);
        printf("\tdirect blocks: %u\n",FileSystem::POINTERS_PER_INODE);
    }
}

// Format file system ----------------------------------------------------------

bool FileSystem::format(Disk *disk) {
    // Checking mounted
    if(disk->mounted()){
        printf("Cannot format a mounted device\n");
        return false;
    }
    Block newBlock;
    // Write superblock
    disk->write(0,newBlock.Data);
    //Disk *newDisk=NULL;
    
    // Clear all other blocks
    //disk=newDisk;  ??
    return true;
}

// Mount file system -----------------------------------------------------------

bool FileSystem::mount(Disk *disk) {
    // Read superblock
    Block super;
    disk->read(0,super.Data);
    // Set device and mount
    disk->mount();
    // Copy metadata
    disk->write(0,super.Data);
    // Allocate free block bitmap
    return true;
}

// Create inode ----------------------------------------------------------------

ssize_t FileSystem::create() {
    // Locate free inode in inode table

    // Record inode if found
    return 0;
}

// Remove inode ----------------------------------------------------------------

bool FileSystem::remove(size_t inumber) {
    // Load inode information

    // Free direct blocks

    // Free indirect blocks

    // Clear inode in inode table
    return true;
}

// Inode stat ------------------------------------------------------------------

ssize_t FileSystem::stat(size_t inumber) {
    // Load inode information
    return 0;
}

// Read from inode -------------------------------------------------------------

ssize_t FileSystem::read(size_t inumber, char *data, size_t length, size_t offset) {
    // Load inode information

    // Adjust length

    // Read block and copy to data
    return 0;
}

// Write to inode --------------------------------------------------------------

ssize_t FileSystem::write(size_t inumber, char *data, size_t length, size_t offset) {
    // Load inode
    
    // Write block and copy to data
    return 0;
}
