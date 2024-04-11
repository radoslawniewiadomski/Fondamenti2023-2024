#include <iostream>
using namespace std;

// Classe rilevamento
class rilevamento {
public:
	rilevamento();
	rilevamento(double temperatura, double pressione);
	rilevamento(double dati[2]);
	rilevamento(const rilevamento& r);
	~rilevamento();
	double get_temperatura() const;
	double get_pressione() const;
	void set_temperatura(double temperatura);
	void set_pressione(double pressione);
private:
	double _dati[2];
};

rilevamento::rilevamento() 
{
	_dati[0] = 0.0;
	_dati[1] = 0.0;
	cout << "Questo e' il costruttore di default della classe rilevamento" << endl;
}

// IN ALTERNATIVA
/* rilevamento::rilevamento() 
	: _dati{0.0, 0.0}
{
	cout << "Questo e' il costruttore di default" << endl;
} */

rilevamento::rilevamento(double temperatura, double pressione)
{
	_dati[0] = temperatura;
	_dati[1] = pressione;
	cout << "Questo e' il primo costruttore con parametri della classe rilevamento" << endl;
}

// IN ALTERNATIVA
/* rilevamento::rilevamento(double temperatura, double pressione)
	: _dati{temperatura, pressione}
{
	cout << "Questo e' il primo costruttore con parametri" << endl;
} */

rilevamento::rilevamento(double dati[2])
{
	_dati[0] = dati[0];
	_dati[1] = dati[1];
	cout << "Questo e' il secondo costruttore con parametri della classe rilevamento" << endl;
}

// IN ALTERNATIVA
/* rilevamento::rilevamento(double dati[2])
	: _dati{dati[0], dati[1]}
{
	cout << "Questo e' il secondo costruttore con parametri" << endl;
} */

rilevamento::rilevamento(const rilevamento& r)
{
	_dati[0] = r._dati[0];
	_dati[1] = r._dati[1];
	cout << "Questo e' il costruttore di copia della classe rilevamento" << endl;
}

// IN ALTERNATIVA
/* rilevamento::rilevamento(const rilevamento& r)
	: _dati{r._dati[0], r._dati[1]}
{
	cout << "Questo e' il costruttore di copia" << endl;
} */

rilevamento::~rilevamento()
{
	cout << "Questo e' il distruttore della classe rilevamento" << endl;
}

double rilevamento::get_temperatura() const
{
	return _dati[0];
}

double rilevamento::get_pressione() const
{
	return _dati[1];	
}

void rilevamento::set_temperatura(double temperatura)
{
	_dati[0] = temperatura;
}

void rilevamento::set_pressione(double pressione)
{
	_dati[1] = pressione;
}


// Funzioni 
// Sono implementate esternamente alla classe per mostrare il funzionamento
// dei costruttori e l'uso di selettori e modificatori.
// Sarebbe piu' opportuno implementarle come funzioni membro.
void stampa_rilevamento(rilevamento r)
{
	cout << "Rilevamento: temperatura = " 
		 << r.get_temperatura() << " C, pressione = "
		 << r.get_pressione() << " hPa" << endl; 
}

void leggi_rilevamento(rilevamento& r)
{
	double t = 0.0;
	double p = 0.0;
	cout << "Inserire il rilevamento di temperatura e pressione: " << endl;
	cout << "Temperatura: "; 
	cin	>> t;
	cout << "Pressione: ";
	cin >> p; 
	r.set_temperatura(t); 
	r.set_pressione(p);
}


// Funzione main
int main() 
{
	cout << "Parte 1: " << endl;
	rilevamento r1;
	stampa_rilevamento(r1);
	
	cout << "Parte 2: " << endl;
	rilevamento r2(15.0, 1060.0);
	stampa_rilevamento(r2);
	
	cout << "Parte 3: " << endl;
	double ril[2] = {20.0, 1065.0};
	rilevamento r3(ril);
	stampa_rilevamento(r3);
	
	cout << "Parte 4: " << endl;
	rilevamento r4;
	leggi_rilevamento(r4);
	stampa_rilevamento(r4);
	
	return 0;
}
