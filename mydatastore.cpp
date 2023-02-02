#include "mydatastore.h"

MyDataStore::MyDataStore()
{

}



MyDataStore::~MyDataStore()
{
  for (User* u : users_) {
    delete u;
  }
  users_.clear();
  for (Product* p : products_) {
    delete p;
  }
  products_.clear();
}

void MyDataStore::addUser(User* u) {
  users_.insert(u);
}

bool MyDataStore::setUser(std::string username) {
  std::set<User*>::iterator it;
  for (it = users_.begin(); it != users_.end(); ++it) {
    if ((*it)->getName() == username) {
      currentUser = *it;
      return true;
    } 
  }
  return false;
}

void MyDataStore::addProduct(Product* p) {
  products_.insert(p);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::set<Product*>::iterator it;
  std::vector<Product*> prods;
  std::set<std::string> termSet(terms.begin(), terms.end());

  if (!(type)) {
    for (it = products_.begin(); it != products_.end(); ++it) {
      std::set<std::string> s = (*it)->keywords();
      std::set<std::string> kwds = setIntersection(termSet, s);
      if (kwds == termSet) {
        prods.push_back(*it);
      }
    }
  } else {
    for (it = products_.begin(); it != products_.end(); ++it) {
      std::set<std::string> s = (*it)->keywords();
      std::set<std::string> kwds = setIntersection(termSet, s);
      if (!(kwds.empty())) {
        prods.push_back(*it);
      }
    }
  }
  return prods;
}

void MyDataStore::dump(std::ostream& ofile) {
  ofile << "<products>" << "\n";
  for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
    (*it)->dump(ofile);
  }
  ofile << "</products>" << "\n" << "<users>" << "\n";
  for (std::set<User*>::iterator it = users_.begin(); it!= users_.end(); ++it) {
    (*it)->dump(ofile);
  }
  ofile << "</users>" << "\n";
}

void MyDataStore::addToCart(std::string username, Product* p) {
  bool userExists = setUser(username);
  if (!userExists) {
    std::cout << "Invalid request" << std::endl;
    return;
  }
  if (!(cart_.count(currentUser))) {
    std::vector<Product*> vec;
    cart_[currentUser] = vec;
  }
  cart_[currentUser].push_back(p);
}

void MyDataStore::viewCart(std::string username) {
  bool userExists = setUser(username);
  if (!userExists) {
    std::cout << "Invalid username" << std::endl;
    return;
  }
  std::vector<Product*>::iterator it;
  int index = 1;
  for (it = cart_[currentUser].begin(); it != cart_[currentUser].end(); ++it) {
    std::cout << "Item: " << index << std::endl;
    std::cout << (*it)->displayString() << std::endl;
    std::cout << std::endl;
    index++;
  }
}

void MyDataStore::buyCart(std::string username) {
  bool userExists = setUser(username);
  if (!userExists) {
    std::cout << "Invalid username" << std::endl;
    return;
  }
  std::vector<Product*>::iterator it = cart_[currentUser].begin();
  while (it != cart_[currentUser].end()) {
    if ((*it)->getQty() > 0 && (currentUser->getBalance() >= (*it)->getPrice())) {
      currentUser->deductAmount((*it)->getPrice());
      (*it)->subtractQty(1);
      it = cart_[currentUser].erase(it);
    } else {
      ++it;
    }
  }
}