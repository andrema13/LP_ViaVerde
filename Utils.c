#include "Utils.h"

bool preencheMatriz(struct lanco *matriz, char *ficheiro, bool distancia) {
    FILE * fp;
    char * linha = NULL;
    size_t len = 0;
    const char s[] = "\t\n\0";
    char *token;
    int i = 0, j = 0;

    fp = fopen(ficheiro, "r");
    if (fp == NULL)
        return false;

    while ((getline(&linha, &len, fp)) != -1) {
        j = 0;    
        token = strtok(linha, s);
        
        if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
        else matriz[i * NUM_PORTAGENS + j].preco = atof(token);
        
        j++;
        while(token != NULL ) {
            token = strtok(NULL, s);
            
            if(token != NULL){
                if (distancia) matriz[i * NUM_PORTAGENS + j].dist = atof(token);
                else matriz[i * NUM_PORTAGENS + j].preco = atof(token);
            }
            j++;
        }
        i++;
    }

    fclose(fp);
    if (linha) 
        free(linha);
    
    return true;
}