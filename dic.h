typedef struct Word {
	char *key;
	char *value;
	struct Word* next;
} Word;

typedef struct Dictionary {
	Word* head;
	Word* last;
	int length;
} Dictionary;