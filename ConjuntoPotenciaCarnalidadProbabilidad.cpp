/*
Universidad Autonoma de Aguascalientes
Ingeniería en Computación Inteligente
Estadística Descriptiva y Probabilidad
Ivan Israel Hurtado Lozano
Netzahualcoyotl Castañeda Leyva
*/

#include<iostream>
#include<string>
#include<math.h>
const std::string Red("\033[1;91m");
const std::string Reset("\033[0m");
const std::string Green("\033[1;32m");
const std::string Blue("\033[1;34m");
const std::string Yellow("\033[0;33m");

int indice = 0,cant;
float probind;

void conversor(int,int[],std::string[]);
int cardinalidad(int[]);

int main(){

    int potencia;
    std::cout<<"Ingresa el numero de elementos que quieres agregar ---> ";
    std::cin>>cant;
    std::string palabra[cant];
    int arreglochars[cant];
    probind = 1.0/cant;

    for(int i=0;i<cant;i++){
        std::cout<<"Ingresa el valor del indice "<<i<<" ---> ";
        std::cin>>palabra[i];
        arreglochars[i] = 0;
    }

    potencia = pow(2,cant);

    std::cout<<Yellow<<"\t\t\tEvento A"<<std::endl<<std::endl<<Reset;

    for(int i=0;i<potencia;i++){
        std::cout<<Blue<<" Subconjunto "<<i+1<<Reset<<":"<<std::endl<<"  ";
        indice = 0;
        conversor(i,arreglochars,palabra);
        
    }

    system("pause");
    return 0;
}

void conversor(int n, int arreglo[],std::string arregloverif[]){
    
    int aux;
    aux = n%2;
    arreglo[indice] = aux;
    
    indice++;
    
    n/=2;
    if(n!=0){ 
        conversor(n,arreglo,arregloverif);
    }
    else{
        int cardin = cardinalidad(arreglo);
        float probab = cardin * probind;

        std::cout<<std::endl<<"{";
        for(int i=0;i<cant;i++){
           ( arreglo[i] == 1) ? std::cout<<arregloverif[i]<<" " : std::cout<<"    ";  
        }
        std::cout<<"}"<<Green<<"\tCardinalidad: "<<Reset<<cardin<<Red<<"\t\tProbabilidad: "<<Reset<<probab;
        (cardin==0) ? std::cout<<"\t\tConjunto vacio { }"<<std::endl<<std::endl : std::cout<<std::endl<<std::endl;
    }
    
}

int cardinalidad(int arreglo[]){
    int cant=0;
    for(int i=0;i<8;i++){
        (arreglo[i] == 1) ? cant++ : cant=cant;
    }
    return cant;
}
