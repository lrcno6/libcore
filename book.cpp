#include<string>
#include"book.h"
using namespace lib;
Book::Book(std::ifstream &fin){
	fin>>m_id;
	do
		getline(fin,m_name);
	while(m_name.empty() && fin);
	fin>>m_time;
}
bool Book::time_cmp(const Book &x,const Book &y)noexcept{
	return x.m_time<y.m_time;
}