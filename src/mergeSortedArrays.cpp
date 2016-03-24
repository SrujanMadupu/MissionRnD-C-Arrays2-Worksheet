/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int length(char *l){

	int lengh = 0;
	while (*l != '\0'){
		lengh++;
		l++;
	}
	return lengh;
}
int greaterorlesser(char *p, char *q){
	int i, j, limit, l;
	l = length(p);
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

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A != NULL && B!= NULL){
		int t = ALen + BLen;
		struct transaction *merge= (struct transaction*)malloc(sizeof(struct transaction)*t);
		int k = 0,i=0,j=0;
		while(i < ALen&&j < BLen){
			if (greaterorlesser(A[i].date, B[j].date) == 1){
				merge[k].amount = A[i].amount;
				merge[k].date[11] = A[i].date[11];
				merge[k].description[20] = A[i].description[20];
				i++;
				k++;
			}
			else if (greaterorlesser(A[i].date, B[j].date) == 2){
				merge[k].amount = B[j].amount;
				merge[k].date[11] = B[j].date[11];
				merge[k].description[20] = B[j].description[20];
				j++;
				k++;
			}
			else{
				merge[k].amount = A[i].amount;
				merge[k].date[11] = A[i].date[11];
				merge[k].description[20] = A[i].description[20];
				k++;
				merge[k].amount = B[j].amount;
				merge[k].date[11] = B[j].date[11];
				merge[k].description[20] = B[j].description[20];
				k++;
				i++;
				j++;
			}
		}
		if (i < ALen){
			while (i < ALen){
				merge[k].amount = A[i].amount;
				merge[k].date[11] = A[i].date[11];
				merge[k].description[20] = A[i].description[20];
				i++;
				k++;
			}
		}
		if (j < BLen){
			while (j < BLen){
				merge[k].amount = B[j].amount;
				merge[k].date[11] = B[j].date[11];
				merge[k].description[20] = B[j].description[20];
				j++;
				k++;
			}
		}
		return merge;
	}
	else{
		return NULL;
	}
}