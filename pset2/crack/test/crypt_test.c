#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <crypt.h>
#include <cs50.h>

int main(void)
{
  unsigned long seed[2];
  char salt[] = "$1$........";
  const char *const seedchars =
    "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  char *password;
  int i;

  /* Generate a (not very) random seed, you should do it better than this... */
  seed[0] = time(NULL);
  seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);

  /* Turn it into printable characters from ‘seedchars’. */
  for (i = 0; i < 8; i++)
    salt[3+i] = seedchars[(seed[i/5] >> (i%5)*6) & 0x3f];

  /* Read in the user’s password and encrypt it. */
  password = crypt(get_string("Password:"), salt);

  /* Print the results. */
  printf("%s\n", password);
  return 0;
}