// textfile.cpp  
// simple reading and writing for text files  
#include "textfile.h"  

unsigned char * readDataFromFile(char *fn)
{
	FILE *fp;
	unsigned char *content = NULL;
	int count = 0;
	if (fn != NULL) {
		fp = fopen(fn, "rb");

		if (fp != NULL) {

			fseek(fp, 0, SEEK_END);
			count = ftell(fp);
			rewind(fp);
			if (count > 0) {
				content = (unsigned char *)malloc(sizeof(unsigned char) * (count + 1));
				count = fread(content, sizeof(unsigned char), count, fp);
				content[count] = '\0';
			}
			fclose(fp);
		}
	}
	return content;

}
char *textFileRead(const char *fn) {


	FILE *fp;
	char *content = NULL;

	int count = 0;

	if (fn != NULL) {
		fp = fopen(fn, "rt");

		if (fp != NULL) {

			fseek(fp, 0, SEEK_END);
			count = ftell(fp);
			rewind(fp);

			if (count > 0) {
				content = (char *)malloc(sizeof(char) * (count + 1));
				count = fread(content, sizeof(char), count, fp);
				content[count] = '\0';
			}
			fclose(fp);
		}
	}
	return content;
}

int textFileWrite(char *fn, char *s) {

	FILE *fp;
	int status = 0;

	if (fn != NULL) {
		fp = fopen(fn, "w");

		if (fp != NULL) {

			if (fwrite(s, sizeof(char), strlen(s), fp) == strlen(s))
				status = 1;
			fclose(fp);
		}
	}
	return(status);
}
