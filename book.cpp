#include "book.h"
#include <sstream>


Book::Book(const std::string name, double price, int qty, const std::string isbn, const std::string author) 
: Product("book", name, price, qty), isbn_(isbn), author_(author)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const {
  std::set<std::string> kwds;

  std::set<std::string> name = parseStringToWords(getName());
  std::set<std::string> author = parseStringToWords(author_);
  std::set<std::string> isbn;
  isbn.insert(isbn_);

  kwds = setUnion(name, author);
  kwds = setUnion(kwds, isbn);

  return kwds;
}

std::string Book::displayString() const {
  return getName() + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(getPrice()) + " " + std::to_string(getQty()) + " left.";
}


void Book::dump(std::ostream& os) const {
  Product::dump(os);
  os << isbn_ << "\n" << author_ << std::endl;
}