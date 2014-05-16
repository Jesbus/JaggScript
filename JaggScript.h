#define VAR_NULL 0
#define VAR_INT 1
#define VAR_BOOL 2
#define VAR_STR 3
#define VAR_FUNC 4
#define VAR_STR_REP 5

typedef enum { typeConVal, typeId, typeOpr } nodeEnum; // typeFid, 

typedef struct object
{
	char type; // 0 = NULL, 1 = INT, 2 = BOOL, 3 = STRING, 4 = FUNCTION
	union
	{
		int valInt;
		char valBool;
		char* valStr;
		struct nodeTypeTag* valFunc;
	};
	int valStrRep;
} object;

typedef struct
{
	object val;
} conNodeType;

typedef struct
{
	char* name;
	int position;
} idNodeType;

typedef struct
{
	int oper;				   /* operator */
	int nops;				   /* number of operands */
	struct nodeTypeTag **op;	/* operands */
} oprNodeType;

typedef struct nodeTypeTag
{
	nodeEnum type;			  /* type of node */

	union
	{
		conNodeType con;		/* constants */
		idNodeType id;		  /* identifiers */
		oprNodeType opr;		/* operators */
	};
} nodeType;

int objectToString(object o);
object ex(nodeType *p);
void defFunc(char* name, nodeType* func);
extern int sym[26];
extern char *varNames[16];
extern object varValues[16];
extern int varCount;
