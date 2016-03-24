
#include <vector>
#include <cstddef>
#include <algorithm>

#ifndef _KENO_BET_H_
#define _KENO_BET_H_

class KenoBet{
	public:
		explicit KenoBet( unsigned int _maxNumSpots = 15, unsigned int _rounds = 1){
			m_maxSpots = _maxNumSpots;
			m_rounds = _rounds;
		}
		bool addNumber(int _spot);
		bool setWage(float _wage);
		void reset(void);
		float getWage( void ) const;
		std::size_t numChosen(void ) const;
		std::vector<int> getHits(std::vector<int> & _hits) const;
		std::vector<int> getSpots( void ) const;
		int getRounds(void) const;
	private:
		std::vector<int> m_spots;
		float m_wage;
		unsigned int m_maxSpots;
		int m_rounds;
};

#endif