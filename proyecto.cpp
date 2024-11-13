#include <iostream>
#include <cmath>
#include <algorithm> 
#include <vector> 

using namespace std;

// Funcion para calcular el Máximo Común Divisor (MCD)
int calcularMCD(int a, int b) {
    while (b != 0) {
     int temp;   	
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funcion para calcular el Mínimo Común Múltiplo (MCM)
int calcularMCM(int a, int b) {
    return (a * b) / calcularMCD(a, b);
}

// Funcion para verificar si un número es primo
bool esPrimo(int num) {
    if (num <= 1) {
        return false;
    } else {
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
    }
    return true;
}
// funcion para que el teorema de euler- fermat funcione
bool es_primo(int p) {
    if (p <= 1)
        return false; 
        
    for (int i = 2; i * i <= p; ++i) {
        if (p % i == 0)
            return false;
    }
    return true;
}

void escribir(const char* mensaje) {
    char* ptr = const_cast<char*>(mensaje);
    while (*ptr != '\0') {
        putchar(*ptr);
        ++ptr;
    }
}

void leer(int& num) {
    num = 0;
    int sign = 1;
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch == '-') {
            sign = -1;
        } else {
            num = num * 10 + ch - '0';
        }
    }
    num *= sign;
}

long long calcular_exponenciacion_modular(int a, int p) {
    long long resultado = 1;
    for (int i = 0; i < p - 1; ++i) {
        resultado = (resultado * a) % p;
    }
    return resultado;
}
// Funcion para calcular el factorial de un número
unsigned long long factorial(int m) {
    if (m == 0 || m == 1) {
        return 1;
    } else {
        return m * factorial(m - 1);
    }
}

// Funcion para calcular las permutaciones sin repeticion
unsigned long long permutacionesSinrepeticion(int m, int s) {
    return factorial(m) / factorial(m - s);
}

// Funcion para calcular las permutaciones con repeticion
unsigned long long permutacionesConrepeticion(int m, int s) {
    return pow(m,s);
}

// Funcion para calcular las combinaciones sin repeticion
unsigned long long combinacionesSinrepeticion(int m, int s) {
    return factorial(m) / (factorial(s) * factorial(m - s));
}

