/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int findlen(char *l){
	int lengh = 0;
	while (*l != '\0'){
		lengh++;
		l++;
	}
	return lengh;
}
int check(char *p, char *q){
	int i, j, limit, l;
	l = findlen(p);
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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr&&len > 0){
		if (check(Arr[len - 1].date,date)==1){
			return 0;
		}
		else{
			int count = 0;
			int first = 0, last = len - 1;
			while (first <= last){
				int mid = first + ((last - first) / 2);
				if (check(Arr[mid].date, date) == 2){
					count = len - mid;
					last = mid - 1;
					if (mid == 0){
						break;
					}
				}
				else{


					if (mid >= last){
						count = 0;
						break;
					}
					first = mid + 1;
				}
			}
			return count;
		}
		}
	else{
      return -1;
	}
}
