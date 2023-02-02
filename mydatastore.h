#include "datastore.h"
#include "product.h"
#include "book.h"
#include "movie.h"
#include "clothing.h"
#include "user.h"

class MyDataStore : public DataStore {
  public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);
    void addUser(User* u);
    bool setUser(std::string username);
    void addToCart(std::string username, Product* p);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    void viewCart(std::string username);
    void buyCart(std::string username);
    void dump(std::ostream& ofile);


  private:
    User* currentUser;
    std::map<User*, std::vector<Product*>> cart_;
    std::set<Product*> products_;
    std::set<User*> users_;
};