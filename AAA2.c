#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

int i, vetor[TAM], aux, contador, passos;
int* pointer = vetor;
int vB[TAM], vS[TAM], vI[TAM];


typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

/* Função que cria uma árvore */
Tree* createTree()
{
  
  return NULL;
}

int treeIsEmpty(Tree* t)
{
  return t == NULL;
}

// Função que mostra a informação da árvore
void showTree(Tree* t)
{
  if(!treeIsEmpty(t)) 
  {
    printf("%d ", t->num); 
    showTree(t->sae); 
    showTree(t->sad); 
  }
  
}

// Função que insere um dado na árvore
void insertTree(Tree** t, int num)
{
  
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); 
    (*t)->sae = NULL; 
    (*t)->sad = NULL; 
    (*t)->num = num; 
  } else {
    if(num < (*t)->num) 
    {
      
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num) 
    {
      
      insertTree(&(*t)->sad, num);
    }
  }
}

// COPIAR ARRAY
void copyArr(int copy[], int orig[])
{
    int count;

    for (count = 0; count < TAM; count++)
        copy[count] = orig[count];
}

// FUNÇÕES DE ORDENAÇÃO ===================================================
// BUBBLE SORT ------------------------------------------------------------
int bubblesort (int *v)
{   
    passos = 0;
    copyArr(vB, v);
	int troca=1;
	int i=0;
	int aux;
	while (troca)
	{
		troca = 0;
		while (i < TAM - 1)
		{
			if (vB[i] > vB[i+1])
			{
				aux = vB[i];
				vB[i] = vB[i+1];
				vB[i+1] = aux;
				troca = 1;
			}
			i++;
            passos += 1;
		}
		i = 0;
	}
return passos;
}
// ------------------------------------------------------------------------

// SELECTION SORT ---------------------------------------------------------
int selectionsort(int* v)
{
    passos = 0;

    copyArr(vS, v);

    int i, j, aux, minimo, pos_minimo;
    for (i = 0; i < TAM - 1; i++)
    {
        minimo = vS[i];
        pos_minimo = i;
        for (j = i + 1; j < TAM; j++) // Passo 1 
        {
            if (minimo > vS[j])
            {
                minimo = vS[j];
                pos_minimo = j;
                passos += 1;
            }
        }
        if (pos_minimo != i)  // Passo 2
        {
            aux = vS[pos_minimo];
            vS[pos_minimo] = vS[i];
            vS[i] = aux;
            passos += 1;
        }
    }
    return passos;
}
// ------------------------------------------------------------------------
// INSERTION SORT ---------------------------------------------------------
int insertion(int* v)
{
    passos = 0;

    copyArr(vI, v);

    int i, j, aux;
    for (i = 0; i < TAM - 1; i++)
    {
        j = i + 1;
        while (vI[j - 1] > vI[j] && j >= 0)
        {
            aux = vI[j - 1];
            vI[j - 1] = vI[j];
            vI[j] = aux;
            j--;
            passos += 1;
        }
    }

    return passos;

}
// ------------------------------------------------------------------------
// ========================================================================


int main()
{
    srand(time(NULL)); 
    
    for (i = 0; i < TAM; i++) {
        vetor[i] = rand() % 1001;
    }

    //Print vetor original
    printf("\nGerando 100 numeros aleatorios de 1 a 1000:\n");
    for (i = 0; i < TAM; i++) {
        printf("%4d ", vetor[i]);
    }

  
  // Realizar Bubble no vetor
    printf("\n\nResultado do bubblesort\n");
    printf("Qtd de passos bubblesort: %2d\n", bubblesort(pointer));
    for (i = 0; i < TAM; i++) {
        printf("%4d ", vB[i]);
    }

    // Realizar INSERTION no vetor
    printf("\n\nResultado do insertion\n");
    printf("Qtd de passos insertion: %2d\n", insertion(pointer));
    for (i = 0; i < TAM; i++) {
        printf("%4d ", vI[i]);
    }

    // Realizar Selection no vetor
    printf("\n\nResultado do selectionsort\n");
    printf("Qtd de passos selectionsort: %2d\n", selectionsort(pointer));
    for (i = 0; i < TAM; i++) {
        printf("%4d ", vS[i]);
    }

    Tree* t = createTree();
    printf("\n\n Arvore em pre-ordem:\n\n");

    for (i = 0; i < TAM; i++) {
        insertTree(&t, vetor[i]);
    }
    
    showTree(t); 
  
    free(t); 
  
    return 0;
}