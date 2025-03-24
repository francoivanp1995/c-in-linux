#ifndef ARCHIVOS_H
#define ARCHIVOS_H

int openFile(char *fileName, char *type);
int readFile(char *fileName);
int writeFile(char *fileName);
void closeFile();

#endif /* _ARCHIVOS_ */
