#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fil;
    int WordSize = 3;
    fil = fopen("Sentence.txt" , "rt");
    //finds the size of the word, plus the string terminator and the space for the "ay"
    do{
        WordSize++;
    }while(fgetc(fil) != EOF);
    
    //alocs the memory space for the string
    char *OriginalWord;
    OriginalWord = (char*) malloc(sizeof(char) * WordSize);
    fclose(fil);
    fil = fopen("Sentence.txt" ,"at");
    
    //gets the word from the text file
    fscanf(fil, "%s", OriginalWord);
    
    //translates the word
    WordSize--;
    int end_of_translation = WordSize - 1;
    OriginalWord[end_of_translation] = OriginalWord[0];
    for(int count = 0; count <= end_of_translation; count++){
        OriginalWord[count] = OriginalWord[count + 1];
    }
    OriginalWord[end_of_translation] = 'a';
    OriginalWord[WordSize] = 'y';

    //saves at the file the translated word
    fprintf(fil, "\n The translation to Pig Latin is: %s", OriginalWord);
    
    //closes the file
    fclose(fil);
    return 0;
}
