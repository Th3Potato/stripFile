#include <stdio.h>
#include <string.h>
#include <ctype.h>

char wordList[622115][255];
int counter = 0;

int lengthCheck(char word[]){
    int checkLength = 0;
    for(int pos = 0; pos < strlen(word); pos++){
        if((unsigned char) word[pos-1] == 195){
            checkLength--;
        }
        checkLength++;
    }
    //printf("lengde: %d\n", checkLength);
    return checkLength;
}

char *removeEOA(char line[]){
    //printf("ord: %s\n", line);
    //printf("verdi i pos 2: %d\n", (unsigned char) line[2]);
    for(int pos = 0; pos <= strlen(line); pos++){
        if((unsigned char) line[pos-1] == 195){
            if((unsigned char)line[pos] == 134){line[pos] = 166;}
            if((unsigned char)line[pos] == 152){line[pos] = 184;}
            if((unsigned char)line[pos] == 133){line[pos] = 165;}
            counter++;
        }
    }
    
    return line;
}

void removeSpaces(char *line){
    for(;*line;line++){
        if(*line == ' ') {
            *line = '\0';
            break;
        }
    }
}

void toLower(char *line){
    while(*line){
        *line = tolower(*line);
        line++;
    }
}



void readTXT(void){
    FILE* fp = fopen("ordliste.txt", "r");
    char line[255];
    int i = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        strcpy(line, removeEOA(line));
        removeSpaces(line);
        toLower(line);
        strcpy(wordList[i], line);
        i++;
    }

    fclose(fp);

}

void writeTXT(){
    FILE* fp = fopen("ordlisten.txt", "w");
    int i = 0;
    for(int i = 0; i < 622115; i++){
        fprintf(fp, wordList[i]);
        fprintf(fp, "\n");
    } 

    fclose(fp);
}

void writeLineTXT(char filename[], char line[], int pos){
    FILE* fp = fopen(filename, "a");
    
    fprintf(fp, line);
    fprintf(fp, "\n");

    fclose(fp);
}

void makeLength(char line[]){
    int i = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0, i9 = 0;
    int newLength = lengthCheck(line);
    switch(newLength){
        case 1:
            writeLineTXT("1word.txt", line, i1++);
            break;
        case 2:
            writeLineTXT("2word.txt", line, i2++);
            break;
        case 3:
            writeLineTXT("3word.txt", line, i3++);
            break;
        case 4:
            writeLineTXT("4word.txt", line, i4++);
            break;
        case 5:
            writeLineTXT("5word.txt", line, i5++);
            break;
        case 6:
            writeLineTXT("6word.txt", line, i6++);
            break;
        case 7:
            writeLineTXT("7word.txt", line, i7++);
            break;
        case 8:
            writeLineTXT("8word.txt", line, i8++);
            break;
        case 9:
            writeLineTXT("9word.txt", line, i9++);
            break;
        default:
            writeLineTXT("word.txt", line, i++);
            break;
    }
}

int main(void){
    /*
    char linje[] = "ÆÆÆØØØÅÅÅ";
    removeEOA(linje);
    printf("ord: %s\n", linje);
    */
   
    readTXT();
    //writeTXT();
    //printf("antall: %d\n", counter);
    for(int i = 0; i < 622115; i++){
        makeLength(wordList[i]);
    }


}