#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int split(char line[128]);

int validateID(char line[128]);

int main(int argc, char **argv) {
    remove("averages.txt");//tries to remove existing averages text file
    if(argc == 0){//checks for command line input
        printf("No input file name given. Exiting.\n");
        exit(0);
    }
    FILE *filePointer;
    if(!(filePointer = fopen(argv[1], "r"))){//checks if file exists
        printf("Input file does not exist. Exiting.\n");
        exit(0);
    }
    FILE *outputPointer = fopen("averages.txt", "w");
    printf("Input file. Opening.\n");
    printf("Output file. Opening.\n");
    char line[128];
    printf("Checking data.\n");
    printf("Computing averages.\n");
    while(fgets(line, 128, filePointer) != NULL){//iterates through all lines in the file
        int studentID = validateID(line);
        int score = split(line);
        fprintf(outputPointer, " %d %d\n", studentID, score);//writes data to file
        printf("Correcting student %d grade %d\n",studentID,score);

    }
    fclose(filePointer);
    fclose(outputPointer);
    printf("Input file. Closing.\n");
    printf("Output file. Closing.\n");

}

int validateID(char line[128]) {
    int index = 1;
    char studentid[7];
    int validID = 1;
    do{ //procures the student ID and validates that it is the right length
        if (index < 9) {
            studentid[index-1] = line[index];
            index++;
        }else{
            validID = 0;
        }
    }while(line[index] != ' ');
    if(validID == 1) {
        return atoi(studentid);
    }else{
        return 0;
    }
}


int split(char line[128]) {
    int total = 0;
    int amount = 0;
    int index = 1;
    char studentid[7];
    int validID = 1;
    do{ 
        if (index < 9) {
            studentid[index-1] = line[index];
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
    }//repeats the validation process to get to the correct point in the line, additionally checking that its in the correct range
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
        }while(line[index] != '\n');
        int score = atoi(num);//this adds the final value to total as it wont do that within the loop
        if(score < 20){//rounds outliers to stop them affecting the average
            score = 20;
        }else if(score > 90){
            score = 90;
        }
        total = total + score;
        memset(num, 0, 64);
        numIndex = 0;
        amount++;
        float average = (float)total/(float)amount;//calculates the average score in decimal form
        int finalAvg = (int) average;
        if((average - finalAvg) >=0.5){//rounds to the nearest whole number
            finalAvg++;
        }
        return finalAvg;
    }else{
        printf("Found an invalid student id: %s. Exiting.\n",studentid);
        exit(0);
        remove("averages.txt");
    }
}

