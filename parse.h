#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "tokenizer.h"
// #include "tree.h"
// #include "g.h"
#include "stack.h"

void push_rule_reverse_ruchi(Rule * rule, AuxStack * as, MainStack * ms, Children * children );
bool match(Token_s * lookahead , TreeNode * tos);
bool traverseGrammarRules(MainStack * ms, AuxStack * as, TreeNode * tn, Grammar * grm, Token_s * looakahead);
int createParseTree();
bool parsing(MainStack * ms, AuxStack * as, Grammar * grm, Token_s * lookahead );
void preordertraversal(TreeNode * root);




