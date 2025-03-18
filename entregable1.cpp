#include <iostream>
#include <cstdlib> // Convierte cadenas a enteros

using namespace std;

// Función para sumar dos números

double suma(int a, int b) {
    return a + b;
}

// Función para restar dos números

double resta(int a, int b) {
    return a - b;
}

// Función para multiplicar dos números

double multiplicacion(int a, int b) {
    return a * b;
}

// Función para dividir dos números

double division(int a, int b) {
    if (b == 0) {
        cout << "No se puede dividir entre cero." << endl;
        return 0; // Evita errores dividiendo entre 0
    }
    return (double)a / b; // Convierte a double para evitar divisiones enteras
}

// Recibe una función como argumento y ejecuta la operación
void ejecutarOperacion(double (*operacion)(int, int), int x, int y) {
    double resultado = operacion(x, y);
    cout << "El resultado es: " << resultado << endl;
}

int main(int argc, char *argv[]) {
    // Revisa si el usuario ingresó los 3 valores necesarios
    if (argc != 4) {
        cout << "Uso: ./programa num1 operador num2" << endl;
        return 1; // Sale si faltan datos
    }

    // Convierte los números ingresados desde la terminal
    int numero1 = atoi(argv[1]);
    int numero2 = atoi(argv[3]);
    char operacion = argv[2][0]; // Toma el operador como un solo caracter

    // Puntero a función que apunta a la operación que se va a ejecutar
    double (*funcionSeleccionada)(int, int) = nullptr;

    // Revisa qué operación se eligió y asigna la función correspondiente
    if (operacion == '+') {
        funcionSeleccionada = suma;
    } else if (operacion == '-') {
        funcionSeleccionada = resta;
    } else if (operacion == '*') {
        funcionSeleccionada = multiplicacion;
    } else if (operacion == '/') {
        funcionSeleccionada = division;
    } else {
        cout << "Operador no válido. Usa +, -, * o /." << endl;
        return 1; // Sale si el operador es incorrecto
    }

    // Llama a la función seleccionada y muestra el resultado
    ejecutarOperacion(funcionSeleccionada, numero1, numero2);

    return 0;
}