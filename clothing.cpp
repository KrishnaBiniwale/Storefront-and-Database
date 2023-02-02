#include "clothing.h"
#include <sstream>


Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) 
: Product("clothing", name, price, qty), size_(size), brand_(brand)
{

}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> kwds;

  std::set<std::string> name = parseStringToWords(getName());
  std::set<std::string> brand = parseStringToWords(brand_);
  std::set<std::string> size;
  size.insert(size_);

  kwds = setUnion(name, brand);
  kwds = setUnion(kwds, size);

  return kwds;
}

std::string Clothing::displayString() const {
  return getName() + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + std::to_string(getPrice()) + " " + std::to_string(getQty()) + " left.";
}

void Clothing::dump(std::ostream& os) const {
  Product::dump(os);
  os << size_ << "\n" << brand_ << std::endl;
}