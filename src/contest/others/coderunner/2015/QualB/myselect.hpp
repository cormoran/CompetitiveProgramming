#ifndef MYSELECT_HPP
#define MYSELECT_HPP

#include<iostream>
#include<vector>
#include<unistd.h>
#include<sys/select.h>
#include<algorithm>

namespace my{

class ReadSelect{
  private:
    int fd_;
  public:
    ReadSelect(int fd):fd_(fd){}
    bool isNew(){
        fd_set fds;
        struct timeval timeout ={0,0};
        FD_ZERO(&fds);
        FD_SET(fd_,&fds);
        return ( select(fd_+1, &fds, NULL, NULL, &timeout) >0
                and FD_ISSET(fd_,&fds));
    }
};



}


#endif
