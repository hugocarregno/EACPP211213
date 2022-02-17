#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const int MAX=100;


/*
*La función no acepta argumentos y debe devolver un valor real ingresado por teclado que sea mayor o igual a 0 y menor o igual que 9.
Si el numero ingresado no está en el rango valido se debe volver a solicitar tantas veces como sea necesario.
Además, el número retornado por la función debe estar redondeado al entero más cercano.
*/

float Cargar_Valor();

/*
Dicha función recibe como parámetros un vector (donde MAX es una constante global de valor 100 previamente definida) y tres valores
enteros N, a y b. La función debe calcular y cargar en el vector una serie de N números reales igualmente distanciados arrancando en el
valor 'a' y terminando en 'b'. Por ejemplo si N=5, a=3 y b=8 entonces los valores a cargar en el vector son 3, 4.25, 5.5, 6.75 y 8.
*/

void calcular_vector(double vector[MAX], int N, int a,int b);

/*
Dicha función recibe como argumentos un vector y un entero N que indica la cantidad de números del vector. La función debe calcular el
promedio de los valores positivos del vector y retornarlo.
*/

float calcular_promedio_de_positivos(double vector[MAX], int N);

/*
Dicha función recibe como argumentos dos vectores, un entero N y un valor real X. El vector "vector_entrada" tiene N números de entrada
a la función. El vector "vector_salida" es el que la función debe completar con los números del "vector_entrada" pero en orden creciente de
distancia al numero X, donde la distancia entre A y X se mide como abs(A-X). Si hay dos valores que tienen la misma distancia se deben
poner en el orden inverso al que se encuentran en el vector de entrada.
*/

void transformar_vector(double vector_entrada[MAX], double vector_salida[MAX], int N, double X);



int main(){
double vector[MAX];
int N;
float a, b;
cout<<"-- Ejercicio 1 --"<<endl;
cout<<"Ingrese N: ";
cin>>N;

a=Cargar_Valor();
b=Cargar_Valor();

while(b<a){
    cout<<"b es menor que a, reingrese: "<<endl;
    a=Cargar_Valor();
    b=Cargar_Valor();

}

cout<<"-- Ejercicio 2 --"<<endl;
calcular_vector(vector,N, a, b);



cout<<"El promedio es= " << calcular_promedio_de_positivos(vector,N) <<endl;

cout<<"-- Ejercicio 3 --"<<endl;
double X = Cargar_Valor();
cout<<"El vector resultante es = ";
transformar_vector(vector, vector, N, X);





system("pause");
return 0;
}

float Cargar_Valor(){

float numero;
cout<<"Ingrese un valor:";
cin>>numero;

while(numero<0 || numero>9 ){
        cout<<"reingrese: ";
        cin>>numero;
}
return  round(numero);
}

void calcular_vector(double vector[MAX], int N, int a, int b){
double separaciones=double((b-a))/double(N-1);
//cout<<separaciones<<endl;
vector[0]=a;
vector[N-1]=b;

for(int i=0; i<N-2; i++){
    vector[i+1]=vector[i]+separaciones;

}

for(int i=0; i<N; i++){
    cout<<vector[i]<<" ";
}

}

float calcular_promedio_de_positivos(double vector[MAX], int N){
    double suma=0;
    double contador=0;
    double promedio=0;
    for(int i=0; i<N; i++){
        if(vector[i]>0){
            suma+=vector[i];
            contador++;
        }

    }
    promedio=suma/contador;
    return promedio;
}
void transformar_vector(double vector_entrada[MAX], double vector_salida[MAX], int N, double X){

double aux;

//uso de metodo burbuja
for (int i=0; i<N-1; i++)
{
   for (int j=i+1; j<N; j++)
  {
      if(abs(vector_salida[i]-X) >= abs(vector_salida[j]-X)){
        aux = vector_entrada[i];
        vector_salida[i] = vector_salida[j];
        vector_salida[j] = aux;
      }
  }
  cout<<vector_salida[i]<<",";
}

cout<<endl;

}



