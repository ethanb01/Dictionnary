#include "dic.h"

static Word* new_word(char* key,char* value) {
	Word* word = (Word*)malloc(sizeof(Word));
	word->value = value;
	word->key = key;
	word->next = NULL;
	return word;
}


// create dictionnary: gets void and returns new dictionnary
Dictionary* new_dictionnary(void) {
	Dictionary *dic = (Dictionary*)malloc(sizeof(Dictionary));
	lst->head = NULL;
	lst->last = NULL;
	lst->length = 0;
	return dic;
}

// function gets int and add Word to the list
void add_word(Dictionary* self, char* key,char* value) {
	Word* to_add = new_word(key,value);		
	
	if (is_empty(self)) {
		self->head = to_add;
		self->last = to_add;
	}
	else
	{
		self->last->next = to_add;
		self->last = to_add;
	}
	self->length++;
}

bool is_empty(Dictionary* self ) {
	return (self->length == 0);
}