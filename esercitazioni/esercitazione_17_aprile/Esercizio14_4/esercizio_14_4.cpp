#include <iostream>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////////
// Interfaccia della classe punto2d
////////////////////////////////////////////////////////////////////

class punto2d {

public:

	// Costruttori
	punto2d();
	punto2d(double x, double y);
	punto2d(const punto2d& p);
	
	// Distruttore
	~punto2d();

	// Selettori
	double getX() const;
	double getY() const;

	// Modificatori
	void setX(double x);
	void setY(double x);

	// Operatori sovraccaricati
	punto2d operator-() const;
	punto2d& operator++();
	punto2d operator++(int);
    punto2d& operator--();
	punto2d operator--(int);
	punto2d operator+(punto2d p) const;
	punto2d operator-(punto2d p) const;
	punto2d operator*(double s) const;
	int operator==(punto2d p) const;
	const punto2d& operator=(const punto2d& p);
	friend ostream& operator<<(ostream& os, const punto2d& p);
	friend istream& operator>>(istream& is, punto2d& p);
	
	// Operazioni
	double distanza(punto2d p) const;

private:
	double _x;
	double _y;
};

/////////////////////////////////////////////////////////////////////
// Costruttori della classe punto2d
/////////////////////////////////////////////////////////////////////

punto2d::punto2d()
	: _x(0.0), _y(0.0)
{
}

punto2d::punto2d(double x, double y)
	: _x(x), _y(y)
{
}

