/*
  emcmotglb.c

  Compile-time configuration parameters

  Set the values in emcmotcfg.h; these vars will be set to those values
  and emcmot.c can reference the variables with their defaults. This file
  exists to avoid having to recompile emcmot.c every time a default is
  changed.

  Modification history:

  20-Mar-2000 WPS added unused attribute to ident to avoid 'defined but not used' compiler warning.
  28-Jul-1999  FMP added NUM_AXES
  8-Jun-1999  FMP took out SM_CYCLE_TIME decl since we're now using
  servo cycle time / 2 for this
  18-Aug-1998  FMP added BIAS, MAX_ERROR
  6-Aug-1998  FMP added SM_CYCLE_TIME
  8-Jul-1998  FMP added EMCMOT_INIFILE defs
  5-Jun-1998  FMP added BACKLASH
  1-Apr-1998  FMP added EMCMOT_COMM_TIMEOUT, EMCMOT_COMM_WAIT
  6-Jan-1998  FMP added PID gains, input/output offsets, base address/key
  15-Nov-1997  FMP changed to emcmotglb.c
  16-Oct-1997  FMP created
  */

#include "emcmotglb.h"          /* these decls */
#include "emcmotcfg.h"          /* initial values */

/* ident tag */
#ifndef __GNUC__
#ifndef __attribute__
#define __attribute__(x)
#endif
#endif

static char __attribute__((unused)) ident[] = "$Id$";

char EMCMOT_INIFILE[EMCMOT_INIFILE_LEN] = DEFAULT_EMCMOT_INIFILE;

// unsigned long int SHMEM_BASE_ADDRESS = DEFAULT_SHMEM_BASE_ADDRESS;

unsigned int SHMEM_KEY = DEFAULT_SHMEM_KEY;

double EMCMOT_COMM_TIMEOUT = DEFAULT_EMCMOT_COMM_TIMEOUT;
double EMCMOT_COMM_WAIT = DEFAULT_EMCMOT_COMM_WAIT;

int NUM_AXES = EMCMOT_MAX_AXIS;

double TRAJ_CYCLE_TIME = DEFAULT_TRAJ_CYCLE_TIME;
double SERVO_CYCLE_TIME = DEFAULT_SERVO_CYCLE_TIME;

double VELOCITY = DEFAULT_VELOCITY;
double ACCELERATION = DEFAULT_ACCELERATION;

double MAX_LIMIT = DEFAULT_MAX_LIMIT;
double MIN_LIMIT = DEFAULT_MIN_LIMIT;

double MAX_OUTPUT = DEFAULT_MAX_OUTPUT;
double MIN_OUTPUT = DEFAULT_MIN_OUTPUT;

int TC_QUEUE_SIZE = DEFAULT_TC_QUEUE_SIZE;

int MMXAVG_SIZE = DEFAULT_MMXAVG_SIZE;

#if 0
double tMmxavgSpace[DEFAULT_MMXAVG_SIZE];
double sMmxavgSpace[DEFAULT_MMXAVG_SIZE];
double nMmxavgSpace[DEFAULT_MMXAVG_SIZE];
#endif

double MAX_FERROR = DEFAULT_MAX_FERROR;

double P_GAIN = DEFAULT_P_GAIN;
double I_GAIN = DEFAULT_I_GAIN;
double D_GAIN = DEFAULT_D_GAIN;
double FF0_GAIN = DEFAULT_FF0_GAIN;
double FF1_GAIN = DEFAULT_FF1_GAIN;
double FF2_GAIN = DEFAULT_FF2_GAIN;
double BACKLASH = DEFAULT_BACKLASH;
double BIAS = DEFAULT_BIAS;
double MAX_ERROR = DEFAULT_MAX_ERROR;

double INPUT_SCALE = DEFAULT_INPUT_SCALE;
double INPUT_OFFSET = DEFAULT_INPUT_OFFSET;
double OUTPUT_SCALE = DEFAULT_OUTPUT_SCALE;
double OUTPUT_OFFSET = DEFAULT_OUTPUT_OFFSET;
