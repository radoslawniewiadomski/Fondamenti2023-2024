class film {
    char* _titolo;
    int _durata;
    int _anno;

public:
    film(); //default
    film(char* titolo, int durata, int anno);
    film(const film& otherFilm); // di copia
     ~film();
    char* getTitolo() const;
    void setTitolo(const char* titolo);
    int getDurata() const;
    void setDurata(int durata);
    int getAnno() const;
    void setAnno(int anno);
    void stampaFilm();

};


