// =======================================================================================================
// PPL ASSIGNMENT 1 2020
// GROUP NUMBER 47
// ANUSHKA JAIN 2017B1A70975P
// KUMAR SAURABH 2017B3A70626P
// MANSI MITTAL 2017B1A70991P
// RUCHI BATRA 2017B3A70629P
// =======================================================================================================



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include"g.h"



//Mappings of ENUM to String
char* TerminalMap[] = {
	"PROGRAM", "SZ", "OP", "CL", "COP", "CCL", "SQOP", "SQCL", "DOTS", "EPSILON", "COLON", "SEMICOLON", "ID", "IDB", "NUM", "INT", "BOOLEAN", "REAL", "ARRAY", "JAGGED", "DEC", "LIST", "OF", "VARIABLES", "R", "VALUES", "EQUALS", "PLUS", "MINUS", "MUL", "DIV", "AND", "OR","DOLLAR"
};

char* NonTerminalMap[] = {
    "program", "stmts", "stmt", "more_stmts", "decl", "declaration", "assign", "var_list", "type", "primitive", "array", "rectangular", "jagged", "arr_dims", "arr_dim", "range", "low", "high", "rows_dec_R1", "rows_dec_jR1", "op_dim", "rowjj", "rowj", "expression", "expression_arith", "expression_bool", "term", "term_bool", "factor", "factor_bool", "ind_list", "more_ind_list", "remaining_var", "more_rowj", "more_rowjj", "array_op", "op_no_op_or", "op_no_op_and", "op_plus_minus", "op_mul_div", "more_arr_dims"
};


//Loads grammar from text file 
Grammar* readGrammar(char* grammar_text_file){

	int next_rule_no = 1;

	FILE* input = fopen(grammar_text_file, "r");
    printf("Loaded");
	if(input==NULL){
		fprintf(stderr, "Error Opening Grammar File\n");
		return NULL;
	}

	int end_of_file = 0;

	Grammar* grm = initialize_grammar();
    printf("\n Init");

	char ch;
    int i =1;
	while(1){

		if(end_of_file==1)
			return grm;

		//Waiting for LHS of a rule
		while((ch = fgetc(input))!='<'){
			//If no new rule is available
			if(ch==EOF){
				return grm;
			}
		}
		
		//Load a new rule
        // printf("\n Loading rule %d", i);
        i++;
		char* non_term_str = (char*)malloc(sizeof(char)*MAX_SYMBOL_SIZE);
		int i = 0;
		while((ch = fgetc(input))!='>'){
			non_term_str[i++] = ch;
		}
		non_term_str[i] = '\0';


		//Load LHS of the rule -- the corresponding enum
		NonTerminal non_term  =  find(non_term_str,1);
		//Now look for RHS of the rule
		Rule* new_rule = initialize_rule(&next_rule_no);
		Symbol_list* list = initialize_symbols_list();
		Symbol_node* curr_node = list->head;

		while(1){
			if(end_of_file==1)
				break;

			ch = fgetc(input);

			while(ch==' '|| ch == '\t' || ch== '=' || ch== '>'){
				ch = fgetc(input);
			}

			//For new line, new rule begins
			if(ch == '\n')
				break;

			//If EOF, notify not to read further for new rules
			else if(ch == EOF){
				end_of_file = 1;
				break;
			}

			else if(ch>='A'&&ch<='Z' || ch=='e'){
				
				char* term_str = (char*)malloc(sizeof(char)*MAX_SYMBOL_SIZE);
				int i = 0;
				term_str[i++] = ch;
				ch = fgetc(input);
				while(ch>='A'&&ch<='Z'){
					term_str[i++] = ch;
					ch = fgetc(input);
				}

				term_str[i] = '\0';
								
				Symbol_node* sym_node = create_symbol(find(term_str,0), 0);

				//Adding Symbol to the list
				curr_node = add_symbol_to_symbol_list(list, sym_node, curr_node);
				

				if(ch == EOF || ch == '\n'){
					if(ch==EOF)
						end_of_file = 1;
					break;
				}
			}

			else if(ch=='<'){
				
				char* non_term_str = (char*)malloc(sizeof(char)*MAX_SYMBOL_SIZE);
				int i = 0;
				while((ch = fgetc(input))!='>'){
					non_term_str[i++] = ch;
				}

				non_term_str[i] = '\0';
				
				Symbol_node* sym_node = create_symbol(find(non_term_str,1), 1);

				//Adding Symbol to the list
				curr_node = add_symbol_to_symbol_list(list, sym_node, curr_node);
				
			}
		}
		
		//Assigning the symbol list to the new_rule
		new_rule->symbols = list;
		
		//Add new rule to the grammar
		add_rule_to_grammar(grm,non_term,new_rule);		
	}
} 


