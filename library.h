#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include<fstream>
#include<vector>
#include<set>
#include<algorithm>
#include"book.h"
namespace lib{
	class Library{
		public:
			const std::set<Book> &books;
			static std::string new_id(size_t);
			Library():books(m_books){}
			Library(std::ifstream&);
			// bug:when one ID is used twice
			void lend(const std::string &id,const std::string &name){
				m_books.insert(Book(id,name));
			}
			void lend(const std::string &id,std::string &&name){
				m_books.insert(Book(id,name));
			}
			void lend(std::string &&id,const std::string &name){
				m_books.insert(Book(id,name));
			}
			void lend(std::string &&id,std::string &&name){
				m_books.insert(Book(id,name));
			}
			// it may throw an exception - type is out_of_range
			void Return(const std::string &id){
				Return(std::string(id));
			}
			void Return(std::string&&);
			std::vector<Book> sort_by_time()const;
			void save(std::ofstream&)const;
		private:
			std::set<Book> m_books;
	};
}
#endif