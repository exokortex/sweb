/**
 * @file FileDescriptor.h
 */

#ifndef FILEDESCRIPTOR_H__
#define FILEDESCRIPTOR_H__

#include "MinixFSTypes.h"
#include <list>

class File;
class FileDescriptor;

extern std::list<FileDescriptor*> global_fd;

/**
 * @class FileDescriptor
 */
class FileDescriptor
{
  protected:
    /**
     * the file descriptor
     */
    uint32 fd_;

    /**
     * the file object
     */
    File* file_;

  public:
    /**
     * constructor
     * @param file the file to create the fd for
     */
    FileDescriptor ( File* file );

    /**
     * destructor
     */
    virtual ~FileDescriptor() {}

    /**
     * get the file descriptor
     * @return the fd
     */
    uint32 getFd() { return fd_; }

    /**
     * get the file
     * @return the file
     */
    File* getFile() { return file_; }

    /**
     * add fd to global fd list
     * @param fd
     */
    static void add(FileDescriptor* fd);

    /**
     * remove fd from global fd list
     * @param fd
     */
    static void remove(FileDescriptor* fd);
};

#endif // FILEDESCRIPTOR_H_
