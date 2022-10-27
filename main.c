#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split(char line[128]);

int main(int argc, char **argv) {
    FILE *filePointer = fopen("C:\\Users\\alexa\\CLionProjects\\Coursework1\\grades.txt", "r");

    char line[128];
    while(fgets(line, 128, filePointer) != NULL){
        int score = split(line);
    }
}

int split(char line[128]) {
    int total = 0;
    int amount = 0;
    int index = 0;
    char studentid[7];
    int validID = 1;
    do{ //procures the student ID and validates that it is the right length
        if (index < 8) {
            studentid[index] = line[index];
            index++;
        }else{
            validID = 0;
        }
    }while(line[index] != ' ');
    if(validID == 1){//checks that the student ID is in the correct range
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
            if (line[index] == ' ') {//splits the remainder of the line into chunks at each space and adds those numbers together
                int score = atoi(num);
                if(score < 20){//rounds outliers to stop them affecting the average
                    score = 20;
                }else if(score > 90){
                    score = 90;
                }
                total = total + score;
                memset(num, 0, 64);
                numIndex = 0;
                amount++;
            } else {
                num[numIndex] = line[index];
                numIndex++;
            }
            index++;
        }while(index < 128);
        float average = (float)total/(float)amount;//calculates the average score in decimal form
        int finalAvg = (int) average;
        if((average - finalAvg) >=0.5){//rounds to the nearest whole number
            finalAvg++;
        }
        return finalAvg;
    }
}

