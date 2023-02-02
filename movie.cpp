#include "movie.h"
#include <sstream>


Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) 
: Product("movie", name, price, qty), genre_(genre), rating_(rating)
{

}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const {
  std::set<std::string> kwds;

  std::set<std::string> name = parseStringToWords(getName());
  std::set<std::string> genre = parseStringToWords(genre_);
  std::set<std::string> rating = parseStringToWords(rating_);

  kwds = setUnion(name, genre);
  kwds = setUnion(kwds, rating);

  return kwds;
}

std::string Movie::displayString() const {
  return getName() + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(getPrice()) + " " + std::to_string(getQty()) + " left.";
}


void Movie::dump(std::ostream& os) const {
  Product::dump(os);
  os << genre_ << "\n" << rating_ << std::endl;
}