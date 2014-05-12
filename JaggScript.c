#include <stdio.h>
#include "JaggScript.h"
#include "interpreter1.h"

/*int exB(nodeType* p)
{
	
}*/


//char funcNames[16];
//nodeType* funcs[16];
//int funcsc = 0;

int ex(nodeType *p)
{
    if (!p) return 0;
    switch(p->type)
    {
    case typeCon:       return p->con.value;
    case typeId:
    {
    	int i = 0;
    	while (i<varCount)
    	{
    		if (strcmp(varNames[i], p->id.name)==0) return varValues[i];
    		i++;
    	}
    	printf("ERROR: Undefined variable %s\n", p->opr.op[0]->id.name);
    	return 0;
    }
    case typeOpr:
        switch(p->opr.oper)
        {
        case FUNCTION:
            printf("should be memorizing a function here...\n");
            /*if (funcsc==16)
            {
            	printf("NO MORE THAN 16 FUNCTIONS ARE ALLOWED - BITCH\n");
            }*/
            //funcNames[funcsc] = p->opr.op[0];
            //funcs[funcsc] = p->opr.op[1];
            //funcsc++;
        return 0;
        case WHILE:     while(ex(p->opr.op[0])) ex(p->opr.op[1]); return 0;
        case FOR:       ex(p->opr.op[0]); while(ex(p->opr.op[1])) { ex(p->opr.op[3]); ex(p->opr.op[2]); } return 0;
        case IF:        if (ex(p->opr.op[0]))
                            ex(p->opr.op[1]);
                        else if (p->opr.nops > 2)
                            ex(p->opr.op[2]);
                        return 0;
        case PRINT:     printf("%d\n", ex(p->opr.op[0])); return 0;
        case ';':       ex(p->opr.op[0]); return ex(p->opr.op[1]);
        case '=':
        {
        	//printf("Start assign to %s\n", p->opr.op[0]->id.name);
        	int i = 0;
        	while (i<varCount)
        	{
        		if (strcmp(varNames[i], p->opr.op[0]->id.name)==0) return varValues[i] = ex(p->opr.op[1]);
        		i++;
        	}
        	
        	if (varCount==16)
        	{
        		printf("Error: Max amount of variables is currently 16.\n");
        		return -1;
        	}
        	varNames[varCount] = p->opr.op[0]->id.name;
        	int newVal = ex(p->opr.op[1]);
        	//printf("Assigning to %s\n", p->opr.op[0]->id.name);
        	varValues[varCount] = newVal;
        	return varValues[varCount++];
        	//return sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
        }
        
        // Calculation
        case OP_PLUS:   return ex(p->opr.op[0]) + ex(p->opr.op[1]);
        case OP_MINUS:  return ex(p->opr.op[0]) - ex(p->opr.op[1]);
        case OP_MUL:    return ex(p->opr.op[0]) * ex(p->opr.op[1]);
        case OP_DIV:    return ex(p->opr.op[0]) / ex(p->opr.op[1]);
        
        // Comparison
        case OP_EQ:     return ex(p->opr.op[0]) == ex(p->opr.op[1]);
        case OP_NEQ:    return ex(p->opr.op[0]) != ex(p->opr.op[1]);
        case OP_GT:     return ex(p->opr.op[0]) >  ex(p->opr.op[1]);
        case OP_LT:     return ex(p->opr.op[0]) <  ex(p->opr.op[1]);
        case OP_GTE:    return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
        case OP_LTE:    return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
        
        // Bitwise
        case OP_BNOT:   return ~ex(p->opr.op[0]);
        case OP_BAND:   return ex(p->opr.op[0]) & ex(p->opr.op[1]);
        case OP_BOR:    return ex(p->opr.op[0]) | ex(p->opr.op[1]);
        case OP_BXOR:   return ex(p->opr.op[0]) ^ ex(p->opr.op[1]);
        
        // Logic
        case OP_LAND:   return ex(p->opr.op[0]) && ex(p->opr.op[1]);
        case OP_LOR:    return ex(p->opr.op[0]) || ex(p->opr.op[1]);
        case OP_LXOR:   return ex(p->opr.op[0]) ^  ex(p->opr.op[1]);
        }
    }
    return 0;
}
