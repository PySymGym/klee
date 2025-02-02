// RUN: %clang %s -emit-llvm %O0opt -c -o %t2.bc
// RUN: rm -rf %t.klee-out
// RUN: %klee --output-dir=%t.klee-out --posix-runtime --exit-on-error %t2.bc --sym-files 1 10
#include "klee/klee.h"
#include <assert.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  int fd = open("A", O_RDWR | O_TRUNC);
  if (fd == -1)
    klee_silent_exit(0);
  assert(fd == 3);
  assert((fcntl(fd, F_GETFD) & FD_CLOEXEC) == 0);
  assert(fcntl(fd, F_SETFD, FD_CLOEXEC, 1) == 0);
  assert((fcntl(fd, F_GETFD) & FD_CLOEXEC) != 0);

  struct flock lck;
  assert(fcntl(fd, F_GETLK, &lck) == 0);
  assert(lck.l_type == F_UNLCK);
  lck.l_type = F_RDLCK;
  assert(fcntl(fd, F_SETLK, &lck) == 0);
  lck.l_type = F_UNLCK;
  assert(fcntl(fd, F_SETLK, &lck) == 0);
  return 0;
}
