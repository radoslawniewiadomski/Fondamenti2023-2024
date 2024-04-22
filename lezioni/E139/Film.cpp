#include "Film.h"
#include<cstring>
#include <iostream>

using namespace std;


film::film() {
    _titolo = new char[20];
    strcpy(_titolo, "N/D");
    _durata = 0;
    _anno = 0;}

film::film(char* titolo, int durata, int anno) {
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);
    _durata = durata;
    _anno = anno;}

film::film(const film& otherFilm) {
    _titolo = new char[strlen(otherFilm._titolo) + 1];
    strcpy(_titolo, otherFilm._titolo);
    _durata = otherFilm._durata;
    _anno = otherFilm._anno;}

film::~film() {
    delete[] _titolo;}

char* film::getTitolo() const {
    return _titolo;}


    void film::setTitolo(const char* titolo) {
    delete[] _titolo;
    _titolo = new char[strlen(titolo) + 1];
    strcpy(_titolo, titolo);}

int film::getDurata() const {
    return _durata;}

void film::setDurata(int durata) {
    _durata = durata;}

int film::getAnno() const {
    return _anno;}

void film::setAnno(int anno) {
    _anno = anno;}

void film::stampaFilm() {
    cout << "Titolo: " << _titolo << endl;
    cout << "Durata: " << _durata << endl;
    cout << "Anno: " << _anno << endl;
}
