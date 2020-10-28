//This is an n-ary tree 
// with nodes containing nonterminal symbol, link to children, the type of the subexpression or variable 
// corresponding to the subtree of the node. The parse tree is created using the grammar and input token stream. 
// Once the parse is created, it is traversed to collect type expression information and populating its non-leaf nodes with accumulated information appropriately. 
// Parse tree nodes are implemented using variant records, 
//which has its variant part implemented using union data type for storing the type expressions.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include "g.h"
#include "tok.h"

union typeExp{
    
    char* str; // if array or none type 
    int i;
    float f;
    bool b;
};

// Linked List of siblings
struct linkedlist{
	struct treenode* head;
	int no_siblings;
};
typedef struct linkedlist Children;

// parse tree node c 
typedef struct treenode{
    struct treenode * parent;
    struct treenode * next; // points to its siblings 
    int term_nonterm;
    Symbol_node_type type; // Terminal or non Terminal 
    Token_s tok; // has line number, token name (Keyword, Op, Symbol) and lexeme (;, }, var, etc), anything that appears in the program
    // tok will be all zeroes and nulls if not a LEAF NODE  
    Children * child;
    int rule_no;
    int height; // handle the height
    union typeExp te;
}TreeNode;



typedef struct tree{
    TreeNode * root;
    TreeNode * next;
}ParseTree;

//initialise tree
ParseTree * iniatilizeTree();
// initialise tree node 
TreeNode* initialize_TreeNode(TreeNode * parent, int rule_no, int term_nonterm, Symbol_node_type type);
// add child 
Children * makeChildList(TreeNode* parent, Rule* rule);
// 
Children* initialize_children();

void printTreeNode(TreeNode *tn);
void printParseTree(ParseTree *t);

// TreeNode * TreeNodeLinkedList(Rule * rule);
void deallocateChildren(Children * children);