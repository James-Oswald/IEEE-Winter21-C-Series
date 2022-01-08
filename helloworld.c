
#include<stdio.h>
#include<string.h>

enum Disorder{
    MAJORDEPRESSSIVE, MINORDEPRESSIVE, PTSD, SEASONALAFFECTIVE
};

struct Goth
{
    char name[20];
    int age;
    enum Disorder disorder;
};

int main(){
    FILE* myfile = fopen("Dawn.Goth", "rb");
    struct Goth g;
    fread((void*)&g, sizeof(struct Goth), 1, myfile);
    fclose(myfile);

    printf("I am goth my is %s. I am %d years sad.\n", g.name, g.age);
    switch (g.disorder)
    {
        case MAJORDEPRESSSIVE:
            printf("I have MAJORDEPRESSSIVE disorder");
            break;
        default:
            printf("I have some other sad thing disorder");
    }
    return 0;
}