/* Bit Masks */
#define STEPPING_NUMBER 0x0F
#define MODEL_NUMBER	0xF0
#define FAMILY_NUMBER	0x0F00
#define PROCESSOR	0xF000


/* Function Prototypes */
char * read_cpu();


/* Helper Functions */
void error(char *message)
{
	fprintf(stderr, "ERROR: %s\n", message);
	exit(1);
}

