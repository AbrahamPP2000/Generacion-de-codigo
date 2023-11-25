#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class SemanticAnalyzer {
public:
	// Método para declarar una variable
	void declareVariable(const string& name) {
		if (variables_.count(name) > 0) {
			throw runtime_error("Error semántico: Variable ya declarada");
		}
		variables_[name] = 0; // Inicializa la variable en 0
	}
	
	// Método para asignar un valor a una variable
	void assignValue(const string& name, int value) {
		if (variables_.count(name) == 0) {
			throw runtime_error("Error semántico: Variable no declarada");
		}
		variables_[name] = value;
	}
	
	// Método para obtener el valor de una variable
	int getVariableValue(const string& name) {
		if (variables_.count(name) == 0) {
			throw runtime_error("Error semántico: Variable no declarada");
		}
		return variables_[name];
	}
	
private:
		map<string, int> variables_;
};

int main() {
	SemanticAnalyzer analyzer;
	
	try {
		// Declaración de variables
		analyzer.declareVariable("x");
		analyzer.declareVariable("y");
		
		// Asignación de valores
		analyzer.assignValue("x", 42);
		analyzer.assignValue("y", 17);
		
		// Uso de variables
		int resultado = analyzer.getVariableValue("x") + analyzer.getVariableValue("y");
		cout << "Resultado: " << resultado << endl;
		
		// Intento de uso de variable no declarada (error semántico)
		// int valor = analyzer.getVariableValue("z");
	} catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
	}
	
	return 0;
}

