// // Stack node for main stack
// // Stack node for auxillary stack
// // Tree node for parse tree 

// // Aux stack functions are normal, isEmpty, push, pop
// // Main stack functions are isEmpty, push into aux stack and then into main
// // pop n elemnets from stack, also check token stream and grammar 

// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>
// // #include "g.h"
// #include "tree.h"

// typedef struct main_stack_node{
//     TreeNode stack_tree_node;
//     struct main_stack_node * next_node;
// }MainStackNode;

// typedef struct main_stack_list{
//     MainStackNode* head;
// }MainStackList;
 
// struct main_stack{
//     MainStackList* ms_list;
//     int capacity;
//     int height;
// };
// typedef struct main_stack MainStack;


// typedef struct aux_stack_node{
//     TreeNode stack_tree_node_a;
//     struct aux_stack_node * next_node_a;
// }AuxStackNode;


// typedef struct aux_stack_list{
//     AuxStackNode* head;
// }AuxStackList;

// typedef struct aux_stack{
//     AuxStackList * as_list;
//     int size;
//     // unsigned capacity;  maybe not, take something big 
// }AuxStack;

// // Initialize
// MainStack* initialize_main_stack();
// AuxStack* initilaize_aux_stack();

// // isempty Main
// bool stackisEmpty(MainStack * ms);  // needs to be implemented
// bool auxstackisEmpty(AuxStack * as);
//  // 2@@@@@@@@@@@@@@
// // create 
// MainStackNode* create_main_stack_node();
// AuxStackNode* create_aux_stack_node();
// // push 
// void push_ms(MainStack * ms, TreeNode * treenode);
// void push_as(AuxStack * as, TreeNode * treenode);

// // pop
// MainStackNode* pop_ms(MainStack * ms);
// AuxStackNode* pop_as(AuxStack * as);
// // pop n elements 
// void pop_n(MainStack * ms, int poppin);
// void pop_all_as(AuxStack * as);

// // check if stack over
// int isTopDOLLAR(MainStack* ms);

// // push from aux stack to main 
// void push_rule_reverse(Rule * rule, AuxStack * as, MainStack *ms);

// // return top of stack;
// TreeNode * topofMainStack(MainStack * ms);
// / Stack node for main stack
// Stack node for auxillary stack
// Tree node for parse tree 

// Aux stack functions are normal, isEmpty, push, pop
// Main stack functions are isEmpty, push into aux stack and then into main
// pop n elemnets from stack, also check token stream and grammar 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "g.h"
#include "tree.h"

typedef struct main_stack_node{

    TreeNode * stack_tree_node;
    struct main_stack_node * next_node;
    
}MainStackNode;

typedef struct main_stack_list{
    MainStackNode* head;
}MainStackList;
 
struct main_stack{
    MainStackList* ms_list;
    int capacity;
    int height;
};
typedef struct main_stack MainStack;


typedef struct aux_stack_node{
    TreeNode * stack_tree_node_a;
    struct aux_stack_node * next_node_a;
}AuxStackNode;


typedef struct aux_stack_list{
    AuxStackNode* head;
}AuxStackList;

typedef struct aux_stack{
    AuxStackList * as_list;
    int size;
    // unsigned capacity;  maybe not, take something big 
}AuxStack;

// Initialize
MainStack* initialize_main_stack();
AuxStack* initilaize_aux_stack();

// isempty Main
bool stackisEmpty(MainStack * ms); 
bool auxstackisEmpty(AuxStack * as);

// create 
MainStackNode* create_main_stack_node();
AuxStackNode* create_aux_stack_node();
// push 
void push_ms(MainStack * ms, TreeNode * treenode);
void push_as(AuxStack * as, TreeNode * treenode);

// pop
TreeNode* pop_ms(MainStack * ms);
TreeNode* pop_as(AuxStack * as);
// pop n elements 
void pop_n(MainStack * ms, int poppin);
void pop_all_as(AuxStack * as);

// check if stack over
int isTopDOLLAR(MainStack* ms);

// push from aux stack to main 
void push_rule_reverse(Rule * rule, AuxStack * as, MainStack *ms);

// return top of stack;
TreeNode * topofMainStack(MainStack * ms);