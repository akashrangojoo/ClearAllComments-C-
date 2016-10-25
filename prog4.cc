/***************************************************************
PROGRAM:   PROG4.CC
AUTHOR:    AKASH RANGOJOO
LOGON ID:  Z1717009
DUE DATE:  9/24/2015

FUNCTION:  Clears all the comments from a CC file and outputs a coment less file
INPUT:     Takes a CC File as input prog4d.cc
OUTPUT:    Puts all the comment less code into prog4NMyOut.cc File
 ****************************************************************/


#include "/home/cs689/common/689.h"
#include "error.h"
#include "prog4.h"
/*
#include <iostream>
#include <fstream>
#include <string>
#include <istream>

void open_files(ifstream & is,ofstream & os);
void process_data(ifstream & is,ofstream & os);
void close_files(ifstream & is,ofstream & os);
*/

int main(){

   ifstream infile;
   ofstream outfile;

   open_files(infile,outfile);  // Opening the Files
   process_data(infile,outfile);// Process the Data
   close_files(infile,outfile); // Close Files
}

/**************************************************************
 *  Method to open input and output files.
 ***************************************************************/
void open_files(ifstream & infile,ofstream & outfile)
{
   infile.open("prog4d.cc");
   if(infile.fail()) error("Could not open File");
   outfile.open("prog4MyOut.cc");
   if(outfile.fail()) error("Could not put in File");

}

/*************************************************************
 * This method takes the input and fetches one line after another
 * For each line, it checks if any comment specifiers are present.
 * And then outputs the uncommented code
 ***************************************************************/
void process_data(ifstream & infile,ofstream & outfile)
{
   string str;
   int startPos, endPos;
   bool commentsOn=false;
   string uncommented;

   while(!getline(infile,str).eof()){ // Getting Line after Line
      uncommented=str;
      if(!commentsOn){
         int lineComment= str.find(" // ");startPos = str.find("/*"); // Checking if line has "//"
         if(lineComment!=-1) {uncommented = str.substr(0,lineComment);outfile<<uncommented<<endl;continue;}
         else{
            string s="";
            // Checking if the code has "" and comments included between them. If yes they're
            // // considered as comments...!!
            int quotStart = str.find('"');
            string quot1 = str.substr(0,quotStart);
            int extra= quot1.length();
            string quot2 = str.substr(quotStart+1,str.length());
            int quotEnd = quot2.find('"')+extra;
            //Checking if the line has /*
            if(startPos!= -1){
               endPos = str.find("*/"); //checking if the line has */
               if(startPos!=-1&&quotStart!=-1&&quotEnd!=-1&&startPos>quotStart && endPos<quotEnd)
               {
                  s = str.substr(0,quotEnd+1);
               }
               string s1="";
               if(startPos!=0 && quotStart==-1){s1 = str.substr(0,startPos);}

               if(endPos!= -1){/*write code to print the rest of the line after end comments*/
                  string s2;
                  if(endPos==str.length()-2) s2="";
                  else {
                     string test = str.substr(endPos+2,str.length());
                     while(test.length()!=0){ // checking if any more comments are present in the same line
                        int x= test.find("/*");
                        int y= test.find("*/");
                        if(x==-1) {s2+=test; test="";}
                        else if(x==0) test=test.substr(y+2,test.length());
                        else {s2=s2+test.substr(0,x); test=test.substr(y+2,test.length());}
                     }
                  }
                  // copying uncommented code into a variable
                  uncommented = s+s1+s2;
                  // Putting that code into the output file.
                  outfile<<uncommented<<endl;
                  //if */ is not found in the same line, commentsOn is set true. If it is found commentsOn is set false
                  commentsOn=false;}
               else{outfile<<s<<endl;commentsOn=true;}
            }
            else outfile<<uncommented<<endl;
         }
      }
      else {
         endPos = str.find("*/");
         if(endPos !=-1) {/*write code to find uncommented code*/
            string s2;

            if(endPos==str.length()-2) s2="";
            else {
               string test = str.substr(endPos+2,str.length());
               while(test.length()!=0){
                  int x= test.find("/*");
                  int y= test.find("*/");
                  if(x==-1) {s2+=test; test="";}
                  else if(x==0) test=test.substr(y+2,test.length());
                  else {s2=s2+test.substr(0,x); test=test.substr(y+2,test.length());}
               }
            }

            uncommented = s2;
            outfile<<uncommented<<endl;
            commentsOn=false;
         }
      }
   }

}

/**************************************************************
  Method to close input and output files.
 ***************************************************************/
void close_files(ifstream & infile,ofstream & outfile)
{
   outfile.close();
   infile.close();
}