Grammar* initialize_grammar(){
	Grammar* grm = (Grammar*)malloc(sizeof(struct grammar));
	grm -> no_of_rules = 0;

	//Total non-terminals will be equal to total number of rules
	grm -> rules = (Rules**)malloc(sizeof(Rules*)*TOTAL_NON_TERMINALS);

	for(int i = 0; i<TOTAL_NON_TERMINALS;i++){
		grm->rules[i] = (Rules*)malloc(sizeof(struct rules));
		grm->rules[i]->head = NULL;
		grm->rules[i]->length = 0;		
	}

	return grm;
}


Symbol_list* initialize_symbols_list(){
	Symbol_list* list = (Symbol_list*)malloc(sizeof(Symbol_list));
	list->head = NULL;
	list->length = 0;

	return list;
}

Rule* initialize_rule(int* next_rule_no){
	Rule* new_rule = (Rule*)malloc(sizeof(Rule));
	new_rule->next = NULL;
	new_rule->symbols = NULL;

	new_rule->rule_no = *next_rule_no; 
	*next_rule_no = *next_rule_no+1;

	return new_rule;
}

Symbol_node* create_symbol(int enum_int, int term_or_nonterm){
	Symbol_node* sym_node = (Symbol_node*)malloc(sizeof(Symbol_node));
	sym_node->next=NULL;
	Symbol_node_type type;
	if(term_or_nonterm==0){
		type.terminal = (Tokentype)enum_int;
	}
	else{
		type.nonterminal = (NonTerminal)enum_int;
	}
	sym_node->type = type;
	sym_node->term_or_nonterm = term_or_nonterm;

	return sym_node;


}

int find(char* str, int term_or_nonterm){
	
	//Terminal
	if(term_or_nonterm==0){
		for(int i=0;i<total_token_types;i++){
			if(strcmp(str,TerminalMap[i])==0)
				return i;
		}
	}

	//Non terminal
	else{
		for(int i=0;i<TOTAL_NON_TERMINALS;i++){
			if(strcmp(str,NonTerminalMap[i])==0)
				return i;
		}
	}
}


Symbol_node* add_symbol_to_symbol_list(Symbol_list* list, Symbol_node* sym_node, Symbol_node* curr_node){
	
	//If initially the list is empty
	if(curr_node==NULL){
		sym_node->next = list->head;
		list->head = sym_node;
		curr_node = list->head;
	}
	else{
		curr_node->next = sym_node;
		curr_node = curr_node->next;
	}

	list->length++;

	return curr_node;
}

void add_rule_to_grammar(Grammar* grm, NonTerminal non_term, Rule* new_rule){

	new_rule->next = grm->rules[non_term]->head;
	grm->rules[non_term]->head = new_rule;

	//One more Rule added for the non terminal
	grm->rules[non_term]->length++;

	grm->no_of_rules++;
}

void print_grammar(Grammar* grm){
	printf("\n============================Printing Grammar===========================\n\n");

	for(int i=0;i<TOTAL_NON_TERMINALS;i++){
		
		printf("%d.  <%s> ===> ",(i+1), NonTerminalMap[i]);

		Rules* rules = grm->rules[i];

		Rule* temp = rules->head;

		for(int j = 0;j< rules->length;j++){
			if(j!=0)
				printf("| ");

			Symbol_list* symbols = temp->symbols;
			Symbol_node* temp2 = symbols->head;

			for(int k=0;k<symbols->length;k++){
				if(temp2->term_or_nonterm==0)
					printf("%s", TerminalMap[temp2->type.terminal]);
				else
					printf("<%s>", NonTerminalMap[temp2->type.nonterminal]);

				printf(" ");
				temp2 = temp2->next;
			}

			
			temp = temp->next;
		}
		printf("\n");
	}
	printf("\n========================Grammar Over====================\n");
	
}
