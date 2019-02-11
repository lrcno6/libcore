#ifndef _BOOK_H_
#define _BOOK_H_
#include<fstream>
#include<string>
#include<ctime>
namespace lib{
	class Book{
		public:
			static bool time_cmp(const Book&,const Book&)noexcept;
			Book(const std::string &id,const std::string &name):m_id(id),m_name(name),m_time(time(nullptr)){}
			Book(const std::string &id,std::string &&name):m_id(id),m_name(name),m_time(time(nullptr)){}
			Book(std::string &&id,const std::string &name):m_id(id),m_name(name),m_time(time(nullptr)){}
			Book(std::string &&id,std::string &&name)noexcept:m_id(id),m_name(name),m_time(time(nullptr)){}
			Book(std::ifstream&);
			bool operator<(const Book &other)const noexcept{
				return m_id<other.m_id;
			}
			std::string show()const{
				return "ID:"+m_id+"\tBorrower:"+m_name+"\tTime:"+ctime(&m_time);
			}
			std::string save()const{
				return m_id+"\n"+m_name+"\n"+std::to_string(m_time);
			}
		private:
			time_t m_time;
			std::string m_id,m_name;
	};
}
#endif