punto2d::punto2d(const punto2d& p)
	: _x(p._x), _y(p._y)
{
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe punto2d
/////////////////////////////////////////////////////////////////////

punto2d::~punto2d()
{
}
	
/////////////////////////////////////////////////////////////////////
// Selettori della classe punto2d
/////////////////////////////////////////////////////////////////////

double punto2d::getX() const
{
	return _x;
}

double punto2d::getY() const
{
	return _y;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe punto2d
/////////////////////////////////////////////////////////////////////

void punto2d::setX(double x)
{
	_x = x;
}

void punto2d::setY(double y)
{
	_y = y;
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe punto2d
/////////////////////////////////////////////////////////////////////

punto2d punto2d::operator-() const
{
	return punto2d(-getX(), -getY());
}

punto2d& punto2d::operator++()
{
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return *this;
}

punto2d punto2d::operator++(int)
{
	punto2d temp(*this);
	setX(getX() + 1.0);
	setY(getY() + 1.0);
	return temp;
}

punto2d& punto2d::operator--()
{
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return *this;
}

punto2d punto2d::operator--(int)
{
	punto2d temp(*this);
	setX(getX() - 1.0);
	setY(getY() - 1.0);
	return temp;
}

punto2d punto2d::operator+(punto2d p) const
{
	return punto2d(getX() + p.getX(), getY() + p.getY());
}

punto2d punto2d::operator-(punto2d p) const
{
	return punto2d(getX() - p.getX(), getY() - p.getY());
}

punto2d punto2d::operator*(double s) const
{
	return punto2d(s * getX(), s * getY());
}

int punto2d::operator==(punto2d p) const
{
	return (getX() == p.getX() && getY() == p.getY());
}

const punto2d& punto2d::operator=(const punto2d& p)
{	
	if (&p != this) {
		setX(p.getX());
		setY(p.getY());
	}
	return *this;
}

ostream& operator<<(ostream& os, const punto2d& p)
{
	os << "(" << p.getX() << "," << p.getY() << ")";
	return os;
}

istream& operator >> (istream& is, punto2d& p)
{
	double x = 0.0;
	double y = 0.0;
	is >> x >> y;
	p.setX(x);
	p.setY(y);
	return is;
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe punto2d
/////////////////////////////////////////////////////////////////////

double punto2d::distanza(punto2d p) const
{
	double deltaX = getX() - p.getX(); 
	double deltaY = getY() - p.getY();
	return sqrt(deltaX * deltaX + deltaY * deltaY);
}

/////////////////////////////////////////////////////////////////////
// Interfaccia della classe poligono2d
/////////////////////////////////////////////////////////////////////

class poligono2d
{
public:

	// Costruttori
	poligono2d();
	poligono2d(int dim);
	poligono2d(punto2d pti[], int dim);
	poligono2d(const poligono2d& p);

	// Distruttore
	~poligono2d();

	// Selettori
	int get_num_vertici() const;
	const punto2d* get_vertici() const;
	
	// Modificatori
	void set_poligono(punto2d pti[], int dim);
	
	// Operatori sovraccaricati
	poligono2d operator*(double s) const;
	const poligono2d& operator=(const poligono2d& p);
	punto2d& operator[](int indice);
	friend ostream& operator << (ostream& os, const poligono2d& p);
	friend istream& operator >> (istream& is, poligono2d& p);
	
	// Operazioni
	double get_perimetro() const;

private:
	punto2d* _p;
	int _n;
};

/////////////////////////////////////////////////////////////////////
// Costruttori della classe poligono2d
/////////////////////////////////////////////////////////////////////

poligono2d::poligono2d()
	: _p(NULL), _n(0)
{
}

poligono2d::poligono2d(int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d* p = new punto2d[dim];
		if (p != NULL) {
			_p = p;
			_n = dim;
		}
	}
}

poligono2d::poligono2d(punto2d pti[], int dim)
	: _p(NULL), _n(0)
{
	if (dim > 0) {
		punto2d* p = new punto2d[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			_p = p;
			_n = dim;
		}
	}
}

poligono2d::poligono2d(const poligono2d& p)
	: _p(NULL), _n(0)
{
	if (p._n > 0) {
		punto2d* pol = new punto2d[p._n];
		if (pol != NULL) {
			for (int k = 0; k < p._n; k++)
				pol[k] = p._p[k];
			_p = pol;
			_n = p._n;
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Distruttore della classe poligono2d
/////////////////////////////////////////////////////////////////////

poligono2d::~poligono2d()
{
	if (_p != NULL) {
		delete [] _p;
	}
}

/////////////////////////////////////////////////////////////////////
// Selettori della classe poligono2d
/////////////////////////////////////////////////////////////////////

int poligono2d::get_num_vertici() const
{
	return _n;
}

const punto2d* poligono2d::get_vertici() const
{
	return _p;
}

/////////////////////////////////////////////////////////////////////
// Modificatori della classe poligono2d
/////////////////////////////////////////////////////////////////////
	
void poligono2d::set_poligono(punto2d pti[], int dim)
{
	if (dim > 0) {
		punto2d* p = new punto2d[dim];
		if (p != NULL) {
			for (int k = 0; k < dim; k++)
				p[k] = pti[k];
			if (_p != NULL)
				delete [] _p;
			_p = p;
			_n = dim;
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Operatori sovraccaricati della classe poligono2d
/////////////////////////////////////////////////////////////////////

poligono2d poligono2d::operator*(double s) const
{
	poligono2d p(*this);
	if (get_vertici() != NULL) {
		for (int k = 0; k < get_num_vertici(); k++)
			p[k]= get_vertici()[k] * s;
	}
	return p;
}

const poligono2d& poligono2d::operator=(const poligono2d& p)
{
	if (&p != this) {
		if (_p != NULL) {
			delete [] _p;
			_p = NULL;
		}
		_n = 0;
		int n = p.get_num_vertici();
		if (n > 0) {
			punto2d* pnewpol = new punto2d[n];
			if (pnewpol != NULL) {
				for (int k = 0; k < n; k++)
					pnewpol[k] = (p._p)[k];
				_p = pnewpol;
				_n = n;
			}
		}
	}
	return *this;
}

punto2d& poligono2d::operator[](int indice)
{
	return _p[indice];
}

/////////////////////////////////////////////////////////////////////
// Operazioni della classe poligono2d
/////////////////////////////////////////////////////////////////////

double poligono2d::get_perimetro() const
{
	double perimetro = 0.0;
	if (get_vertici() != NULL) {
		for (int k = 0; k < (get_num_vertici() - 1); k++)
			perimetro += (get_vertici()[k]).distanza(get_vertici()[k + 1]);
		perimetro += (get_vertici()[0]).distanza(get_vertici()[get_num_vertici() - 1]);
	}
	return perimetro;
}

////////////////////////////////////////////////////////////////////
// Funzioni amiche della classe poligono2d
////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const poligono2d& p)
{
	const punto2d* pt = p.get_vertici();
	if (pt != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			os << pt[k] << ' ';
	return os;
}

istream& operator>>(istream& is, poligono2d& p)
{
	if (p.get_vertici() != NULL)
		for (int k = 0; k < p.get_num_vertici(); k++)
			is >> p[k];
	return is;
}

/////////////////////////////////////////////////////////////////////
// Funzione main
/////////////////////////////////////////////////////////////////////

int main ()
{
	int numVertici;
	do {
		cout << "Inserire il numero di vertici di un poligono: ";
		cin >> numVertici;
		if (numVertici <= 0)
			cout << "Attenzione! Il numero di vertici deve essere un numero positivo" << endl;
	} while (numVertici <= 0);

	poligono2d p(numVertici);	

	cout << "Inserire le cordinate dei vertici del poligono:" << endl;
	cin >> p;

	cout << "Il perimetro del poligono costituito dai seguenti " << p.get_num_vertici() << " vertici:" << endl;
	cout << p << endl;
	cout << "e' lungo " << p.get_perimetro() << endl;
	cout << endl;

	return 0;
}
