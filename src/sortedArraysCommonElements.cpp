/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int findlength(char *l){
	int lengh = 0;
	while (*l != '\0'){
		lengh++;
		l++;
	}
	return lengh;
}

int validdates(char *p, char *q){
	int i, j, limit, l;
	l = findlength(p);
	limit = l;
	for (i = l - 1; i >= 0; i--){
		if (p[i] != '-'&&q[i] != '-'&&i != 0){
			continue;
		}
		else{
			for (j = i; j<limit; j++){
				if (p[j] - 48<q[j] - 48){
					return 1;
				}
				else if (p[j] - 48>q[j] - 48){
					return 2;
				}
				else
					continue;
			}

		}
		limit = i;
	}
	return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if ((A!=NULL&&B!=NULL)){
		int num[10] = { 0 };
		int k = 0;
		for (int i = 0; i < ALen; i++){
			for (int j = 0; j < BLen; j++){
				if (validdates(A[i].date, B[j].date) == 1){
					j=BLen;
				}
				else if (validdates(A[i].date, B[j].date) == 0){
					num[k] = i;
					k++;
					j = BLen;
				}
				else{
					continue;
				}
			}	
		}
		if (k > 0){
			int j = 0;
			for (int i = 0; i < k; i++){
				B[j] = A[num[i]];
				j++;
			}
			return B;
		}
		else{
			return NULL;
		}
	}
	else{
		return NULL;
	}
}