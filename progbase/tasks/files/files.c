#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<pbconsole.h>
#include<progbase.h>

enum{ BUFFER_SIZE = 100 };

	int file_process(char *file_in, char *file_out){
		const char *read = file_in;
		const char *write = file_out;
		long sum = 0;
		int i = 0;
		char buffer[BUFFER_SIZE];
		FILE *fin = fopen(read, "r");
		FILE *fout = fopen(write, "w");
		if (file_in == NULL || file_out == NULL){
			puts("ERROR");
			return 1;
		}

		fprintf(fout, "%s\n\n","Check every string for negative and positive integers and output their sum");
		while (!feof(fin)) {
			fgets(buffer, BUFFER_SIZE, fin);
			buffer[strlen(buffer) - 1] = '\0';
			sum = 0;
			if((buffer[i] == '-' || isdigit(buffer[i]) != 0) && isdigit(buffer[i+1])){
				const char *str = buffer;
				while (*str != '\0'){
					if(isdigit(*str) || *str == '-'){
						sum += strtol(str,(char **)&str,10);
					}

					else{
						str++;
					}
				}
				fprintf(fout, "%ld\t",sum);			
			}
		}

		fclose(fout);
		fclose(fin);
		return 0;
	}

int main(void){
	file_process("read_file.txt", "output_file.txt");
	return 0;
}

