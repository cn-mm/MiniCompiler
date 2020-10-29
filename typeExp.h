#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//  typeExpressionTable: The table is a two dimensional array implemented for storing the types for each array. This is implemented using variant record with three of the following fields being fixed and the fourth for type expression being the variant one. The four fields are as follows.
//  Field 1: The name of variable extracted from the declaration statement and to be used in the assignment statement.
//  Field 2: The information about whether it is an array or not, if yes, then whether it is rectangular array or a jagged array. Use numbers enumerated values of 0, 1 and 2 for primitive data type, rectangular array and jagged array respectively. The value 0 corresponds to integer, real and Boolean types. However, these primitive type details are filled in the fourth field explicitly defining the integer, real or Boolean specifications appropriately.
//  Field 3: If the type is a rectangular array, then whether it is static or dynamic based on the type of range parameters used in defining the array type. If it is not a rectangular array this value is stored as “not_applicable”.
//  Field 4: type expression, which is implemented using the union data type.
// This table is populated on the fly as the parse tree is traversed and the types are computed fully.


// Using array of linked lists 

typedef enum {
    PRIMITIVE, RECTANGUALRARRAY, JAGGEDARRAY
}ArrayorNot;

typedef enum{
    NON_APPLICABLE, STATIC, DYNAMIC
}StatDy;

#define NUM_ROWS 200

typedef union type_exp{
    int inte;
    float rea;
    bool boo;
}typeExp;

typedef struct typeExpRow{
    char * var_name; // Field 1
    ArrayorNot arr_noarr; // Field 2
    StatDy stat_dyn; // Field 3 only when ArrayorNot is rect i.e 1
    typeExp type_exp; // Field 4 only when ArrayorNot is 0
}typeExpressionRow;

 
typedef struct typeExpTable{
    typeExpressionRow rows[NUM_ROWS];
    int num_rows;
}typeExpressionTable;