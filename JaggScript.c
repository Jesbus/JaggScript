#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "JaggScript.h"
#include "interpreter1.h"

#define OP_POSTINC 111111
#define OP_PREINC 111112
#define OP_POSTDEC 111113
#define OP_PREDEC 111114

object wrapint(int i);
object exOperator(nodeType* args);

object ex(nodeType *p)
{
	object val;
	val.type = VAR_NULL;
	val.valInt = 0;
	static int dropToFunctionCall = 0;
	static int functionReturnValue = 0;
    if (!p) return val;
    switch(p->type)
    {
    case typeConVal:
    {
    	return p->con.val;
    }
    case typeId:
    {
    	if (p->id.position!=-1)
    	{
			return varValues[p->id.position];
		}
    	printf("Error: Non-existant variable %s\n", p->id.name);
    	val.valInt = 0;
    	return val;
    }
    case typeOpr:
    {
        switch(p->opr.oper)
        {
        case FUNCTION:
        {
		    //printf("Case function\n");
			//printf("Function called: %s\n", p->opr.op[0]->id.name);
			//printf("Function position=%i\n", p->opr.op[0]->id.position);
			
			//ex(funcValues[p->opr.op[0]->id.position]); // Execute function.
			
			ex((nodeType*)varValues[p->opr.op[0]->id.position].valFunc); // Execute function :)
			
			//TODO
			/*if (dropToFunctionCall)
			{
				dropToFunctionCall = 0;
				return functionReturnValue;
			}*/
			return val;
        }
        case DOTLENGTH:
        {
        	object in1 = ex(p->opr.op[0]);
        	if (in1.type==VAR_STR)
        	{
		    	val.type = VAR_INT;
		    	val.valInt = strlen(in1.valStr);
		    }
        	else if (in1.type==VAR_STR_REP)
        	{
		    	val.type = VAR_INT;
		    	val.valInt = strlen(in1.valStr)*in1.valStrRep;
		    }
        	return val;
        }
        case WHILE:
        {
        	char executed = 0;
        	while(ex(p->opr.op[0]).valBool)
        	{
        		ex(p->opr.op[1]);
        		executed = 1;
        	}
        	val.type = VAR_BOOL;
			val.valBool = executed;
			return val;
       	}
        case FOR:
        {
        	ex(p->opr.op[0]);
        	val.type = VAR_BOOL;
        	val.valBool = 0;
        	while(ex(p->opr.op[1]).valBool)
        	{
        		ex(p->opr.op[3]);
        		//object latestVal
        		val = ex(p->opr.op[2]);
        		//val.type = latestVal.type;
        		//val.valInt = latestVal.valInt;
        		
        	}
        	return val;
        }
        case IF:
        {
        	if (ex(p->opr.op[0]).valBool)
        	{
            	ex(p->opr.op[1]);
            }
            else if (p->opr.nops > 2)
            {
            	ex(p->opr.op[2]);
            }
            else
            {
            
            }
			return val;
        }
        case PRINT:
        {
        	//to print:
        	object tp = ex(p->opr.op[0]);
        	if (tp.type==VAR_INT) printf("%i\n", tp.valInt);
        	else if (tp.type==VAR_STR) printf("%s\n", tp.valStr);
        	else if (tp.type==VAR_STR_REP)
        	{
        		if (strlen(tp.valStr)==0) return val;
        		int i = 0;
        		for (i=0;i<tp.valStrRep;i++)
        		{
        			printf("%s", tp.valStr);
        		}
        	}
        	else
        	{
        		printf("Error printerror: failed to print.\n");
        	}
			return val;
        }
        case ';':
        {
        	printf("Multiple statements\n");
        	ex(p->opr.op[0]);
        	val = ex(p->opr.op[1]);
        	return val;
        }
        case '=':
        {
        	// It exists:
        	if (p->opr.op[0]->id.position!=-1)
        	{
        		return varValues[p->opr.op[0]->id.position] = ex(p->opr.op[1]);
        	}
        	
        	printf("Error: #024\n");
        	// It doesn't exist:
        	// wtf this should never happen =.=
			return val;
        }
        default:
        {
        	return exOperator(p);
        }
        /*case OP_POSTINC:
        {
			int i=0;
			while(i<varCount)
			{
				if (strcmp(varNames[i],p->opr.op[0]->id.name)==0)
				{
					val.valInt = varValues[i].valInt++;
					return val;
				}
				i++;
			}
			printf("Error: Non-existant variable %s\n", p->opr.op[0]->id.name);
			return val;
        }
        case OP_PREINC:
        {
			int i = 0;
			while(i<varCount)
			{
				if (strcmp(varNames[i],p->opr.op[0]->id.name)==0)
				{
					val.valInt = ++varValues[i].valInt;
					return val;
				}
				i++;
			}
			printf("Error: Non-existant variable %s\n", p->opr.op[0]->id.name);
			return val;
        }
        case OP_POSTDEC:
        {
			int i = 0;
			while(i<varCount)
			{
				if (strcmp(varNames[i],p->opr.op[0]->id.name)==0)
				{
					val.valInt = varValues[i].valInt--;
					return val;
				}
				i++;
			}
			printf("Error: Non-existant variable %s\n", p->opr.op[0]->id.name);
			return val;
        }
        case OP_PREDEC:
        {
			int i = 0;
			while(i<varCount)
			{
				if (strcmp(varNames[i],p->opr.op[0]->id.name)==0)
				{
					val.valInt = --varValues[i].valInt;
					return val;
				}
				i++;
			}
			printf("Error: Non-existant variable %s\n", p->opr.op[0]->id.name);
			return val;
        }
        
        // Logic
        case OP_LAND:   return wrapint(ex(p->opr.op[0]).valInt && ex(p->opr.op[1]).valInt);
        case OP_LOR:    return wrapint(ex(p->opr.op[0]).valInt || ex(p->opr.op[1]).valInt);
        case OP_LXOR:   return wrapint(ex(p->opr.op[0]).valInt ^  ex(p->opr.op[1]).valInt);
        default:
        {
        	printf("Error: Woops! Error #023\n");
        	return val;
        };
        */
        }
    }
    }
    printf("Error: Woopsydaysy error #0299876 ;(\n");
	return val;
}

