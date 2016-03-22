#include <iostream>

#include "KenoDAO.h"

using namespace std;

//TODO: CONSTRUTOR
explicit
KenoBet(unsigned int  _maxNumSpots = 15, vector<int> _spots,  float _wage){
    m_spots = _spots;
    m_wage = _wage;
    m_maxSpots = _maxNumSpots;
}

bool
addNumber( int _spot){
    if( std::find(m_spots.begin(), m_spots.end(), _spot) != m_spots.end()){
        m_spots.insert(m_spots.end(), _spot);
        return true;
    } else{
        return false;
    }
}

bool
setWage( float _wage){
    if(_wage > 0){
        m_wage = _wage;
        return true;
    } else{
        return false;
    }
}

void
reset( void ){
    m_spots.clear();
    m_wage = 0;
}

float
getWage() const{
    return m_wage;
}


std::vector<int>
getHits(vector<int> & _hits){
    //TODO: USAR O TOKENIZADOR AQUI??
    for(int i = 0; i < m_spots.size()){

    }
}



