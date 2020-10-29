#include "traverse.h"

// Line number ( This refers to the line number in the leaf node taken from the token stream at the time of creating parse tree. The errors printed without this line number will not get any credit.)
//  Statement type (declaration or assignment)
//  operator
//  lexeme of first operand
//  type of first operand
//  lexeme of second operand
//  type of second operand
//  position in the parse tree in terms of its depth from parse tree’s root node (take root node depth as 0)
//  short message (in maximum 30 characters length)