#/****************************************************************
   PROGRAM:   ERROR.CC
   AUTHOR:    AKASH RANGOJOO
   LOGON ID:  Z1717009
   DUE DATE:  9/16/2015

   FUNCTION:  HAS IMPLEMENTATION FOR STDERR TO PRINT OUT ERRORS ON TO STREAM

   INPUT:     NO INPUT.

   OUTPUT:    NO OUTPUT.
****************************************************************/

#include "error.h"

void error(string error) {
  cerr<<error<<endl;
  exit(EXIT_FAILURE);
}

