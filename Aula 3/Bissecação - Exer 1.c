#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float func(float y){
    return y - y*log(y);
}

float descobrirRaiz(float a, float b, float e, int itMax){
    if(a == 0){
        return a;
    }

    if(b == 0){
        return b;
    }

    float xk;
    int it = 1;

    while(it <= itMax){
        xk = (a + b) / 2;

        if( (fabs(b - a) / fmax(1, abs(b))) < e ){ // Aproximou de e.
            break;
        }

        if( (func(a) * func(xk)) < 0){ // Comparou f(a) * f(xk) < 0.
            b = xk;
        }else{
            a = xk;
        }

        it++;
    }
    
    xk = (a + b) / 2;
    return xk;
}

int main(){
    float v = descobrirRaiz(2, 4, 000.1, 4);

    printf("%f", v);

}
