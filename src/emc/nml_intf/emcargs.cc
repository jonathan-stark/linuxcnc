/*
  emcags.cc

  Globals initialized to values in emccfg.h

  Modification history:

  19-Nov-1999 WPS ifdef'd out -host and -queryhost of linux_2_0_36
  17-Nov-1999 WPS moved emcGetArgs from emcglb.c to this file.
  10-Nov-1999 WPS added -host  and -queryhost option to emcGetArgs.
  16-Sep-1999  FMP took out errors in emcGetArgs for unrecognized args
  21-Jul-1999  FMP removed -d from emcGetArgs() since DEBUG is now in
  ini file; added EMC_NMLFILE in emcGetArgs()
  6-Jul-1998  FMP added EMC_DEBUG, emcGetArgs()
  17-Nov-1999 WPS created.
  */

#include <string.h>             /* strcpy() */
#include <stdio.h>       /* fgets() */
#include "rcs.hh"               /* nmlSetHostAlias() */
#include "emcglb.h"             /* these decls */
#include "emccfg.h"             /* their initial values */

/* ident tag */
#ifndef __GNUC__
#ifndef __attribute__
#define __attribute__(x)
#endif
#endif

static char __attribute__((unused)) ident[] = "$Id$";

int emcGetArgs(int argc, char *argv[])
{
  int t;

  /* process command line args, indexing argv[] from [1] */
  for (t = 1; t < argc; t++) {
    if (!strcmp(argv[t], "-ini")) {
      if (t == argc - 1) {
        return -1;
      }
      else {
        strcpy(EMC_INIFILE, argv[t+1]);
        t++;
      }
      continue;
    }
    if (!strcmp(argv[t], "-rcsdebug")) {
      set_rcs_print_flag(PRINT_EVERYTHING);
      max_rcs_errors_to_print=-1;
      continue;
    }
#ifndef linux_2_0_36
    if (!strcmp(argv[t], "-queryhost")) {
      char qhost[80];
      printf("EMC Host?");
      fgets(qhost,80,stdin);
      for (int i = 0; i < 80; i++) {
        if (qhost[i] == '\r' || qhost[i] == '\n' || qhost[i] == ' ') {
          qhost[i]=0;
          break;
        }
      }
      nmlSetHostAlias(qhost,"localhost"); /* If localhost appears in .nml file it will overriden by this argument. */
      nmlForceRemoteConnection();
      /* The only good reason for aliasing the host that I know of is to
         connect to a remote server so we will ignore the LOCAL/REMOTE
         field in the .nml file and always connect remotely. */
      continue;
    }
    if (!strcmp(argv[t], "-host")) {
      if (t == argc - 1) {
        return -1;
      }
      else {
        nmlSetHostAlias(argv[t+1],"localhost"); /* If localhost appears in .nml file it will overriden by this argument. */
        nmlForceRemoteConnection();
        /* The only good reason for aliasing the host that I know of is to
           connect to a remote server so we will ignore the LOCAL/REMOTE
           field in the .nml file and always connect remotely. */
        t++;
      }
      continue;
    }
#endif
  }
  /* else not recognized-- ignore */

  return 0;
}

