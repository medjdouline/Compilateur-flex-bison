#ifndef INTERM_H
#define INTERM_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Structure for quadruplets
typedef struct {
    char oper[100];  // operator
    char op1[100];   // operand 1
    char op2[100];   // operand 2
    char res[100];   // result
} Quadruplet;

// Structure for identifiers
typedef struct tabIDF {
    char name[25];
    char val[25];
    char type[25];
    struct tabIDF *suiv; // Assuming a list of identifiers
} tabIDF;

// Linked list node for symbol table
typedef struct listePointure {
    tabIDF *tab1;
    struct listePointure *suiv;
    int ts;
} listePointure;

#define MAX_QUAD 1000
extern Quadruplet quad[MAX_QUAD];
extern int qc;  // quadruplet counter
extern listePointure *tabLP;
extern tabIDF *tabt;
extern int l;

// Function declarations
void quadr(char opr[], char op1[], char op2[], char res[]);
void afficher_qdr();
void ajour_quad(int num_quad, int colon_quad, char val[]);
void GetValue(char entite[25], char value[25], int ts);
void SaveValue(char entite[25], char Value[25], int ts);
int findIndex(char entite[], int ts);
int search_temp(int l, int ts);
void do_operation(char x[], char y[], char z[], char op[], int ts);
void do_comparison(char x[], char y[], char z[], char op[], int ts);

#endif
