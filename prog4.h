/****************************************************************
   PROGRAM:   PROG4.H
   AUTHOR:    AKASH RANGOJOO
   LOGON ID:  Z1717009 
   DUE DATE:  9/24/2015

   FUNCTION:  CONTAINS CONSTANTS FOR FILE PATHS AND METHIDS THAT ARE CALLED FROM SOURCE FILE PROG4.CC
   INPUT:     NO INPUT. 
   OUTPUT:    NO OUTPUT
****************************************************************/



#include "/home/cs689/common/689.h"

#ifndef prog4_h
#define prog4_h

extern void open_files(ifstream & is,ofstream & os);
extern void process_data(ifstream & is,ofstream & os);
extern void close_files(ifstream & is,ofstream & os);

#endif
