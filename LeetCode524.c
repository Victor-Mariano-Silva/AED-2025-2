char* findLongestWord(char* s, char** dictionary, int dictionarySize);
int compare(const void* a,const void* b);
int isThere(char* s, char* word);

// comparar as palavras do array com as letras da string e salvar quais que podem ser formadas e selecionar a maior
//usar o quick sot para organizar a string s para formar o array

char* findLongestWord(char* s, char** dictionary, int dictionarySize) {

    //funçao do stdlib qsort(void * arr, size_t amount, size_t size, compare);
    qsort(dictionary, dictionarySize, sizeof(char*), compare);
    
    // compara cada palavra do array com a string até encontrar uma que retorne, e como já está ordenado a primeira
    // a ser encontrada é a maior
    for (int i = 0; i < dictionarySize; i++) {
        if (isThere(s, dictionary[i])) {
            return dictionary[i];
        }
    }
    
    //caso não tenha resultado possivel
    return "";
}

int compare(const void* a,const void* b) {

    char* s1 = *(char **)a;
    char* s2 = *(char **)b;

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // como queremos ordenar de maior para menor invertemos a logica, 
    // retorna numero negativo se a for maior que b, e positivo se b for maior que a
    if (len1 != len2) {
        return len2 - len1;
    }
    return strcmp(s1,s2);
}

int isThere(char* s, char* word){
    int i = 0, j = 0;
    int s_len = strlen(s);
    int word_len = strlen(word);

    //compara cada caractere da palavra do array com os da string
    //caso encontre incrementa o j
    while(i < s_len && j < word_len) {
        if (s[i] == word[j]) {
            j++;
        }
        i++;
    }

    //apenas retorn true se o j for igual ao tamanho da palavra do array
    return j == word_len;
}