// Funcion para calcular las combinaciones con repeticion
unsigned long long combinacionesConrepeticion(int m, int s) {
    return factorial(m + s - 1) / (factorial(s) * factorial(m - 1));
}
//Para ordenamiento de numeros ascendente
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar los elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
//para ordenamineto de numeros descendente
void bubbleSortDesc(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Intercambiar los elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int opcionPrincipal;

    cout << "Bienvenido a La calculadora-proyecto-cosa" << endl;
    cout << "1. ordenamientos" << endl;
    cout << "2. modulos " << endl; //div ente
    cout << "3. Secuencias" << endl;
    cout << "4. T.conteo" << endl;
    cout << "Elija una categoria: ";
    cin >> opcionPrincipal;

    int num1, num2, op; 

    switch(opcionPrincipal) {
//-----------------------------------------------------------------------------------------------------------------------------------    	
            case 1: {
            int n;
            cout << "Cuantos numeros desea ordenar?: ";
            cin >> n;

            vector<int> numeros(n);

            cout << "Ingrese los numeros: ";
            for (int i = 0; i < n; ++i) {
                cin >> numeros[i];
            }

            // Ordenar los números utilizando el método de la burbuja
            bubbleSort(numeros);

            cout << "Numeros ordenados de manera Ascendente: ";
            for (int i = 0; i < n; ++i) {
                cout << numeros[i] << " ";
            }
            cout << endl; 
            
            bubbleSortDesc(numeros);

            cout << "Numeros ordenados de manera Descendente: ";
            for (int i = 0; i < n; ++i) {
                cout << numeros[i] << " ";
            }
            cout << endl;

            break;
        }
//-----------------------------------------------------------------------------------------------------------------------------------    	
        case 2: {
            cout <<""<<endl<< "Ingrese"<<endl<< "1. para MCM" <<endl<<"2. para MCD: "<<endl<<"3. para teorena euler-fermat"<<endl<<"4. numeros primos"<<endl<<"5. divisiones enteras"<<endl;
            cin >> op;        

	            if (op == 1) {
	            	 cout << "Ingrese dos numeros enteros: ";
	            cin >> num1 >> num2;            	
	                int mcm = calcularMCM(num1, num2);
	                cout << "Minimo Comun Multiplo: " << mcm << endl;
	            }
	            if (op == 2) {
	            	 cout << "Ingrese dos numeros enteros: ";
	            cin >> num1 >> num2;            	
	                int mcd = calcularMCD(num1, num2);
	                cout << "Maximo Comun Divisor: " << mcd << endl;
	            }
	            if (op==3){
	            	 cout<<"Ingrese un numero entero: "<<endl;
	            cin>>num1;
	            	cout<<"Ingrese un numero primo: "<<endl;
	            cin>>num2;
	
	            while (!es_primo(num2)) {
	               		cout<<"El numero ingresado no es primo."<<endl;
	                	cout<<"Ingrese otro numero primo: "<<endl;
	                cin>>num2;
	            }
	
	            long long resultado = calcular_exponenciacion_modular(num1, num2);
	            
	            if (resultado == 1)
	                cout<<"X elevado a la p - 1 es congruente con 1 modulo p "<<endl;
	            else
	                cout<<"X elevado a la p - 1 no es congruente con 1 modulo p "<<endl;            	
				}            
	            
				if (op==4){
					int numero;
	            cout << "Ingrese un numero: ";
	            cin >> numero;
	
	            if (esPrimo(numero)) {
	                cout << numero << " es un numero primo." << endl;
	            } else {
	                cout << numero << " no es un numero primo." << endl;
	            }
				}
				if (op==5)
				{
				 cout << "Ingrese dos numeros enteros para la division: "<<endl;
            cout << "El primero sera el dividendo"<<endl;
            cout << "El segundo sera el divisor"<<endl;
            cin >> num1 >> num2;

            // Manejar division por cero
            if (num2 != 0) {
                int cociente = num1 / num2;
                int residuo = num1 % num2;
                if (residuo == 0) {
                    cout << "La division es entera y da: " << cociente << endl;
                } else {
                    cout << "La division no es entera porque su residuo da: " << residuo << endl;
                }
            } else {
                cout << "Error: Division por cero, todavia no sabemos cuanto da eso :c" << endl;
            }
            break;
        }	
				}
			
//-----------------------------------------------------------------------------------------------------------------------------------        
    int opcionsecundaria;
case 3: {
	  cout<< "1. Sucecion aritmetica "<<endl<<"2. sucecion geometrica"<<endl<<"3. sucecion de fibonacci"<<endl;	
	  cout << "Elija una opcion: ";
      cin >> opcionsecundaria;
      	
		  
	if  (opcionsecundaria == 1){ 
		   		 int primerTermino, diferencia, cantidadTerminos;    
    // Solicitar al usuario el primer término de la sucesión
    cout << "Ingrese el primer termino de la sucesion: ";
    cin >> primerTermino;
    
    // Solicitar al usuario la diferencia entre los términos de la sucesión
    cout << "Ingrese la diferencia entre los terminos: ";
    cin >> diferencia;
    
    // Solicitar al usuario la cantidad de términos a generar
    cout << "Ingrese la cantidad de terminos a generar: ";
    cin >> cantidadTerminos;
    
    // Generar la sucesión e imprimir los términos
    cout << "La sucesion aritmetica es: ";
    for (int i = 0; i < cantidadTerminos; i++) {
        int termino = primerTermino + i * diferencia;
        cout << termino << " - ";
    }
    
    return 0;
}
			
 	if (opcionsecundaria==2) {
			   	 double primer_termino, razon, n;
    
    cout << "Ingrese el primer termino de la sucesion: ";
    cin >> primer_termino;
    
    cout << "Ingrese la razon de la sucesion: ";
    cin >> razon;
    
    cout << "Ingrese el numero de terminos que desea calcular: ";
    cin >> n;
    
    cout << "La sucesion geometrica es: ";
    for (int i = 0; i < n; i++) {
        cout << primer_termino * pow(razon, i) << " - ";
    }
    
    return 0;
}
			
if (opcionsecundaria ==3 ) {
			   	int ntermino, a = 0, b = 1, suma;

    cout << "Cual es el N-simo termino de la sucesion de Fibonacci que esta buscando?" << endl;
    cin >> ntermino;

    if (ntermino <= 0) {
        cout << "El termino de Fibonacci debe ser un numero positivo." << endl;
        break;
    }

    if (ntermino == 1) {
        cout << "El termino " << ntermino << " de la sucesion de Fibonacci es: " << a << endl;
    } else if (ntermino == 2) {
        cout << "El termino " << ntermino << " de la sucesion de Fibonacci es: " << b << endl;
    } else {
        int contador = 2; // Comenzamos desde el tercer término
        do {
            suma = a + b;
            a = b;
            b = suma;
            contador++;
        } while (contador < ntermino);

        cout << "El termino " << ntermino << " de la sucesion de Fibonacci es: " << suma << endl;
    }
			
			   }
	if (opcionsecundaria==4){
		  int a, b, m;
    
    cout << "Ingrese el valor de a: ";
    cin >> a;
    
    cout << "Ingrese el valor de b: ";
    cin >> b;
    
    cout << "Ingrese el valor de m: ";
    cin >> m;
    
    if ((a - b) % m == 0) {
        cout << "La congruencia " << a << " = " << b << " (mod " << m << ") es verdadera." << endl;
    } else {
        cout << "La congruencia " << a << " = " << b << " (mod " << m << ") es falsa." << endl;
    }
    
    return 0;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------
double m, s, res;
case 4:{
			int subopcion;

    cout << "Bienvenido a la calculadora de permutaciones y combinaciones" << endl;
    cout << "1. Permutaciones" << endl;
    cout << "2. Combinaciones" << endl;

    cout << "Elija una opcion: ";
    cin >> subopcion;

    int m, s;

    switch(subopcion) {
        case 1: {
            cout << "Ingrese el valor de m: ";
            cin >> m;
            cout << "Ingrese el valor de s: ";
            cin >> s;

            cout << "1. Con repeticion" << endl;
            cout << "2. Sin repeticion" << endl;

            int opcionPermutaciones;
            cout << "Elija una opcion: ";
            cin >> opcionPermutaciones;

            switch(opcionPermutaciones) {
                case 1:
                    cout << "Permutaciones con repeticion: " << permutacionesConrepeticion(m, s) << endl;
                    break;
                case 2:
                    cout << "Permutaciones sin repeticion: " << permutacionesSinrepeticion(m, s) << endl;
                    break;
                default:
                    cout << "Opcion no válida" << endl;
                    break;
            }
            break;
        }
        case 2: {
            cout << "Ingrese el valor de m: ";
            cin >> m;
            cout << "Ingrese el valor de s: ";
            cin >> s;

            cout << "1. Con repeticion" << endl;
            cout << "2. Sin repeticion" << endl;

            int opcionCombinaciones;
            cout << "Elija una opcion: ";
            cin >> opcionCombinaciones;

            switch(opcionCombinaciones) {
                case 1:
                    cout << "Combinaciones posibles: " << combinacionesConrepeticion(m, s) << endl;
                    break;
                case 2:
                    cout << "Combinaciones posible: " << combinacionesSinrepeticion(m, s) << endl;
                    break;
                default:
                    cout << "Opcion no válida" << endl;
                    break;
            }
            break;
        }
        default:
            cout << "Opcion no válida" << endl;
            break;
    }

    return 0;
}       

        default:
            cout<<"Opcion no valida";
            break;
    }
    return 0;
}