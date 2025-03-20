#include "interm.h"

// Define the global variables
Quadruplet quad[MAX_QUAD];
int qc = 0;
listePointure *tabLP = NULL;
tabIDF *tabt = NULL;
int l = 0;

void quadr(char opr[], char op1[], char op2[], char res[]) {
    if (qc < MAX_QUAD) {
        strcpy(quad[qc].oper, opr);
        strcpy(quad[qc].op1, op1);
        strcpy(quad[qc].op2, op2);
        strcpy(quad[qc].res, res);
        qc++;
    } else {
        printf("Error: Maximum number of quadruplets exceeded\n");
    }
}

void afficher_qdr() { 
    printf("\nLes Quadruplets\n"); 
 
    int i; 
 
    for (i = 0; i < qc; i++) { 
        if (strcmp(quad[i].oper, "") == 0) { 
            strcpy(quad[i].oper, "="); 
        } 
        printf("\n%d - ( %s , %s , %s , %s )", i, quad[i].oper, quad[i].op1, quad[i].op2, quad[i].res);  
        printf("\n--------------------------------------------------------\n"); 
    } 
}


void ajour_quad(int num_quad, int colon_quad, char val []) {
    if (colon_quad == 0) strcpy(quad[num_quad].oper, val);
    else if (colon_quad == 1) strcpy(quad[num_quad].op1, val);
    else if (colon_quad == 2) strcpy(quad[num_quad].op2, val);
    else if (colon_quad == 3) strcpy(quad[num_quad].res, val);
}

void GetValue(char entite[25], char value[25], int ts) {
    listePointure *courantLP = tabLP;
    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL) {
        tabIDF *courant = courantLP->tab1;
        while (courant != NULL) {
            if (strcmp(entite, courant->name) == 0) {
                sprintf(value, "%s", courant->val);
                return;
            }
            courant = courant->suiv;
        }
    }

    // Entité non trouvée
    strcpy(value, "Entité non trouvée");
}

void SaveValue(char entite[25], char Value[25], int ts) {
    listePointure *courantLP = tabLP;
    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL) {
        tabIDF *courant = courantLP->tab1;
        while (courant != NULL) {
            if (strcmp(entite, courant->name) == 0) {
                strcpy(courant->val, Value);

                if (strcmp(courant->type, "LOGICAL") == 0) {
                    if (strcmp(courant->val, "1") == 0) {
                        strcpy(courant->val, "TRUE");
                    } else {
                        strcpy(courant->val, "FALSE");
                    }
                }
                return;
            }
            courant = courant->suiv;
        }
    }

    // Entité non trouvée
}

int findIndex(char entite[], int ts) {
    listePointure *courantLP = tabLP;
    while (courantLP != NULL && courantLP->ts != ts) {
        courantLP = courantLP->suiv;
    }

    if (courantLP != NULL) {
        tabIDF *courant = courantLP->tab1;
        int i = 0;
        while (courant != NULL) {
            if (strcmp(entite, courant->name) == 0) {
                return i;
            }
            i++;
            courant = courant->suiv;
        }
    }

    // Entité non trouvée
    return -1;
}

int search_temp(int l, int ts) {
    int i = l;
    while (strcmp(quad[i].op1, "TEMP") == 0 || strcmp(quad[i].op2, "TEMP") == 0) {
        i--;
    }

    // Assuming TEMP is related to the symbol table, update the value
    if (strcmp(quad[i].op1, "TEMP") == 0) {
        GetValue(quad[i].op1, quad[i].op1, ts);
    } else if (strcmp(quad[i].op2, "TEMP") == 0) {
        GetValue(quad[i].op2, quad[i].op2, ts);
    }

    return i - 1;
}

void do_operation(char x[], char y[], char z[], char op[], int ts) {
    int b = 1;
    if (strcmp(x, "TEMP") == 0) {
        strcpy(x, tabt[l - 1].val);

        if (strcmp(y, "TEMP") == 0) {
            strcpy(x, tabt[search_temp(l - 2, ts)].val);
            strcpy(y, tabt[search_temp(l - 1, ts)].val);
        }
    }

    if (strcmp(y, "TEMP") == 0) {
        strcpy(y, tabt[l - 1].val);
    }

    char te1[25], te2[25];
    strcpy(te1, x);
    strcpy(te2, y);

    if (findIndex(x, ts) != -1) {
        GetValue(x, x, ts);
    }

    if (findIndex(y, ts) != -1) {
        GetValue(y, y, ts);
    }

    if (strcmp(op, "+") == 0) {
        sprintf(tabt[l].val, "%f", atof(y) + atof(x));
    } else if (strcmp(op, "-") == 0) {
        sprintf(tabt[l].val, "%f", atof(x) - atof(y));
    } else if (strcmp(op, "*") == 0) {
        sprintf(tabt[l].val, "%f", atof(y) * atof(x));
    } else if (strcmp(op, "/") == 0) {
        if (atof(y) == 0) {
            printf("error");
            return;
        }
        sprintf(tabt[l].val, "%f", atof(x) / atof(y));
    }

    strcpy(x, te1);
    strcpy(y, te2);
    l++;
}

void do_comparison(char x[], char y[], char z[], char op[], int ts) {
    int b = 1;

    if (strcmp(x, "TEMP") == 0 || strcmp(x, "TEMP!") == 0 || strcmp(x, "TEMP2") == 0) {
        strcpy(x, tabt[l - 1].val);
    }

    if (strcmp(y, "TEMP") == 0 || strcmp(y, "TEMP!") == 0 || strcmp(y, "TEMP2") == 0) {
        strcpy(y, tabt[l - 1].val);
    }

    char te1[25], te2[25];
    strcpy(te1, x);
    strcpy(te2, y);

    if (findIndex(x, ts) != -1) {
        GetValue(x, x, ts);
    }

    if (findIndex(y, ts) != -1) {
        GetValue(y, y, ts);
    }

    if (strcmp(op, ">") == 0) {
        if (atof(x) > atof(y)) {
            sprintf(tabt[l].val, "%f", 1.0);
        } else {
            sprintf(tabt[l].val, "%f", 0.0);
        }
    } else if (strcmp(op, ">=") == 0) {
        if (atof(x) >= atof(y)) {
            sprintf(tabt[l].val, "%f", 1.0);
        } else {
            sprintf(tabt[l].val, "%f", 0.0);
        }
    } else if (strcmp(op, "<") == 0) {
        if (atof(x) < atof(y)) {
            sprintf(tabt[l].val, "%f", 1.0);
        } else {
            sprintf(tabt[l].val, "%f", 0.0);
        }
    } else if (strcmp(op, "<=") == 0) {
        if (atof(x) <= atof(y)) {
            sprintf(tabt[l].val, "%f", 1.0);
        } else {
            sprintf(tabt[l].val, "%f", 0.0);
        }
    } else if (strcmp(op, "==") == 0) {
        if (atof(x) == atof(y)) {
            sprintf(tabt[l].val, "%f", 1.0);
        } else {
            sprintf(tabt[l].val, "%f", 0.0);
        }
    } else if (strcmp(op, "!=") == 0) {
        if (atof(x) != atof(y)) {
            sprintf(tabt[l].val, "%f", 1.0);
        } else {
            sprintf(tabt[l].val, "%f", 0.0);
        }
    }

    strcpy(x, te1);
    strcpy(y, te2);
    l++;
}
