#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include<fstream>
#include<vector>
#include<set>
#include<stdexcept>
#include<algorithm>
#include"book.h"
namespace lib{
	class Library{
		public:
			const std::set<Book> &books;
			static std::string new_id(size_t);
			Library():books(m_books){}
			Library(std::ifstream&);
			// it may throw an exception - type is logic_error
			void lend(const std::string &id,const std::string &name){
				using namespace std;
				lend(string(id),string(name));
			}
			void lend(const std::string &id,std::string &&name){
				using namespace std;
				lend(string(id),name);
			}
			void lend(std::string &&id,const std::string &name){
				using namespace std;
				lend(id,string(name));
			}
			void lend(std::string &&id,std::string &&name){
				Book book(id,name);
				if(m_books.find(book)!=m_books.end())
					throw std::logic_error("lib::Library::lend:the ID is used");
				m_books.insert(book);
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