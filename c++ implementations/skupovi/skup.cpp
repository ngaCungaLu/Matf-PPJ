#include<iostream>
#include<string>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include"skup.hpp"


std::ostream& operator << (std::ostream& out, const Skup& s){
	out << "{ " ;
	auto iter = s.m_set.begin();
	while (iter != s.m_set.end()){
		std::cout << *iter << " ";
		iter++;
	}
//	for (auto e : s.m_set){
//		out << e << ", " ;
//	}
	out << "}" << std::endl;

	return out;
}
Skup* Skup::operator * (const Skup& s){
	std::set<int> novi;

	std::cout << "unija" << std::endl;
	//da bi koristili std::set_union mora da se ukljuci
	//<algorithm>
	std::set_union(
			m_set.begin(), m_set.end(),
			s.m_set.begin(), s.m_set.end(),
			std::inserter(novi, novi.begin())
			);

	return new Skup(novi);

}
Skup* Skup::operator + (const Skup& s){
	std::set<int> novi;

	std::cout << "presek" << std::endl;
	//<algorithm>
	std::set_intersection(
			m_set.begin(), m_set.end(),
			s.m_set.begin(), s.m_set.end(),
			std::inserter(novi, novi.begin())
			);
	return new Skup(novi);

}

Skup* Skup::operator - (const Skup& s){
	std::set<int> novi;

	std::cout << "razlika" << std::endl;
	//<algorithm>
	std::set_difference(
			m_set.begin(), m_set.end(),
			s.m_set.begin(), s.m_set.end(),
			std::inserter(novi, novi.begin())
			);
	return new Skup(novi);
	
}
Skup::Skup(int& num){
	m_set.insert(num);

}

//GET-er za m_set
const std::set<int>& Skup::elementi() const{
	return m_set;
}

bool Skup::podskup(const Skup& s){

	for (const auto& e : m_set){
		auto finder = s.elementi().find(e);
		if (finder == s.elementi().end()) return false;
		std::cout << "tu smo" << std::endl;
	}

	return true;
}

bool Skup::clan(const int& n){
	auto finder = m_set.find(n);
	if (finder == m_set.end()) return false;
	return true;
}

void Skup::add(const int& m){
	m_set.insert(m);
}

Skup::Skup(){}

Skup::Skup(const std::set<int>& s)
	:m_set(s){};
