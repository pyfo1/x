#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
int digits, i;
long number, number_saved;
string company;
bool status;

// check length if valid; else(valid length): complete rest of code
digits = 1; 
number = get_long("Number:");
if (number < 1000000000000 || number > 9999999999999999 || (number < 100000000000000 && number >= 10000000000000)) {  
status = false;
printf("INVALID\n");
}   
else {   
number_saved = number; 

// digits zählen
do{
number = number / 10;
digits += 1;
}while(number >= 10);
    
// die Nummer falsch herum in eine Liste übertragen
int list[digits], list_reverse[digits];
number = number_saved;
for(i = 0; i <= digits-1; i++) {
    list[i] = number % 10;
    number = number / 10;
}

// die Liste für später umdrehen
for (i = digits-1; i >= 0; i--) {
    list_reverse[digits-i-1] = list[i];
}

// jeden zweiten Eintrag beginnend mit dem 2. Eintrag verdoppeln
for(i = 1; i <= digits-1; i = i+2)  {
    list[i] = list[i] * 2;
} 

// Einträge, die durch die Verdoppelung nun zweistellig sind, werden in ihre digits aufgeteilt (z.B. 12 in 1 und 2) und das ergebnis aufsummiert
int sum = 0;
for(i = 1; i <= digits-1; i = i+2)  {
    if (list[i] >= 10) {
     sum += list[i] % 10;
     sum += list[i] / 10;
    }
    else {
     sum += list[i];
    }
}
// alle Einträge, die nicht verdoppelt wurden, zur Gesamtsumme hinzufügen
for(i = 0; i <= digits-1; i = i+2)  {
    sum += list[i];
}

// checken, ob die Summe auf 0 endet, wenn ja ist die Kartennummer "valid"
if (sum%10 == 0) {
    status = true;
}  
else {
    status = false;
}

// Check, zu welcher Firma die Karte gehört
if (status == true) {
    if (list_reverse[0] == 3 && (list_reverse[1] == 4 || list_reverse[1] == 7)) {
        company = "AMEX";
    }
    else if (list_reverse[0] == 5 && (list_reverse[1] == 1 || list_reverse[1] == 2 || list_reverse[1] == 3 || list_reverse[1] == 4 || list_reverse[1] == 5)) {
        company = "MASTERCARD";
    }
    else if (list_reverse[0] == 4) {
        company = "VISA";
    }
    else {
        company ="INVALID";
    }
}  
    
// Ergebnis Printen
if (status == true) {
    printf("%s\n", company);
}
else {
    printf("INVALID\n");
}
}    
}

