#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class SemanticAnalyzer {
public:
	// M�todo para declarar una variable
	void declareVariable(const string& name) {
		if (variables_.count(name) > 0) {
			throw runtime_error("Error sem�ntico: Variable ya declarada");
		}
		variables_[name] = 0; // Inicializa la variable en 0
	}
	
	// M�todo para asignar un valor a una variable
	void assignValue(const string& name, int value) {
		if (variables_.count(name) == 0) {
			throw runtime_error("Error sem�ntico: Variable no declarada");
		}
		variables_[name] = value;
	}
	
	// M�todo para obtener el valor de una variable
	int getVariableValue(const string& name) {
		if (variables_.count(name) == 0) {
			throw runtime_error("Error sem�ntico: Variable no declarada");
		}
		return variables_[name];
	}
	
private:
		map<string, int> variables_;
};

int main() {
	SemanticAnalyzer analyzer;
	
	try {
		// Declaraci�n de variables
		analyzer.declareVariable("x");
		analyzer.declareVariable("y");
		
		// Asignaci�n de valores
		analyzer.assignValue("x", 42);
		analyzer.assignValue("y", 17);
		
		// Uso de variables
		int resultado = analyzer.getVariableValue("x") + analyzer.getVariableValue("y");
		cout << "Resultado: " << resultado << endl;
		
		// Intento de uso de variable no declarada (error sem�ntico)
		// int valor = analyzer.getVariableValue("z");
	} catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
	}
	
	return 0;
}

