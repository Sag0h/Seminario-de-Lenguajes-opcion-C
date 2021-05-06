
int es_palindromo(const char *word){
    const char *end;
    int len = 0; 
    for(end = word; *end != 0; end++, len++); // voy hasta el final de str
    end--; // en el for se suma uno de mas y apunta al /0
    const char *begin = word;
    int ok = 1;
    for(int i=0, j=len; ok && ((i < (len/2)) && (j > (len/2))); i++, j--){
        ok = (*begin == *end);
        if(ok){
            begin++;
            end--;
        }
    }
    return ok;
}

char *encripto (char *dest, const char *src){
    char *aux_dest;
    const char *p;
    for(p = src; *p != 0; p++, aux_dest++){
        *aux_dest = ~*p;
    }
    *aux_dest = '\0';
    return dest;
}
