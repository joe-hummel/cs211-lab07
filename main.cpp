/*main.cpp*/

/**
  * @brief C++ program for traversing nuPython program graph.
  *
  * To run:
  *
  *   ./a.out filename.py
  *
  * Or you can just ./a.out and enter the nuPython program manually
  * line by line, entering $ to denote the end of the input program.
  * This is helpful for small test programs.
  *
  * @author YOUR NAME
  *
  * @author original template by Prof. Joe Hummel
  * @note Northwestern University
  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // true, false

//
// When including header files that are meant for C,
// we need to tell C++ to treat these differently:
//
extern "C" {
  #include "tokenqueue.h"
  #include "parser.h"
  #include "programgraph.h"
}


/**
  * @brief main
  *
  * usage: ./a.out [filename.py]
  * 
  * If a filename is given, the file is opened and serves as
  * input to the debugger. If a filename is not given, then 
  * input is taken from the keyboard until $ is input.
  *
  * @param argc # of arguments to program
  * @param argv Array of actual arguments
  * @return 0 Success
  */
int main(int argc, char* argv[])
{
  FILE* input = nullptr;
  bool  keyboardInput = false;

  //
  // where is the input coming from?
  //
  if (argc < 2) {
    //
    // no args, just the program name:
    //
    input = stdin;
    keyboardInput = true;
  }
  else {
    //
    // assume 2nd arg is a nuPython file:
    //
    char* filename = argv[1];

    input = fopen(filename, "r");

    if (input == nullptr) // unable to open:
    {
      printf("**ERROR: unable to open input file '%s' for input.\n", filename);
      return 0;
    }

    keyboardInput = false;
  }

  if (keyboardInput)  // prompt the user if appropriate:
  {
    printf("nuPython input (enter $ when you're done)>\n");
  }

  //
  // call parser to check program syntax:
  //
  struct TokenQueue* tokens = parser_parse(input);

  if (tokens == nullptr)
  {
    // 
    // program has a syntax error, error msg already output:
    //
    printf("**parsing failed...\n");
  }
  else
  {
    //
    // we have a valid program in terms of syntax, so let's
    // build the program graph so we can work with program:
    //
    printf("**parsing successful\n");
    printf("**building program graph\n");
    printf("\n");

    struct STMT* program = programgraph_build(tokens);

    //
    // TODO:
    //
    // Traverse the program graph denoted by "program" and
    // output the type of each statement. 
    //


    //
    // done, free data structures:
    //
    programgraph_destroy(program);
    tokenqueue_destroy(tokens);
  }

  //
  // done:
  //
  if (!keyboardInput)
    fclose(input);

  return 0;
}
