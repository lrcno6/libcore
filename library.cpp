#include<stdexcept>
#include"library.h"
#include"function.h"
using namespace lib;
std::string Library::new_id(size_t len){
	using namespace std;
	string id(len,'\0');
	for(auto &i:id)
		i=randc();
	return id;
}
Library::Library(std::ifstream &fin):books(m_books){
	while(1){
		Book book(fin);
		if(!fin)
			break;
		m_books.insert(book);
	}
}
void Library::Return(std::string &&id){
	using namespace std;
	auto iter=m_books.find(Book(id,string()));
	if(iter==m_books.end())
		throw out_of_range("lib::Library::Return:invalid ID");
	m_books.erase(iter);
}
std::vector<Book> Library::sort_by_time()const{
	using namespace std;
	vector<Book> V(m_books.begin(),m_books.end());
	sort(V.begin(),V.end(),Book::time_cmp);
	return V;
}
void Library::save(std::ofstream &fout)const{
	for(auto i:m_books)
		fout<<i.save()<<std::endl;
}