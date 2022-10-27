#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int total = 0;
int amount = 0;
int main(int argc, char **argv) {
    FILE *filePointer = fopen("C:\\Users\\alexa\\CLionProjects\\Coursework1\\grades.txt", "r");

    char line[128];
    while(fgets(line, 128, filePointer) != NULL){

    }
}

int split(char line[]){
    int index = 0;
    char studentid[7];
    int validID = 1;
    do{ //procures the student ID and validates that it is the right length and in the correct range
        if (index < 8) {
            studentid[index] = line[index];
            index++;
        }else{
            validID = 0;
        }
    }while(line[index] != ' ');
    if(validID == 1){
        int intID = atoi(studentid);
        if(intID >= 2022000 && intID <= 2022099){

        }else{
            validID = 0;
        }
    }
    if(validID == 1){
        int numIndex = 0;
        char num[64];
        index++;
        do {
            if (line[index] == ' ') {
                total = total + atoi(num);
                memset(num, 0, 64);
                numIndex = 0;
            } else {
                num[numIndex] = line[index];
            }
        }while(index < 128);
    }

}