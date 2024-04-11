#include <iostream>
using namespace std;

// Classe rilevamento
class rilevamento {
public:
	rilevamento();
	rilevamento(double t, double p);
	rilevamento(double dati[2]);
	rilevamento(const rilevamento& r);
	~rilevamento();
	double get_temperatura() const;
	double get_pressione() const;
	void set_temperatura(double t);
	void set_pressione(double p);
	void stampa() const;
	void leggi();
private:
	double _temperatura;
	double _pressione;
};

rilevamento::rilevamento() 
	: _temperatura(0.0), _pressione(0.0)
{
	cout << "Questo e' il costruttore di default della classe rilevamento" << endl;
}

rilevamento::rilevamento(double t, double p)
	: _temperatura(t), _pressione(p)
{
}

rilevamento::rilevamento(double dati[2])
	: _temperatura(dati[0]), _pressione(dati[1])
{
}

rilevamento::rilevamento(const rilevamento& r)
	: _temperatura(r._temperatura), _pressione(r._pressione)
{
}

rilevamento::~rilevamento()
{
	cout << "Questo e' il distruttore della classe rilevamento" << endl;
}

double rilevamento::get_temperatura() const
{
	return _temperatura;
}

double rilevamento::get_pressione() const
{
	return _pressione;	
}

void rilevamento::set_temperatura(double t)
{
	_temperatura = t;
}

void rilevamento::set_pressione(double p)
{
	_pressione = p;
}

void rilevamento::stampa() const
{
	cout << "Rilevamento: temperatura = " 
		 << get_temperatura() << " C, pressione = "
		 << get_pressione() << " hPa" << endl; 
}

void rilevamento::leggi()
{
	double t = 0.0;
	double p = 0.0;
	cout << "Inserire il rilevamento di temperatura e pressione: " << endl;
	cout << "Temperatura: "; 
	cin	>> t;
	cout << "Pressione: ";
	cin >> p; 
	set_temperatura(t); 
	set_pressione(p);
}


// Classe tempo
class tempo {
public:
	tempo();
	tempo(int h, int m, int s);
	tempo(const tempo& o);
	~tempo();
	int get_ora() const;
	int get_minuto() const;
	int get_secondo() const;
	void set_ora(int h);
	void set_minuto(int m);
	void set_secondo(int s);
	void stampa() const;
	void leggi();
private:
	int _h;
	int _m;
	int _s;
};

tempo::tempo() : _h(0), _m(0), _s(0)
{	
	cout << "Questo e' il costruttore di default della classe tempo" << endl;
}

tempo::tempo(int h, int m, int s) : _h(h), _m(m), _s(s)
{	
}

tempo::tempo(const tempo& o) : _h(o._h), _m(o._m), _s(o._s)
{	
}

tempo::~tempo()
{
	cout << "Questo e' il distruttore della classe tempo" << endl;	
}

int tempo::get_ora() const
{
	return _h;
}

int tempo::get_minuto() const
{
	return _m;
}

int tempo::get_secondo() const
{
	return _s;
}

void tempo::set_ora(int h)
{
	_h = h;
}

void tempo::set_minuto(int m)
{
	_m = m;
}

void tempo::set_secondo(int s)
{
	_s = s;
}

void tempo::stampa() const 
{
	cout << "Ore: " << get_ora() << ":" << get_minuto() << ":" << get_secondo();
}

void tempo::leggi()
{
	int h = 0;
	int m = 0;
	int s = 0;
	cout << "Inserire un tempo espresso in ore, minuti e secondi: " << endl;
	cout << "Ore: "; 
	cin	>> h;
	cout << "Minuti: ";
	cin >> m; 
	cout << "Secondi: ";
	cin >> s;
	set_ora(h); 
	set_minuto(m);
	set_secondo(s);
}

// Classe lettura_sensore
class lettura_sensore {
public:
	lettura_sensore();
	lettura_sensore(tempo t, rilevamento r);
	lettura_sensore(const lettura_sensore& l);
	~lettura_sensore();
	tempo get_tempo() const;
	rilevamento get_rilevamento() const;
	void set_tempo(tempo t);
	void set_rilevamento(rilevamento r);
	void stampa() const;
	void leggi();
private:
	tempo _t;
	rilevamento _r;	
};

lettura_sensore::lettura_sensore() : _t(), _r()
{	
	cout << "Questo e' il costruttore di default della classe lettura_sensore" << endl;	
}

lettura_sensore::lettura_sensore(tempo t, rilevamento r) : _t(t), _r(r)
{
}

lettura_sensore::lettura_sensore(const lettura_sensore& l) : _t(l._t), _r(l._r)
{
}

lettura_sensore::~lettura_sensore()
{
	cout << "Questo e' il distruttore della classe lettura_sensore" << endl;
}

tempo lettura_sensore::get_tempo() const
{
	return _t;	
}

rilevamento lettura_sensore::get_rilevamento() const
{
	return _r;
}

void lettura_sensore::set_tempo(tempo t)
{
	_t = t; // OPERA ASSEGNAMENTO BIT A BIT
}

void lettura_sensore::set_rilevamento(rilevamento r)
{
	_r = r; // OPERA ASSEGNAMENTO BIT A BIT
}

void lettura_sensore::stampa() const
{
	_t.stampa();
	cout << " - ";
	_r.stampa();
	cout << endl;
}

void lettura_sensore::leggi()
{
	_t.leggi();
	_r.leggi();
}


// Funzione main
int main() 
{
	const int dim = 3;
	lettura_sensore d[dim];
	for (int i = 0; i < dim; i++) {
		cout << "Inserire dati della lettura #" << i + 1 << ": " << endl; 
		d[i].leggi();
	}
	for (int j = 0; j < dim; j++) {	
		cout << "Lettura #" << j + 1 << ": " << endl;
		d[j].stampa();
	}
	return 0;
}

