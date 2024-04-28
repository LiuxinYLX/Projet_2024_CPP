#include "../include/Emprunt.hpp"

Emprunt::Emprunt(double montant, double montantMax, int dateEmprunt, int dateRemboursement)
    : montant(montant), montantMax(montantMax), dateEmprunt(dateEmprunt), dateRemboursement(dateRemboursement)
{
    // Constructor body (if needed)
}

double Emprunt::getMontant() const {
    return montant;
}

double Emprunt::getMontantMax() const {
    return montantMax;
}

int Emprunt::getDateEmprunt() const {
    return dateEmprunt;
}

int Emprunt::getDateRemboursement() const {
    return dateRemboursement;
}

void Emprunt::setMontant(double nouveauMontant) {
    montant = nouveauMontant;
}

void Emprunt::setDateEmprunt(int date) {
    dateEmprunt = date;
}

void Emprunt::setDateRemboursement(int date) {
    dateRemboursement = date;
}
/*bool Emprunt::condition_Emprunt(double montant, Emprunt emprunt){
    if (montant <= emprunt.getMontantMax()){return true;}
    else {return false;}
}

Emprunt Emprunt::creerEmprunt(double montantMax, int day){
    Emprunt emprunt(0, montantMax, day, day + 5);
    return emprunt;
}*/
