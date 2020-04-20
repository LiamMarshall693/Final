#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int DISK_SIZE = 500;
	int init_pos = 250;

	int base_requests[] = {3,100,106,98,150,90,122,133,400, 20};
	int requests[10];
	for (int i = 0; i < 10; i++){
		requests[i] = base_requests[i];
	}

	printf("Scanning with SCAN...\n");
	int scanned = 0;
	int dir = 1;
	int j = init_pos;
	int found = 0;
	while (found < 10){
		j+= dir;
		scanned++;
		for (int k = 0; k < 10; k++){
			if (requests[k] == j){
				printf("Read %d\n", j);
				requests[k] = -1;
				found++;
			}
		}
		if (j >= DISK_SIZE){
			dir = -1;
		}
		if (j <= 0){
			dir = 1;
		}
	}
	printf("Finished SCAN, total entries read: %d\n", scanned);

	printf("Scanning with SSTF...\n");
	scanned = 0;
	j = init_pos;
	found = 0;

	for (int i = 0; i < 10; i++){
		requests[i] = base_requests[i];
	}
	while (found < 10){
		int min = 2000;
		int ind = 0;
		for (int i = 0; i <10; i++){
			if ( abs(requests[i]-j) < abs(min-j) && requests[i] != -1){
				min = requests[i];
				ind = i;
			}
		}
		requests[ind] = -1;
		scanned += abs(min - j);
		j = min;
		found++;
		printf("Read %d\n", j);
	}

	printf("Finished SSTF, total entries read: %d\n", scanned);
}
