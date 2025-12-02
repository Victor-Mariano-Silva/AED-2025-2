#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define INITIAL_SIZE    201 
#define controlRegion   0
#define dataRegion      200

#define OPT             (int *)pBuffer + controlRegion
#define TOTALSIZE       (int *)pBuffer + 1
#define USEDSIZE        (int *)pBuffer + 2
#define MEMAMOUNT       (int *)pBuffer + 3
#define TOTALPEOPLE     (int *)pBuffer + 4
#define TEMPNAME        (char *)pBuffer + 24
#define TEMPAGE         (char *)pBuffer + 82
#define TEMPMAIL        (char *)pBuffer + 132
#define GENERICPOINTER  (char *)pBuffer + dataRegion;
#define ENDDATA         (char *)pBuffer + *usedSize;

char* search(void** pBuffer, char* tempName, int* usedSize, char* p, char* end, int* totalPeople);

int main( void ) {
    void *pBuffer       = malloc(INITIAL_SIZE);
    
    int *opt            = OPT;
    int *totalSize      = TOTALSIZE;
    int *usedSize       = USEDSIZE;
    int *memAmount      = MEMAMOUNT;
    int *totalPeople    = TOTALPEOPLE;

    char *tempName      = TEMPNAME;
    char *tempAge       = TEMPAGE;
    char *tempMail      = TEMPMAIL;

    char *p             = GENERICPOINTER;   
    char *p2            = GENERICPOINTER; 
    char *end           = ENDDATA;          
    *totalSize          = INITIAL_SIZE;
    *usedSize           = dataRegion;
    *totalPeople        = 0;

    while (true) {
        printf("================= Agenda =================\n");
        printf("1. Adicionar pessoa\n");
        printf("2. Remover pessoa\n");
        printf("3. Buscar pessoa\n");
        printf("4. Listar todos\n");
        printf("5. Sair\n");
        printf("==========================================\n");
        printf("Digite sua opcao: ");
        scanf("%d", opt);

        switch (*opt) {
        case 1:

            getchar();                      
            printf("Email: ");
            scanf("%[^\n]s", tempMail);     
            
            getchar();                      
            printf("Nome: ");
            scanf("%[^\n]s", tempName);

            getchar();
            printf("Idade: ");
            scanf("%s", tempAge);          

            if(search(&pBuffer, tempMail, usedSize, p, end, totalPeople) != NULL) {
                printf("Essa pessoa ja esta na agenda!\n");

            } else {
                *memAmount = 0;
                *memAmount = strlen(tempName) + 1 + strlen(tempAge) + 1 + strlen(tempMail) + 1;

                if(!( (*usedSize + *memAmount) <= *totalSize )) {   
                    *totalSize += (*usedSize + *memAmount - *totalSize);
                    pBuffer     = realloc(pBuffer, *totalSize);
                    
                    opt         = OPT;
                    totalSize   = TOTALSIZE;
                    usedSize    = USEDSIZE;
                    memAmount   = MEMAMOUNT;
                    totalPeople = TOTALPEOPLE;

                    tempName    = TEMPNAME;
                    tempAge     = TEMPAGE;
                    tempMail    = TEMPMAIL;

                    p           = GENERICPOINTER;
                    p2          = GENERICPOINTER;
                    end         = ENDDATA;
                }

                char *next = (char *)pBuffer + *usedSize;
                
                memcpy(next, tempMail, strlen(tempMail) + 1);
                next += strlen(tempMail) + 1;

                memcpy(next, tempName, strlen(tempName) + 1);   
                next += strlen(tempName) + 1;                  

                memcpy(next, tempAge, strlen(tempAge) + 1);
                next += strlen(tempAge) + 1;
                
                *usedSize += *memAmount;
                *totalPeople += 1;
            }
            break;
        
        case 2:
            if(*totalPeople == 0) {
                printf("Agenda vazia!\n");
            } else {
                getchar();
                printf("Quem voce deseja remover? (digite email) ");
                scanf("%[^\n]s", tempMail);
                
                p   = search(&pBuffer, tempMail, usedSize, p, end, totalPeople);
                p2  = p;

                if( p2 != NULL ) {

                    *memAmount = 0;
                    *memAmount += strlen(p2) + 1;       
                    p2 += strlen(p2) + 1;
                    *memAmount += strlen(p2) + 1;       
                    p2 += strlen(p2) + 1;
                    *memAmount += strlen(p2) + 1;      
                    p2 += strlen(p2) + 1;

                    end = (char *)pBuffer + *usedSize;  

                    memmove(p, p2, (end - p2));         

                    pBuffer = realloc(pBuffer, (*totalSize - *memAmount));

                    opt         = OPT;
                    totalSize   = TOTALSIZE;
                    usedSize    = USEDSIZE;
                    memAmount   = MEMAMOUNT;
                    totalPeople = TOTALPEOPLE;

                    tempName    = TEMPNAME;
                    tempAge     = TEMPAGE;
                    tempMail    = TEMPMAIL;

                    p           = GENERICPOINTER;
                    p2          = GENERICPOINTER;
                    end         = ENDDATA;

                    *usedSize       -= *memAmount;
                    *totalSize      -= *memAmount;
                    *totalPeople    -= 1;

                } else {
                    printf("Essa pessoa nao esta na agenda!\n");
                    break;
                }
            }
            break;    

        case 3:
            if(*totalPeople == 0) {
                printf("Agenda vazia!\n");
            } else {
                getchar();
                printf("Quem voce deseja buscar? (digite email): ");
                scanf("%[^\n]s", tempMail);

                p = search(&pBuffer, tempMail, usedSize, p, end, totalPeople);
                if(p != NULL) {
                    printf("--------------------------\n");
                    printf("Email: %s\n", p);
                    p += strlen(p) + 1;

                    printf("Nome: %s\n", p);
                    p += strlen(p) + 1;

                    printf("Idade: %s\n", p);
                    p += strlen(p) + 1;
                    printf("--------------------------\n");
                } else {
                    printf("Pessoa nao encontrada");
                }
            }

            break;

        case 4:
            p   = GENERICPOINTER;
            end = ENDDATA;

            if(*totalPeople == 0) {             
                printf("Agenda vazia!\n");
                break;
            } else {
                while( p < end ) {              
                    printf("--------------------------\n");
                    printf("Email: %s\n", p);   
                    p += strlen(p) + 1;        

                    printf("Nome: %s\n", p);
                    p += strlen(p) + 1;

                    printf("Idade: %s\n", p);
                    p += strlen(p) + 1;
                    printf("--------------------------\n");
                }
            }
            break;

        case 5:
            free(pBuffer);  
            exit(1);        
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    
}

char* search(void** pBuffer, char* tempMail, int* usedSize, char* p, char* end, int* totalPeople) {
    p   = (char *)(*pBuffer) + dataRegion;
    end = (char *)(*pBuffer) + *usedSize;

    if(*totalPeople == 0) {
        return NULL;
    } else {
        while( p < end ) {
            if(strcmp(tempMail, p) == 0) {
                return p;
            } else {
                p += strlen(p) + 1;
                p += strlen(p) + 1;
                p += strlen(p) + 1; 
            }
        }
    }
    return NULL;
}