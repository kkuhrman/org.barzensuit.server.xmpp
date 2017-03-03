/**
 * @file:	bzenxm2d.c
 * @brief:	Project Barzensuit XMPP Server Module  main().
 * 
 * Refrences to "section #.#" in comments are to IETF RFC-6120.
 * @see: https://tools.ietf.org/html/rfc6120
 *
 * @copyright:	Copyright (C) 2017 Kuhrman Technology Solutions LLC
 * @license:	GPLv3+: GNU GPL version 3
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "bzenxm2d.h"

/* Activate the XMPP Server on the local host. */
int start()
{
  int result;

  /* 1.  @todo: Determine the IP address and port at which to connect, typically
         based on resolution of a fully qualified domain name (Section 3.2) */

  /* 2.  Open a TCP connection */

  /* 3.  @todo: Open an XML stream (Section 4.2) */

  /* 4.  @todo: Negotiate TLS for channel encryption (Section 5) */

  /* 5.  @todo: Authenticate using a Simple Authentication and Security Layer
         [SASL] mechanism (Section 6) */

  result = -1;

  return result;
}

/* Terminate the XMPP Server. */
int stop()
{
  int result;

  /* 7.  @todo: Close the XML stream (Section 4.4) */

  /* 8.  Close the TCP connection */

  result = -1;

  return result;
}

int main (int argc, char *argv[])
{
  FILE* flog = NULL;
  pid_t process_id = 0;
  pid_t sid = 0;

  /* @todo: libzenc logging facilities. */
  flog = fopen ("bzend.log", "w+");
  if (flog == NULL)
    {
      fprintf(stderr, "\n\tFailed to start bzend. Could not open logging.\n");
      goto LOG_FAIL;
    }

  /* Create child process */
  process_id = fork();

  /* Exit with fail code if fork() fails  */
  if (process_id < 0)
    {
      fprintf(flog, "Failed to start bzend. fork() returned %d", process_id);
      goto DAEMON_FAIL;
    }

  /* Terminate parent process. */
  if (process_id > 0)
    {
      exit(0);
    }

  /* Unmask file mode. */
  umask(0);

  /* Set new session. */
  sid = setsid();
  if(sid < 0)
    {
      fprintf(flog, "Failed to start bzend. setsid() returned %d", sid);
      goto DAEMON_FAIL;
    }

  /* Change pwd to root. */
  chdir("/");

  /* Close stdin. stdout and stderr. */
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  fprintf(flog, "\n\tStarting bzend... process id is %d.\n", process_id);
  do
    {
      sleep(1);
      /* @todo: */
    } while(1);

 DAEMON_FAIL:
  fflush(flog);
  fclose(flog);

 LOG_FAIL:

  return (0);
}
