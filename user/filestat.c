#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"


int
main(int argc, char *argv[])
{
  int printed;
  char * pathname;
  struct stat st;
  if (argc != 2) {
    printf(2, "Usage: %s <pathname>\n", argv[0]);
    exit();
  }

  pathname = argv[1];
  int fd = open(pathname, O_CREATE | O_CHECKED | O_RDWR);
  printed = write(fd, "blahblahblah", 12);
  close(fd);
  stat(pathname, &st);
  printf(1, "fd: %d\n", fd);
  printf(1, "written: %d\n", printed);
  printf(1, "type: %x\n", st.type);
  printf(1, "size: %d\n", st.size);
  printf(1, "checksum: %x\n", st.checksum);
  exit();
}
