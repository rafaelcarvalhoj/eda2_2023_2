#include <stdio.h>
#include <math.h>

float dist(int x, int y){
    return sqrt(x*x+y*y); 
}

int main(){
    int C, T;
    scanf("%d %d",&C,&T);
    int raio[C];
    for(int i = 0 ; i < C; i++) 
        scanf("%d",&raio[i]);

    int pontos = 0;
    int x, y;

    for(int i = 0 ; i < T; i++){
        scanf("%d %d", &x, &y);
        float distancia = dist(x, y);
        int j = 0;
        for( ; j < C ;j++)
            if (distancia <= (float)raio[j])
                break;

        pontos += (C-j);
    }
    printf("%d\n",pontos);
    return 0;

}