object exOperator(nodeType* args)
{
	int argc = args->opr.nops;
	object val;
	val.type = VAR_NULL;
	val.valInt = 0;
	object o1 = ex(args->opr.op[0]);
	object o2;
	if (argc>=2)
	{
		o2 = ex(args->opr.op[1]);
	}
	else
	{
		o2.type = VAR_NULL;
		o2.valInt = 0;
	}
	switch (args->opr.oper)
	{
		case '[':
		{
			if (o1.type==VAR_STR && o2.type==VAR_INT)
			{
				val.type = VAR_STR;
				int strLen = strlen(o1.valStr);
				if (o2.valInt<0 || o2.valInt>=strLen)
				{
					printf("Index out of bounds, idiot!\n");
					exit(0);
				}
				char* newStr = malloc(2);
				newStr[0] = o1.valStr[o2.valInt];
				newStr[1] = 0x00;
				val.valStr = newStr;
			}
			else if (o1.type==VAR_STR_REP && o2.type==VAR_INT)
			{
				val.type = VAR_STR;
				int strLen = strlen(o1.valStr);
				if (o2.valInt<0 || o2.valInt>=strLen*o1.valStrRep)
				{
					printf("Index out of bounds, idiot!\n");
					exit(0);
				}
				char* newStr = malloc(2);
				newStr[0] = o1.valStr[o2.valInt%strLen];
				newStr[1] = 0x00;
				val.valStr = newStr;
			}
			break;
		}
		case OP_BNOT:
			if (o1.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = !o1.valInt;
			}
		break;
		case OP_BAND:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt&o2.valInt;
			}
		break;
		case OP_BOR:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt|o2.valInt;
			}
		break;
		case OP_BXOR:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt^o2.valInt;
			}
		break;
		
		
		case OP_EQ:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt==o2.valInt;
			}
		break;
		case OP_NEQ:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt!=o2.valInt;
			}
		break;
		case OP_GT:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt>o2.valInt;
			}
		break;
		case OP_LT:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt<o2.valInt;
			}
		break;
		case OP_GTE:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt>=o2.valInt;
			}
		break;
		case OP_LTE:
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt<=o2.valInt;
			}
		break;
		case OP_MINUS:
		{
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt-o2.valInt;
			}
			break;
		}
		case OP_DIV:
		{
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt/o2.valInt;
			}
			break;
		}
		case OP_PLUS:
		{
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt+o2.valInt;
			}
			else if (o1.type==VAR_STR && o2.type==VAR_STR)
			{
				int len1 = strlen(o1.valStr);
				int len2 = strlen(o2.valStr);
				char* newStr;
				if ((newStr = malloc(len1+len2+1)) == NULL)
				{
					printf("Error: Out of memory!\n");
				}
				memcpy(newStr, o1.valStr, len1);
				memcpy(newStr+len1, o2.valStr, len2);
				newStr[len1+len2] = 0x00;
				val.type = VAR_STR;
				val.valStr = newStr;
			}
			else if (o1.type==VAR_INT && o2.type==VAR_STR)
			{
				//int len1 = strlen(o1.valStr);
				int len2 = strlen(o2.valStr);
				char* intStr;
				if ((intStr = malloc(16)) == NULL)
				{
					printf("Error: Out of memory!\n");
				}
				sprintf(intStr, "%d", o1.valInt);
				int len1 = strlen(intStr);
				char* newStr;
				if ((newStr = malloc(len1+len2+1)) == NULL)
				{
					printf("Error: Out of memory!\n");
				}
				memcpy(newStr, intStr, len1);
				memcpy(newStr+len1, o2.valStr, len2);
				newStr[len1+len2] = 0x00;
				val.type = VAR_STR;
				val.valStr = newStr;
			}
			else if (o1.type==VAR_STR && o2.type==VAR_INT)
			{
				int len1 = strlen(o1.valStr);
				int len2 = 16;
				char* newStr;
				if ((newStr = malloc(len1+len2+1)) == NULL)
				{
					printf("Error: Out of memory!\n");
				}
				memcpy(newStr, o1.valStr, len1);
				sprintf(&newStr[len1], "%d", o2.valInt);
				newStr[len1+len2] = 0x00;
				val.type = VAR_STR;
				val.valStr = newStr;
			}
			else
			{
				printf("Error: Cannot execute operator + on those data types\n");
			}
			break;
		}
		case OP_MUL:
		{
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				val.valInt = o1.valInt*o2.valInt;
			}
			else if ((o1.type==VAR_STR_REP && o2.type==VAR_INT))
			{
				val = o1;
				val.valStrRep *= o2.valInt;
			}
			else if ((o1.type==VAR_STR && o2.type==VAR_INT))
			{
				//val.type = VAR_STR;
				val.type = VAR_STR_REP;
				int strLen = strlen(o1.valStr);
				char* newStr;
				
				if ((newStr = malloc(strLen+1)) == NULL)
				{
					printf("Fatal error: Out of memory!\n");
					exit(0);
				}
				memcpy(newStr, o1.valStr, strLen);
				newStr[strLen] = 0x00;
				//printf("newStr=%s\n", newStr);
				val.valStr = newStr;
				val.valStrRep = o2.valInt;
				
				/*
				if ((newStr = malloc(strLen*o2.valInt+1)) == NULL)
				{
					printf("Fatal error: Out of memory!\n");
					exit(0);
				}
				int i;
				for (i=0;i<o2.valInt;i++)
				{
					memcpy(&newStr[i*strLen], o1.valStr, strLen);
				}
				newStr[strLen*o2.valInt] = 0x00;
				val.valStr = newStr;
				*/
				
			}
			break;
		}
		case OP_POW:
		{
			if (o1.type==VAR_INT && o2.type==VAR_INT)
			{
				val.type = VAR_INT;
				int i1 = o1.valInt;
				int i2 = o2.valInt;
				if (i1==0 && i2==0)
				{
					printf("Math error: 0 ** 0 is undefined\n");
					exit(0);
				}
				else if (i1==0) val.valInt = 0;
				else if (i1==1) val.valInt = 1;
				else if (i2==0) val.valInt = 1;
				else if (i2==1) val.valInt = i1;
				else if ((i1&(i1-1))==0)
				{
					// i1 is a power of 2
					
				}
				else
				{
					printf("WIP error: ** is WIP :(\n");
				}
			}
			break;
		}
	}
	return val;
}

object wrapint(int i)
{
	object val;
	val.type = 1;
	val.valInt = i;
	return val;
}

// TODO
// undefine function should freeNode(funcValue[..]);

void defFunc(char* name, nodeType* func)
{
	varNames[varCount] = name;
	varValues[varCount].type = 4;
	varValues[varCount].valFunc = func;
	varCount++;
/*
	if (funcCount==16)
	{
		printf("NO MORE THAN 16 FUNCTIONS ARE ALLOWED - BITCH\n");
	}
	if (func->type==typeOpr) printf("Funcval is typeOpr\n");
	if (func->opr.oper==';') printf("Hoi ;)\n");
	funcNames[funcCount] = name;
	funcValues[funcCount] = func;
	funcCount++;
*/
}



int objectToString(object o)
{
	return o.valInt;
}
