#include <stdio.h>

// het defineren van de hoeveelheid rijen en kolommen van de orginele en de geprinte foto
#define nrOfImageRows 512
#define nrOfImageColumns 512
#define nrOfImageChars 16
#define nrOfImageLevels 256

#define nrOfScreenRows 64
#define nrOfScreenRows2 50
#define nrOfScreenRows3 0
#define nrOfScreenColumns 64
#define nrOfScreenColumns2 48
#define nrOfScreenColumns3 0
#define nrOfScreenLevels 16

int main () {
    // de correcte integers voor de resolutie maken
    int a = nrOfScreenColumns;
    int b = nrOfScreenRows;
    int c = nrOfScreenColumns2 - 20;
    int d = nrOfScreenRows2 - 20;
    int e = nrOfScreenRows - 1;

    int stepsize = 0;
    int rowNr = 0;
    int columnNr = 0;
    int brightness = 1;
    int brightnessDivider = 1;

    int image [nrOfImageRows][nrOfImageColumns];
    char screen [nrOfScreenRows][nrOfScreenColumns];

   // het lena.txt bestand lezen
    FILE *file;
    char charactersOnBrightness [nrOfScreenLevels];

    file = fopen ("lena.txt", "r");

    for (int pixelCounter = 0; pixelCounter < nrOfImageRows * nrOfImageColumns; pixelCounter++) {
        fscanf (file, "%d %d %d\n", &rowNr, &columnNr, &brightness);
        image [rowNr-1][columnNr-1] = brightness;
    
    }
    fclose (file);

    // de character op grijswaarde sorteren van donker naar licht 
    charactersOnBrightness[0] = ' '; 
    charactersOnBrightness[1] = '.'; 
    charactersOnBrightness[2] = '^'; 
    charactersOnBrightness[3] = ';'; 
    charactersOnBrightness[4] = 'i'; 
    charactersOnBrightness[5] = '+'; 
    charactersOnBrightness[6] = '1'; 
    charactersOnBrightness[7] = 't'; 
    charactersOnBrightness[8] = 'x'; 
    charactersOnBrightness[9] = 'X'; 
    charactersOnBrightness[10] = 'Q'; 
    charactersOnBrightness[11] = 'w'; 
    charactersOnBrightness[12] = 'b'; 
    charactersOnBrightness[13] = '&'; 
    charactersOnBrightness[14] = 'B'; 
    charactersOnBrightness[15] = '@'; 

    stepsize = nrOfImageRows / nrOfScreenRows;
    brightnessDivider = nrOfImageLevels / nrOfScreenLevels;

    for (int rowIndex = 0; rowIndex < nrOfScreenRows; rowIndex++) {
        for (int columnIndex = 0; columnIndex < nrOfScreenColumns; columnIndex++) {
            screen [rowIndex][columnIndex] = charactersOnBrightness [
                image [rowIndex * stepsize][columnIndex * stepsize] / brightnessDivider
            ];
        }
    }

// het printen van de foto's in ascii characters
printf("De orginele foto in ASCII characters:\n");
    for (int rowIndex = 0; rowIndex < nrOfScreenRows; rowIndex++){
        for (int columnIndex = 0; columnIndex < nrOfScreenColumns; columnIndex++) {
           printf ("%c ", screen [rowIndex][columnIndex]);
        }
        printf ("\n");
    }

printf ("\n\n\nDe verkleinde foto in ASCII characters:\n");
 for (int rowIndex = 20; rowIndex < nrOfScreenRows2; rowIndex++){
        for (int columnIndex = 20; columnIndex < nrOfScreenColumns2; columnIndex++) {
           printf ("%c ", screen [rowIndex][columnIndex]);
        }
        printf ("\n");
    }

printf ("\n\n\nDe originele foto gespiegeld in ASCII characters:\n");
 for (int rowIndex = 0; rowIndex < nrOfScreenRows; rowIndex++){
        for (int columnIndex = 64; columnIndex > nrOfScreenColumns3; columnIndex--) {
           printf ("%c ", screen [rowIndex][columnIndex]);
        }
        printf ("\n");
    }
    
 // voor het extra punt de foto draaien, en de resolutie van elke foto geven   
 printf ("\n\n\nDe orginele foto naar rechts gedraait in ASCII characters:\n");
 for (int columnIndex = 64; columnIndex > nrOfScreenColumns3; columnIndex--){
        for (int rowIndex = 63; rowIndex > nrOfScreenRows3; rowIndex--) {
           printf ("%c ", screen [rowIndex][columnIndex]);
        }
        printf ("\n");
    }

    printf("\nDe resolutie van de eerste foto is: %i x %i\n", a,b);
    printf("De resolutie van de tweede foto is: %i x %i\n", c,d);
    printf("De resolutie van de derde foto is: %i x %i (gespiegeld, dus de resolutie verandert niet)\n", a,b);
    printf("De resolutie van de vierde foto is: %i x %i\n", e,a);

return 0;
}