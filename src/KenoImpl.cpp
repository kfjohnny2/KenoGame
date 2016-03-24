#include <iostream>

#include "KenoDAO.h"

using namespace std;
//TODO: CONSTRUTOR
// explicit
// KenoBet(unsigned int _maxNumSpots, vector<int> _spots,  float _wage){
//     m_spots = _spots;
//     m_wage = _wage;
//     m_maxSpots = _maxNumSpots;
// }

bool
KenoBet::addNumber( int _spot){
    if( std::find(m_spots.begin(), m_spots.end(), _spot) != m_spots.end()){
        m_spots.insert(m_spots.end(), _spot);
        return true;
    } else{
        return false;
    }
}

bool
KenoBet::setWage( float _wage){
    if(_wage > 0){
        m_wage = _wage;
        return true;
    } else{
        return false;
    }
}

void
KenoBet::reset( void ){
    m_spots.clear();
    m_wage = 0;
}

float
KenoBet::getWage() const{
    return m_wage;
}

std::size_t
KenoBet::numChosen() const{
    return m_spots.size();
}

std::vector<int>
KenoBet::getHits(vector<int> & _hits) const{
    //TODO: USAR O TOKENIZADOR AQUI??
}

std::vector<int>
KenoBet::getSpots(void) const{
    return m_spots;
}


